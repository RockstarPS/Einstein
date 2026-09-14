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

def ExtractMaxROMSize (line_ach):
    #uncomment the below commented lines when you use .ld file
    '''temp1_ach = ""
    extractLen = ""
    hiLimit = ''
    loLimit = ''
      
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = line_ach.replace("*/","")
    temp1_ach = temp1_ach.split("-")
    print(temp1_ach[2])
    #extractLen = temp1_ach[len(temp1_ach)-1].split("-") 
    loLimit = int((temp1_ach[1]),16)
    hiLimit = int((temp1_ach[2]),16)
    return((float(hiLimit/1024)- float(loLimit/1024)))'''
    
    #Input file Type:memory_sections_Vip.txt
    temp1_ach = ""
    extractLen = ""
    
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = temp1_ach.split("LENGTH=")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('K',"")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('M',"")
    extractLen = temp1_ach[len(temp1_ach)-1]
    extractLen = int(extractLen)
    #print(extractLen,"MB")
    
    return(extractLen)
    
      
def ExtractMaxNORSize (line_ach):
    #uncomment the below commented lines when you use .ld file
    '''temp1_ach = ""
    extractLen = ""
    hiLimit = ''
    loLimit = ''
    hiLimit2 = ''
    
    temp1_ach = line_ach.replace(" ","")
    #temp1_ach = line_ach.replace("/*","")
    temp1_ach = temp1_ach.split("=")
    extractLen = temp1_ach[len(temp1_ach)-1].split("-")
    #print(extractLen)  
    loLimit = int((extractLen[0]),16)
    hiLimit2 = extractLen[1]
    #extractLen = hiLimit2[len(hiLimit2)-1].split("/*")
    extractLen = hiLimit2.split("/*")
    #print(extractLen)
    hiLimit = int((extractLen[0]),16)
    
    return((float(loLimit/1024)- float(hiLimit/1024)))'''
    
    #Input file Type:memory_sections_Vip.txt
    temp1_ach = ""
    extractLen = ""
    
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = temp1_ach.split("LENGTH=")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('K',"")
    temp1_ach[len(temp1_ach)-1] = temp1_ach[len(temp1_ach)-1].replace('M',"")
    extractLen = temp1_ach[len(temp1_ach)-1]
    extractLen = int(extractLen)
    #print(extractLen,"MB")
    
    return(extractLen)
    
    
def ExtractUsageRamSize (line_ach):
    temp1_ach = ""
    extractRAMSize = 0
    temp1_ach2 = ""
    temp1_ach = line_ach.replace(" ","")
    temp1_ach = temp1_ach.split("|")
    #print(temp1_ach[4]) 
    for x in range (3,(len(temp1_ach)-1),2):
        if(temp1_ach[x].find("KBytes") != -1 ):
            temp1_ach2 = temp1_ach[x].replace("KBytes","")
            extractRAMSize += float(float(temp1_ach2))
            extractRAMSize = round(extractRAMSize,2)
            #print(extractRAMSize,"MB")
        elif(temp1_ach[x].find("MBytes") != -1 ):
            temp1_ach2 = temp1_ach[x].replace("MBytes","")
            extractRAMSize = float(temp1_ach2)
            extractRAMSize = round(extractRAMSize,2)*1000
            #print(extractRAMSize,"MB")
        elif(temp1_ach[x].startswith("Bytes") != -1 ):
            temp1_ach2 = temp1_ach[x].replace("Bytes","")
            extractRAMSize = float(temp1_ach2)
            #extractRAMSize = round(extractRAMSize,3)
            #print(extractRAMSize,"Bytes")
        
          
    return(extractRAMSize)


def GenerateReport():
    
    time = datetime.datetime.now()
    dir_path = os.path.dirname(sys.path[0])
    file_path = os.path.join(dir_path, '/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/programs/bmw/my2026/ic-mic/vp-build/Misc_script/daily/RAM_ROM_scripts/scripts/results/Vip_ROM_Report.html')
    #print(file_path)

    with open(file_path, 'w') as myFile:
       
        myFile.write('<html>')
        myFile.write('<body bgcolor =#FFFFF0>')
        myFile.write('<br><br><br><br><br>')
        myFile.write('<h1 align=center>Build Report: %s </h1>' %time);
        myFile.write('<h3 align=center >TEST RESULTS</h3>')
        myFile.write('<table border="0.5" cellpadding="5" style="width:60%;vertical-align: middle" align=center >')
        myFile.write('<tr bgcolor="#788D95"><th>Test Name</th><th>Actual Size(TCM + NOR)<br>(KB)</th><th>Used Size<br>(KB)</th><th>Warning Limit<br>(KB)</th><th>Results</th><th>Details/Reason</th></tr>')
        myFile.write('<tr bgcolor="#FDF5E6" ><td>VIP_ROM_metrics_BMW.py</td><td align="center">%.2f</td>' %memSize);
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

myTotalRam = open("/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/programs/bmw/my2026/ic-mic/vp-build/memory_sections.txt", "r+")
myUsageRam = open("/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/programs/bmw/my2026/ic-mic/out/VP/IC_MIC_EVK/release/output.txt", "r+")



myTotalRam_text = myTotalRam.readlines()
myUsageRam_text = myUsageRam.readlines()


#for line in myTotalRam_text:
#    if (line.find("SRAM:  ORIGIN")!= -1):
#        memSize += ExtractMaxROMSize(line)
        #print ("Memsize")
        #print (memSize)
        
for line in myTotalRam_text:
    if (line.find("FLASH: ORIGIN")!= -1):
        memSize += (ExtractMaxNORSize(line)*1)
        #print ("afterMemsize")
        #print (memSize)         
        
for line in myUsageRam_text:
    if (line.find("FPKB8_VP_CM7           |")!= -1):
        memUsage = ExtractUsageRamSize(line)
        #print("memUsage")
        #print(memUsage)  
        
memSize = round(memSize, 2)
memUsage = round(memUsage, 2)

headers_RAM = ["ROM Size(MB)", "Warning Level(MB)", "ROM Usage(MB)"]
RAM_data = [str(memSize), str(memSize*0.8), str(memUsage)]
warninglevel = float(memSize*0.8)

dir_path = os.path.dirname(sys.path[0])
file_path = os.path.join(dir_path, '/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/programs/bmw/my2026/ic-mic/vp-build/Misc_script/daily/RAM_ROM_scripts/scripts/results/vip_ROM.csv')
#print(file_path)
    
    
csv_out = open(file_path, 'w',newline='')
wr = csv.writer(csv_out)
wr.writerow(headers_RAM)
wr.writerow(RAM_data)
GenerateReport()
csv_out.close()
    
