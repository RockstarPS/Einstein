import argparse
import csv
import os

def usage():
    print("Run command: python ui_core_merge_key_validator.py --master <master_file_path> --slave <slave_file_path> --lines <number of lines to process in each file> --name <Name of the program; This will be appended into generated file name>")

parser = argparse.ArgumentParser()

parser.add_argument("--master", help=" path to master CSV file", required=True)
parser.add_argument("--slave", help=" path to slave CSV file", required=True)
parser.add_argument("--lines", help=" number of lines/rows to process in each file", type=int, default = None)
parser.add_argument("--name", help=" name of the program; this will be appended into generated file name", default = None)

args = parser.parse_args()

try:
    with open(args.master) as master_file:
        master_reader = csv.DictReader(master_file)
        master_columns = master_reader.fieldnames
        if args.lines is not None:
            master_rows = [next(master_reader) for _ in range(args.lines)]
        else:
            master_rows = [row for row in master_reader]
except:
    print("Error: Could not read Master CSV file. Verify file name/path. Close if any application using this file")
    usage()
    exit()

try:
    with open(args.slave) as slave_file:
        slave_reader = csv.DictReader(slave_file)
        slave_columns = slave_reader.fieldnames
        if args.lines is not None:
            slave_rows = [next(slave_reader) for _ in range(args.lines)]
        else:
            slave_rows = [row for row in slave_reader]
except:
    print("Error: Could not read Slave CSV file. Verify file name/path. Close if any application using this file")
    usage()
    exit()

merge_key_column = [column for column in master_columns if "Merge Key" in column][0]
cid_column = [column for column in master_columns if "CID" in column][0]
triage_column = [column for column in master_columns if "Last Triage Comment" in column][0]

if not all(column in slave_columns for column in [merge_key_column, cid_column, 'Type', 'Category', 'Checker', 'Component', 'Impact', 'File']):
    print("Error: Required columns are not found in the Slave CSV file i.e., 'Merge Key', 'CID', 'Type', 'Category', 'Checker', 'Component', 'Impact', 'File'. Seems invalid file")
    usage()
    exit()

output_rows = []

for slave_row in slave_rows:
    merge_key = slave_row[merge_key_column]
    cid_slave = slave_row[cid_column]
    type_slave = slave_row['Type']
    category_slave = slave_row['Category']
    checker_slave = slave_row['Checker']
    component_slave = slave_row['Component']
    impact_slave = slave_row['Impact']
    file_slave = slave_row['File']
    
    matching_master_rows = [row for row in master_rows if merge_key in row[merge_key_column]]
    if not matching_master_rows:
        cid_master = "0"
        triage_comment = ""
    elif len(matching_master_rows) == 1:
        cid_master = matching_master_rows[0][cid_column]
        triage_comment = matching_master_rows[0][triage_column]
    else:
        cid_master = "Error"
        triage_comment = "Error"
    
    output_rows.append([merge_key, cid_master, cid_slave, impact_slave, type_slave, category_slave, checker_slave, component_slave, file_slave, triage_comment])

#finally print the formatted text
slave_dir = os.path.dirname(args.slave)

if slave_dir == "":  #if the user has not provided any path for the slave file, Take current directory as slave directory path.
    slave_dir = "."

if args.name is None:
    csvfile = open(slave_dir + '\\ui_core_merge_key_validated_sheet.csv','w', newline='')
else:
    csvfile = open(slave_dir + '\\ui_core_'+ args.name +'_merge_key_validated_sheet.csv','w', newline='')
    
writer = csv.writer(csvfile)
writer.writerow(["Merge Key", "CID in Master", "CID", "Impact", "Type", "Category", "Checker", "Component", "File", "Last Triage Comment in Master"])
for row in output_rows:
    writer.writerow(row)
