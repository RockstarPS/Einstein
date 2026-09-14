/*
 * This file registers the FreeType modules compiled into the library.
 *
 * If you use GNU make, this file IS NOT USED!  Instead, it is created in
 * the objects directory (normally `<topdir>/objs/`) based on information
 * from `<topdir>/modules.cfg`.
 *
 * Please read `docs/INSTALL.ANY` and `docs/CUSTOMIZE` how to compile
 * FreeType without GNU make.
 *
 */
 
#define FT_USE_RASTER                     // monochrome rasterizer
#define FT_USE_SMOOTH                     // anti-aliasing rasterizer
#define FT_USE_TT                         // truetype font driver
#define FT_USE_T1                         // type1 font driver
#define FT_USE_T42                        // type42 font driver
#define FT_USE_T1CID                      // cid-keyed type1 font driver  // no cmap support
#define FT_USE_CFF                        // opentype font driver
#define FT_USE_PCF                        // pcf bitmap font driver
#define FT_USE_PFR                        // pfr font driver
#define FT_USE_WINFNT                     // windows .fnt|.fon bitmap font driver

#ifdef FT_USE_T42
#define FT_USE_TT
#define FT_USE_PSAUX
#endif

#ifdef FT_USE_TT
#define FT_USE_SFNT
#endif

#ifdef FT_USE_CFF
#define FT_USE_SFNT
#define FT_USE_PSAUX
#define FT_USE_PSHINT
#define FT_USE_PSNAMES
#endif

#ifdef FT_USE_T1
#define FT_USE_PSAUX
#define FT_USE_PSHINT
#define FT_USE_PSNAMES
#endif

#ifdef FT_USE_T1CID
#define FT_USE_PSAUX
#define FT_USE_PSHINT
#define FT_USE_PSNAMES
#endif

#ifdef FT_USE_PSAUX
#define FT_USE_PSNAMES
#endif

#ifdef FT_USE_SFNT
#define FT_USE_PSNAMES
#endif

/* Now include the modules */
#ifdef FT_USE_AUTOFIT
FT_USE_MODULE( FT_Module_Class, autofit_module_class )
#endif

#ifdef FT_USE_TT
FT_USE_MODULE( FT_Driver_ClassRec, tt_driver_class )
#endif

#ifdef FT_USE_T1
FT_USE_MODULE( FT_Driver_ClassRec, t1_driver_class )
#endif

#ifdef FT_USE_CFF
FT_USE_MODULE( FT_Driver_ClassRec, cff_driver_class )
#endif

#ifdef FT_USE_T1CID
FT_USE_MODULE( FT_Driver_ClassRec, t1cid_driver_class )
#endif

#ifdef FT_USE_PFR
FT_USE_MODULE( FT_Driver_ClassRec, pfr_driver_class )
#endif

#ifdef FT_USE_T42
FT_USE_MODULE( FT_Driver_ClassRec, t42_driver_class )
#endif

#ifdef FT_USE_WINFNT
FT_USE_MODULE( FT_Driver_ClassRec, winfnt_driver_class )
#endif

#ifdef FT_USE_PCF
FT_USE_MODULE( FT_Driver_ClassRec, pcf_driver_class )
#endif

#ifdef FT_USE_BDF
FT_USE_MODULE( FT_Driver_ClassRec, bdf_driver_class )
#endif

#ifdef FT_USE_PSAUX
FT_USE_MODULE( FT_Module_Class, psaux_module_class )
#endif

#ifdef FT_USE_PSNAMES
FT_USE_MODULE( FT_Module_Class, psnames_module_class )
#endif

#ifdef FT_USE_PSHINT
FT_USE_MODULE( FT_Module_Class, pshinter_module_class )
#endif


#ifdef FT_USE_SFNT
FT_USE_MODULE( FT_Module_Class, sfnt_module_class )
#endif

#ifdef FT_USE_SMOOTH
FT_USE_MODULE( FT_Renderer_Class, ft_smooth_renderer_class )
#endif

#ifdef FT_USE_RASTER
FT_USE_MODULE( FT_Renderer_Class, ft_raster1_renderer_class )
#endif

#ifdef FT_USE_SDF
FT_USE_MODULE( FT_Renderer_Class, ft_sdf_renderer_class )
FT_USE_MODULE( FT_Renderer_Class, ft_bitmap_sdf_renderer_class )
#endif

#ifdef FT_USE_SVG
FT_USE_MODULE( FT_Renderer_Class, ft_svg_renderer_class )
#endif

/* EOF */
