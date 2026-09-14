import os
import sys
import gitlab
import subprocess
import datetime
import time
import re
from operator import *
import dateparser
import argparse
from simple_colors import *
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import xml.etree.ElementTree as ET
#import pandas as pd
#from pandas import ExcelWriter
#from pandas import ExcelFile

"""
# Please provide branch and manifest details to do "repo init"
"""
os.system("rm -rf project_status")

cre_apps_project = {}
mr_list = []
manifest_update = {}
open_mr = []
already_merged_mr_list = []
project_branch = {}
project_revision = {}
remote_values={}
d = {}

def Directory_create(cur_dir, build_id):
    if os.path.exists(f"{cur_dir}/project_status/{build_id}"):
        print("Directory is Present ..you can go ahead")
    else:
        print("Directory is not present ..so creating for you")
        os.makedirs(f"{cur_dir}/project_status/{build_id}")
        Directory_create(cur_dir, build_id)

def file_create(CUR_DIR, build_id):
    os.system(f"touch {CUR_DIR}/project_status/{build_id}/{build_id}.txt")
    os.system(f"touch {CUR_DIR}/project_status/{build_id}/{build_id}_mr.txt")
    os.system(f"touch {CUR_DIR}/project_status/{build_id}/{build_id}_mr_log.txt")
    os.system(f"touch {CUR_DIR}/project_status/{build_id}/{build_id}_total_mrs.txt")


def repo_init(cur_dir, build_id, manifest):
    Directory_create(cur_dir, build_id)
    file_create(cur_dir,build_id)
    get_repo_project_to_path_mapping(cur_dir, build_id, cur_dir, manifest)

# Here We are geting all repositories from manifest and filtering visteon projects using keyword "REMOTE"

def get_mf_names(repo_dir,mf_detail):
    print(repo_dir)
    mf_names=[mf_detail]
    manifest_files=[mf_detail]
    while mf_names:
        mf_names_list = mf_names
        mf_names=[]
        for mf in mf_names_list:
            manifest_file="{}/{}".format(repo_dir,mf)
            xml_config=ET.parse(manifest_file)
            xml_config_root=xml_config.getroot()
            xml_include=xml_config_root.findall('include')
            for i in xml_include:
                mf_file_name = i.get("name")
                if mf_file_name not in manifest_files:
                    mf_names.append(mf_file_name)
                    manifest_files.append(mf_file_name)
    return manifest_files

def get_remote_details(repo_dir,mf_name):
    remote_details={}
    for mf in mf_name:
       manifest_file="{}/{}".format(repo_dir,mf)
       xml_config=ET.parse(manifest_file)
       xml_config_root=xml_config.getroot()
       xml_remote=xml_config_root.findall('remote')
       for i in xml_remote:
           remote_details[i.get("name")]=i.get("fetch")
    return remote_details


def get_repo_project_to_path_mapping(CUR_DIR, build_id, dir_path, manifest):
    repo_meta_path = os.path.join(dir_path, '.repo')
    global repo_manifest_path
    global remote_values
    repo_manifest_path = os.path.join(repo_meta_path, 'manifests')
    repo_tool_path = os.path.join(repo_meta_path, 'repo')
    print(repo_meta_path)
    print(repo_tool_path)

    if repo_tool_path not in sys.path:
        sys.path.insert(0, repo_tool_path)
    print(repo_manifest_path, manifest)
    total_mf_names=get_mf_names(repo_manifest_path, manifest)
    remote_values=get_remote_details(repo_manifest_path, total_mf_names)
    repo_manifest_file=os.path.join(repo_manifest_path,manifest)
    import manifest_xml
    try:
        xm = manifest_xml.XmlManifest(repo_meta_path)
    except:
        xm = manifest_xml.XmlManifest(repo_meta_path, repo_manifest_file)
    project_to_path_mapping = {}
    project_count = 0
    non_project_count = 0
    print(CUR_DIR)
    total_repositories = open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_repos_desc.txt", "w+")
    for path, p in xm.paths.items():
        if not(remote_values[p.remote.name].__contains__("git.mirror")):
            Project_Name = p.name.replace('.git', '')
            Project_Name = Project_Name.rstrip('/')
            Project_Name = remote_values[p.remote.name].strip('/')+"/"+Project_Name
            if re.match(r"\w+://[\w+|.|-]+/(.*)",Project_Name):
                Project_Name= re.match(r"\w+://[\w+|.|-]+/(.*)",Project_Name).group(1)
            remote = p.remote.name
            print(Project_Name, p.upstream, path, p.revisionExpr)
            try:
                if p.upstream == None:
                    total_repositories.write(Project_Name+"\t"+path+'\t'+p.revisionExpr+'\t'+remote+"\n")
                    project_details(Project_Name, p.revisionExpr, path, dir_path, remote)
                else:
                    total_repositories.write(Project_Name+"\t"+path+'\t'+p.upstream+'\t'+remote+"\n")
                    project_details(Project_Name, p.upstream, path, dir_path, remote)
            except:
                pass 
            project_count += 1
        else:
            non_project_count += 1
    total_repositories.close()
    print("visteon_project_count", project_count)
    print("Non-Visteon-Project", non_project_count)

    return project_to_path_mapping


def conflict_error_mail(author, mr_approvers, conflict_files, MR):
    sender_email = "vtscpdo@visteon.com"
    to_list = []
    MR = MR.strip()
    print(author)
    print(mr_approvers)
    to_list.append(author)
    for i in mr_approvers:
        to_list.append(i)
    print(to_list)
    cc_list = ['gururaj.rao@visteon.com', 'ssudhave@visteon.com','amariyal@visteon.com', 'ppadakan@visteon.com']
    message = MIMEMultipart("alternative")
    message["Subject"] = "GOT CONFLICTS DURING CHERRY-PICKING"
    message["From"] = sender_email
    message["To"] = (', ').join(to_list)
    message["Cc"] = (', ').join(cc_list)
    print(message["From"])
    print(message["To"])
    print(message["Cc"])
    html = f"""\
    <html>
      <body>
        <p>Hi <b>{author}</b>,</p>
        <p>We have got conflicts while cherry-picking the below MR for the <style="color: red"><b>PRE-INT BUILD.</b></style></p>
        <p><a href='{MR}'>{MR}</a></p>
        <p style="color: red">CONFLICT Files are :</p>
        <p>{conflict_files}</p>
        <p>Please check and resolve the conflict ASAP.</p>
        <p>Regards,</p>
        <p style='color: green'><b>Integration Team.</b></p>
        <p>Note: This is an automated mail from JENKINS.</p>
      </body>
    </html>
    """
    part2 = MIMEText(html, "html")
    message.attach(part2)
    s = smtplib.SMTP("localhost")
    s.sendmail(sender_email, to_list, message.as_string())
    print("triggered email")

    
# Connecting To Visteon GitLab using Private Token
project_auth = gitlab.Gitlab('https://git.visteon.com/', private_token="wMrcsykwmSi6Sk5hk9gN")
project_auth_blr = gitlab.Gitlab('https://blr.git.visteon.com/', private_token="pZvhvvJZNiu9FqePp9qq")
project_auth_bsp = gitlab.Gitlab('https://bsp-os.git.visteon.com/', private_token="dnHz5gJx7yrbFKjvGkuw")
project_auth_eu = gitlab.Gitlab('https://eu.git.visteon.com/', private_token="Bqyv7hZKF39syqV_B7gs")

# Getting project details like Project Id , Project Name from Visteon "GITLAB"
def project_details(project_name, upstream, project_path, dir_path, remote):
    try:
        project = project_auth.projects.get(project_name)
    except:
        try:
            project = project_auth_blr.projects.get(project_name)
        except:
            try:
                project = project_auth_bsp.projects.get(project_name)
            except:
                project = project_auth_eu.projects.get(project_name)
    print('Project Name: ',project.name)
    print('Project Id: ',project.id)

# Getting all mergerequests that are raised to the upstream branch and got approval and are in ready to submit state
def project_to_merge_request_details(project, project_name, upstream, project_path, dir_path, remote):
    mergerequests = project.mergerequests.list(target_branch=upstream, sort="asc")
    for mr in mergerequests:
        if mr.approvals.get().approved == True and mr.state == "opened" and mr.has_conflicts == False and mr.approvals.get().approvals_left == 0:
            mr_list.append(mr.web_url)
            print(str(mr.iid)+'\t'+project_name+'\t'+mr.target_branch)
            with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}.txt", "a") as f, open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_mr.txt", "a") as f_mr:
                f.write(str(mr.iid)+'\t'+ project_name +'\t'+ mr.target_branch+'\n')
                f_mr.write(mr.web_url+'\n')
        elif mr.approvals.get().approved == False and mr.state == "opened":
            open_mr.append(mr.web_url)
        else:
            already_merged_mr_list.append(mr.web_url)


def merge_request_details_as_input(CUR_DIR, build_id, project_name, mr_number):
    upstream = ''
    with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_repos_desc.txt", 'r') as f:
         for line in f.readlines():
             if project_name.strip().casefold() in line.casefold():
                 b = line.split()
                 if project_name.strip().casefold() == b[0].strip().casefold():
                     project_path = b[1].strip('\n').strip('')
                     remote = b[3].strip('\n').strip('')
                     upstream = b[2].strip('\n').strip('')
                     break
                 else:
                     pass
             else:
                 pass
    if upstream == '':
        print(f"For this project '{project_name}', upstream branch is NOT FOUND <==========PLEASE CHECK MANIFESIT FILE and UPDATE UPSTREAM BRANCH=====>")
        exit(128)
    else:
        print(f"For this project '{project_name}', upstream branch is '{upstream}'")
    if project_path == '':
        print(f"For this project '{project_name}', Project Path is NOT FOUND <==========PLEASE CHECK MANIFESIT FILE and UPDATE the PATH=====>")
        exit(128)
    else:
        print(f"For this project '{project_name}', project path is '{project_path}'")

    try:
        project = project_auth.projects.get(project_name)
    except:
        try:
            project = project_auth_blr.projects.get(project_name)
        except:
            try:
                project = project_auth_bsp.projects.get(project_name)
            except:
                project = project_auth_eu.projects.get(project_name)
    mergerequests = project.mergerequests.get(mr_number)
    mr = mergerequests
    print("<========= START PRE-CONDITION CHECKS FOR MR LIKE WHETHER MR IS OPEN/CLOSED and TARGET BRANCH IS MATCHING WITH UPSTREAM BRANCH OR NOT =======>")
    if mr.has_conflicts == False and mr.target_branch == upstream:
        mr_list.append(mr.web_url)
        print(str(mr.iid)+'\t'+project_name+'\t'+mr.target_branch)
        print(f"{mr.web_url} is OPEN AND READY TO MERGE STATE")
        with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}.txt", "a") as f, open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_mr.txt", "a") as f_mr:
            f.write(str(mr.iid)+'\t'+ project_name +'\t'+project_path+'\t'+ mr.target_branch+'\t'+remote+'\n')
            f_mr.write(mr.web_url+'\n')
    else:
        if mr.target_branch != upstream:
            print(f"{mr.web_url} ===  TARGET BRANCH IS NOT MATCHING WITH MANIFEST UPSTREAM BRANCH")
        elif mr.has_conflicts == True:
            print(f"{mr.web_url} ===  MR HAS Merge Conflicts")
        else:
            print("UNKNOWN MR STATUS")
            print(f"{mr.web_url} === MR IS NOT PROPER, PLEASE CHECK ONCE AGAIN AND RETRY")
        print(str(mr.iid)+'\t'+project_name+'\t'+mr.target_branch)
        with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_unknown_mr.txt", "a") as f_mr:
            f_mr.write(mr.web_url+'\n')
        exit(128)
    print("<========= END PRE-CONDITION CHECKS FOR MR LIKE WHETHER MR IS OPEN/CLOSED and TARGET BRANCH IS MATCHING WITH UPSTREAM BRANCH OR NOT =======>")


# Listing all MR's one by and one and line by line.
def listing_mr(CUR_DIR, build_id):
    with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_mr.txt", "r") as f:
        for line in f.readlines():
            print(line)

list_of_merge_requests = []
final_list_merge_requests = {}

# If u providing ready to submit MR's in the text file or using parameters 
def mr_list_from_user(CUR_DIR, build_id):
    file_trunk = open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_total_mrs.txt", "r+")
    file_trunk.truncate()
    with open(f"{CUR_DIR}/input_mr_list.txt") as f:
        for line in sorted(f.readlines()):
            if line.startswith('https'):
                l = line.strip('\t')
                l = l.strip("\n")
                l = l.strip()
                list_of_merge_requests.append(l)
                with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_total_mrs.txt", "a") as f:
                    l=l.strip('/')
                    f.write(l+'\n')
            else:
                pass


# If u provided MR's in the text file or using parametrs...from them i am making trim and getting MR id, project and Branch Details
def project_and_mr_details(CUR_DIR, build_id):
    file_trunk = open(f"{CUR_DIR}/project_status/{build_id}/{build_id}.txt", "r+")
    file_trunk.truncate()
    with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_total_mrs.txt", "r") as f:
        for request in f.readlines():
            r = request.split("/merge_requests/")
            r3 = r[1].strip()
            r1 = r[0].split("https://git.visteon.com/")
            print(r1, len(r1))
            if len(r1) == 1:
                r1 = r[0].split("https://blr.git.visteon.com/")
                print(r1, len(r1))
                if len(r1) == 1:
                    r1 = r[0].split("https://bsp-os.git.visteon.com/")
                    print(r1, len(r1))
                    if len(r1) == 1:
                        r1 = r[0].split("https://eu.git.visteon.com/")
                        print(r1, len(r1))
            else:
                pass
            r2 = r1[1].strip('-/')
            project = r2
            mr_number = int(r3)
            final_list_merge_requests[project] = mr_number
            merge_request_details_as_input(CUR_DIR, build_id, project, mr_number)

def merge_mr(CUR_DIR, build_id):
    print()
    print(yellow("<=========================== CHERRY-PICKING STARTS HERE =====================================>"))
    with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}.txt", "r") as f:
        for line in f.readlines():
            #sample mr="114   snapdragonseries/aosp-caf-androidr/platform/frameworks/base aosp-caf/frameworks/base hd_dhu_develop  hd-agent99"
            # mr[0]= MR_ID, mr[1]=Project_Name, mr[2]=Project_Path mr[3]=Branch_Name mr[4]=Remote_Name
            mr = line.split()
            try:
                project = project_auth.projects.get(str(mr[1]))
            except:
                try:
                    project = project_auth_blr.projects.get(str(mr[1]))
                except:
                    try:
                        project = project_auth_bsp.projects.get(str(mr[1]))
                    except:
                        project = project_auth_eu.projects.get(str(mr[1]))
            project_path = str(mr[2])
            merge_request = project.mergerequests.get(mr[0])
            author_name = merge_request.author['name']
            author_name = author_name + "@visteon.com"
            mr_approvers = []
            if len(merge_request.approvals.get().approved_by) == 0:
                mr_approver = ""
            else:
                for i in range(len(merge_request.approvals.get().approved_by)):
                    mr_approver = merge_request.approvals.get().approved_by[0]['user']['username']
                    mr_approver = mr_approver + "@visteon.com"
                    mr_approvers.append(mr_approver)
            mr_web_url = merge_request
            commits_final = []
            commits = merge_request.commits()
            for cm in commits:
                commits_final.append(cm.id)
            commits_final.reverse()
            target_branch = merge_request.target_branch
            source_branch = merge_request.source_branch
            project_branch[str(mr[1])] = target_branch
            print(project_path)
            try:
                if os.path.exists(project_path):
                    print()
                    print(f"========================================== START =================================================") 
                    os.chdir(f"{CUR_DIR}")
                    print(f"=========================== Changing to project path '{project_path}'================================") 
                    os.chdir(project_path)
                    os.system(f"git fetch {mr[4]} &> /dev/null")
                    for commit in commits_final:
                        commit_id = commit
                        commit_check = subprocess.run([f"git log| grep '{commit_id}'"], shell=True) #, text=True)
                        if int(commit_check.returncode) == 0:
                            print(green(f"{commit_id} is already merged, So skipping to cherry-pick"))
                        else:
                            #os.system(f"git cherry-pick {commit_id}")
                            os.system('git fetch --all')
                            cmd_merge = "git cat-file -p {}".format(commit_id)
                            commit_type = subprocess.check_output(cmd_merge, shell=True).decode('utf-8')
                            commits_p = re.findall(r"parent .*", commit_type)
                            if len(commits_p) == 2:
                                print('it is a Merge_commit')
                                try:
                                    output = subprocess.check_output(['git', 'pull', mr[4], commit_id], stderr=subprocess.STDOUT)
                                except subprocess.CalledProcessError as e:
                                    print("Exception on process, rc=", e.returncode, "output=", e.output)
                                    raise Exception("Cherrypick Failed")
                            else:
                                print('it is a Normal_commit')
                                try:
                                    output = subprocess.check_output(['git', 'cherry-pick', commit_id], stderr=subprocess.STDOUT)
                                except subprocess.CalledProcessError as e:
                                    print("Exception on process, rc=", e.returncode, "output=", e.output)
                                    raise Exception("Cherrypick Failed")

                            print(f"=========================== Checking for Git Conflicts if any After Cherry-Picking ================================")
                            conflicts = subprocess.check_output(["git ls-files -u | wc -l"], shell=True) #, text=True)
                            conflicts = conflicts.decode('utf-8').strip()
                            if f'{conflicts}' == '0':
                                print(f"Cherry-picked {commit_id} successfully")
                            else:
                                print(f"There is a merge conflict with commit id {commit_id} and the MR {merge_request.web_url}. So Aborting....")
                                print("merge conflicts files are below")
                                conflict_files = subprocess.check_output(["git diff --name-only --diff-filter=U"], shell=True) #, text=True)
                                print(conflict_files)
                                with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_merge_log.txt", "a") as gitlog:
                                    gitlog.write(merge_request.web_url +'\t'+ str(mr[1]) +'\t'+'\n'+ f"There is a conflict with MR with commit id {commit_id}..Please check and resolve the same"+'\n\n')
                                #conflict_error_mail(author_name, mr_approvers, conflict_files, merge_request.web_url)
                                print("Number of MR's are successfully cherry-picked for now :", len(mr_list)-1 )
                                print("Total MR's :", len(list_of_merge_requests))
                                sys.exit(1)
                    print(f"{merge_request.web_url} ===> Cherry-picked Successfully ..Thanks")
                    print("==========================================  END  ==========================================================")
                    revision = subprocess.run("git log --pretty=oneline | sed -n 1p | awk '{print $1}'", shell=True, check=True, encoding="utf-8", stdout=subprocess.PIPE)
                    log = subprocess.run("git log | head -6", shell=True, check=True, encoding="utf-8", stdout=subprocess.PIPE)
                    os.chdir(f"{CUR_DIR}")
                    with open(f"{CUR_DIR}/project_status/{build_id}/{build_id}_merge_log.txt", "a") as gitlog:
                        gitlog.write(merge_request.web_url +'\t'+ str(mr[1]) +'\t'+'\n'+ log.stdout.strip()+'\n\n')
                else:
                    print("======================  Below Project is NOT FOUND. PLEASE CHECK IT  ===================================")
                    print(f"the project path {project_path} doesnt't exists")
                    print("==========================================  PROJECT NOT FOUND CLOSED  ==========================================================")
            except subprocess.CalledProcessError as err:
                if err.returncode in [1, 128]:
                    print("Error:", err)
                    sys.exit(print("Exit ", str(err.returncode)))
                else:
                    pass


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--manifest_branch', help='manifest branch')
    parser.add_argument('--manifest_name', help='manifest name')
    parser.add_argument('--build_number', help='jenkins build_number')
    parser.add_argument('--workspace', help='workspace')

    args = parser.parse_args()

    branch = args.manifest_branch
    manifest = args.manifest_name
    build_id = args.build_number
    WORKSPACE = args.workspace
    if manifest == None:
        print("Manifest variable is empty, Please input something")
        exit(128)
    else:
        pass

    cur_dir=os.getcwd()
    repo_init(cur_dir, build_id, manifest)
    mr_list_from_user(cur_dir, build_id)
    project_and_mr_details(cur_dir, build_id)
    merge_mr(cur_dir, build_id)
    print(green("===============LIST OF MERGE REQUESTS ARE CONSIDERED FOR PRE-INT BUILD/CHERRY-PICKED====================="))
    listing_mr(cur_dir, build_id)
    print("NO OF MR's WERE CHERRY-PICKED SUCCESSFULLY: ", len(mr_list))
    print()
    print(red("===============LIST OF MERGE REQUESTS ARE NOT CONSIDERED FOR PRE-INT BUILD/CHERRY-PICK====================="))
    print(open_mr)
    print("NO OF MR's WERE NOT CONSIDERED INTO THE PRE-INT BUILD: ", len(open_mr))
    print()


if __name__=="__main__":
    main()
