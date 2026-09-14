###############################################################################
#                                                                             #
# This script shows a sample usage of gen_psdk_qnx_trim_pkg_j721e.py script.  #
#                                                                             #
# The script is intended to be run on a previously built release of PSDK QNX  #
# software package and will generate a directory structure containing a       #
# subset of the PSDK QNX release that can be used for development, without    #
# requiring fulll download, installation and build of the TI PSDK RTOS and    #
# PSDK QNX releases.                                                          #
#                                                                             #
# See gen_psdk_qnx_trim_pkg_j721e.py for further information                  #
#                                                                             #
# The env variable ${PSDK_RTOS_PATH} must be set to the install path of the   #
# PSDK RTOS SDK Installer:                                                    #
# ti-processor-sdk-rtos-j721e-xx_xx_xx_xx-linux-x64-installer.run             #
#                                                                             #
###############################################################################
echo "Make sure \$PSDK_RTOS_PATH env variable is set"
echo "The \$PSDK_RTOS_PATH is set as: ${PSDK_RTOS_PATH}"
if [ ! -d ${PSDK_RTOS_PATH}/psdkqa ]
then
  echo "Invalid PSDK_RTOS_PATH or env variable not set.. ${PSDK_RTOS_PATH}"
  exit
else
  python3  gen_psdk_qnx_trim_pkg_j721e.py -r ${PSDK_RTOS_PATH}/psdkqa/pdk/packages/ti -d udma sciclient sciclient_hs enet ipc -o psdk_qnx_trim_pkg_j721e
  tar -czf psdk_qnx_trim_pkg_j721e.tar.gz psdk_qnx_trim_pkg_j721e
  echo "Trim package psdk_qnx_trim_pkg_j721e.tar.gz generated!"
fi
