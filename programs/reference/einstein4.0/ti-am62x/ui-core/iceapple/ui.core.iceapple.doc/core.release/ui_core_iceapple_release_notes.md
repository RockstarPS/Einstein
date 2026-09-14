# ICEAPPLE RELEASE UI-FRAMEWORKS-ICEAPPLE-4.67 (17-Jul-2024)

## Language Core

    - New Features
        - None
    - Defect Fixes
        - None
    - Enhancements/Improvements
        - None

## Language Encoder tool

    - New Features
        - None
    - Defect Fixes
        - None
    - Enhancements/Improvements
        - N59727219-11727: [GDT] - TVS HMI - GFX sections in GDT core to be allocated for GCC compiler

## Animation Core

    - New Features
        - None
    - Defect Fixes
        - N59727219-16366: [TVS][N597] - Animation rotation property is not enabled for VGlite
    - Enhancements/Improvements
        - T38XD29284-61298: Data animation core update to give all images equal display time
  
## Message Core

    - New Features
        - T38XD29284-59633: Special process for short press BACK-SW - core support - Group Acknowledge feature
    - Defect Fixes
        - None      
    - Enhancements/Improvements
        - TATA27883-32484: [X451_MCE] Store queue API for returning the store add/removal status to HMI - Notification List Implementation

## Menu Core

    - New Features
        - None
    - Defect Fixes
        - TATA27883-30347: X451_CNG: Inside the settings pressing up button the illumination disable menu was not observed
    - Enhancements/Improvements
        - None

## Popup Core  

    - New Features
        - None
    - Defect Fixes
        - None
    - Enhancements/Improvements
        - None

## Testing performed

- Static analysis - IceApple components and tool generated files for various projects analyzed and results mentioned below

| Program       |            Reports            |       Results Link      |   Target Testing       |   Integration for current release |
|:---------:    | :---------------------------: | :------------------:    | :--------------------: | :----------------------------: |
| HONDA_K0RN | Compiler | [HONDA_K0RN Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=43219931&objAction=browse&viewType=1) |   Done |  Done |
| TOYOTA 38XD | Compiler | [TOYOTA 38XD Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=43278899&objAction=browse&viewType=1) |   Done |  Done |
| TVS N597 | Compiler | [TVS N597 Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=42233963&objAction=browse&viewType=1) |   Done |  Done |
| TATAGEN2 | Compiler | [TATAGEN2 Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=39920881&objAction=browse&sort=name&viewType=1) |   Done |  Done |
| RE KCLUSTER | Compiler | [RE KCLUSTER Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=43286965&objAction=browse&viewType=1) | Done | Done |
| HERO_RAAA | Compiler | [Hero RAAA Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=43330820&objAction=browse&viewType=1) | Done | Done |
| HERO_ACJB | Compiler | [Hero ACJB Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=41414592&objAction=browse&viewType=1) | Done | Done |
| MAZDA | Compiler | [Mazda Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=26574607&objAction=browse&viewType=1) | Done | Done |
| RE P3F2 | Compiler | [RE P3F2 Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=43333466&objAction=browse&viewType=1) | Done | Done |
| RENAULT PY1B | Compiler | [RENAULT PY1B Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=36478893&objAction=browse&viewType=1) | Done | Done |
| RENAULT HBC | Compiler | [RENAULT HBC Build Results](https://vfile.visteon.com/livelink/livelink.exe?func=ll&objId=35078277&objAction=browse&viewType=1) | Done | Done |


- Integration testing done in the below programs

| Program | Stream/Snapshot |
| :-----: | :-----------------------------------------------: |
| HONDA_K0RN | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/honda/manifest/-/blob/develop/my2025/k0rn/honda_my2025_k0rn_20.04.ini> |
| Toyota 38XD | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/toyota/manifest/-/blob/develop/my2024/38xd/toyota_my2024_38xd_ubuntu_20.4.ini> |
| TVS N597 | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/tvs/manifest/-/blob/develop/my2023/n597/tvs_my2023_n597.ini> |
| TATAGEN2 | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/tata/manifest/-/blob/develop/my2022/tatagen2_tamor_ic/tata_my2022_tatagen2_tamor_ev_ic_20.4.ini>  |
| RE KCLUSTER | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/royale/manifest/-/blob/develop/my2023/kcluster/royale_my2023_kcluster__20.04.ini> |
| HERO_RAAA | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/hero/manifest/-/blob/develop/my2023/raaa/hero_my2023_raaa_20.04.ini> |
| HERO_ACJB | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/hero/manifest/-/blob/develop/my2023/acjb/hero_my2023_acjb_20.04.ini> |
| MAZDA | <https://rtc-proj.git.visteon.com/programs/mazda> |
| RE P3F2 | <https://bsp-os.git.visteon.com/platform/bsp-os/programs/royale/manifest/-/blob/develop/my2024/p3f2/royale_my2024_p3f2.ini> |
| HYUNDAI PY1B | <https://rtc-proj.git.visteon.com/programs/renault/py1b_my24> |
| HYUNDAI HBC | <https://rtc-proj.git.visteon.com/programs/renault/hbc_my19> |
| OpenGL Platform | Tested in Simulation |
| Mono Platform | Tested in Simulation |

## Integration Requirements

- TATA27883-32484: For Store Add/Remove Notification, Application can define a new callback function and add it in the following macro definition in the hmi_msgSequencer.cfg file.    
&ensp; &ensp; &ensp;**MSG_SEQUENCER_CLIENT_ADD**        
&ensp; &ensp; &ensp;**MSG_SEQUENCER_CLIENT_REMOVE**

- T38XD29284-61298: In the current data animation implementation, every image, excluding the last one, remains on the display for T/(n-1) milliseconds. Here, T represents the total duration in
milliseconds, and n stands for the number of images in the animation. The final image, however, is displayed for just one frame. To switch to an alternative implementation wherein each image
remains on the display for equal duration of T/n milliseconds, define the following macro in "hmi_gfx_anim_engine.cfg" file. For more info, refer ui.core.iceapple\animation.core.02\src\hmi_gfx_anim_engine.$cfg                    
&ensp; &ensp; &ensp;**GFX_ANIM_EQUAL_DISPLAY_TIME_TO_ALL_IMAGES**

- N59727219-11727: For GCC compiler-based programs, HMI team can add the following memory sections in the linker script (.ld file) to 
place language encoder related ro/rw data to user-defined memory regions.              
&ensp; &ensp; &ensp;**HMI_LNG_1_CONST**

- T38XD29284-59633: For utilizing Group Acknowledge feature, Application needs to define **"MSG_ENABLE_GROUP_ACKNOWLEDGEMENT"** macro in hmi_msgDefinition.cfg. 
AckGroup ID to be provided in excel sheet against each warning and generated in hmi_msgDefinition.inc file. Refer "Warning_configuration_group_ack.xlsm" sheet from the path "ui.core.iceapple.doc\message.core.01\design\" for the newly generated "AckGroup" ID parameter.
For single instance program, If the application is using stor_MessageList, it needs to be replaced with stor_MessageList[0]

- TATA27883-30347: In case of multiple greyout elements that is consecutive Greyout element count is greater than or equal to actual visible element size, 
the focusline should stay in the last valid position till next valid focus entry is found.
Enabling the following macro in hmi_menu_core_01.cfg file, will enable this feature 
and all element will be ensured to be visible in wrap around case or any similar case of grey out         
&ensp; &ensp; &ensp;**HMI_MENU_CORE_ALLOW_INVALID_FOCUS_LINE**
    