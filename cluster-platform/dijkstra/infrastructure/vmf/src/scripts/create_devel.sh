### Create a devel package for the given project.


if [ "$1" == "?" ]
then
    echo " "
    echo "******************************************************************"
    echo "* create_devel.sh"
    echo "******************************************************************"
    echo "* Build VMF devel"
    echo "******************************************************************"
    echo "* Command line arguments:"
    echo "*   arg1 == PROJECT (WINDOWS_X86 / LINUX_X86 / LINUX_ARM_HF / "
    echo "*                    EAGLE / R013 / QNX_X86 / DC15 / "
    echo "*                    EAGLE_UPDATE / ANDROID / EINSTEIN / "
    echo "*                    D544 / RasPi / U321 / INTEGRITY) "
    echo "*           e.g. ./create_devel.sh R013"
    echo "******************************************************************"
    echo " "

    exit
fi


if [ ! -n "$1" ] #if empty
then
    # default
    PROJECT="LINUX_X86"
else
    PROJECT=$(echo $1 | tr '[:lower:]' '[:upper:]')
fi

VERBOSE="-v"

# remind current dir
CURRENT=$PWD

# Create devel in parallel to vmf_linux repo.
cd ../..
DIR_DEVEL=$PWD"/vmf_devel/"$PROJECT


# OS config folder
if [ "$PROJECT" == "WINDOWS_X86" ]
then
DIR_OS_CONFIG="nw_os_config_windows"
fi

if [ "$PROJECT" == "WINDOWS_X86_64" ]
then
DIR_OS_CONFIG="nw_os_config_windows"
fi

if [ "$PROJECT" == "LINUX_X86" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "LINUX_X86_GCOV" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "LINUX_ARM_HF" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi


if [ "$PROJECT" == "EAGLE" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "R013" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "QNX_X86" ]
then
DIR_OS_CONFIG="nw_os_config_qnx"
fi

if [ "$PROJECT" == "DC15" ]
then
DIR_OS_CONFIG="nw_os_config_qnx"
fi

if [ "$PROJECT" == "EINSTEIN" ]
then
DIR_OS_CONFIG="nw_os_config_qnx"
fi

if [ "$PROJECT" == "EAGLE_UPDATE" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "OPENSYN" ]
then
DIR_OS_CONFIG="nw_os_config_opensyn_linux"
fi

if [ "$PROJECT" == "ANDROID" ]
then
DIR_OS_CONFIG="nw_os_config_android"
fi

if [ "$PROJECT" == "D544" ]
then
DIR_OS_CONFIG="nw_os_config_qnx"
fi

if [ "$PROJECT" == "P2D3" ]
then
DIR_OS_CONFIG="nw_os_config_qnx"
fi

if [ "$PROJECT" == "INNO_WINDOWS" ]
then
DIR_OS_CONFIG="nw_os_config_windows"
fi

if [ "$PROJECT" == "INNO_WINDOWS_64" ]
then
DIR_OS_CONFIG="nw_os_config_windows_64"
fi

if [ "$PROJECT" == "INNO_ARM" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "INNO_ARM_HF" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "RASPI" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "U321" ]
then
DIR_OS_CONFIG="nw_os_config_linux"
fi

if [ "$PROJECT" == "INTEGRITY" ]
then
DIR_OS_CONFIG="nw_os_config_integrity"
fi

cd $CURRENT
cd ..


echo ""
echo ""
echo "Creating $DIR_DEVEL"
echo ""


mkdir $VERBOSE -p $DIR_DEVEL

#if devel already exists, then clean
rm $VERBOSE -r -f $DIR_DEVEL/*


FOLDER="bin"
mkdir $VERBOSE -p $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f rel/$PROJECT/$FOLDER/* $DIR_DEVEL/$FOLDER
if [ "$PROJECT" == "INNO_WINDOWS_64" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w64/* $DIR_DEVEL/$FOLDER
fi

FOLDER="libs"
mkdir $VERBOSE -p $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f rel/$PROJECT/$FOLDER/*.so $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f rel/$PROJECT/$FOLDER/*.a $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f rel/$PROJECT/$FOLDER/*.dll $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f rel/$PROJECT/$FOLDER/*.lib $DIR_DEVEL/$FOLDER

if [ "$PROJECT" == "WINDOWS_X86" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w32/$FOLDER/* $DIR_DEVEL/$FOLDER
fi
if [ "$PROJECT" == "INNO_WINDOWS" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w32/$FOLDER/* $DIR_DEVEL/$FOLDER
fi
if [ "$PROJECT" == "INNO_WINDOWS_64" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w64/* $DIR_DEVEL/$FOLDER
fi


FOLDER="include"
mkdir $VERBOSE -p $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f include/* $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f vmf/03_code/public/* $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f vmf_trace/03_code/public/* $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f vmf_config/* $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f $DIR_OS_CONFIG/03_code/public/* $DIR_DEVEL/$FOLDER
cp $VERBOSE -r -f vmf_sql/03_code/public/* $DIR_DEVEL/$FOLDER

if [ "$PROJECT" == "WINDOWS_X86" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w32/$FOLDER/* $DIR_DEVEL/$FOLDER
fi
if [ "$PROJECT" == "INNO_WINDOWS" ]
then
cp $VERBOSE -r -f $DIR_OS_CONFIG/pthread_w32/$FOLDER/* $DIR_DEVEL/$FOLDER
fi

echo ""
echo "Creating $DIR_DEVEL finished!"
