===========================================================

                       README.txt

===========================================================

1. Configuration Properties->Debugging->Command Arguments, Specify the 
reference and output directories. Example, C:\Project\Reference,C:\Project\Target

2. Run the simulation 

3. In sid_test_input.h, Specify the number of SIDs and the SIDs array from the hmi_language_identifiers.h ( Reference files provided for HBC, PSA and SU2 )

4. In hmi_main.c, specify the language to test in SIDSTesting in the API, hmi_language_if_set_current_language(HMI_LANGUAGE_HINDI);

5. By default, the screenshots will be captured in the first commandline argument (C:\Project\Reference folder ). Hence, capture the reference images
first. Once done, have a copy of it in the Target folder.

6. Run the simulation again and capture the screenshot with the updated changes. Again screenshots will be generated in (C:\Project\Reference folder ).

7. Comparison will be done automatically between the folders C:\Project\Reference and C:\Project\Target after Step 6.

8. The log will be generated in TestingSIDSLog.txt