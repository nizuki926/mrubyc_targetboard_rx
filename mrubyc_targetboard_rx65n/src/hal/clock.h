/**
 * @file hwinit.h
 * @author nizuki926
 * @brief clock setting header file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */

#ifndef CLOCK_H_
#define CLOCK_H_

/**
 * @brief clock setting register
 * 
 */
#define	SCKCR (*(volatile long *)0x00080020)
#define ROMWT (*(volatile char *)0x0008101C)
#define SCKCR2 (*(volatile short *)0x00080024)
#define SCKCR3 (*(volatile short *)0x00080026)
#define PLLCR (*(volatile short *)0x00080028)
#define PLLCR2 (*(volatile char *)0x0008002A)
#define BCKCR (*(volatile char *)0x00080030)
#define MOSCCR (*(volatile char *)0x00080032)
#define SOSCCR (*(volatile char *)0x00080033)
#define LOCOCR (*(volatile char *)0x00080034)
#define ILOCOCR (*(volatile char *)0x00080035)
#define HOCOCR (*(volatile char *)0x00080036)
#define HOCOCR2 (*(volatile char *)0x00080037)
#define OSCOVFSR (*(volatile char *)0x0008003C)
#define OSTDCR (*(volatile char *)0x00080040)
#define OSTDSR (*(volatile char *)0x00080041)
#define MOSCWTCR (*(volatile char *)0x000800A2)
#define SOSCWTCR (*(volatile char *)0x000800A3)
#define MOFCR (*(volatile char *)0x0008C293)
#define HOCOPCR (*(volatile char *)0x0008C294)

/**
 * @brief Oscillation stabilization complete
 * 
 */
#define STABILIZATION_COMPLETE (1)
#define STABILIZATION_NOT_COMPLETE (0)
#define STABILIZATION_MAIN (0x01)
#define STABILIZATION_SUB (0x02)
#define STABILIZATION_PLL (0x04)
#define STABILIZATION_HOCO (0x08)
#define STABILIZATION_IWDT (0x10)

void hardware_setup (void);

#endif /* CLOCK_H_ */
