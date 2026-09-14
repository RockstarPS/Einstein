from __future__ import division
import sys
import time
import re
import csv
import os
import datetime

memUsage = 0
memSize = 0
warninglevel = 0

def ExtractMaxRamSize (line_ach):
    temp1_ach = ""
    extractLen = ""
    
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = temp1_ach.split("LENGTH=")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('K',"")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('M',"")
    extractLen = temp1_ach[len(temp1_ach)-1]
    extractLen = int(extractLen)
    #print(extractLen)
    
    return(extractLen)
    
def ExtractUsageRamSize (line_ach,x):
    temp1_ach = ""
    extractRAMSize = ''
    temp1_ach2 = ""
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = temp1_ach.split("|")
   
    if(temp1_ach[x].find("KBytes") != -1 ):
        temp1_ach2 = temp1_ach[x].replace("KBytes","")
        extractRAMSize = float(temp1_ach2)
        extractRAMSize = round(extractRAMSize,2)
        #print(extractRAMSize,"KB")
    elif(temp1_ach[x].find("MBytes") != -1 ):
        temp1_ach2 = temp1_ach[x].replace("MBytes","")
        extractRAMSize = float(temp1_ach2)
        extractRAMSize = round(extractRAMSize,2)
        #print(extractRAMSize,"MB")
    elif(temp1_ach[x].startswith("Bytes") != -1 ):
        temp1_ach2 = temp1_ach[x].replace("Bytes","")
        extractRAMSize = float(temp1_ach2)
        extractRAMSize = round(extractRAMSize,3)/1000
        #print(extractRAMSize,"Bytes")
    
      
    return(extractRAMSize)

def GenerateReport():
    
    time = datetime.datetime.now()
    dir_path = os.path.dirname(sys.path[0])
    file_path = os.path.join(dir_path, '/home/jenkins/workspace/VW_DI_fpkb8/VW_MY2022_FPKB8_IC_EP28877_Quality/programs/vw/my2022/fpkb8/vp-build/Misc_Scripts/RAM_ROM_scripts/scripts/results/Vip_RAM_Report.html')
    #print(file_path)


    with open(file_path, 'w') as myFile:
       
        myFile.write('<html>')
        myFile.write('<body bgcolor =#FFFFF0>')
        myFile.write('<br><br><br><br><br>')
        myFile.write('<h1 align=center>Build Report: %s </h1>' %time);
        myFile.write('<h3 align=center >TEST RESULTS</h3>')
        myFile.write('<table border="0.5" cellpadding="5" style="width:60%;vertical-align: middle" align=center >')
        myFile.write('<tr bgcolor="#788D95"><th>Test Name</th><th>Actual Size(TCM + DDR)<br>(KB)</th><th>Used Size<br>(KB)</th><th>Warning Limit<br>(KB)</th><th>Results</th><th>Details/Reason</th></tr>')
        myFile.write('<tr bgcolor="#FDF5E6" ><td>Vip_RAM_metrics_VW_fpkb8.py</td><td align="center">%.2f</td>' %memSize);
        myFile.write('<td align="center">%.2f</td>' % memUsage);
        myFile.write('<td align="center">%.2f</td>' % warninglevel);
        if (memUsage > warninglevel):
            myFile.write('<td bgcolor = #FC5F5F align="center">FAIL</td><td>Excedded Warning Limit</td>')
        else:
            myFile.write('<td bgcolor = #BCFC5F align="center">PASS</td><td align="center">Ok</td>')
            
        myFile.write('</tr>')
        myFile.write('</table>')
        myFile.write('</body>')
        myFile.write('</html>')
        myFile.close()



#myTotalRam = open("D:\\PST\\S2.8_Release_0909\\S2.8_Rel_0909\\programs\\ford\\my2023\\s2dot8\\vp-build\\memory_sections_Vip.txt", "r+")
#myUsageRam = open("D:\\PST\\S2.8_Release_0909\\S2.8_Rel_0909\\programs\\ford\\my2023\\s2dot8\\out\\VP_Platform\\S2DOT8_ED1\\release\\output.txt", "r+")
myTotalRam = open("/home/jenkins/workspace/VW_DI_fpkb8/VW_MY2022_FPKB8_IC_EP28877_Quality/programs/vw/my2022/fpkb8/vp-build/memory_sections.txt", "r+")
myUsageRam = open("/home/jenkins/workspace/VW_DI_fpkb8/VW_MY2022_FPKB8_IC_EP28877_Quality/programs/vw/my2022/fpkb8/out/VP/FPKB8_Traveo2/release/output.txt", "r+")



myTotalRam_text = myTotalRam.readlines()
myUsageRam_text = myUsageRam.readlines()


for line in myTotalRam_text:
    if (line.find("SRAM:           ORIGIN")!= -1):
        memSize = ExtractMaxRamSize(line)
        for line in myUsageRam_text:
            if (line.find("FPKB8_VP_CM7           |")!= -1):
                memUsage = ExtractUsageRamSize(line,2)
                #print("Memsize1")
                #print(line)
    if (line.find("SECURED_SRAM:   ORIGIN")!= -1):
        memSize = ExtractMaxRamSize(line) + memSize
        for line in myUsageRam_text:
            if (line.find("FPKB8_VP_CM7           |")!= -1):
                memUsage = ExtractUsageRamSize(line,3) + memUsage
                #print("Memsize2")
                #print(line)
    if (line.find("SAFE_DATA_SRAM: ORIGIN")!= -1):
        memSize = ExtractMaxRamSize(line) + memSize
        for line in myUsageRam_text:
            if (line.find("FPKB8_VP_CM7           |")!= -1):
                memUsage = ExtractUsageRamSize(line,4) + memUsage
                #print("Memsize3")
                #print(line)
    if (line.find("SRAM_NOCACHE:   ORIGIN")!= -1):
        memSize = ExtractMaxRamSize(line) + memSize
        for line in myUsageRam_text:
            if (line.find("FPKB8_VP_CM7           |")!= -1):
                memUsage = ExtractUsageRamSize(line,5) + memUsage
                #print("Memsize4")
                #print(line)
    if (line.find("SRAM_BURAM:     ORIGIN")!= -1):
        memSize = ExtractMaxRamSize(line) + memSize
        for line in myUsageRam_text:
            if (line.find("FPKB8_VP_CM7           |")!= -1):
                memUsage = ExtractUsageRamSize(line,6) + memUsage
                #print("Memsize5")
                #print(line) 
        
#for line in myTotalRam_text:
#    if (line.find("FLASH: ORIGIN")!= -1):
#        memSize += ExtractMaxRamSize(line)
        #print("Memsize")
        #print(memSize)         
        
#for line in myUsageRam_text:
#    if (line.find("FPKB8_VP_CM7           |")!= -1):
#       memUsage = ExtractUsageRamSize(line)
        #print("memUsage")
        #print(memUsage)  


headers_RAM = ["RAM Size(KB)", 'Warning Level(KB)', 'RAM Usage(KB)']
RAM_data = [str(memSize), str(memSize*0.5), str(memUsage)]
warninglevel = float(memSize*0.5)

dir_path = os.path.dirname(sys.path[0])
file_path = os.path.join(dir_path, '/home/jenkins/workspace/VW_DI_fpkb8/VW_MY2022_FPKB8_IC_EP28877_Quality/programs/vw/my2022/fpkb8/vp-build/Misc_Scripts/RAM_ROM_scripts/scripts/results/vip_RAM.csv')
#print(file_path)
        
csv_out = open(file_path, 'w',newline='')
wr = csv.writer(csv_out)
wr.writerow(headers_RAM)
wr.writerow(RAM_data)
GenerateReport()
csv_out.close()
   
