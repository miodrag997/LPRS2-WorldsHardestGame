/*
 * SI_logic.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_logic.h"

//i = y
//j = x
#define left_border 1
#define top_border 2
#define endpoint 3
#define right_border 4
#define enemy 5
#define base 6
#define bottom_border 7
#define fill 8
#define cube 9
#define right_top 10
#define right_bottom 11
#define left_bottom 12
#define left_top 13
//10-corner bl
//11-corner bt
//12-corner rt
//13-corner rb

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw_level(Xuint8 *current_level){
	int i, j;
	for(i = 0; i < 60; i++){
		for(j = 0; j < 80; j++){

			if(*(current_level + i*80 + j)==0 || *(current_level + i*80 + j)==4){								//////////two
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, fillMe, 'j');
			}
			if(*(current_level + i*80 + j)==1){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, border_bitmap, 'k');
			}
			if(*(current_level + i*80 + j)==2){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, base_bitmap, 'k');
			}
			if(*(current_level + i*80 + j)==3){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, endpoint_bitmap, 'k');
			}
			if(*(current_level + i*80 + j)==5){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, key_bitmap, 'k');
			}
			if(*(current_level + i*80 + j)==6){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, gate_bitmap, 'k');
			}

		}
	}
}


void enemy_moving(struct Enemy *enemy_curr_level, int numOfEnemy, int cube_x, int cube_y, int cube_x_old, int cube_y_old, Xuint8 *curr_level){
	int i;
	if(enemy_curr_level[0].begin_x == enemy_curr_level[0].end_x && enemy_curr_level[0].begin_y == enemy_curr_level[0].end_y){
		for (i = 0; i < numOfEnemy; i++){
			int t = 0;
			if(enemy_curr_level[i].curr_x == cube_x && enemy_curr_level[i].curr_y == cube_y){
				t++;
			}
			erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_curr_level[i].curr_x, enemy_curr_level[i].curr_y);
			
			if(enemy_curr_level[i].dir_x == 1){
				enemy_curr_level[i].curr_x += enemy_curr_level[i].dir_x;
				if (*(curr_level + enemy_curr_level[i].curr_y*80 + enemy_curr_level[i].curr_x + 1) == 1){
					enemy_curr_level[i].dir_x = 0;
					enemy_curr_level[i].dir_y = 1;
				}
			}else if (enemy_curr_level[i].dir_x == -1){
				enemy_curr_level[i].curr_x += enemy_curr_level[i].dir_x;
				if (*(curr_level + enemy_curr_level[i].curr_y*80 + enemy_curr_level[i].curr_x - 1) == 1){
					enemy_curr_level[i].dir_x = 0;
					enemy_curr_level[i].dir_y = -1;
				}

			}else if (enemy_curr_level[i].dir_y == 1){
				enemy_curr_level[i].curr_y += enemy_curr_level[i].dir_y;
				if (*(curr_level + (enemy_curr_level[i].curr_y+1)*80 + enemy_curr_level[i].curr_x) == 1){
					enemy_curr_level[i].dir_x = -1;
					enemy_curr_level[i].dir_y = 0;
				}
			}else if (enemy_curr_level[i].dir_y == -1){
				enemy_curr_level[i].curr_y += enemy_curr_level[i].dir_y;
				if (*(curr_level + (enemy_curr_level[i].curr_y-1)*80 + enemy_curr_level[i].curr_x) == 1){
					enemy_curr_level[i].dir_x = 1;
					enemy_curr_level[i].dir_y = 0;
				}
			}
			
			if(enemy_curr_level[i].curr_x == cube_x && enemy_curr_level[i].curr_y == cube_y){
				fails++;
			}
			if(enemy_curr_level[i].curr_x == cube_x_old && enemy_curr_level[i].curr_y == cube_y_old && t == 1){
				fails++;
			}
		}
	}else{

		for (i = 0; i < numOfEnemy; i++){
			int t = 0;
			if(enemy_curr_level[i].curr_x == cube_x && enemy_curr_level[i].curr_y == cube_y){
				t++;
			}
			erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_curr_level[i].curr_x, enemy_curr_level[i].curr_y);
			
			if(enemy_curr_level[i].dir_x == 1){
				enemy_curr_level[i].curr_x += enemy_curr_level[i].dir_x;
				if (enemy_curr_level[i].curr_x == enemy_curr_level[i].end_x){
					enemy_curr_level[i].dir_x = -1;
				}
			}else if (enemy_curr_level[i].dir_x == -1){
				enemy_curr_level[i].curr_x += enemy_curr_level[i].dir_x;
				if (enemy_curr_level[i].curr_x == enemy_curr_level[i].begin_x){
					enemy_curr_level[i].dir_x = 1;
				}

			}else if (enemy_curr_level[i].dir_y == 1){
				enemy_curr_level[i].curr_y += enemy_curr_level[i].dir_y;
				if (enemy_curr_level[i].curr_y == enemy_curr_level[i].end_y){
					enemy_curr_level[i].dir_y = -1;
				}
			}else if (enemy_curr_level[i].dir_y == -1){
				enemy_curr_level[i].curr_y += enemy_curr_level[i].dir_y;
				if(enemy_curr_level[i].curr_y == enemy_curr_level[i].begin_y){
					enemy_curr_level[i].dir_y = 1;
				}
			}
			
			if(enemy_curr_level[i].curr_x == cube_x && enemy_curr_level[i].curr_y == cube_y){
				fails++;
			}
			if(enemy_curr_level[i].curr_x == cube_x_old && enemy_curr_level[i].curr_y == cube_y_old && t == 1){
				fails++;
			}
		}

	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
void main_level(int level){

	int cube_x, old_cube_x;
	int cube_y, old_cube_y;
	int i=0;
	int numberOfEnemy = 0;
	int numberOfFriends = 0;
	int numberOfStationaryEnemies = 0;
	Xuint8 *current_level;
	struct Enemy *curr_enemy_level;
	int fails_old = 0;
	int start_cube_x, start_cube_y;

	// player coordinates
	//level = 4;


	if(level==1){////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cube_x = start_cube_x = 16;
		cube_y = start_cube_y = 30;
		numberOfEnemy=15;
		numberOfStationaryEnemies = 0;
		numberOfFriends=0;
		current_level = &level_1[0][0];
		curr_enemy_level = enemy_level1;
	}
	else if(level==2){
		cube_x = start_cube_x = 15;
		cube_y = start_cube_y = 22;
		numberOfEnemy=37;
		numberOfStationaryEnemies = 0;
		numberOfFriends=0;
		current_level = &level_2[0][0];
		curr_enemy_level = enemy_level2;
	}
	else if(level == 3){
		cube_x = start_cube_x = 36;
		cube_y = start_cube_y = 30;
		numberOfEnemy=38;
		numberOfStationaryEnemies = 0;
		numberOfFriends=0;
		current_level = &level_3[0][0];
		curr_enemy_level = enemy_level3;
	}
	else if(level == 4){
		cube_x = start_cube_x = 10;
		cube_y = start_cube_y = 18;
		numberOfEnemy=62;
		numberOfStationaryEnemies = 0;
		numberOfFriends=0;
		current_level = &level_4[0][0];
		curr_enemy_level = enemy_level4;
	}
	/* variables */
	char* str = NULL;

	// PRINT LEVEL
	set_cursor(666);
	clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
	print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "LEVEL", strlen("LEVEL"));

	set_cursor(688);
	num_to_str(str, level, num_len(level));
	print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

	// PRINT FAILS
	set_cursor(751);
	print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, "FAILS", strlen("FAILS"));


	set_cursor(773);
	num_to_str(str, fails, num_len(fails));
	print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));



	clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);

	u32 frame_cnt = 0;
  	while(1){

  		// PRINT FAILS
  		before_drawing();
		set_cursor(773);
		num_to_str(str, fails, num_len(fails));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		// PRINT LEVEL
		set_cursor(688);
		num_to_str(str, level, num_len(level));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		old_cube_x = cube_x;
		old_cube_y = cube_y;

		// Get controls.
		u8 input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);

		// Update gameplay.
		// Check controls.

		if(frame_cnt % 3 == 0){
			switch(input){
			case RIGHT_JOY:
				if(*(current_level + cube_y*80 + cube_x +1)!=1 && *(current_level + cube_y*80 + cube_x +1)!=6)
					cube_x++;
				break;
			case LEFT_JOY:
				if(*(current_level + cube_y*80 + cube_x - 1)!=1 && *(current_level + cube_y*80 + cube_x -1)!=6)
					cube_x--;
				break;
			case UP_JOY:
				if(*(current_level + (cube_y+1)*80 + cube_x)!=1 && *(current_level + (cube_y+1)*80 + cube_x)!=6)
					cube_y++;
				break;
			case DOWN_JOY:
				if(*(current_level + (cube_y-1)*80 + cube_x)!=1 && *(current_level + (cube_y-1)*80 + cube_x)!=6)
					cube_y--;
				break;
			default:
				break;
			}

			// TODO Animations.
			enemy_moving(curr_enemy_level, numberOfEnemy, cube_x, cube_y,old_cube_x ,old_cube_y , current_level);
			if(fails != fails_old){
				fails_old = fails;
				cube_x = start_cube_x;
				cube_y = start_cube_y;
			}

		}
		if (level == 2){

			if (*(current_level + cube_y*80 + cube_x) == 5 || *(current_level + cube_y*80 + cube_x) == 7){
				*(current_level + cube_y*80 + cube_x) = 0;

				if(*(current_level + 31*80 + 28) == 6){
					erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 28, 30);
					erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 28, 31);
					*(current_level + 30*80 + 28) = 0;
					*(current_level + 31*80 + 28) = 0;
				}else{
					erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 46, 33);
					erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 46, 34);
					*(current_level + 33*80 + 46) = 0;
					*(current_level + 34*80 + 46) = 0;
				}

			}
		}else if(level == 3){
			if (*(current_level + cube_y*80 + cube_x) == 5){
				*(current_level + cube_y*80 + cube_x) = 0;
				erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 41, 31);
				*(current_level + 31*80 + 41) = 0;
			}
		}
		// Drawing.



		if(cube_x != old_cube_x || cube_y != old_cube_y){
			erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, old_cube_x, old_cube_y);
		}

		draw_level(current_level);

		// TODO Enemies.
		for(i = 0; i < numberOfStationaryEnemies; i++){

		}

		for(i = 0; i < numberOfEnemy; i++){
			 if(level==1){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_level1[i].curr_x, enemy_level1[i].curr_y, enemy_bitmap, 'e');
			}
			 if(level==2){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_level2[i].curr_x, enemy_level2[i].curr_y, enemy_bitmap, 'e');
			}
			 if(level==3){
			 	draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_level3[i].curr_x, enemy_level3[i].curr_y, enemy_bitmap, 'e');
			 }
			 if(level==4){
				 draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_level4[i].curr_x, enemy_level4[i].curr_y, enemy_bitmap, 'e');

			 }

		}

		draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, cube_x, cube_y, cube_bitmap, 'k');

		after_drawing();

  		frame_cnt++;


  		/* End level */

		if(level==1 || level == 2 || level == 3 || level==4){
			if(*(current_level + cube_y*80 + cube_x) == 3) {
				level++;
				break;
			}
		}

	}
}
