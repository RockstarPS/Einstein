
import os
import subprocess


DEBUG = False;



class version_date:
    def __init__(self):
        self.version = "version"
        self.time = "time"


def debug_print(suffix, what):
    if DEBUG == True:
        if len(suffix) > 0:
            print(suffix + " :" + what);
        else:
            print(what);
    return;


def get_vmf_version():
    version_file = open("version.txt", "r");
    version = version_date();
    version.version = version_file.readline();
    version.time = version_file.readline();
    return version;




def write_html(file_name, coverage, stats):
    html_file = open(file_name, "w");

    vmf_version = get_vmf_version();
    debug_print("get_vmf_version", vmf_version.version);
    debug_print("get_vmf_version", vmf_version.time);

    out = "<html>\n<title>VMF Coverage</title>\n<link rel=\"stylesheet\" href=\"VMF-Coverage.css\"></head>\n<body>\n"
    html_file.writelines(out)

    out =  "<div id=\"page-wrapper\">\n<h1>VMF coverage test results</h1>\n"
    out += "<h3>" + vmf_version.version + "</h3>\n"
    out += "Execution time:" + vmf_version.time + "\n"
    out += "<br><br>\n"

    html_file.writelines(out)

    out =  "<h2>Overall Coverage: " + "{:.2f}".format(coverage) + "% </h2>\n"
    out += "<meter min=\"0\" max=\"100\" value=\"" + str(int(coverage)) + "\"></meter>\n"
    out += "<br><br><br>\n"    
    html_file.writelines(out)

    for stat in stats:
        stat_split = stat.split(";")
        out =  "<div class=\"file_container\">\n<div class=\"file\">\n" + stat_split[3] + "</div>\n<div class=\"coverage\">\n"
        out += "Coverage: " + stat_split[1] + " of " + stat_split[0] + " lines\n</div></div><br>" 
        html_file.writelines(out)


    out = "</body>\n</html>"
    html_file.writelines(out)

    html_file.close();
    return;



# Vars
filtered = [];              # List with files ending by .c.txt
statistics = [];            # statistics from all files
sum_covered_lines = 0;      # sum of all covered lines
sum_number_lines = 0;       # sum of all number of lines


# Main
files = os.listdir(".");

for file in files:
    if file.endswith(".c.txt"):
        debug_print("", file);
        filtered.append(file);


for file in filtered:
    file_obj = open(file, "r");
    line = file_obj.readline();

    while len(line) > 0:
        if line.startswith("File"):
            my_file = line.split("'");
            line = file_obj.readline();
            my_percent = ((line.split(":"))[1].split("%"))[0];
            my_number = ((line.split("of"))[1].split("\n"))[0];
            my_covered = str( int(float(my_percent) / 100 * float(my_number)) );
            out = my_number + ";" + my_percent + ";" + my_covered + ";" + my_file[1];
            debug_print("out", out);
            statistics.append(out);
            sum_covered_lines += int(my_covered) ;
            sum_number_lines += int(my_number); 
        else:
            line = file_obj.readline();

    file_obj.close();

print("Lines\tPerCent\tCovered\tFile");
for stat in statistics:
    print(stat.replace(";","\t"));

debug_print("sum_covered_lines", str(sum_covered_lines));
debug_print("sum_number_lines", str(sum_number_lines));

coverage = (100.0 / sum_number_lines) * sum_covered_lines;
print("Coverage: %0.2f (%d / %d lines)" % (coverage, sum_covered_lines, sum_number_lines));

write_html("test.html", coverage, statistics);


debug_print("","finsihed.");

