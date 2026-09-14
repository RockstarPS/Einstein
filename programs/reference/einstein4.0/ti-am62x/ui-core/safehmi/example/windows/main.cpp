// main.cpp : Defines the entry point for the console application.
//
#include <windows.h>
#include "stdafx.h"
#include "ux_shmi_uimain.h"
#include "ux_safehmi_player.h"
#include "ux_safehmi_image.h"
#include "ux_safehmi_gl20_render.h"
#include <time.h>

using namespace UX_SHMI_PLAYER;



long GetTimeMs(void)
{
  SYSTEMTIME st;
  long fl_ctime_ms;
  GetSystemTime(&st);
  fl_ctime_ms = (st.wHour * 60 * 60 * 1000) +
    (st.wMinute * 60 * 1000) +
    (st.wSecond * 1000) +
    st.wMilliseconds;
  return(fl_ctime_ms);
}

long GetTimeDurationMs(long p_cur, long p_start)
{
  if (p_cur >= p_start)
  {
    return(p_cur - p_start);
  }
  else
  {
    return((86399999 - p_start) + p_cur + 1);
  }
}
#define RTSK_RATE_MS (16)

int _tmain(int argc, _TCHAR* argv[])
{
  shmi_qnx_disp_info disp_info;
  disp_info.display_id = -1;
  disp_info.display_type = -1;
  disp_info.zorder = -1;
  disp_info.pipeline = -1;
  ux_safehmi_gl20_render gr;
  UX_SHMI_PLAYER::ux_safehmi_player player(&ui_main, static_cast<ux_safehmi_renderer *>(&gr), disp_info);
  long fl_ctime = GetTimeMs();
  long fl_render_stime = fl_ctime;
  long fl_tdiff = 0;
  long fl_total_time_elapsed = RTSK_RATE_MS;
  long fl_time_elapsed = RTSK_RATE_MS;
  uint32_t fl_total_render_cycles = 0;
  bool fl_data_changed = true;

  int32_t flipIndex = 0;
  int fl_tt_proveout = 100;

  while (1)
  {
    player.Render(fl_data_changed);
  /*  Setmyint_value2(500);
    Setmyint_value1(400);*/
    fl_ctime = GetTimeMs();
    fl_tdiff = GetTimeDurationMs(fl_ctime, fl_render_stime);
    if (fl_tdiff < RTSK_RATE_MS)
    {
      Sleep((RTSK_RATE_MS - fl_tdiff));
      fl_tdiff = RTSK_RATE_MS;
      fl_ctime = GetTimeMs();
    }
    fl_render_stime = fl_ctime;
    fl_time_elapsed += fl_tdiff;
    fl_total_time_elapsed += fl_tdiff;
    fl_total_render_cycles++;
    if (fl_total_time_elapsed > 1000)
    {
      float fl_fps = (float)fl_total_time_elapsed;
      fl_fps /= 1000.0f;
      fl_fps = (((float)fl_total_render_cycles) / fl_fps);
      printf("afps=%3.2f\n", fl_fps);
    }
    fl_data_changed = true;
  }
  return 0;
}

