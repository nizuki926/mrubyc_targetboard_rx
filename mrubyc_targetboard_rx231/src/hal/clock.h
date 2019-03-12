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
#define SCKCR3 (*(volatile short *)0x00080026)
#define PLLCR (*(volatile short *)0x00080028)
#define PLLCR2 (*(volatile char *)0x0008002A)
#define UPLLCR (*(volatile char *)0x0008002C)
#define UPLLCR2 (*(volatile char *)0x0008002E)
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
#define CKOCR (*(volatile short *)0x0008003E)
#define MOFCR (*(volatile char *)0x0008C293)
#define MEMWAIT (*(volatile char *)0x00080031)
#define LOCOTRR (*(volatile char *)0x00080060)
#define ILOCOTRR (*(volatile char *)0x00080064)
#define HOCOTRR0 (*(volatile char *)0x00080068)
#define HOCOTRR3 (*(volatile char *)0x0008006B)

/**
 * @brief Oscillation stabilization complete
 * 
 */
#define STABILIZATION_COMPLETE (1)
#define STABILIZATION_NOT_COMPLETE (0)
#define STABILIZATION_MAIN (0x01)
#define STABILIZATION_PLL (0x04)
#define STABILIZATION_HOCO (0x08)
#define STABILIZATION_USBPLL (0x20)

void hardware_setup (void);

#endif /* CLOCK_H_ */
