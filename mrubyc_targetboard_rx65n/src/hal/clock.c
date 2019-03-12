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

    HOCOCR2 = 0x02;
    HOCOCR = 0x00;
    while (STABILIZATION_NOT_COMPLETE == (OSCOVFSR & STABILIZATION_HOCO));

    ROMWT = 0x02;

    PLLCR = 0x1710;
    PLLCR2 = 0x00;
    while (STABILIZATION_NOT_COMPLETE == (OSCOVFSR & STABILIZATION_PLL));

    SCKCR = 0x21011222;
    SCKCR2 = 0x0011;
    SCKCR3 = 0x0400;

    register_protect_enable();
}

