#ifndef HMI_GFX_MGR_DRAG_H
#define HMI_GFX_MGR_DRAG_H

#define DRAG_TIMER_TICK_RATE_MS 16
#define DRAG_THRESHOLD          20  
#define DRAG_IDLE_THRESHOLD      4

#define DRAG_DIR_N -1
#define DRAG_DIR_Z  0
#define DRAG_DIR_P  1

typedef struct{
   int    tdistance;
   int    dir;
   UINT32 ticks;
   UINT32 distance;
   UINT32 velocity;
}DRAG_ITEM;

typedef struct{
   DRAG_ITEM x;
   DRAG_ITEM y;
   int       basex;
   int       basey;
   int       active;
   UINT32    idle_time;
}DRAG_ENG;

void drag_reset(DRAG_ENG * peng_ctx);
void drag_process(DRAG_ENG * peng_ctx);
void drag_mouse_ev(DRAG_ENG * peng_ctx, UINT uMsg, int x, int y);

#endif

