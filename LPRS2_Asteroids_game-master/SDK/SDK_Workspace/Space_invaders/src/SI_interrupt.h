/*
 * SI_init.h
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#ifndef SI_INIT_H_
#define SI_INIT_H_

#include "SI_globals.h"
#include "SI_defines.h"
#include <stdlib.h>
#include <time.h>

void init_interrupt_controller();

void before_drawing(void);
void after_drawing(void);

#endif /* SI_INIT_H_ */
