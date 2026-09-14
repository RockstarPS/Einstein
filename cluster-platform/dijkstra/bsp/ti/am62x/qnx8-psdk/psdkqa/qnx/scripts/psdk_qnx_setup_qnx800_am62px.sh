###############################################################################
#
# This script in intended to minize the amount of manual steps required for 
# PSDK QNX addon package installation for QNX SDP 800.
#
# This script MUST be run from the PSDK RTOS installation directory, after the
# PSDK QNX addon has been extracted.
#
# The invoking of this scripts MUST be
#
#    ./psdkqa/qnx/scripts/psdk_qnx_setup_qnx800.sh
#
# The location of the BSP is determined by the user during installation of
# BSP from QNX Sofwtare Center.  This script is assuming that the BSP
# was downloaded to
#
#    ${QNX_BSP_PATH}/BSP_ti-am62p-sk-evm_br-hw-rel_be-800_SVN998577_JBN85.zip
#
###############################################################################

# Paths to different locations with PSDK RTOS installation
PSDK_RTOS_PATH=${PWD}
PSDK_QNX_PATH=${PSDK_RTOS_PATH}/psdkqa
PDK_PATH=${PSDK_QNX_PATH}/pdk
QNX_BASE=/home/$USER/qnx800
SOC=am62px

# The QNX installation directory may differ, but the
# download location of BSP from QNX Software Center
# should be resident in the same relative location
QNX_BSP_NAME=BSP_ti-am62p-sk-evm_br-hw-rel_be-800_SVN998577_JBN85.zip
QNX_BSP_PATH=${QNX_BASE}/bsp
QNX_BSP_VERSION=800_SVN998577_JBN85

# Print off the configuration
print_variables()
{
  echo "For installation script to function below variables must be correct"
  echo "PSDK_RTOS_PATH=${PWD}"
  echo "PSDK_QNX_PATH=${PSDK_QNX_PATH}"
  echo "PDK_PATH=${PDK_PATH}"
  echo "QNX_BSP_NAME=${QNX_BSP_NAME}"
  echo "QNX_BSP_PATH=${QNX_BSP_PATH}"
}

# Lets check the setup, before running the script
check_variables()
{
  # Check PSDK_QNX Path exists
  if [ ! -d ${PSDK_QNX_PATH} ]
    then
    echo "Invalid path to psdk qnx, ${PSDK_QNX_PATH}"
    exit
  fi


  # Check BSP Path exists
  if [ ! -d ${QNX_BSP_PATH} ]
    then
    echo "Invalid path to ${QNX_BSP_PATH}"
    echo "${QNX_BSP_NAME} must be extracted and available at, ${QNX_BSP_PATH}"
    exit
  fi
 
  # Check BSP zip file exists
  if [ ! -f ${QNX_BSP_PATH}/${QNX_BSP_NAME} ]
    then
    echo "Invalid path to ${QNX_BSP_PATH}/${QNX_BSP_NAME}"
    echo "${QNX_BSP_NAME} must be extracted and available at, ${QNX_BSP_PATH}/bsp"
    exit
  fi

  # Check that PDK directory exists
  if [ ! -d ${PDK_PATH} ]
    then
    echo "Invalid PDK_PATH ${PDK_PATH}"
    exit
  fi
}


setup_qnx_bsp_in_psdkqa()
{
  # Extract QNX BSP to psdkqa/qnx/bsp
  mkdir -p ${PSDK_QNX_PATH}/qnx/bsp
  unzip ${QNX_BSP_PATH}/${QNX_BSP_NAME} -d ${PSDK_QNX_PATH}/qnx/bsp

  # Update the QNX BSP with some TI BSP files
  cp -Rv ${PSDK_QNX_PATH}/qnx/scripts/bsp/${QNX_BSP_VERSION}_${SOC}/* ${PSDK_QNX_PATH}/qnx/bsp/
  #if [ $QNX_BSP_VERSION="710_SVN977709_JBN6" ]
  #    then
  #    cd ${PSDK_QNX_PATH}/qnx/bsp/
  #    patch -p1 < i2c2_startup.patch
  #    patch -p1 < ddr_startup.patch
  #    rm i2c2_startup.patch ddr_startup.patch
  #fi
}

setup_qnx_pdk_in_psdkqa()
{
  # Copy the PDK from PSDK RTOS to PSDK QNX
  mkdir ${PSDK_QNX_PATH}/pdk
  cp -Rv ${PDK_PATH}/packages ${PSDK_QNX_PATH}/pdk/

  # Copy modified PDK files 
  cp -Rv ${PSDK_QNX_PATH}/qnx/pdk/* ${PSDK_QNX_PATH}/pdk/
}

print_variables
check_variables
setup_qnx_bsp_in_psdkqa
#setup_qnx_pdk_in_psdkqa
