// SPDX-License-Identifier: GPL-2.0
/*
 * vdma_example_1.c
 *
 *  Created on: 28 Feb 2019
 *      Author: florentw
 */


#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"

#include "app_vga.h"

XV_tpg tpg_inst;
XV_tpg_Config *tpg_config;

int main()
{
	int Status;
    init_platform();

    print("VDMA application on ZC702 using on-board HDMI\n\r");

    xil_printf("HDMI Setup Complete!\r\n");

    //Initialize the TPG IP
    Status = XV_tpg_Initialize(&tpg_inst, XPAR_V_TPG_0_DEVICE_ID);
    if(Status!= XST_SUCCESS)
    {
    	xil_printf("TPG configuration failed\r\n");
    	return(XST_FAILURE);
    }

    //Configure the TPG
    app_vga_conf_tpg(&tpg_inst, 1080, 1920, 0x2, XTPG_BKGND_COLOR_BARS);

    //Configure the moving box of the TPG
    app_vga_conf_tpg_box(&tpg_inst, 50, 1);

    //Start the TPG
    XV_tpg_EnableAutoRestart(&tpg_inst);
    XV_tpg_Start(&tpg_inst);
    xil_printf("TPG started!\r\n");

	while(1)
	{
	}


    cleanup_platform();
    return 0;
}


