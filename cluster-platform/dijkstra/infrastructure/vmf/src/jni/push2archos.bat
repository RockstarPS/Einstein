
rem push all vmf executables to Archos Tablet

call adb push ..\libs\armeabi\vmf /tmp/vmf/vmf
call adb push ..\libs\armeabi\libvmf_client.so /tmp/vmf/
call adb push ..\libs\armeabi\libvmf_trace.so /tmp/vmf/
call adb push ..\libs\armeabi\vmf_ping_listener /tmp/vmf
call adb push ..\libs\armeabi\vmf_ping_sender /tmp/vmf
call adb push vmf_ping_run.sh /tmp/vmf
call adb push config.sh /tmp/vmf/
call adb push vmf_mi.ini /tmp/vmf/

rem call adb push ..\libs\armeabi\vmf_receive /tmp/vmf/
rem call adb push ..\libs\armeabi\vmf_send /tmp/vmf/

call adb shell mkdir -p /tmp/vmf
call adb shell chmod 777 /tmp/vmf/*



echo ****************************************************
echo Ensure LD_LIBRARY_PATH points to /tmp/vmf !!!!
echo ****************************************************



