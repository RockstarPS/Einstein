echo Copy the files from rtc workspace to src folder for running QAC

xcopy ..\..\..\..\ui.core.iceapple\animation.core.02\src\*.*		..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\language.core.01\src\*.*			..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\menu.core.01\src\*.*					..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\menu.core.lite.01\src\*.*		..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\message.core.01\src\*.*			..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\popup.core.02\src\*.*				..\..\qac\src\  /Y
xcopy ..\..\..\..\ui.core.iceapple\view.manager.02\src\*.*			..\..\qac\src\  /Y

xcopy ..\..\autogen\*.*																					..\..\qac\src\  /Y
xcopy ..\..\stub\*.*																					  ..\..\qac\src\  /Y

echo source files copied to qac\src
exit 0



