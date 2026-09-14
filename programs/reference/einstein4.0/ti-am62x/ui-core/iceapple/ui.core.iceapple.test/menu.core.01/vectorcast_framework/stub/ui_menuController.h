/*
 * ui_menuController.h
 *
 *  Created on: Apr 11, 2022
 *      Author: BRAJ
 */

#ifndef UI_MENUCONTROLLER_H_
#define UI_MENUCONTROLLER_H_



extern void hmi_menu_app_store_MenuID(MENU_LIST_ID_T p_menuID_e);
extern void hmi_menu_app_store_menu_item(MENU_LIST_ID_T p_menuID_e, UINT16 p_item_val_U16);
extern UINT8 Menu_Configured_Timeout_Value(void);
extern UINT16 hmi_menu_app_get_stored_menu_item(MENU_LIST_ID_T p_menuID_e);

/*============================================================================
**
**============================================================================
** C M S    R E V I S I O N    N O T E S
**============================================================================
**
** For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**
** CMS Rev #        Date         By
** CMS Rev X.X      mm/dd/yy     CDSID
**
**============================================================================
**/

#endif /* UI_MENUCONTROLLER_H_ */
