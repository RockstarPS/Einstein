#include "system.h"
#include "hmi_simulation_tick.h"
#include "conio.h"
#include "stdio.h"
#include "hmi_gfx_manager.h"
#include "hmi_gfx_mgr_cfg.h"

SINT16 l_x_pos = 0;
SINT16 l_y_pos = 0;

static void move_the_image(UINT8 index);

void move_left(void)
{
   l_x_pos--;
   if(l_x_pos < 0)
   {
      l_x_pos = 0;
   }
}

void move_right(void)
{
   l_x_pos++;
   if(l_x_pos >= 480)
   {
      l_x_pos = 479;
   }
}

void move_up(void)
{
   l_y_pos--;
   if(l_y_pos < 0)
   {
      l_y_pos = 0;
   }
}

void move_down(void)
{
   l_y_pos++;
   if(l_y_pos >= 272)
   {
      l_y_pos = 271;
   }
}

void move_ok(void)
{
   l_x_pos = 0;
   l_y_pos = 0;
}

int main(int argc, char* argv[])
{
   UINT8 i;
   GfxManagerInitialize();
   while(1)
   {
      if(_kbhit())
      {
         switch(_getch())
         {
            case 27:
			{
				DestroyLcdWindow();
				return;
			}
			break;
			case 224:
			{
				switch(_getch())
				{
				   case 72:/*UP*/move_up();break;
				   case 80:/*DN*/move_down();break;
				   case 75:/*LEFT*/move_left();break;
				   case 77:/*RIGHT*/move_right();break;
				}
			}
			break;
			case 'o':
			{
			   //GfxManagerSendEvent(GFX_CLIP_SCREEN, 1);
               GfxManagerSendEvent(GFX_SCR_WELCOME, 1);
			   /*for(i=1;i<=12;i++)
			   {
                  move_the_image(i);*/

               /*GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,50);
			   GfxManagerSendEvent(GFX_SCROLLING_IMAGE_Y,0);
			   GfxManagerSendEvent(GFX_SCROLL_TXT_X,10);
               GfxManagerSendEvent(GFX_SCROLL_TXT_Y,40);*/
			   GfxManagerBuildScreen(1);

			   //}
			}
			break;
			case 'p':
				{
                     GfxManagerSendEvent(GFX_CLIP_SCREEN, 1);
					 GfxManagerBuildScreen(1);
				}
				break;
			default:
				break;

         }
      }
	  else
	  {
         MSG  msg;
         if (GetMessage(&msg, NULL, 0, 0))
         {
            /*TranslateMessage(&msg);*/
            DispatchMessage(&msg);
         }
	  }
   }
}

static void move_the_image(UINT8 index)
{
	GfxManagerSendEvent(GFX_SCROLLING_IMAGE_Y,0);
	switch(index)
	{
	case 1:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,50);
			break;
	case 2:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,60);
            break;
	case 3:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,70);
            break;
	case 4:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,80);
            break;
	case 5:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,90);
            break;
	case 6:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,100);
            break;
	case 7:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,110);
            break;
	case 8:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,120);
            break;
	case 9:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,130);
            break;
	case 10:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,140);
            break;
	case 11:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,150);
            break;
	case 12:
			GfxManagerSendEvent(GFX_SCROLLING_IMAGE_X,160);
			break;
	default:
		    break;
	}
}

