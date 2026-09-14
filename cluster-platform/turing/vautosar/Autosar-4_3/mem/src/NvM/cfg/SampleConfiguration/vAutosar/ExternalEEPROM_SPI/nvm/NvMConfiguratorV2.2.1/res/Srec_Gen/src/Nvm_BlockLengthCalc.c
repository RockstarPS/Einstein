#include <stdio.h>
#include "Std_Types.h"
#include "Nvm_BlockLengthCalc.h"

FILE *blocklenFile;
void BlockLengthCalc_Init()
{
    blocklenFile = fopen("../../../BlockLength_dump.csv", "wb");
}

void BlockLengthCalc_Add(uint32 Blocklen)
{
    char data[4];
    char S[5];
    sprintf(data, "%d",Blocklen);
    int i=0;
    for(i; i<4; i++){
        if(NULL==data[i]){
            break;
        }
        else{
            S[i]=data[i];
        }
    }
    S[i++]=',';
    fwrite(S, 1, i, blocklenFile); 
}

void BlockLengthCalc_Close()
{
    fclose(blocklenFile);
}