/**
 * @file register_protect.h
 * @author nizuki926
 * @brief register protect setting header file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */

#ifndef REGISTER_PROTECT_H_
#define REGISTER_PROTECT_H_

/**
 * @brief register protect setting register
 * 
 */
#define PRCR (*(volatile short *)0x000803FE)

void register_protect_disable (void);
void register_protect_enable (void);

#endif /* REGISTER_PROTECT_H_ */
