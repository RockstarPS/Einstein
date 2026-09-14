import os
import sys
import netrc
import shutil
import tarfile
import hashlib
import urllib3
import argparse
import platform
import requests
from tqdm import tqdm
from getpass import getpass
from requests.auth import HTTPBasicAuth

# devNext Specific Functionalities
from devNext.utils.utils import is_pat_enabled
from devNext.utils.gitutil.gitcacheutil import gitcacheutil

# Disable insecure request warnings
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)


def display_usage():
    """
    Displays usage instructions for the script, including environment variables
    and command-line arguments.
    """
    usage_text = """
    Usage: python script_name.py [OPTIONS]

    This script downloads a file from Artifactory, validates its checksum, 
    and extracts it to a specified output path.

    Parameters can be set via environment variables or command-line arguments.
    If both are set, command-line arguments take precedence.

    Required Environment Variables (or Command-Line Arguments):
        - ARTI_HOST       : The host URL of Artifactory (e.g., https://artifactory.example.com)
        - ARTI_REPO       : The repository name in Artifactory (e.g., example-repo)
        - ARTI_PATTERN    : File pattern for matching artifacts (e.g., *.zip)
        - ARTI_OUTPUT_PATH     : The path to download and extract files to

    Command-Line Arguments (Overrides environment variables):
        --host <URL>         : The host URL of Artifactory (required if ARTI_HOST is not set)
        --repo <repo_name>   : Repository name in Artifactory (required if ARTI_REPO is not set)
        --pattern <pattern>  : File pattern for matching artifacts (required if ARTI_PATTERN is not set)
        --output <path>      : Download and extraction path (required if OUTPUT_PATH is not set)

    Optional Arguments:
        --usage              : Display this usage information and exit

    Example Usage:
        # Using environment variables
        export ARTI_HOST="https://artifactory.example.com"
        export ARTI_REPO="example-repo"
        export ARTI_PATTERN="*.zip"
        export ARTI_OUTPUT_PATH="/path/to/download"
        
        run "python script_name.py"

        
        # Using command-line arguments
        python script_name.py --host https://artifactory.example.com --repo example-repo --pattern "*.zip" --output /path/to/download

    Notes:
        - This script requires Python 3.8 and above versions.
        - Ensure you have permissions to write to the specified OUTPUT_PATH.
    """
    print(usage_text)


def is_env_var_present(partial_var_name):
    """
    Checks if any environment variable contains the specified partial name.
    
    Parameters:
    partial_var_name (str): The partial name of the environment variable to search for.
    
    Returns:
    bool: True if an environment variable with the partial name is found, False otherwise.
    """
    # Look for any environment variable name containing the partial_var_name
    return any(partial_var_name in var for var in os.environ)


def get_netrc_credentials(hostname=None, netrc_path=None):
    """
    Retrieve credentials from the .netrc file (or _netrc on Windows).
    
    Parameters:
    hostname (str, optional): The hostname for which to retrieve the credentials.
                              If not provided, the default credentials are retrieved.
    netrc_path (str, optional): The path to the .netrc (or _netrc) file.
                                If not provided, the default ~/.netrc (or ~/_netrc) path is used.
                              
    Returns:
    tuple: A tuple containing the username, account, and password, or None if no credentials are found.
    """
    try:
        # Determine the default netrc file path based on the platform
        default_netrc_path = os.path.expanduser("~/.netrc")
        if platform.system() == "Windows":
            default_netrc_path = os.path.expanduser("~/_netrc")

        # If no custom netrc path is provided, use the default path
        if not netrc_path:
            netrc_path = default_netrc_path
        
        # Parse the .netrc file
        netrc_data = netrc.netrc(netrc_path)
        
        # Get credentials for the specified hostname or the default credentials
        if hostname:
            auth = netrc_data.authenticators(hostname)
        else:
            auth = netrc_data.authenticators("default")
        
        if auth:
            username, account, password = auth
            return username, account, password
        else:
            print(f"No credentials found for {'default' if not hostname else hostname}.")
            return None

    except FileNotFoundError:
        print(f"The .netrc file was not found at {netrc_path}.")
        return None
    except netrc.NetrcParseError as e:
        print(f"Error parsing the .netrc file: {e}")
        return None

def get_or_prompt_credentials(hostname=None, netrc_path=None):
    """
    Retrieve credentials from the .netrc file or prompt the user if not available.

    Parameters:
    hostname (str, optional): The hostname for which to retrieve the credentials.
    netrc_path (str, optional): The path to the .netrc (or _netrc) file.
    
    Returns:
    tuple: A tuple containing the username, account, and password.
    """
    credentials = get_netrc_credentials(hostname, netrc_path)
    if credentials:
        return credentials
    else:
        print("*" * 30)
        print("Please enter the CDSID and Network Password: ")
        print("*" * 30)
        username = input("Enter username: ")
        password = getpass("Enter password: ")
        return username, None, password

def extract_tar_gz(file_name, dest_path, overwrite=False):
    """
    Extracts a .tar.gz file to a specified destination path.

    Parameters:
    file_name (str): The path to the .tar.gz file to be extracted.
    dest_path (str): The path where the contents of the file should be extracted.
    overwrite (bool): Whether to overwrite the destination path if it exists.

    Returns:
    None
    """
    if not tarfile.is_tarfile(file_name):
        raise ValueError(f"The file {file_name} is not a valid tar.gz file.")
    
    if os.path.exists(dest_path):
        if overwrite:
            shutil.rmtree(dest_path)
            print(f"Existing path {dest_path} has been removed.")
        else:
            raise FileExistsError(f"The destination path {dest_path} already exists.")
    
    os.makedirs(dest_path, exist_ok=True)
    
    with tarfile.open(file_name, "r:gz") as tar:
        tar.extractall(path=dest_path)
        print(f"Extracted {file_name} to {dest_path}")

def get_sha256_checksum(file_path):
    """
    Calculate the SHA256 checksum of a file.

    Parameters:
    file_path (str): The path to the local file.

    Returns:
    str: The SHA256 checksum of the file.
    """
    sha256 = hashlib.sha256()
    with open(file_path, 'rb') as f:
        for chunk in iter(lambda: f.read(4096), b''):
            sha256.update(chunk)
    return sha256.hexdigest()

def get_original_checksums(api_url, username, password):
    """
    Retrieve the original checksums from a given API URL.

    Parameters:
    api_url (str): The API URL of the package in JFrog Artifactory.
    username (str): The username for authentication.
    password (str): The password for authentication.

    Returns:
    dict: A dictionary containing SHA1, SHA256, and MD5 checksums if found, else None.
    """
    response = requests.get(api_url, auth=HTTPBasicAuth(username, password), verify=False)
    response.raise_for_status()
    data = response.json()
    return data.get("checksums")

def download_file(host, repo, final_file_name, local_path, username, password):
    """
    Download a file from Artifactory to the local path with a progress bar.

    Parameters:
    host (str): The Artifactory host URL.
    repo (str): The repository name.
    final_file_name (str): The name of the file to be downloaded.
    local_path (str): The local path to save the file.
    username (str): The username for authentication.
    password (str): The password for authentication.

    Returns:
    None
    """
    url = f"https://{host}/artifactory/{repo}/{final_file_name}"
    with requests.get(url, auth=(username, password), stream=True, verify=False) as response:
        response.raise_for_status()
        total_size = int(response.headers.get('content-length', 0))
        block_size = 1024  # 1 Kibibyte
        t = tqdm(total=total_size, unit='iB', unit_scale=True)
        os.chdir
        with open(local_path, 'wb') as f:
            for chunk in response.iter_content(chunk_size=block_size):
                t.update(len(chunk))
                f.write(chunk)
        t.close()

def search_artifactory(username, password, host, repo, file_pattern):
    """
    Search for files in Artifactory using AQL.

    Parameters:
    username (str): The username for Artifactory authentication.
    password (str): The password for Artifactory authentication.
    host (str): The Artifactory host URL.
    repo (str): The repository name to search in.
    file_pattern (str): The file name pattern to search for.

    Returns:
    dict: The response from the Artifactory API in JSON format.
    """
    url = f"https://{host}/artifactory/api/search/aql"
    headers = {
        "Content-Type": "text/plain"
    }
    data = f'items.find({{ "repo": {{"$eq":"{repo}"}}, "name": {{"$match" : "{file_pattern}*"}}}}).sort({{"$desc" : ["updated"]}}).limit(1)'
    response = requests.post(url, auth=(username, password), headers=headers, data=data, verify=False)
    response.raise_for_status()
    return response.json()


def ensure_output_path(output_path):
    """Ensure the output path exists, creating it if necessary."""
    try:
        # Check if the output path exists; if not, create it
        if not os.path.exists(output_path):
            os.makedirs(output_path)
            print(f"Output directory created: {output_path}")
        else:
            print(f"Directory already exists: {output_path} Continuing extraction..")
    except OSError as e:
        print(f"Error creating directory {output_path}: {e}")
        sys.exit(1)  # Exit if we can't create the necessary directory



def main():
    """
    Main function to manage file download from Artifactory.

    Checks if the local file exists and compares its SHA256 checksum with the remote file.
    Downloads the file if it doesn't exist or if checksums differ (with user confirmation).
    Supports auto-overwrite via the AUTO_OVERWRITE_DOWNLOAD environment variable.

    Parameters:
    None

    Returns:
    None
    """
    # Initialize the argument parser with descriptions
    parser = argparse.ArgumentParser(description="Artifactory file download script with checksum validation and extraction.")

    # Set up command-line arguments with environment variable defaults
    parser.add_argument('--host', type=str, default=os.getenv("ARTI_HOST"), help='The host URL of the Artifactory')
    parser.add_argument('--repo', type=str, default=os.getenv("ARTI_REPO"), help='The repository name in Artifactory')
    parser.add_argument('--pattern', type=str, default=os.getenv("ARTI_PATTERN"), help='File pattern for matching artifacts')
    parser.add_argument('--output', type=str, default=os.getenv("ARTI_OUTPUT_PATH"), help="The directory path to download and extract the files.")
    parser.add_argument('--usage', action='store_true', help="Display the usage information.")

    # Parse arguments
    args = parser.parse_args()

    # Show usage if the --usage argument is set
    if args.usage:
        display_usage()
        sys.exit(0)

    # Check if any required values are missing after parsing
    if not args.host or not args.repo or not args.pattern or not args.output:
        print("Error: All required parameters must be provided either through environment variables or command-line arguments.")
        display_usage()
        sys.exit(1)

    # Access the values, preferring command-line arguments over environment variables
    host = args.host
    repo = args.repo
    file_pattern = args.pattern
    output_path = args.output

    # # Example of using the parsed arguments
    # print(f"Host: {host}")
    # print(f"Repository: {repo}")
    # print(f"File Pattern: {file_pattern}")
    # print(f"Output Path: {output_path}")

    try:
        # Ensure output path exists or create it
        ensure_output_path(output_path)
            

        # Proceed with using the variables
        print(f"Detected Variables are :- Host: {host}, Repo: {repo}, File Pattern: {file_pattern}, Output Dir: {output_path}")

    except ValueError as ve:
        # Handle the case where one or more environment variables are not set
        print(f"Error: {ve}")
        sys.exit(1)
    except Exception as e:
        # General exception handler for any other unforeseen errors
        print(f"An unexpected error occurred: {e}")

    auto_overwrite_download = os.getenv("AUTO_OVERWRITE_DOWNLOAD", "false").lower() == "true"

    if is_env_var_present("DEVNEXT") and sys.stdout.isatty():
        print("Running in devNext Environment")
        if not is_pat_enabled():
            url = "https://git.visteon.com"
            cred = gitcacheutil()
            username, password = cred.getCredentials(url)
    else:
        username, _, password = get_or_prompt_credentials(host)

    if not username or not password:
        print("Credentials are missing, re-run the build.")
        sys.exit(1)

    try:
        result_as_json = search_artifactory(username, password, host, repo, file_pattern)
        if not result_as_json['results']:
            print("No results found in Artifactory.")
            return
        
        latest_result = result_as_json['results'][0]
        file_name = latest_result['name']
        file_path = latest_result['path']
        final_file_name = os.path.join(file_path, file_name).replace("\\", "/")
        local_path = file_name
        local_file_path = os.path.join(output_path, file_name)

        print(f"File to be downloaded: {final_file_name}")

        if os.path.exists(local_path):
            local_sha256 = get_sha256_checksum(local_path)
            api_url = f"https://{host}/artifactory/api/storage/{repo}/{final_file_name}"
            remote_checksums = get_original_checksums(api_url, username, password)

            if remote_checksums is None:
                print("Could not retrieve remote checksums. Continuing...")
                download_file(host, repo, final_file_name, local_path, username, password)
                print("File downloaded.")
                return

            if remote_checksums['sha256'] == local_sha256 and auto_overwrite_download:
                print("Auto overwrite is enabled. Downloading new file.")
                os.remove(local_path)
                download_file(host, repo, final_file_name, local_path, username, password)
                print("File downloaded and overwritten.")
            elif remote_checksums['sha256'] == local_sha256:
                print("Local file is up-to-date. Skipping download...")
                return
            else:
                user_input = input("Local file differs from remote file. Do you want to overwrite it? (yes/no): ")
                if user_input.lower() == "yes":
                    os.remove(local_path)
                    download_file(host, repo, final_file_name, local_path, username, password)
                    print("File downloaded and overwritten.")
                else:
                    print("File not downloaded.")
        else:
            download_file(host, repo, final_file_name, local_path, username, password)
            print("File downloaded.")

        extract_tar_gz(local_path, local_file_path, overwrite=True)

    except requests.exceptions.RequestException as e:
        print("Error:", e)


if __name__ == "__main__":
    main()
