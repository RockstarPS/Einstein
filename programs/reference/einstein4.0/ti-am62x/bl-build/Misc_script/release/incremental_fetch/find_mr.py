#!/usr/bin/python3
import os
import re
import sys
import json
import argparse
import subprocess
import urllib.error
import urllib.request
from http import client
from functools import reduce
from collections import namedtuple
from decimal import InvalidContext
from sqlite3 import OperationalError
from socket import error as socket_error
import xml.etree.ElementTree as xml_parser
from urllib.parse import urlparse, urlunparse, quote

"""
_exitcodes_
--------------------------------
    0: Successful exit
    200: Jenkins job should abort(Do not Fail)
--------------------------------
"""

class pseudo_requests():
    """[summary]
    Created to emulate requests for easy debugging when using native urllib
    Ensures that HTTPError and HTTPRespose returns same Object

    Libraries Used:
        import json
        import urllib.request
        from http import client
        from socket import error as socket_error
        from collections import namedtuple

    Args:
        urllib_method (Object): Any method of module urllib.request

    Returns:
        namedtuple: A dynamically created class like object.
    """

    def urlopen(self, *args, **kwargs):

        """[summary]
        The fuction to wrap the actual urllib method .

        Returns:
            Exception: When there are any errors occur
            HTTPres: When everything runs as expected
        """
        try:
            # Actual running of the called method/Function
            func_result_or_exception = urllib.request.urlopen(*args, **kwargs)

        except socket_error as serr:
            func_result_or_exception = serr

        """
        Handing Valid scenarios and Exceptions
        ----------------------------------------
        Inner Function should return
        1) instance of HTTPError, (Handled to return useful information)
        2) instance of HTTPres
        """
        if isinstance(func_result_or_exception,
                      (urllib.error.HTTPError, client.HTTPResponse)):

            if isinstance(func_result_or_exception, urllib.error.HTTPError):
                http_res = func_result_or_exception.fp
            else:
                http_res = func_result_or_exception

            status_code = http_res.code
            headers = http_res.headers
            url = http_res.url
            msg = http_res.reason or http_res.msg
            read = http_res.read
            fp = func_result_or_exception.fp

            if 'json' in headers['Content-type']:
                json_conent = json.loads(read().decode())
                if 'errors' in json_conent:
                    msg = msg or json_conent['errors'][0]['message']
            else:
                json_conent = json.loads('{}')

            # Creating a namedTuple to act like a dynamic class
            request_info = namedtuple(
                'UrllibHandlerResponse',
                'status_code headers url read msg json fp')
            return_res = request_info(status_code, headers, url, read,
                                      msg, json_conent, fp)

            return return_res

            # Throwing Errors for Unknown Exceptions and Invalid scenarios
            # 1) Other Exceptions
            # 2) Unexpected Scenario  # To do

        elif isinstance(func_result_or_exception, Exception):
            # Creating new variable for readability
            unknown_error = func_result_or_exception
            raise (unknown_error)

    def post(self, url: str, headers: dict = {}, *args, **kwargs):
        req = urllib.request.Request(url, *args, **kwargs)
        for key in headers:
            req.add_header(key, headers[key])
        return self.urlopen(req)


request = pseudo_requests()


class RepoProject():
    def __init__(self, project: xml_parser.Element,
                 default: xml_parser.Element):
        if not isinstance(project, xml_parser.Element):
            raise TypeError("project should be XMLElement")
        if not project.tag == 'project':
            raise TypeError("project.tag should be a project")
        if not isinstance(default, (xml_parser.Element, type(None))):
            raise TypeError("default should be XMLElement")

        if default is not None:
            if not default.tag == 'default':
                raise TypeError("default.tag should be default")
            else:
                self.__default = default.attrib
        else:
            self.__default = {}

        self.__attrib = project.attrib

    @property
    def path(self) -> str:
        if 'path' in self.__attrib:
            return self.__attrib['path']
        else:
            return self.__attrib['name']

    @property
    def name(self) -> str:
        return self.__attrib['name']

    @property
    def remote(self) -> str:
        rem = self.__attrib.get('remote') or self.__default.get('remote')
        if rem:
            return rem
        else:
            raise NameError("remote not found for project" +
                            self.__attrib['name'])

    @property
    def branch(self) -> str:
        return self.__attrib['upstream']

    def __repr__(self):
        return self.__attrib['name']

    def __str__(self):
        return self.__attrib['name']


class RepoManifest():

    def __init__(self, name: str, manifest_dir: str):

        def get_manifest_dir(path):
            if (os.path.basename(path) == ".repo"):
                manifest_dir = os.path.join(path, "manifests")
            elif (os.path.basename(path) == "manifests"):
                manifest_dir = path
            else:
                raise RuntimeError("manifest directory is not correct")

            return manifest_dir

        def get_sub_files(filename: str, path: str):
            if not os.path.isdir(path):
                raise NotADirectoryError("{} not a directory".format(path))

            filepath = os.path.join(path, filename)
            root = xml_parser.parse(filepath).getroot()
            sub_files = [x.attrib['name'] for x in root if x.tag == "include"]

            """ manifest should be either in .repo or .repo/manifests """
            if (sub_files):
                manifest_dir = get_manifest_dir(path)
                new_files = [get_sub_files(x, manifest_dir) for x in sub_files]
                [sub_files.extend(new_sub) for new_sub in new_files if new_sub]
                return sub_files

        _manifest = os.path.join(manifest_dir, name)
        self.__root = xml_parser.parse(_manifest).getroot()

        self.__projList = self.__root.findall('project')
        self.__default = self.__root.findall('default')
        self.__remote_obj = self.__root.findall('remote')

        self.__subManifests = get_sub_files(name, manifest_dir)

        if (self.__subManifests):
            _manifest_dir = get_manifest_dir(manifest_dir)
            for manifest in self.__subManifests:
                _filepath = os.path.join(_manifest_dir, manifest)
                _subroot = xml_parser.parse(_filepath).getroot()
                _subProj = _subroot.findall('project')
                _default = _subroot.findall('default')
                _remotes = _subroot.findall('remote')
                self.__projList.extend(_subProj)
                self.__default.extend(_default)
                self.__remote_obj.extend(_remotes)

        if len(self.__default) > 1:
            raise RuntimeError("Multiple default Elements in manifest")
        if len(self.__default) == 1:
            _default = self.__default[0]
        else:
            _default = None

        self.__projects = {}
        self.__remotes = {}
        for proj in self.__projList:
            _projName = proj.attrib['name']
            if _projName.endswith('.git'):
                _projName = _projName[:-4]
            self.__projects[_projName] = RepoProject(proj, _default)

        for remote in self.__remote_obj:
            _remoteName = remote.attrib['name']
            _remoteUrl = remote.attrib['fetch']
            self.__remotes[_remoteName] = _remoteUrl

    def getProjects(self) -> dict:
        return self.__projects

    def getRemotes(self) -> dict:
        return self.__remotes

    def getRemoteUrl(self, name) -> str:
        if name not in self.__remotes:
            raise NameError("Remote name '{name}' not available in manifest")
        return self.__remotes[name]

    def getProjectFullName(self, project_name: str) -> str:
        for i in self.__remotes.values():
            if project_name.__contains__(i):
                if project_name.endswith(".git"):
                    project_name = re.sub(r'.git$', "", project_name)
                project_name = project_name.split(i)[1]
                project_name = project_name.strip('/')
        return project_name

    def getProjectPath(self, project_name: str) -> str:
        project_name = project_name.lower()
        if project_name in self.__projects:
            return self.__projects[project_name].path
        else:
            for project in self.__projects:
                possible_manifest_names = (project.lower(),
                                           project.lower()+".git")
                if project_name.endswith(possible_manifest_names):
                    return self.__projects[project].path
        raise NameError("{} not found in manifest".format(project_name))


class GitLabUser():

    def __init__(self, url: str, username: str, password: str) -> None:

        self.username = username
        self.password = password
        self.url_parts = urlparse(url)
        self.url = url

    @property
    def oauth_token(self) -> str:
        server_url = self.url_parts.scheme+"://"+self.url_parts.netloc
        data = 'grant_type=password&username={}&password={}'\
               .format(self.username, quote(self.password))
        data = data.encode('utf-8')
        token_gen = request.post(server_url+'/oauth/token', data=data)

        if "invalid_grant" in str(token_gen.json):
            msg = "Invalid Credentials!!!\n"
            msg += token_gen.msg
            raise urllib.error.HTTPError(token_gen.url, 401, msg,
                                         token_gen.headers, token_gen.fp)

        token_gen = token_gen.json
        return token_gen['access_token']


class GitLabMergeRequest():
    _approval_rule = namedtuple('GitLabApprovalRule',
                                '''name eligible_approvers approvals_required
                                approved_by is_approved''')

    def __init__(self, project_http_url: str, mr_iid: str,
                 token: str = "", bearer: bool = False):
        _url_parts = urlparse(project_http_url)
        _url_path = _url_parts.path.strip()
        _dns = _url_parts.netloc.strip()
        _protocol = _url_parts.scheme.strip()
        self.target_url = project_http_url

        # Removing the ending .git
        if _url_path.endswith(".git"):
            _url_path = _url_path[:-4]

        # MR API URL Path
        _api_path = '/api/v4/projects/'
        _proj_path = _url_path.lstrip("/").replace("/", r"%2F")
        _mr_path = '/merge_requests/{}'.format(mr_iid)
        _proj_mr_path = _api_path + _proj_path + _mr_path

        # parameters to Url
        if bearer:
            self.__header_key = 'Authorization'
            self.__header_val = f'Bearer {token}'
        else:
            self.__header_key = 'PRIVATE-TOKEN'
            self.__header_val = token

        self.__url_parts = (_protocol, _dns, _proj_mr_path, '', '', '')
        self.__approval_details = ""
        self.__rules = ()

        # Test Connection
        _test_url = urlunparse(self.__url_parts)
        _req = urllib.request.Request(_test_url)
        _req.add_header(self.__header_key, self.__header_val)
        _res = request.urlopen(_req)
        if _res.status_code != 200:
            _new_msg = _res.msg + "\nTest connection failed\n"
            _new_msg += _res.url
            raise urllib.error.HTTPError(_res.url, _res.status_code,
                                         _new_msg, _res.headers, _res.fp)

        self.__mr_details = _res.json

 
    @property
    def sha(self):
        return self.__mr_details['sha']

    @property
    def conflicts(self):
        return self.__mr_details['has_conflicts']

    @property
    def state(self):
        return self.__mr_details['state']

    def close(self):
        protocol, dns, proj_path, _, heads, _ = self.__url_parts
        params = 'state_event=close'
        close_url_parts = (protocol, dns, proj_path, params, heads, '')
        close_url = urlunparse(close_url_parts)
        req = urllib.request.Request(close_url, method='PUT')
        req.add_header(self.__header_key, self.__header_val)
        res = request.urlopen(req)
        if res.status_code != 200:
            new_msg = res.msg + "\nMerge Failed\n"
            new_msg += res.url
            raise urllib.error.HTTPError(res.url, res.status_code,
                                         new_msg, res.headers, res.fp)
        raise OperationalError()


 
if __name__ == "__main__":
    # Variables
    parent_url = os.environ.get('gitlabTargetRepoHttpUrl', None)
    mr_iid = os.environ.get('gitlabMergeRequestIid', None)
    description = os.environ.get('gitlabMergeRequestDescription', None)
    dep_details = {}
    # ArgParse
    parser = argparse.ArgumentParser()

    parser.add_argument("-p", "--passkey", metavar="token", default=None,
                        help="GitLab Token to connect")
    parser.add_argument("-u", "--userpassword", metavar="creds", default=None,
                        help="GitLab username and password in format \
                             '<user>:<password>'")
    parser.set_defaults(identity=None)

    commands = parser.add_subparsers()


    co_parser = commands.add_parser("find_mr")
    co_parser.set_defaults(identity="find_mr")
    co_parser.add_argument("-m", "--manifest", metavar="<manifest_file>",
                           help="name of manifest to be used",
                           default="manifest.xml")

    args = parser.parse_args()

    token = args.passkey
    creds = args.userpassword

    if token and creds:
        print("Arguments -u and -p cannot be used together", file=sys.stderr)
        exit(401)

    if creds:
        username, password = creds.split(':', 1)
        if not (username and password):
            print("credentials should be in format username:password",
                  file=sys.stderr)
            exit(401)

    #  Getting dependencies from MR Descriptions
    if description:
        desc_pattern = r".*\[\s*DEPENDENCY\s*\]\s*:\s*\{(?P<deps>.*)\}"
        desc = re.search(desc_pattern, description, re.S)
        if desc:
            deps_info = desc.group('deps')
            dep_ui_urls = deps_info.split(',')

            for url in dep_ui_urls:
                # Remove any unwanted chars like space and \n
                dep_ui_url = url.strip()
                url_parts = urlparse(dep_ui_url)
                protocol, dns, url_path, _, heads, _ = url_parts
                extracts = url_path.split('/-/merge_requests/')
                err_msg = "Malformed URL in dependencies:\n{}".format(url)
                if len(extracts) == 2 and extracts[0] and extracts[1]:
                    valid = True
                else:
                    valid = False
                assert valid, err_msg
                project, dep_iid = extracts
                dep_url = urlunparse((protocol, dns, project, '', '', ''))
                dep_details[dep_url] = dep_iid

    if creds:
        git_user = GitLabUser(parent_url, username, password)
        token = git_user.oauth_token

    parent_mr = GitLabMergeRequest(parent_url, mr_iid, token, bool(creds))


    # Code find_mr
    if  (args.identity == 'find_mr'):
        manifest_name = args.manifest

        # Look for a repo installation, starting at the current directory.
        curdir = os.getcwd()
        repo = None
        olddir = None
        repodir = ".repo"
        REPO_MAIN = "repo/main.py"
        while curdir != '/' and curdir != olddir and not repo:
            repo = os.path.join(curdir, repodir, REPO_MAIN)
            if not os.path.isfile(repo):
                repo = None
                olddir = curdir
                curdir = os.path.dirname(curdir)

        download_home = curdir
        repo_root = os.path.join(curdir, repodir)
        manifest_dir = os.path.join(repo_root, "manifests")
        manifest = RepoManifest(manifest_name, manifest_dir)

        dep_details[parent_url] = mr_iid  # Adding Main MR into list

        for project_url in dep_details:
            if creds:
                git_user = GitLabUser(project_url, username, password)
                token = git_user.oauth_token
            proj_mr_iid = dep_details[project_url]
            project = manifest.getProjectFullName(project_url)
            relative_path = manifest.getProjectPath(project)
            local_path = os.path.join(download_home, relative_path)
            sha = GitLabMergeRequest(project_url, proj_mr_iid,
                                     token, bool(creds)).sha
            
            if project_url.endswith(".git"):
               project_url = project_url[:-4]

            print(project_url + "/merge_requests/" + proj_mr_iid  )
     
    elif (not args.identity):
        print("No Commands are specified to run")
        parser.parse_known_args(['-h'])
 
