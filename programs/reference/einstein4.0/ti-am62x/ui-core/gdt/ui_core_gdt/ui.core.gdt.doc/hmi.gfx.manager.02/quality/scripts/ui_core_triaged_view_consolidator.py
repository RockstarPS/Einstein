import argparse
import csv
import os
import glob

def usage():
    print("Usage: python ui_core_triaged_view_consolidator.py --master path to master sheet CSV file --folder Folder path containing all the triaged view CSV files --type coverity/misra/cert/his")

parser = argparse.ArgumentParser()
parser.add_argument("--folder", help=" Folder path containing all the triaged view CSV files ", required = True)
parser.add_argument("--master", help=" path to master sheet CSV file", default = None)
parser.add_argument("--type", help=" cov/misra/cert/his ", default = None)
args = parser.parse_args()

path = args.folder

csv_files = glob.glob(os.path.join(path, "*.csv")) # returns all the csv files in given path/folder

if args.master is None:
    output_rows = [] 
else:
    try:
        with open(args.master) as master_file:
            reader = csv.reader(master_file)
            output_rows = [row for row in reader if not "Merge Key" in row] # taking a copy of existing master sheet into output_rows[]
    except:
        print("Error: Could not read", args.master, "CSV file. Verify file name/path. Close if any application using this file")
        usage()
        exit()
        
for file in csv_files:
    try:
        with open(file) as slave_file:
            reader = csv.DictReader(slave_file)
            columns = reader.fieldnames
            rows = [row for row in reader]
    except:
        print("Error: Could not read", file, "CSV file. Verify file name/path. Close if any application using this file")
        usage()
        exit()
    
    for column in ["Merge Key","ï»¿CID","Last Triage Comment"]: #checking if slave files contains all the required columns 
        if column not in columns: 
            print("Error: Required columns Merge Key, ï»¿CID, Last Triage Comment not found in Slave CSV file. Seems invalid file. Please input only TRIAGED_VIEW.csv files")
            usage()
            exit()
    
    merge_key_column = [column for column in columns if "Merge Key" in column][0]
    cid_column = [column for column in columns if "CID" in column][0]
    triage_column = [column for column in columns if "Last Triage Comment" in column][0]
    filename = os.path.basename(file) #getting the filename from the path.
        
    for row in rows:
        merge_key = row[merge_key_column]
        cid = row[cid_column]
        triage = row[triage_column]
        
        matching_rows = [row for row in output_rows if merge_key in row[0]]
        
        if not matching_rows:
            output_rows.append([merge_key, filename, cid, triage])
        else: 
            index = output_rows.index(matching_rows[0])
            
            if cid not in output_rows[index][2] or filename not in output_rows[index][1]:
                output_rows[index][3] = output_rows[index][3] + "\n" + triage
                output_rows[index][2] = output_rows[index][2] + "\n" + cid
                output_rows[index][1] = output_rows[index][1] + "\n" + filename 


if args.master is None: # create a new master sheet ui_core_triaged_view_consolidated_sheet.csv or overwrite it if already exists
    if args.type is None:
        csvfile = open('ui_core_triaged_view.csv','w', newline='') 
    else:  
        csvfile = open('ui_core_triaged_view_' + args.type + '.csv','w', newline='')
else:
    csvfile = open(args.master,'w', newline='') # modify existing master sheet

writer = csv.writer(csvfile)
writer.writerow(["Merge Key", "File", "ï»¿CID", "Last Triage Comment"])
for row in output_rows:
    writer.writerow(row)