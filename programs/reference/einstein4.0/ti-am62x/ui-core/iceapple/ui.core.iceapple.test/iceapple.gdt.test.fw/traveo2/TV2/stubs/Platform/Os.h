
#ifndef OS_H_
#define OS_H_

#define OsTask_Render 1

#define Gfx_Ev_RdrInit (1 << 1)
#define Gfx_Ev_RdrDeinit (1 << 2)
#define Gfx_Ev_RdrStart  (1 << 3)


typedef int EventMaskType;

int SetEvent(int task, int ev);
int GetEvent(int task, EventMaskType* ev);
int WaitEvent(int ev);
int ClearEvent(int ev);


#endif