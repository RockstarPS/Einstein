#ifdef __cplusplus
extern "C" {
#endif

#pragma once
extern HRESULT hmi_gfx_ddraw_init(HWND l_hWnd);
extern void    hmi_gfx_ddraw_distroy(void);
extern void    hmi_gfx_ddraw_flip(BOOL p_post_copy);
extern LPVOID  hmi_gfx_ddraw_get_backbuffer(void);
extern DWORD   hmi_gfx_ddraw_get_fb_pix_format(void);

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif
