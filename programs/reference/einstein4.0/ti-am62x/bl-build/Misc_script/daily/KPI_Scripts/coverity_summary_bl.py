import pandas as pd
from lib.l_utils import read_config
from lib.l_utils import add_date_to_filename
import csv

#coverity_key_dict={"38XD_VIP_coverity_static_defects_2022-11-28":"VIP STATIC","38XD_VIP_coverity_misra_defects_2022-09-28":"VIP MISRA C 2012"}
#c_path="C:/Users/varvind/Documents"
"""
hmi=["UI Core","UI-APPS"]
di=["Driver Information & Controls","di-core"]
infineon=["Adc","Dio","Pwm","Port","Fls","Icu","Ocu","Mcu","Gpt","Spi","Wdg","SigUnit Driver","HSM PerfLib - IPC (M0+)","HSM PerfLib - IPC (M7)","HSM PerfLib - CRYPTO","HSM PerfLib - PROT"]
vector=['Microsar Os','BswM','EcuM','ComM','COM']
"""
path_config_file = 'logfile_paths.json'
local_paths = read_config('local_paths.json')
paths = read_config(path_config_file)
hmi=local_paths["hmi_repo"]
di=local_paths["di_repo"]
infra=local_paths["infra_repo"]
infineon=local_paths["infineon"]
vector=local_paths["vector"]
v_mcal=local_paths["v_mcal"]
Coverity_Summary_bl_html = local_paths['Coverity_Summary_bl_html']
Coverity_Summary_bl=local_paths['Coverity_Summary_bl']
Coverity_high=local_paths['Coverity_high_bl']
Coverity_med=local_paths['Coverity_med_bl']
Coverity_low=local_paths['Coverity_low_bl']
Coverity_tech=local_paths['Coverity_all_bl']

def create_style_sheet():
  to_write="""<style>
table.imagetable {
  font-family: arial;
  padding: 40px;
  font-size:14px;
  color:#333333;
  border-width: 1px;
  border-color: #999999;
  border-collapse: collapse;
}
table.imagetable th {
  background:#b5cfd2 url('cell-blue.jpg');
  border-width: 1px;
  padding: 8px;
  border-style: solid;
  border-color: #999999;
 /* word-break: break-word;*/
  /*overflow-wrap: break-word;*/
}
table.imagetable td {
  /*background:#dcddc0 url('cell-grey.jpg');*/
  border-width: 1px;
  padding: 8px;
  border-style: solid;
  border-color: #999999;
 /* word-break: break-word;*/
 /* overflow-wrap: break-word;*/
}
h1{
  background-color: #CACFD2;
  padding: 30px;
  text-align: left;
  font-size: 24px;
  font-family: arial;
color: black;
}
h2{
font-family: arial;
font-size: 18px;
}
}
h4{
font-family: arial;
font-size: 18px;
}
.footer {
  position:absolute;
  right: 0;
  bottom: 0;
  left: 0;
  padding: 1rem;
  background-color: #efefef;
  text-align: center;}
</style>"""
  return to_write
  
def create_html_table(csvfilepath,core):

    html_table = []
    rows=[]
    with open(csvfilepath, 'r',encoding="UTF-8") as fp:
        html_table.append("<table class='imagetable'>")
        csv_rows=csv.reader(fp, delimiter=',', quotechar='"')
        for i in csv_rows:
            rows.append(i)
        heading = rows[0]
        if core == 'BL':
            html_table.append("<tr>")
            html_table.append("<th>BL</th>")
            html_table.append("<th colspan=\"3\">STATIC FOR BL STREAM</th>")
            html_table.append("<th colspan=\"3\">MISRA C FOR BL STREAM</th>")
            html_table.append("<th colspan=\"3\">CERT C\CPP FOR BL STREAM</th>")
            html_table.append("<th colspan=\"1\">TECH TEAM</th>")
            html_table.append("</tr>")
        for h in heading:
            html_table.append("<th>")
            html_table.append(h)
            html_table.append("</th>")
        html_table.append("</tr>")
        for line in rows[1:]:
            html_table.append("<tr>")
            for v in line:
                html_table.append("<td>")
                html_table.append(v)
                html_table.append("</td>")
            html_table.append("</tr>")
       
    return html_table

def convert_to_html(core):
    html_table = create_html_table(Coverity_Summary_bl,core)
    with open(Coverity_Summary_bl_html, 'w') as html_obj:
        html_obj.write(create_style_sheet())
        if core == 'BL':
            html_obj.write("<h1>Coverity Summary Report</h1>")
            html_obj.write("<hr>")
            html_obj.write("<h2>BL Impact Summary Report</h1>")
            html_obj.write("<hr>")
        for row in html_table:
            html_obj.write(row)

def parse_coverity_data(mode):
        
    if mode=="BL":
        static_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_static'])
        misra_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_misra'])
        cert_c_defects_file = add_date_to_filename(paths['backup_files']['bl_coverity_cert_c'])
        Coverity_Summary = local_paths['Coverity_Summary_bl']
        Coverity_Summary_html = local_paths['Coverity_Summary_bl_html']
        coverity_key_dict={static_defects_file:"STATIC",misra_defects_file:"MISRA C 2012",cert_c_defects_file:"CERT C"}
   
    coverity_data_list = []
    sub = 'Standard: MISRA Category'
    sub2= 'Standard: CERT Category'
    # Extracting coverity data from files
    for key in coverity_key_dict.keys():
            df = pd.read_csv(key)
            columnNames = df.columns.tolist()
            misra_category_str = "".join(s for s in columnNames if sub.lower() in s.lower())
            cert_category_str = "".join(s for s in columnNames if sub2.lower() in s.lower())
            comp_list = list(set(df['Component']))
            for comp in comp_list:
                if comp=="MCAL_Infineon" or comp=="BSW_Vector" or comp=="HSM_Infineon":
                    continue
                coverity_data_row = []
                specific_comp = df.loc[df['Component'] == comp]
                bl_high = len(specific_comp[specific_comp['Impact'] == "High"]) 
                bl_medium = len(specific_comp[specific_comp['Impact'] == "Medium"]) 
                bl_low = len(specific_comp[specific_comp['Impact'] == "Low"]) 
                bl_misra_high = len(specific_comp[specific_comp[misra_category_str] == "Mandatory"]) 
                bl_misra_medium = len(specific_comp[specific_comp[misra_category_str] == "Required"]) 
                bl_misra_low = len(specific_comp[specific_comp[misra_category_str] == "Advisory"]) 
                bl_cert_high = len(specific_comp[specific_comp[cert_category_str] == "L1"]) 
                bl_cert_medium = len(specific_comp[specific_comp[cert_category_str] == "L2"]) 
                bl_cert_low = len(specific_comp[specific_comp[cert_category_str] == "L3"])
                
                coverity_data_row.append(coverity_key_dict[key])
                coverity_data_row.append(comp)
                coverity_data_row.append(bl_high)
                coverity_data_row.append(bl_medium)
                coverity_data_row.append(bl_low)
                coverity_data_row.append(bl_misra_high)
                coverity_data_row.append(bl_misra_medium)
                coverity_data_row.append(bl_misra_low)
                coverity_data_row.append(bl_cert_high)
                coverity_data_row.append(bl_cert_medium)
                coverity_data_row.append(bl_cert_low)
                
                coverity_data_list.append(coverity_data_row)
      
    coverity_df = pd.DataFrame(coverity_data_list, columns = ['Coverity Rule', 'Component','High', 'Medium', 'Low','Mandatory','Required','Advisory','L1','L2','L3'])
    
    bl_static = coverity_df.loc[(coverity_df['Coverity Rule'] == 'STATIC')]
    bl_static = bl_static[['Component', 'High','Medium','Low']]
    bl_static = bl_static.rename(columns={'High':'SHigh','Medium':'SMedium','Low':'SLow'})

    bl_misra = coverity_df.loc[(coverity_df['Coverity Rule'] == 'MISRA C 2012') | (coverity_df['Coverity Rule'] == 'MISRA CPP 2008')]
    bl_misra = bl_misra[['Component','Mandatory','Required','Advisory']]
    bl_misra = bl_misra.rename(columns={'Mandatory':'MHigh','Required':'MMedium','Advisory':'MLow'})


    bl_cert = coverity_df.loc[(coverity_df['Coverity Rule'] == 'CERT C') | (coverity_df['Coverity Rule'] == 'CERT CPP')]
    bl_cert = bl_cert[['Component','L1','L2','L3']]
    bl_cert = bl_cert.rename(columns={'L1':'CHigh','L2':'CMedium','L3':'CLow'})

    bl_frames = [bl_static, bl_misra, bl_cert]
    bl_df = pd.concat(bl_frames, keys=["STATIC", "MISRA", "CERT"])
    bl_df = bl_df.groupby(['Component'],as_index = False).agg({'SHigh': 'sum', 'SMedium': 'sum','SLow': 'sum','MHigh': 'sum', 'MMedium': 'sum','MLow': 'sum','CHigh': 'sum', 'CMedium': 'sum','CLow': 'sum'})
    bl_df = bl_df.sort_values(by = ['Component'],ascending=True) 
    bl_df[['SHigh','SMedium','SLow','MHigh','MMedium','MLow','CHigh','CMedium','CLow']] = bl_df[['SHigh','SMedium','SLow','MHigh','MMedium','MLow','CHigh','CMedium','CLow']].astype(int)
    
    Third_party=[]
    Tech_team=[]

    for ind in bl_df.index:
        if bl_df['Component'][ind] in hmi:
            Tech_team.append("HMI")
        elif bl_df['Component'][ind] in di:
            Tech_team.append("DI-APPS")
        elif bl_df['Component'][ind] in infra:
            Tech_team.append("INFRA")
        else:
            Tech_team.append("AUTOSAR")
    
    #vip_df['Third-Party'] = Third_party
    bl_df['Tech Team'] = Tech_team
    return bl_df
    
x=[]
build=local_paths["coverity_stream"]

if "BL" in build:
	df1=parse_coverity_data("BL")
	x.append(df1)

u=[]
for i in range(len(x)):
	u.append(x[i])
f_df=pd.concat(u)

#f_df=f_df.drop_duplicates(subset=["Component"], keep="first")
f_df = f_df.groupby(["Component"]).agg({"Component": 'first',"SHigh": 'sum', "SMedium": 'sum',"SLow": 'sum',"MHigh": 'sum', "MMedium": 'sum',"MLow": 'sum',"CHigh": 'sum', "CMedium": 'sum',"CLow": 'sum', "Tech Team": 'first'})
f_df = f_df.sort_values(by ='Tech Team', ascending = 1)
f_df_total = f_df.select_dtypes(pd.np.number).sum()    
f_df_total.name = 'Total'
f_df_total.loc['Component'] = 'Total'
f_df = f_df.append(f_df_total.transpose())


a=[0,0,0]
h=[0,0,0]
d=[0,0,0]
I=[0,0,0]

for i in range(len(f_df)):
    if f_df.iloc[i,10]=="AUTOSAR":
        a[0]+=f_df.iloc[i,1]+f_df.iloc[i,4]+f_df.iloc[i,7]
        a[1]+=f_df.iloc[i,2]+f_df.iloc[i,5]+f_df.iloc[i,8]
        a[2]+=f_df.iloc[i,3]+f_df.iloc[i,6]+f_df.iloc[i,9]
    
    elif f_df.iloc[i,10]=="HMI":
        h[0]+=f_df.iloc[i,1]+f_df.iloc[i,4]+f_df.iloc[i,7]
        h[1]+=f_df.iloc[i,2]+f_df.iloc[i,5]+f_df.iloc[i,8]
        h[2]+=f_df.iloc[i,3]+f_df.iloc[i,6]+f_df.iloc[i,9]
        
    elif f_df.iloc[i,10]=="DI-APPS":
        d[0]+=f_df.iloc[i,1]+f_df.iloc[i,4]+f_df.iloc[i,7]
        d[1]+=f_df.iloc[i,2]+f_df.iloc[i,5]+f_df.iloc[i,8]
        d[2]+=f_df.iloc[i,3]+f_df.iloc[i,6]+f_df.iloc[i,9]
    
    elif f_df.iloc[i,10]=="INFRA":
        I[0]+=f_df.iloc[i,1]+f_df.iloc[i,4]+f_df.iloc[i,7]
        I[1]+=f_df.iloc[i,2]+f_df.iloc[i,5]+f_df.iloc[i,8]
        I[2]+=f_df.iloc[i,3]+f_df.iloc[i,6]+f_df.iloc[i,9]
    
data ={'TECH TEAM': ['HIGH', 'MEDIUM', 'LOW'],
       'AUTOSAR':a,
       'HMI': h,
       'DI-APPS':d,
       'INFRA':I}
tech_df = pd.DataFrame.from_dict(data, orient ='index')  

high=[[a[0],h[0],d[0],I[0]]]
med=[[a[1],h[1],d[1],I[1]]] 
low=[[a[2],h[2],d[2],I[2]]] 
h=["AUTOSAR","HMI","DI-APPS","INFRA"]
f_df.to_csv(Coverity_Summary_bl,index=False)
print("Generated Coverity Summary CSV in Plot_Batch folder")
tech_df.to_csv(Coverity_tech)
print("Generated Coverity Tech Team High Low Medium CSV in Plot_Batch folder")
convert_to_html("BL")
print("Generated Coverity Summary HTML in Plot_Batch folder")
with open(Coverity_high, 'w') as csvfile:
  write = csv.writer(csvfile)
  write.writerow(h)
  h=["AUTOSAR","HMI","DI-APPS","INFRA"]
  write.writerows(high)
print("Generated Coverity Tech Team High CSV in Plot_Batch folder")  
with open(Coverity_low, 'w') as csvfile:
  write = csv.writer(csvfile)
  write.writerow(h)
  write.writerows(low)
print("Generated Coverity Tech Team Low CSV in Plot_Batch folder")  
with open(Coverity_med, 'w') as csvfile:
  write = csv.writer(csvfile)
  write.writerow(h)
  write.writerows(med)
print("Generated Coverity Tech Team High Medium in Plot_Batch folder")
