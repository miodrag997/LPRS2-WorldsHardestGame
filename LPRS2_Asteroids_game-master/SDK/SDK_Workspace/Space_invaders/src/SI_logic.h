/*
 * SI_logic.h
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#ifndef SI_LOGIC_H_
#define SI_LOGIC_H_

#include "SI_defines.h"
#include "SI_globals.h"
#include "SI_draw.h"
#include "SI_interrupt.h"

void draw_level_zero();
void enemy_moving_level_zero(int *cube_x, int *cube_y, int *enemy_x, int *enemy_y, int *level_frame_border);
void draw_level_one();
void main_level_zero();
void main_level_one();


/*
 * generate_field , generate_player , fire_shot , destroy_asteriod , destroy_player , get_player_angle
 *
 * */



#endif /* SI_LOGIC_H_ */
