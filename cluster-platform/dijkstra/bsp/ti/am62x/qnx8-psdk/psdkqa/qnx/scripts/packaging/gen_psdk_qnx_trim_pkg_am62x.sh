###############################################################################
#                                                                             #
# This script shows a sample usage of gen_psdk_qnx_trim_pkg_am62x.py script.  #
#                                                                             #
# The script is intended to be run on a previously built release of PSDK QNX  #
# software package and will generate a directory structure containing a       #
# subset of the PSDK QNX release that can be used for development, without    #
# requiring full download, installation and build of the TI PSDK QNX release. #
#                                                                             #
# See gen_psdk_qnx_trim_pkg_am62x.py for further information                  #
#                                                                             #
# The env variable ${PSDK_PATH} must be set to the install path of the        #
# PSDK QNX SDK Installer.                                                     #
#                                                                             #
###############################################################################
echo "Make sure \$PSDK_PATH env variable is set"
echo "The \$PSDK_PATH is set as: ${PSDK_PATH}"
if [ ! -d ${PSDK_PATH}/psdkqa ]
then
  echo "Invalid PSDK_PATH or env variable not set.. ${PSDK_PATH}"
  exit
else
  python3  gen_psdk_qnx_trim_pkg_am62x.py -r ${PSDK_PATH}/psdkqa/pdk/packages/ti -d udma sciclient sciclient_hs enet ipc -o psdk_qnx_trim_pkg_am62x
  tar -czf psdk_qnx_trim_pkg_am62x.tar.gz psdk_qnx_trim_pkg_am62x
  echo "Trim package psdk_qnx_trim_pkg_am62x.tar.gz generated!"
fi

