/**
 * @file clock.c
 * @author nizuki926
 * @brief clock setting source file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */
#include "clock.h"
#include "register_protect.h"

/**
 * @brief hardware setup
 * 
 */
void hardware_setup (void)
{
    register_protect_disable();

    HOCOCR2 = 0x03;
    HOCOCR = 0x00;
    while (STABILIZATION_NOT_COMPLETE == (OSCOVFSR & STABILIZATION_HOCO));

    MEMWAIT = 0x01;
    SCKCR = 0x10010100;
    SCKCR3 = 0x0100;

    register_protect_enable();
}

