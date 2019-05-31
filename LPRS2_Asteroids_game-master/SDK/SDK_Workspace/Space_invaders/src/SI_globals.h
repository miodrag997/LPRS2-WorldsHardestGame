/*
 * SI_globals.h
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#ifndef SI_GLOBALS_H_
#define SI_GLOBALS_H_

#include "SI_defines.h"

/* variables for interrupts */
extern XIntc Intc;

extern  Xuint8	spaceship_speed,
		spaceship_speed_cnt,
		spaceship_x,
		projectil_speed,
		invader_speed,
		spaceship_flag,
		projectil_flag,
		shoot_flag,
		invader_shoot_flag,
		move_faster,
		print_level,
		counter,
		game_over,
		lives,
		points,
		seed,
		input;

extern Xuint8 flag_row[INIT_ROWS];

extern struct asteroids_info {
	Xuint8 Y_coordinate,
			X_coordinate,
			asteroid_speed,
			asteroid_direction,
			type,
			id;
};

extern struct bullet{
	Xuint8 bullet_dir,
			bullet_X,
			bullet_Y,
			is_Bullet;
};

extern struct Enemy{
	unsigned int begin_x;
	unsigned int begin_y;
	unsigned int end_x;
	unsigned int end_y;
	unsigned int curr_x;
	unsigned int curr_y;
	int dir;
};

/****************************/

/* main variables/maps */
extern Xuint8 invaders_map[MAX_PROJECTILES_X][MAX_PROJECTILES_Y];
extern Xuint8 invaders_num;

extern Xuint8 projectiles_of_ship_num[MAX_PROJECTILES_X];	//Number of projectiles in column
extern Xuint8 projectiles_of_invaders_num[MAX_PROJECTILES_X];
extern Xuint8 projectiles_map[MAX_PROJECTILES_X][MAX_PROJECTILES_Y];



/****************************/

extern Xuint8 fails;

extern Xuint32 cursor_position;
extern Xuint8 level_1[LEVEL_Y_SIZE][LEVEL_X_SIZE];
extern Xuint8 level_2[LEVEL_Y_SIZE][LEVEL_X_SIZE];

extern struct Enemy enemy_level1[15];

extern Xuint32 enemy_bitmap[8][3];
extern Xuint32 cube_bitmap[8][3];
extern Xuint32 base_bitmap[8][3];
extern Xuint32 endpoint_bitmap[8][3];
extern Xuint32 border_bitmap[8][3];
extern Xuint32 key_bitmap[8][3];
extern Xuint32 gate_bitmap[8][3];

extern Xuint32 border_vertical_bottom[8][3];
extern Xuint32 border_vertical_top[8][3];

extern Xuint32 border_vertical_right[8][3];
extern Xuint32 border_vertical_left[8][3];


extern Xuint32 cornerrb[8][3];
extern Xuint32 cornerrt[8][3];

extern Xuint32 cornerlb[8][3];
extern Xuint32 cornerlt[8][3];
extern Xuint32 fillMe[8][3];
extern Xuint32 friend_bitmap[8][3];



#endif /* SI_GLOBALS_H_ */
