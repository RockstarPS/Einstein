import os
import sys
from time import gmtime, strftime

DEBUG = True;


def debug_print(suffix, what):
    if DEBUG == True:
        if len(suffix) > 0:
            print(suffix + " :" + what);
        else:
            print(what);
    return;



# Vars
my_argc = 0;
my_time = "time";
my_argv = "";
my_folder = [];
my_file = "build_time.h";
my_out = "";
my_line = "const char *build_time = ";
my_2_line = "const char *vmf_user = ";
user_file_name = "../vmf_user.txt"; # ensure that file is outside of version control!
vmf_user = "undefined"


# Main


#get opt
my_argc = len(sys.argv);

if my_argc == 2:
    my_argv = sys.argv[1];
    my_folder = my_argv.split(os.sep);
    
    for my_folder_part in my_folder:
        if my_folder_part is not "": 
            my_out += my_folder_part + os.sep;
    
    my_out += my_file;

else:
    my_out = my_file;

debug_print ("out file", my_out);



#get user
if os.path.isfile(user_file_name):
    user_file = open(user_file_name, "r");
    vmf_user = user_file.readline();
    user_file.close();
    vmf_user = vmf_user.replace("\n", "");

debug_print("vmf user", vmf_user);
my_2_line += "\"" + vmf_user + "\";\n" 

#get time as string
my_time = strftime("%Y-%m-%d %H:%M:%S", gmtime());
debug_print("time:", my_time);
my_line += "\"" + my_time + "\";\n"  

#write time string to file
header_file = open(my_out, "w");
header_file.writelines(my_line);
header_file.writelines(my_2_line);

header_file.close();

debug_print("","Finished.")
