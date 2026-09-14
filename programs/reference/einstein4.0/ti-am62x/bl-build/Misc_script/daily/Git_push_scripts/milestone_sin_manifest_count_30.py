import os 
import fnmatch
a = 30
dir_path = '/home/jenkins/workspace/VW_DI_fpkb8/VW_DI_IC_FPKB8_EP29854_Daily/manifest/my2022/fpkb8/product/daily/'
count = len(fnmatch.filter(os.listdir(dir_path), '*.xml'))
print("Number of milestone manifest file are : ",count)

if count > a:
    path = "/home/jenkins/workspace/VW_DI_fpkb8/VW_DI_IC_FPKB8_EP29854_Daily/manifest/my2022/fpkb8/product/daily/"
    max_Files = 30
 
    def sorted_ls(path):
        mtime = lambda f: os.stat(os.path.join(path, f)).st_mtime
        return list(sorted(os.listdir(path), key=mtime))
 
    del_list = sorted_ls(path)[0:(len(sorted_ls(path))-max_Files)]
 
    for dfile in del_list:
        os.remove(path + dfile)
else:
    print("count is not greater than 30")
