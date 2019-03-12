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
 * @brief exception vectors
 * 
 */
const void *excep_vectors[] __attribute__ ((section (".exvectors"))) =
{
    (void *)0,
    (void *)0,
    (void *)0,
    (void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
    excep_supervisorinst,
    excep_accessinst,
	(void *)0,
    excep_undefinedinst,
	(void *)0,
    excep_floatingpoint,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
    nonmaskableinterrupt,
};

/**
 * @brief reset vector
 * 
 */
const void *HardwareVectors[] __attribute__ ((section (".fvectors"))) =
{
    PowerON_Reset
};

#ifdef __RX_BIG_ENDIAN__
    /**
     * @brief MDE register for big endian
     * 
     */
    const unsigned long __MDEreg __attribute__ ((section (".ofs1"))) = 0xfffffff8;
#else
    /**
     * @brief MDE register for little endian
     * 
     */
    const unsigned long __MDEreg __attribute__ ((section (".ofs1"))) = 0xffffffff;
#endif

/**
 * @brief OFS0 register
 * 
 */
const unsigned long __OFS0reg __attribute__ ((section (".ofs1"))) = 0xffffffff;

/**
 * @brief OFS1 register
 * 
 */
const unsigned long __OFS1reg __attribute__ ((section (".ofs1"))) = 0xffffffff;

/**
 * @brief TMINF register
 * 
 */
const unsigned long __TMINFreg __attribute__ ((section (".ofs2"))) = 0xffffffff;

/**
 * @brief SPCC register
 * 
 */
const unsigned long __SPCCreg __attribute__ ((section (".ofs3"))) = 0xffffffff;

/**
 * @brief TMEF register
 * 
 */
const unsigned long __TMEFreg __attribute__ ((section (".ofs4"))) = 0xffffffff;

/**
 * @brief OSIS register
 * 
 */
const unsigned long __OSISreg[4] __attribute__ ((section (".ofs5"))) = {
        0xffffffff,
        0xffffffff,
        0xffffffff,
        0xffffffff,
};

/**
 * @brief FAW register
 * 
 */
const unsigned long __FAWreg __attribute__ ((section (".ofs6"))) = 0xffffffff;

/**
 * @brief RCP register
 * 
 */
const unsigned long __RCPreg __attribute__ ((section (".ofs7"))) = 0xffffffff;
