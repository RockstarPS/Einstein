import os 
import fnmatch
a = 30
dir_path = '/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/manifest/my2026/ic-mic/product/release'
count = len(fnmatch.filter(os.listdir(dir_path), '*.xml'))
print("Number of milestone manifest file are : ",count)

if count > a:
    path = '/media/sofia13/Data/workspace/workspace/Daily/MIC_Next_29130/BMW_MY26_MIC_NEXT_IC_EP29130_DAILY/manifest/my2026/ic-mic/product/release'
    max_Files = 30
 
    def sorted_ls(path):
        mtime = lambda f: os.stat(os.path.join(path, f)).st_mtime
        return list(sorted(os.listdir(path), key=mtime))
 
    del_list = sorted_ls(path)[0:(len(sorted_ls(path))-max_Files)]
 
    for dfile in del_list:
        os.remove(path + dfile)
else:
    print("count is not greater than 30")
  


  
