###############################################################################
#                                                                             #
# This script is versioned and available in the psdkqa/qnx/scripts directory  #
# in the TI PSDK QNX software Package.                                        #
#                                                                             #
# The script is intended to be run on a previously built release of PSDK QNX  #
# software package and will generate a directory structure containing a       #
# subset of the PSDK QNX release that can be used for development, without    #
# requiring full download, installation and build of the TI PSDK QNX release. #
#                                                                             #
# The env variable ${PSDK_PATH} must be set to the install path of the        #
# PSDK QNX SDK Installer.                                                     #
#                                                                             #
#                                                                             #
# To see Usage:                                                               #
#   python3  gen_psdk_qnx_trim_pkg_am62px.py -h                                #
#                                                                             #
# Sample command used in TI PSDK QNX Build environment                        #
#   python3  gen_psdk_qnx_trim_pkg_am62px.py                                   #
#       -r ${PSDK_PATH}/psdkqa/pdk/packages/ti                                #
#       -d umda sciclient enet ipc                                            #
#       -o psdk_qnx_pkg_am62px                                                 #
#                                                                             #
# Expected output:                                                            #
#      Directory 'psdk_qnx_pkg_am62px' is created containing libraries,        #
#      headers and binaries to build and run against PSDK QNX release         #
#                                                                             #
###############################################################################
import sys
import os
import re
import ast
import shutil
import glob
from pprint import pprint
import argparse

def parseDepFile(db, path, platform, cpu, fname):
    fileLst = db[platform][cpu][fname]
    with open(path, 'r') as f:
        lines  = f.readlines()
        y = []
        if any(re.findall(r'mcu|c66|c7x|r5f', path)):
            l = [x.lstrip(' ').rstrip('\n').split(': ')[1] for x in lines if not any(re.findall(r'xdc|bios', x))]
            y = [x[x.find('packages/ti')+12:] for x in l if x.find('packages') >= 0]
        elif any(re.findall(r'mpu|a72|a53', path)):
            l = [x.lstrip(' ').rstrip('\n').split(' \\')[0] for x in lines if not any(re.findall(r'xdc|bios|:', x))]
            y = [x[x.find('packages/ti')+12:] for x in l if x.find('packages') >= 0]

        # Gather the common CSL file list for the platform
        commonCslLst = db[platform]['common_csl']
        z = [z for z in y if z.find('csl') >= 0]
        for zf in z:
            if zf not in commonCslLst:
                commonCslLst.append(zf)

        #Gather the common non-CSL file list for the platform
        commonNonCslLst = db[platform]['common_non_csl']
        w = [w for w in y if w.find('csl') < 0]
        for wf in w:
            if wf not in commonNonCslLst:
                commonNonCslLst.append(wf)

        # Update the file dependency list
        for yf in y:
            if yf not in commonCslLst:
                fileLst.append(yf)

# def parseDepFile

def ProcessDir(db, dirName, drvName):
    dirName = dirName + drvName + '/obj'
    if verbose:
        print('Parsing files under directory: ' + dirName)

    for root, dirs, files in os.walk(dirName):
        if files:
            for f in files:
                if '.P' in f:
                    path = root+'/'+f
                    offset = path.find(dirName)
                    tok = path[offset+len(dirName)+1:].split('/')
                    start    = 0
                    platform = tok[start + 0]
                    cpu      = tok[start + 1]
                    fname    = tok[start + 5]
                    if platform not in db:
                        db[platform] = {}
                        db[platform]['common_csl'] = []
                        db[platform]['common_non_csl'] = []
                    elif cpu not in db[platform]:
                        db[platform][cpu] = {}
                    elif fname not in db[platform][cpu]:
                        db[platform][cpu][fname] = []
                        parseDepFile(db, path, platform, cpu, fname)

# def main

def ProcessTranscriptFile(transFile):
    with open(transFile, 'r') as f:
        dbData = f.read()
        return ast.literal_eval(dbData)

#def ProcessTranscriptFile

def ParseCmdLineArgs():
    # Define the parser rules
    parser = argparse.ArgumentParser(description='FILE DEPENDENCY PARSER.', add_help=False)

    required    = parser.add_argument_group('required arguments')
    optional    = parser.add_argument_group('optional arguments')
    conditional = parser.add_argument_group('conditional arguments')

    required.add_argument('-r', '--root_dir',
                          help='Root directory for the operation.',
                          required=True)

    conditional.add_argument('-d', '--driver_list',
                             help='''Name of the driver(s) (ex:- udma). Multiple keywords can
                                     be specified seperated by white space (ex:- udma ipc edma).
                                     You MUST specifiy this if the transcript file is not provided
                                     as input.
                                     If a transcript is provided as input then the script takes
                                     precedence and this option will be ignored.''',
                             nargs='*',
                             required=not any(['-t' in sys.argv, '--transcript_file' in sys.argv]))

    optional.add_argument('-t', '--transcript_file',
                          help='Input transcript file name.')

    optional.add_argument('-g', '--gen_tran_file',
                          help='Output transcript file name.')

    optional.add_argument('-o', '--out_dir',
                          help='Output directory for generated header files.')

    optional.add_argument('-v', '--verbose',
                          help='Verbose flag.',
                          action='store_true')

    optional.add_argument('-h', '--help',
                          help='show this help message and exit.',
                          action='help')

    # Invoke the parser
    args = parser.parse_args()

    return args

# End of def ParseCmdLineArgs()

#############################################
# def CopyPrebuiltDtbs
#############################################
def CopyPrebuiltDtbs(rootDir, outDir, verbose):
    src_dtb_folder = rootDir + "/../../../qnx/internal_docs/scripts/trim_package/dtbs/am62p/*.dt*"


    dest_dir = outDir + "/psdkqa/dtbs/"
    if not os.path.exists(dest_dir):
        os.makedirs(dest_dir)

    for file in glob.glob(src_dtb_folder):
        if verbose:
            print(file)
        shutil.copy(file, dest_dir)

def GenerateCommonCslHdrFiles(db, outDir, verbose):
    # Create the output directory, if it does not exist
    if not os.path.exists(outDir):
        os.makedirs(outDir)

    for p in db:
        pdb = db[p]
        for d in ['common_csl']:
            cdb = pdb[d]
            hdrName = '_'.join([p, d, '.h'])
            hdrMacro = '_'.join(['', p, d, '']).upper()
            with open(hdrName, 'w') as out:
                out.write('#if !defined({})\n#define {}\n\n'.format(hdrMacro, hdrMacro))
                for fname in cdb:
                    out.write('/' +20*'*' + fname + 20*'*' + '/\n')
                    with open(fname, 'r') as f:
                        out.write(f.read())
                out.write('\n#endif // !defined({})\n\n'.format(hdrMacro))

# def CopyPdkLibraries

def CopyPdkLibraries(rootDir, outDir, verbose):

    for dirpath, dirs, files in os.walk(rootDir):
      for filename in files:
        fname = os.path.join(dirpath, filename)
        # Search PSDK QNX for the QNX aa72fg libraries
        if (".aa72fg" in fname) and ("qnx" in fname):
            # Generate and create output path
            splitpath = dirpath.split("psdkqa",2);
            olibpath = outDir + "/psdkqa" + splitpath[1]
            if not os.path.exists(olibpath):
                os.makedirs(olibpath)
            filepath = os.path.join(olibpath, filename)
            # Copy libraries
            if verbose:
                print("Copying lib from:", fname, "to: ", filepath)
            shutil.copyfile(fname, filepath)

# def CopyPsdkqaQnxLibsAndBinaries

def CopyPsdkqaQnxLibsAndBinaries(rootDir, outDir, verbose):
     files = ["/qnx/resmgr/udma_qnx_rsmgr/resmgr/aarch64/o.le/tiudma-mgr",
             "/qnx/resmgr/ipc_qnx_rsmgr/resmgr/aarch64/o.le/tiipc-mgr",
             "/qnx/resmgr/sciclient_qnx_rsmgr/aarch64/o.le/tisci-mgr",
             "/qnx/sharedmemallocator/resmgr/aarch64/o.le/shmemallocator",
             "/qnx/sharedmemallocator/usr/aarch64/so.le/libsharedmemallocator.so",
             "/qnx/sharedmemallocator/usr/aarch64/so.le/libsharedmemallocatorS.a",
             "/qnx/sharedmemallocator/usr/aarch64/a.le/libsharedmemallocator.a",
             "/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/so.le/libtiudma-usr.so",
             "/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/so.le/libtiudma-usrS.a",
             "/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/a.le/libtiudma-usr.a",
             "/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/so.le/libtiipc-usr.so",
             "/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/so.le/libtiipc-usrS.a",
             "/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/a.le/libtiipc-usr.a",
             "/qnx/pdk_libs/sciclient/aarch64/so.le/libti-sciclient.so",
             "/qnx/pdk_libs/sciclient/aarch64/so.le/libti-sciclientS.a",
             "/qnx/pdk_libs/ipclld/aarch64/so.le/libti-ipclld.so",
             "/qnx/pdk_libs/ipclld/aarch64/so.le/libti-ipclldS.a",
             "/qnx/pdk_libs/udmalld/aarch64/so.le/libti-udmalld.so",
             "/qnx/pdk_libs/udmalld/aarch64/so.le/libti-udmalldS.a",
             "/qnx/pdk_libs/pdk/aarch64/so.le/libti-pdk.so",
             "/qnx/pdk_libs/pdk/aarch64/so.le/libti-pdkS.a",
             "/qnx/utils/k3conf/qnx/aarch64/o.le/k3conf"]

     for file in files:
        dst_filename = ""
        dst_filename = outDir + "/psdkqa" + file
        dirpath = ""
        dirpath = "./" + os.path.dirname(dst_filename)
        if not os.path.exists(dirpath):
            os.makedirs(dirpath)
        src_filename = rootDir + "/../../.." + file
        if verbose:
            print("Copying binaries from:", src_filename, "to:", dst_filename)
        shutil.copy(src_filename, dst_filename)


# def GenerateCommonCslHdrFiles

def CopyCommonCslHdrFiles(db, rootDir, outDir, verbose):
    # Create the output directory, if it does not exist
    oDir = '/'.join([outDir, 'psdkqa/pdk/packages/ti'])
    for p in db:
        pdb = db[p]
        for d in ['common_csl', 'common_non_csl']:
            cdb = pdb[d]
            for fname in cdb:
                fullSrcFileName = '/'.join([rootDir, fname])
                dstDir = '/'.join([oDir, os.path.dirname(fname)])
                if not os.path.exists(dstDir):
                    os.makedirs(dstDir)
                if verbose:
                    print("Copy ", fullSrcFileName, "to ", dstDir)
                shutil.copy(fullSrcFileName, dstDir)


if __name__ == '__main__':
    db = {}

    # Parse command line arguments
    args      = ParseCmdLineArgs()
    verbose   = args.verbose
    dirName   = args.root_dir + '/binary/ti/drv/'
    drvList   = args.driver_list
    transFile = args.transcript_file
    outDir    = args.out_dir

    # Check if we have a transcript file provided
    if transFile is not None:
        db = ProcessTranscriptFile(transFile)
    else:
        for drvName in drvList:
            ProcessDir(db, dirName, drvName)

    if args.verbose:
        pprint(db, depth=3)

    if args.gen_tran_file:
        with open(args.gen_tran_file, "w") as f:
            pprint(db, stream=f)

    # Create common header files
    #GenerateCommonCslHdrFiles(db, args.out_dir, args.verbose)

    if args.out_dir:
        CopyCommonCslHdrFiles(db, args.root_dir, args.out_dir, args.verbose)

    if args.out_dir:
        CopyPdkLibraries(args.root_dir, args.out_dir, args.verbose)

    if args.out_dir:
        CopyPsdkqaQnxLibsAndBinaries(args.root_dir, args.out_dir, args.verbose)

    if args.out_dir:
        CopyPrebuiltDtbs(args.root_dir, args.out_dir, args.verbose)
