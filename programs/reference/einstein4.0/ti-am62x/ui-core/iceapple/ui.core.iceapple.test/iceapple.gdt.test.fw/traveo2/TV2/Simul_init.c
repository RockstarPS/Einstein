
#include "Std_Types.h"
#include "CmpLib.h"


extern void CGdtCtrl_Impl_MainFunction( void ) ;
extern Std_ReturnType CGdtCtrl_Impl_OnCommand( ECmpCmd cmd );

extern void CGdtCdd_Impl_MainFunction( void ) ;
extern Std_ReturnType CGdtCdd_Impl_OnCommand( ECmpCmd cmd );

extern void OsTask_Renderfunc(void);

int stage = 0;

int tick = 0;

void Simul_task()
{
    while(1)
    {
        switch(stage)
        {
        case 0:
            CGdtCdd_Impl_OnCommand(eCmpCmd_Init);
            CGdtCdd_Impl_OnCommand(eCmpCmd_Activate);
            stage = 1;
            break;
        case 1:
            if(E_OK == CGdtCdd_Impl_OnCommand(eCmpCmd_Activate)) 
            {
                stage = 2;
            }
            else
            {
                CGdtCdd_Impl_MainFunction();
                return ;
            }
            break;
        case 2:
            CGdtCtrl_Impl_OnCommand(eCmpCmd_Init);
            CGdtCtrl_Impl_OnCommand(eCmpCmd_Activate);
            stage = 3;
            break;
        case 3:
            if(E_OK == CGdtCtrl_Impl_OnCommand(eCmpCmd_Activate)) 
            {
                stage = 4;
            }
            else
            {
                CGdtCtrl_Impl_MainFunction();
                return;
            }
            break;
        default:
            CGdtCtrl_Impl_MainFunction();
            if(tick == 0)
            {
                CGdtCdd_Impl_MainFunction();
            }

            tick = 1 - tick;
            return;
        }
    }
}

void Simul_taskGFX(void)
{
    OsTask_Renderfunc();
}
