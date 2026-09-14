#include "system.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_mgr_gest_drag.h"

/* implements the generation of a drag/flick gesture from raw single touch XY input */

void drag_item_init(DRAG_ITEM * peng_item)
{
   peng_item->tdistance = 0;
   peng_item->dir       = DRAG_DIR_Z;
   peng_item->ticks     = 0;
   peng_item->distance	= 0;
   peng_item->velocity  = 0;
}

void drag_init(DRAG_ENG * peng_ctx, int x, int y)
{
   peng_ctx->basex = x;
   peng_ctx->basey = y;

   peng_ctx->x.tdistance = 0;
   peng_ctx->x.dir       = DRAG_DIR_Z;
   peng_ctx->x.ticks     = 0;
   peng_ctx->x.distance	= 0;
   peng_ctx->x.velocity  = 0;

   peng_ctx->y.tdistance = 0;
   peng_ctx->y.dir       = DRAG_DIR_Z;
   peng_ctx->y.ticks     = 0;
   peng_ctx->y.distance	= 0;
   peng_ctx->y.velocity  = 0;
}

void drag_process_item(DRAG_ITEM * peng_item)
{
	peng_item->ticks    += (DRAG_TIMER_TICK_RATE_MS);
	peng_item->velocity  = (int)(peng_item->distance * 1000)/peng_item->ticks;
	if(peng_item->velocity == 0)
	{
	  drag_item_init(peng_item);
	}
}

void drag_process(DRAG_ENG * peng_ctx)
{
	if(peng_ctx->active)
	{
		drag_process_item(&peng_ctx->x);
		drag_process_item(&peng_ctx->y);
		if(!peng_ctx->x.velocity && !peng_ctx->y.velocity)
		{
			peng_ctx->active = 0;
			drag_init(peng_ctx, 0, 0);
		}
		peng_ctx->idle_time++;
		if(peng_ctx->idle_time > DRAG_IDLE_THRESHOLD)
		{
			peng_ctx->active = 0;
			drag_init(peng_ctx, 0, 0);
		}
	}
}

void drag_pmove(DRAG_ITEM * pitem, int pd)
{
    int fdelta;
    if(pitem->dir == DRAG_DIR_P)
    {
       if((pd < pitem->tdistance) && ((pitem->tdistance-pd) > DRAG_THRESHOLD))
       {
          /* direction change */
		  pitem->dir = DRAG_DIR_N;
		  pitem->distance = 0;
		  pitem->ticks = 0;
       }
    }
    else if(pitem->dir == DRAG_DIR_N)
    {
       if((pd > pitem->tdistance) && ((pd - pitem->tdistance) > DRAG_THRESHOLD))
       {
          /* direction change */
		  pitem->dir = DRAG_DIR_P;
		  pitem->distance = 0;
		  pitem->ticks = 0;
       }
    }
    else if((pd > DRAG_DIR_Z) && (pd > DRAG_THRESHOLD))
    {
       pitem->dir = DRAG_DIR_P;
    }
    else if((pd < DRAG_DIR_Z) && (pd < DRAG_THRESHOLD))
    {
       pitem->dir = DRAG_DIR_N;
    }
    else
    {
    }
	if(pitem->tdistance > pd)
	{
	   fdelta = (pitem->tdistance - pd);
	}
	else
	{
	   fdelta = (pd - pitem->tdistance);
	}
    pitem->distance += fdelta;
    pitem->tdistance = pd;
}

void drag_mouse_ev(DRAG_ENG * peng_ctx, UINT uMsg, int x, int y)
{
   switch(uMsg)
   {
      case WM_MOUSEMOVE:
      case WM_LBUTTONUP:
      {
         if(peng_ctx->active)
		 {
            int dx, dy;
            dx = (peng_ctx->basex-x);
            dy = (peng_ctx->basey-y);
		    drag_pmove(&peng_ctx->x, dx);
		    drag_pmove(&peng_ctx->y, dy);
			if(uMsg == WM_LBUTTONUP)
			{
				peng_ctx->active = 0;
			}
		 }
		 else
		 {
			drag_init(peng_ctx, x, y);
			peng_ctx->active = 1;
		 }
		 peng_ctx->idle_time = 0;
      }
      break;
      case WM_LBUTTONDOWN:
      {
          drag_init(peng_ctx, x, y);
		  peng_ctx->active = 1;
		  peng_ctx->idle_time = 0;
      }
      break;
	  default:
      {
      }
      break;
   }
}
