import gitlab
import os
import sys

gitlab_url = sys.argv[1]
access_token = sys.argv[2]
group_id = sys.argv[3]
mr_id = sys.argv[4]
repo_url = sys.argv[5]

modified_url = repo_url.replace(gitlab_url+"/", "")
modified_url = modified_url.replace(".git", "")

gl = gitlab.Gitlab(gitlab_url, private_token=access_token)

group = gl.groups.get(group_id, lazy=True)

projects = group.projects.list(include_subgroups=True, all=True)

project_ids = []
for project in projects:
    project_ids.append((project.path_with_namespace, project.id))

for key, value in project_ids:
    if key == modified_url:
#        print(value)
        break
project_id = value

project = gl.projects.get(project_id)
mr = project.mergerequests.get(mr_id)

maillist = []

maillist.append(mr.author['name'].lower()+'@visteon.com')
maillist.append(mr.assignee['name'].lower()+'@visteon.com')
reviewer = mr.reviewers

for i in reviewer:
    maillist.append(i['name'].lower()+'@visteon.com')

mail_list = ','.join(maillist)
print(mail_list)
