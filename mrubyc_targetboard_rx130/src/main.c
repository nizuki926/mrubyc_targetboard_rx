/**
 * @file main.c
 * @author nizuki926
 * @brief main program
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */
#include "hal/clock.h"
#include "hal/vector.h"
#include "mrubyc.h"

#define PORTD_PDR (*(char *)0x0008C00D)
#define PORTD_PODR (*(char *)0x0008C02D)
#define	PORTB_PIDR (*(char *)0x0008C04B)
#define SW1 ((PORTB_PIDR >> 1) & 0x01)

#define MEMORY_SIZE (1024*10)
static char memory_pool[MEMORY_SIZE];

extern char sample01[];

static void c_sw1_read(mrb_vm * vm, mrb_value * v)
{
	SET_INT_RETURN(SW1);
}

static void c_led1_write(mrb_vm * vm, mrb_value * v)
{
	if (1 == GET_INT_ARG(1))
	{
		PORTD_PODR = (PORTD_PODR & ~(0x01 << 7));
	}
	else
	{
		PORTD_PODR = (PORTD_PODR | (0x01 << 7));
	}
}

int hal_write(int fd, const void * buf, int nbytes)
{
	return 0;
}

int hal_flush(int fd)
{
	return 0;
}

/**
 * @brief mruby/c initialize routine
 * 
 */
int main (void)
{
	int_initialize();
	excep_initialize();
	hardware_setup();
	PORTD_PDR = (PORTD_PDR | (0x01 << 7));

	mrbc_init(memory_pool, MEMORY_SIZE);
	mrbc_define_method(0, mrbc_class_object, "sw1_read", (mrbc_func_t)c_sw1_read);
	mrbc_define_method(0, mrbc_class_object, "led1_write", (mrbc_func_t)c_led1_write);

	mrbc_create_task(sample01, 0);
	mrbc_run();

	while(1)
	{
		/* do nothing */
	}

    return 0;
}
