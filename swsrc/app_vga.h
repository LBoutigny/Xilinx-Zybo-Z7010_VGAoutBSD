// SPDX-License-Identifier: GPL-2.0
/*
 * app_hdmi.h
 *
 *  Created on: 07 Jan 2019
 *      Author: florentw
 */

#ifndef APP_VGA_H_
#define APP_VGA_H_

	#include "xv_tpg.h"
	
	void app_vga_conf_tpg(XV_tpg *InstancePtr, u32 height, u32 width, u32 colorFormat, u32 bckgndId);
	void app_vga_conf_tpg_box(XV_tpg *InstancePtr, u32 boxSize, u32 motionSpeed);

#endif /* APP_VGA_H_ */
