/**
 * @file register_protect.c
 * @author nizuki926
 * @brief register protect setting source file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */

#include "register_protect.h"

/**
 * @brief register protect disable
 * 
 */
void register_protect_disable (void)
{
    PRCR = 0xA50B;
}

/**
 * @brief register protect enable
 * 
 */
void register_protect_enable (void)
{
    PRCR = 0xA500;
}