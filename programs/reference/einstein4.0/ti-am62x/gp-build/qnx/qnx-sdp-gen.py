import os
import re
import subprocess
import sys
import argparse

def parse_and_fetch_files(plist_file, artifactory_url, root_directory):
    # Create the root directory if it doesn't exist
    if not os.path.exists(root_directory):
        os.makedirs(root_directory)
        print(f"Created root directory: {root_directory}", flush=True)
    else:
        print(f"Root directory already exists: {root_directory}", flush=True)

    # Regex to extract the first two fields (package name and version)
    pattern = re.compile(r"^([\w.]+)/([\w.]+)(?=/)")

    with open(plist_file, 'r') as file:
        for line in file:
            line = line.strip()  # Remove leading/trailing whitespace
            match = pattern.match(line)
            if match:
                # Extract the name and version
                name = match.group(1)
                version = match.group(2)
                
                # Create the file name by concatenating with an underscore
                file_name = f"{name}_{version}.qpkg"
                
                # Construct the full URL for the file on JFrog Artifactory
                file_url = f"{artifactory_url}/{file_name}"
                
                print(f"Fetching and untarring: {file_name} from {file_url}", flush=True)

                # Construct the curl command piped into tar
                curl_command = f"curl -sSfLk {file_url} | tar xvJf - -C {root_directory}"

                try:
                    # Execute the curl and tar command using subprocess
                    subprocess.run(curl_command, shell=True, check=True, executable='/bin/bash')
                    print(f"Successfully untarred: {file_name} to {root_directory}", flush=True)
                except subprocess.CalledProcessError as e:
                    print(f"Failed to fetch or untar {file_name}: {e}", flush=True)
                    sys.exit(1)  # Exit with an error code if the command fails

def main():
    # Setup argument parsing
    parser = argparse.ArgumentParser(description="Fetch and untar files based on a QNX package list file.")
    parser.add_argument("plist_file", help="Path to the package list file")
    parser.add_argument("artifactory_url", help="Base URL of the JFrog Artifactory")
    parser.add_argument("root_directory", help="Directory to untar files into")
    
    # Parse arguments
    args = parser.parse_args()
    
    # Call the main function with parsed arguments
    parse_and_fetch_files(args.plist_file, args.artifactory_url, args.root_directory)

if __name__ == "__main__":
    main()
