This folder contains Python Scripts for Static Analysis

Merge Key Validator:
    >> Python script to validate merge key by looking up into master sheet 
    >> Generate a report indicating if the Merge Key of the outstanding warnings in slave file already present in the master sheet or not.
    >> Slave file can be downloaded from the coverity server (Outstanding Issues). "Merge KEY" and "Checker" columns will not be available in Outstanding Issues window by default. 
       These two columns are required for generating the report. Please add these two columns before exporting csv file.
    >> Usage: python ui_core_merge_key_validator.py --master master file path --slave slave file path [--lines no. of lines to process] [--name name of the program]
        --master path of master file                                                                                                            [mandatory]
        --slave  path of slave file                                                                                                             [mandatory]
        --lines  number of lines/rows to process in each file                                                                                   [optional]
        --name   name of the current program and type of analysis (cov/misra/his/cert). This will be appended into output file name             [optional]
    >> For more info run the following command: python ui_core_merge_key_validator.py --help
    
Triaged View Consolidator:
    >> Python Script to generate a consolidated master sheet for Merge Key Validator by parsing through all the triaged view csv sheets from the given input folder.
    >> If no --master is provided, it will create a new master sheet, else the provided --master sheet will be updated.   
    >> It is required to have all the triaged view sheet in a single folder. Sheet can be downloaded from coverity server (TRIAGE_VIEW) for the deviated programs.
    >> Upon running the script "ui_core_triaged_view_<type>_consolidated_sheet.csv" file will be generated 
    >> Triaged view files from the following programs are consolidated into master sheet - HONDA_MKRG, MMC_4P45_MY20, MMC_4P45_MY24, RE_KCLUSTER, TOYOTA_38XD
    >> Usage: python ui_core_triaged_view_consolidator.py [--master path to master sheet] --folder Folder path containing all the triaged view CSV files [--type coverity/misra/cert/his]
        --master  path to master sheet CSV file                                                                                                  [optional]
        --folder  Folder path containing all the triaged view CSV files                                                                          [mandatory]
        --type    coverity/misra/cert/his                                                                                                        [optional] 
    >> For more info run the following command: python ui_core_triaged_view_consolidator.py --help