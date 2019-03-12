/**
 * @file vector.c
 * @author nizuki926
 * @brief interrupt vector and exception vector setting source file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */
#include "vector.h"

extern void PowerON_Reset (void);

void (* int_vectors[INT_VECTOR_NUMBER])(void);
void (* excep_vectors_sub[EXCEP_VECTOR_NUMBER])(void);

void dummy (void)
{
    
}

void excep_supervisorinst(void)
{
	void (*target_func)(void);

	target_func = (void (*)())(*excep_vectors_sub[0]);
	target_func();
}

void excep_accessinst(void)
{
	void (*target_func)(void);

	target_func = (void (*)())(*excep_vectors_sub[1]);
	target_func();
}

void excep_undefinedinst(void)
{
	void (*target_func)(void);

	target_func = (void (*)())(*excep_vectors_sub[2]);
	target_func();
}

void excep_floatingpoint(void)
{
	void (*target_func)(void);

	target_func = (void (*)())(*excep_vectors_sub[3]);
	target_func();
}

void nonmaskableinterrupt(void)
{
	void (*target_func)(void);

	target_func = (void (*)())(*excep_vectors_sub[4]);
	target_func();
}

void int_initialize (void)
{
    int i;

	for(i = 0; i < INT_VECTOR_NUMBER; ++i) {
		int_vectors[i] = dummy;
	}
}

void excep_initialize (void)
{
    int i;

	for(i = 0; i < EXCEP_VECTOR_NUMBER; ++i) {
		excep_vectors_sub[i] = dummy;
	}
}

void int_regist (unsigned int vect_number, void (*func) (void))
{
    if(vect_number < INT_VECTOR_NUMBER)
    {
		int_vectors[vect_number] = func;
	}
}

void excep_regist (unsigned int excep_number, void (*func) (void))
{
    if(excep_number < EXCEP_VECTOR_NUMBER)
    {
		int_vectors[excep_number] = func;
	}
}

/**
 * @brief reset vector
 * 
 */
const void *HardwareVectors[] __attribute__ ((section (".fvectors"))) =
{
#ifdef __RX_LITTLE_ENDIAN__
	(void *)0xffffffff,
#endif
#ifdef __RX_BIG_ENDIAN__
	(void *)0xfffffff8,
#endif
	(void *)0,
	(void *)0xFFFFFFFF,
	(void *)0xFFFFFFFF,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0xFFFFFFFF,
	(void *)0xFFFFFFFF,
	(void *)0xFFFFFFFF,
	(void *)0xFFFFFFFF,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	excep_supervisorinst,
	(void *)0,
	(void *)0,
	excep_undefinedinst,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	nonmaskableinterrupt,
	PowerON_Reset
};
