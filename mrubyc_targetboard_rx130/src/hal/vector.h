/**
 * @file vector.h
 * @author nizuki926
 * @brief interrupt vector and exception vector setting header file
 * @version 1.0
 * @date 2019-02-03
 * 
 * @copyright Copyright (c) 2019, nizuki926 All rights reserved.
 * 
 */

#ifndef VECTOR_H_
#define VECTOR_H_

/**
 * @brief number of interrupt vector
 * 
 */
#define INT_VECTOR_NUMBER (256)

/**
 * @brief number of exception vector
 * 
 */
#define EXCEP_VECTOR_NUMBER (5)

void int_initialize (void);
void excep_initialize (void);
void int_regist (unsigned int vect_number, void (*func) (void));
void excep_regist (unsigned int excep_number, void (*func) (void));

#endif /* VECTOR_H_ */
