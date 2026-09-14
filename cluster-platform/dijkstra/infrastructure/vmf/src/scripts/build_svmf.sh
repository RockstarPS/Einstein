

sudo echo

PROJECT="LINUX_X86"


cd ..
echo " "
echo "*********************************************************************"
echo "*** Clean SMALL-VMF for Linux X86"
echo "*********************************************************************"
CLEAN_RULES="PROJECT=$PROJECT SMALL_VMF=YES svmf_clean"
echo "make $CLEAN_RULES"
make $CLEAN_RULES



echo " "
echo " "
echo " "
echo "*********************************************************************"
echo "*** Build SMALL-VMF for Linux X86"
echo "*********************************************************************"
MAKE_RULES="PROJECT=$PROJECT SMALL_VMF=YES svmf_exec"
echo "make $MAKE_RULES"
make $MAKE_RULES
