/**
 * @file delay.c
 * @author nizuki926
 * @brief software delay function source file
 * @version 1.0
 * @date 2019-02-09
 *
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 *
 */

/**
 * @brief wait for fixed 10 cycles
 * 
 * @param[in] loop_cnt loop count 
 */
static void delay (unsigned long loop_cnt)
{
    __asm("MOV #00H, R2");
    __asm("BRA LOOP+");
    __asm("NOP");
    __asm("LOOP:");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("NOP");
    __asm("ADD #01H, R2");
    __asm("CMP R1, R2");
    __asm("BNE LOOP-");
}

/**
 * @brief wait for microseconds
 * 
 * @param[in] us wait time
 * @param[in] hz system clock frequency
 */
void delay_us (unsigned long us, unsigned long hz)
{
    signed long loop_cnt;

    loop_cnt = (((us * hz) / 1000000) / 10);

    if(loop_cnt > 0)
    {
        delay(loop_cnt);
    }
}

/**
 * @brief wait for milliseconds
 * 
 * @param[in] us wait time
 * @param[in] hz system clock frequency
 */
void delay_ms (unsigned long ms, unsigned long hz)
{
    signed long loop_cnt;

    loop_cnt = (((ms * hz) / 1000) / 10);

    if(loop_cnt > 0)
    {
        delay(loop_cnt);
    }
}
