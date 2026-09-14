import requests
import urllib
import os
import sys
import ConfigParser
import json

WARNMSG = "[WARN]"
ERRMSG = "[ERROR]"
REQ_OPTIONS = ['project', 'host', 'viewtype', 'viewid', 'rows']
CREDENTIALS = ['cov_username', 'cov_password']

def usage():
# pylint: disable=line-too-long
    print ("covfetch.py <config.ini> <section/project name> <output_file.json> ")

def check_section(parser, section): 
    if parser.has_section(section):
        return True
    else:
        print (ERRMSG + "Missing section in parser:" + section)
        exit(2)

def get_options(parser, section, options):
    option_values = []
    check_section(parser, section)
    for option in options:
        if parser.has_option(section, option) == False:
            print (ERRMSG + "Option missing :" + option)
            exit(1)
# pylint: disable=unbalanced-tuple-unpacking
        option_values.append(parser.get(section, option))
    return option_values

# check if username and password are exported
# else, check if given in config file
def get_credentials(parser, section, credentials):
    cred_list = []
    print ("Checking environment variables for " + str(credentials))
    for var in credentials:
        if var not in os.environ:
            print (WARNMSG + "Variable:" + var + " is not exported or set")
            break
        cred_list.append(os.environ[var])

    if len(cred_list) != len(credentials):
        print ("Checking the ini file for " + str(credentials))
        cred_list = get_options(parser, section, credentials)

    return cred_list

def get_json(parser, section, req_opts, credentials):
    [project, host, vtype, view,
        rows] = get_options(parser, section, req_opts)
    [user, passwd] = get_credentials(parser, section, credentials)

    vtype = urllib.quote(vtype)
    view = urllib.quote(view)

    payload = {'projectId' : project, 'rowCount' : rows}

    url = host+'/api/viewContents/'+vtype+'/v1/'+view
    print ("Fetching the view:" + view + " form coverity server")
    reply = requests.get(url, auth=(user, passwd), 
                        params=payload, stream=True)
    print ("URL:" + reply.url)
    if reply.ok:
        return reply
    else:
        print (ERRMSG + "Error in fetching from url")
        reply.raise_for_status()
        return None

def download_file(requestobj, output_filename):
    csv_file = open(output_filename, "wb")
    try:
        for chunk in requestobj.iter_content(chunk_size=10240):
            if chunk:
                csv_file.write(chunk)
    except Exception, error:
        print (ERRMSG + "Error in writing data to file:" + output_filename)
        print (error)
        requestobj.raise_for_status()
        exit(1)

def convert_file(input_filename, output_filename):
    in_file = open(input_filename, "rb")
    data_in = json.load(in_file)
    data_out = { "_class": "io.jenkins.plugins.analysis.core.restapi.ReportApi", "issues": [] }

    severity_map = { "High" : "High", "Medium" : "Normal", "Low" : "Low" }
    
    for row in data_in["viewContentsV1"]["rows"]: 
    #for x in range(5): 
    #    row = data_in["viewContentsV1"]["rows"][x]
        newentry  = { "lineStart" : str(row["cid"]), "Type" : row["displayType"], "severity" : severity_map[row["displayImpact"]], "Category" : row["displayCategory"], "fileName" : row["displayFile"] }
    
        data_out["issues"].append(newentry)

    out_file = open(output_filename, "wb")
    json.dump(data_out, out_file, indent = 4)

def check_file(ini_file):
    if os.path.isfile(ini_file) != True:
        print (ERRMSG + "file:" + ini_file + ": is a wrong file.")
        usage()
        exit(1)

def check_ini_file(ini_file):
    check_file(ini_file)
    try:
        parser = ConfigParser.ConfigParser()
        parser.read(ini_file)
    except ConfigParser.ParsingError:
        print (ERRMSG + "ParsingError. when parsing :" + ini_file)
        usage()
        exit(2)
    except ConfigParser.Error:
        print (ERRMSG + "Error. Reading ini file:" + ini_file)
        usage()
        exit(2)
    return parser

def main():
    [ini_file, section, output_filename] = sys.argv[1:4]

    parser = check_ini_file(ini_file)
    print ("Fetching view from coverity server..:" +  section)
    request_obj = get_json(parser, section, REQ_OPTIONS, CREDENTIALS)
    if request_obj:
        temp_filename = output_filename + ".in"
        download_file(request_obj, temp_filename)
        print ("Changes are fetched and written to file:" + temp_filename)
        convert_file(temp_filename, output_filename)
    else:
        print (ERRMSG + "Issue in fetching data from coverity server..")
        exit(1)

if __name__ == "__main__":
    if len(sys.argv) < 4:
        print (ERRMSG + "input arguments..")
        usage()
        exit(1)
    main()
