/*
 * SI_logic.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_logic.h"

 int enemy_x[3] = {50,30,40};
 int enemy_y[3] = {40,20,30};

 	 	 	 	 	 	 	 	 	 	           //49-38(12)							//38-23 22
 int enemy_x_one[39] = {60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20};																						///////////////////////////////////////////
 int enemy_y_one[39] = {39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39,21,39};


 void init_level_zero(){
	int i, j;

	for(i = 0; i < 60; i++){
		for(j = 0; j < 80; j++){
			level_zero[j][i]=0;
			if(j == 10 && i >= 17 && i <= 45){
				level_zero[j][i]=1;//l
			}
			if(j == 70 && i >= 17 && i <= 45){
				level_zero[j][i]=4;//r
			}
			if(i == 16 && j >= 12 && j <= 68){
				level_zero[j][i]=2; //top
			}
			if(i == 46 && j >= 12 && j <= 68){
				level_zero[j][i]=7; //bottom
			}
			if(j >=11 && j <= 20 && i >= 17 && i <= 45){
				level_zero[j][i]=6; //draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, base, 'k');
			}
			if(j >=20 && j <= 60 && i >= 17 && i <= 45){
				level_zero[j][i]=8; // inner fill
			}
			if(j >= 60 && j <= 69 && i >= 17 && i <= 45){
				level_zero[j][i]=3; //draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, endpoint, 'k');
			}
		}
	}

 }



void init_level_one(){
	int i, j;

	for(i = 0; i < 60; i++){
		for(j = 0; j < 80; j++){
			level_zero[j][i]=0;
			//i = y
			//j = x
			//1-left
			//2-top
			//3-endpoint
			//4-right
			//5-enemy
			//6-base
			//7-bottom
			//8-fill
			//9-cube
			//10-corner bl
			//11-corner bt
			//12-corner rt
			//13-corner rb
			if(j == 9 && i >= 26 && i <= 34){
				level_zero[j][i]=1;
			}
			if(j == 18 && i >= 20 && i <= 24){
				level_zero[j][i]=1; //levi deo gornjeg ugla odzdo gledajuci
			}

			if(j == 18 && i >= 36 && i <= 40){
				level_zero[j][i]=1;
			}
			if(i == 25 && j >= 11 && j <= 16){
				level_zero[j][i]=2;
			}
			if(i == 35 && j >= 11 && j <= 16){
				level_zero[j][i]=7;
			}
			if(j == 62 && i >= 20 && i <= 24){
				level_zero[j][i]=4;
			}
			if(j == 62 && i >= 36 && i <= 40){
				level_zero[j][i]=4;
			}
			if(i == 25 && j >= 64 && j <= 69){
				level_zero[j][i]=2;
			}
			if(i == 35 && j >= 64 && j <= 69){
				level_zero[j][i]=7;
			}
			if(j == 71 && i >= 26 && i <= 34){
				level_zero[j][i]=4;
			}
			if(i == 19 && j >= 20 && j < 61){
				level_zero[j][i]=2;
			}
			if(i == 41 && j >= 20 && j < 61){
				level_zero[j][i]=7;
			}
			if(j >=10 && j <= 18 && i >= 26 && i <= 34){
				level_zero[j][i]=6;//begin
			}
			if(j >= 62 && j <= 70 && i >= 26 && i <= 34){
				level_zero[j][i]=3;//end
			}
				//videti granice za base end i za fill(verovatno nevalja)
			if(j >=19 && j <= 61 && i > 19 && i < 41){//61
				level_zero[j][i]=8; // inner fill
			}


			if(j == 18 && i == 35){
				level_zero[j][i]=10;//bl
			}
			if(j == 18 && i == 25){
				level_zero[j][i]=11;//bt
			}

			if(j == 62 && i == 25){
				level_zero[j][i]=12;//rt
			}
			if(j == 62 && i == 35){
				level_zero[j][i]=13;
			}
		}
	}

}



void enemy_moving_level_zero(int *cube_x, int *cube_y, int *enemy_x, int *enemy_y, int *level_frame_border){

	if(*level_frame_border == 0){
				if(*enemy_y == 18){
					*level_frame_border = 1;
				}
				erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x, *enemy_y);
				if(*cube_x == *enemy_x && *cube_y == *enemy_y){
					*cube_x=15;
					*cube_y=30;

					fails++;
				}
				(*enemy_y)--;
			}else if(*level_frame_border == 1){
				if(*enemy_y == 44){
					*level_frame_border = 0;
				}
				erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x, *enemy_y);
				if(*cube_x == *enemy_x && *cube_y == *enemy_y){
					*cube_x=15;
					*cube_y=30;

					fails++;
				}
				(*enemy_y)++;
			}

}


void enemy_moving_level_one(int *cube_x, int *cube_y, int *enemy_x_one, int *enemy_y_one, int *level_frame_border_one){

	if(*level_frame_border_one == 0){
				if(*enemy_y_one == 21){
					*level_frame_border_one = 1;
				}
				erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x_one, *enemy_y_one);
				if(*cube_x == *enemy_x_one && *cube_y == *enemy_y_one){
					*cube_x=15;
					*cube_y=30;

					fails++;
				}
				(*enemy_y_one)--;
			}else if(*level_frame_border_one == 1){
				if(*enemy_y_one == 39){
					*level_frame_border_one = 0;
				}
				erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x_one, *enemy_y_one);
				if(*cube_x == *enemy_x_one && *cube_y == *enemy_y_one){
					*cube_x=15;
					*cube_y=30;

					fails++;
				}
				(*enemy_y_one)++;
			}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int friend_x_two[4] = {20,63,16,59};
int friend_y_two[4] = {13,16,43,46};

int enemy_x_two[22] = {20,22,20,22,20,22,20,22,20,22,20, 59,61,59,61,59,61,59,61,59,61,59};
int enemy_y_two[22] = {18,20,22,24,26,28,32,34,36,38,40, 18,20,22,24,26,28,32,34,36,38,40};
int enemy_x_two_static[64] = {23,23, 25,25, 27,27, 29,29, 31,31, 33,33, 35,35, 37,37,
							  43,43, 45,45, 47,47, 49,49, 51,51, 53,53, 55,55, 57,57,

							  23,23, 25,25, 27,27, 29,29, 31,31, 33,33, 35,35, 37,37,
							  43,43, 45,45, 47,47, 49,49, 51,51, 53,53, 55,55, 57,57};
int enemy_y_two_static[64] = {17,16, 15,16, 17,16, 15,16, 17,16, 15,16, 17,16, 15,16,
							  17,16, 15,16, 17,16, 15,16, 17,16, 15,16, 17,16, 15,16,

							  42,43, 44,43, 42,43, 44,43, 42,43, 44,43, 42,43, 44,43,
							  42,43, 44,43, 42,43, 44,43, 42,43, 44,43, 42,43, 44,43};

void init_level_two(){
	int i, j;

	// Filling map matrix.
	//TODO Do it just once on the start.  left_top_corner
	//TODO Empty to corners.
	for(i = 0; i < 60; i++){
		for(j = 0; j < 80; j++){
			level_zero[j][i]=0;
			//i = y
			//j = x
			//1-left
			//2-top
			//3-endpoint
			//4-right
			//5-enemy
			//6-base
			//7-bottom
			//8-fill
			//9-cube
			//10-corner bl
			//11-corner bt
			//12-corner rt
			//13-corner rb
			if((i == 14 && j >= 25 && j <= 64)||(i == 41 && j == 16)||(i == 11 && j >= 20 && j<=21)){
				level_zero[j][i]=2;//top
			}
			if((i == 45 && j >= 16 && j <= 55)||(i == 18 && j == 64)||(i == 48 && j >= 59 && j <= 60)){
				level_zero[j][i]=7;//bottom
			}
			if((j == 18 && i >= 12 && i <= 40)||(j == 57 && i >= 46 && i <= 47)||(j == 14 && i >= 42 && i <= 44)){
				level_zero[j][i]=1;//left
			}
			if((j == 62 && i >= 19 && i <= 47)||(j == 66 && i >= 15 && i <= 17)||(j == 23 && i >= 12 && i <= 13)){
				level_zero[j][i]=4;//right
			}

			if(j == 57 && i == 45){
				level_zero[j][i]=10;//donji desni
			}
			if(j == 18 && i == 41){
				level_zero[j][i]=11;//doljni levi
			}
			if(j == 23 && i == 14){
				level_zero[j][i]=12;//gornji levi
			}
			if(j == 62 && i == 18){
				level_zero[j][i]=13;//gornji desni cosak
			}

			if((i >= 15 && i<=17 && j >= 22 && j <= 65)||(i >= 12 && i<=44 && j >= 19 && j <= 22)||(i >= 42 && i<=44 && j >= 15 && j <= 60)||(i >= 17 && i<=47 && j >= 58 && j <= 61)){
				level_zero[j][i]=8;
			}

			if((i == 18 && j >= 25 && j <= 55)||(i == 32 && j >= 25 && j <= 55)){
				level_zero[j][i]=7;//ne moze od gore
			}
			if((i == 41 && j >= 25 && j <= 55)||(i == 28 && j >= 25 && j <= 55)){
				level_zero[j][i]=2;//ne moze od dole
			}
			if((j == 23 && i >= 19 && i <= 27)||(j == 23 && i >= 33 && i <= 40)){
				level_zero[j][i]=4;//leva crta
			}
			if((j == 57 && i >= 19 && i <= 27)||(j == 57 && i >= 33 && i <= 40)){//j=56
				level_zero[j][i]=1;//desna crta
			}

			if((j == 57 && i == 18)||(j == 57 && i == 32)){
				level_zero[j][i]=10;//donji desni
			}
			if((j == 23 && i == 28)||(j == 23 && i == 41)){
				level_zero[j][i]=12;//gornji levi
			}
			if((j == 57 && i == 28)||(j == 57 && i == 41)){
				level_zero[j][i]=11;//doljni levi
			}
			if((j == 23 && i == 18)||(j == 23 && i == 32)){
				level_zero[j][i]=13;//gornji desni cosak
			}

			if((i >= 29 && i<=31 && j > 23 && j < 57)){
				level_zero[j][i]=6;
			}
			if((i >= 29 && i<=31 && (j == 23 || j == 57))){
				level_zero[j][i]=3;
			}

		}
	}

}

void draw_level_two(){
	int i, j;
	for(i = 0; i < 60; i++){
		for(j = 0; j < 80; j++){
			if(level_zero[j][i]==1){								//////////two
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, border_vertical_left, 'l');
			}
			if(level_zero[j][i]==4){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, border_vertical_right, 'r');
			}
			if(level_zero[j][i]==2){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, border_vertical_top, 't');
			}
			if(level_zero[j][i]==7){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, border_vertical_bottom, 'b');
			}
			if(level_zero[j][i]==9){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, cube, 'p');
			}
			if(level_zero[j][i]==6){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, base, 'k');
			}
			if(level_zero[j][i]==3){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, endpoint, 'k');
			}
			if(level_zero[j][i]==10){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, cornerlb, 'l');
			}
			if(level_zero[j][i]==11){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, cornerlt, 'l');
			}
			if(level_zero[j][i]==12){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, cornerrt, 'r');
			}
			if(level_zero[j][i]==13){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, cornerrb, 'r');
			}
			/*if(level_two[j][i]==8){
				//draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, j, i, endpoint, 't');
			}*/
		}
	}
}

void enemy_moving_level_two(int *cube_x, int *cube_y, int *enemy_x_two, int *enemy_y_two, int *level_frame_border_two){

	if(*level_frame_border_two == 0){
		if(*enemy_x_two == 20 || *enemy_x_two == 59){
			*level_frame_border_two = 1;
		}
		erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x_two, *enemy_y_two);
		if(*cube_x == *enemy_x_two && *cube_y == *enemy_y_two){
			*cube_x=40;
			*cube_y=30;
			fails++;
		}
		(*enemy_x_two)--;					//dole
	}else if(*level_frame_border_two == 1){
		if(*enemy_x_two == 21|| *enemy_x_two == 60){
			*level_frame_border_two = 0;
		}
		erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, *enemy_x_two, *enemy_y_two);
		if(*cube_x == *enemy_x_two && *cube_y == *enemy_y_two){
			*cube_x=40;
			*cube_y=30;

			fails++;
		}
		(*enemy_x_two)++;				//
	}
}


//////////////////////////////////////////////////////////////////////////////
void main_level(){

	int cube_x;
	int cube_y;
	int i=0;
	int numberOfEnemy;
	int numberOfFriends;
	int numberOfStationaryEnemies;
	// player coordinates
	if(level==0){////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cube_x = 15;
		cube_y = 30;
		numberOfEnemy=3;
		numberOfStationaryEnemies = 0;
	}
	else if(level==1){
		cube_x = 15;
		cube_y = 30;
		numberOfEnemy=39;
		numberOfStationaryEnemies = 0;
	}
	else if(level==2){
		cube_x = 40;
		cube_y = 30;
		numberOfEnemy=22;
		numberOfStationaryEnemies = 64;
		numberOfFriends=4;
	}
	/* variables */
	char* str = NULL;
	int level_frame_border[numberOfEnemy];
	for(i=0;i<numberOfEnemy;i++){
		level_frame_border[i]=0;
	}



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


	if(level==0){//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		init_level_zero();
	}
	else if(level==1){//stavi 1 kasnije
		init_level_one();
	}
	else if(level==2){//2
		init_level_two();
	}

	u32 frame_cnt = 0;
  	while(1){
  		// PRINT FAILS
		set_cursor(773);
		num_to_str(str, fails, num_len(fails));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		// PRINT LEVEL
		set_cursor(688);
		num_to_str(str, level, num_len(level));
		print_string(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, str, strlen(str));

		int old_cube_x;
		int old_cube_y;

		old_cube_x = cube_x;
		old_cube_y = cube_y;

		// Get controls.
		u8 input = VGA_PERIPH_MEM_mReadMemory(XPAR_MY_PERIPHERAL_0_BASEADDR);

		// Update gameplay.
		// Check controls.
		if(frame_cnt % 2 == 0){
			switch(input){
			case RIGHT_JOY:
				if(!(level_zero[cube_x-1][cube_y]==1) && (level_zero[cube_x-1][cube_y] != 0)&&(level_zero[cube_x-1][cube_y]!=10)&&(level_zero[cube_x-1][cube_y]!=11)&&(level_zero[cube_x-1][cube_y]!=12)&&(level_zero[cube_x-1][cube_y]!=13)) cube_x--;
				break;
			case LEFT_JOY:
				if(!(level_zero[cube_x+1][cube_y]==4) && (level_zero[cube_x+1][cube_y] != 0)&&(level_zero[cube_x+1][cube_y]!=10)&&(level_zero[cube_x+1][cube_y]!=11)&&(level_zero[cube_x+1][cube_y]!=12)&&(level_zero[cube_x+1][cube_y]!=13)) cube_x++;
				break;
			case UP_JOY:
				if(!(level_zero[cube_x][cube_y-1]==2) && (level_zero[cube_x][cube_y-1] != 0)&&(level_zero[cube_x][cube_y-1]!=10)&&(level_zero[cube_x][cube_y-1]!=11)&&(level_zero[cube_x][cube_y-1]!=12)&&(level_zero[cube_x][cube_y-1]!=13)) cube_y--;
				break;
			case DOWN_JOY:
				if(!(level_zero[cube_x][cube_y+1]==7) && (level_zero[cube_x][cube_y+1] != 0)&&(level_zero[cube_x][cube_y+1]!=10)&&(level_zero[cube_x][cube_y+1]!=11)&&(level_zero[cube_x][cube_y+1]!=12)&&(level_zero[cube_x][cube_y+1]!=13)) cube_y++;
				break;
			default:
				break;
			}

			// TODO Animations.

			if(level==0){
				for(i = 0; i < numberOfEnemy; i++){
					enemy_moving_level_zero(&cube_x, &cube_y, &enemy_x[i], &enemy_y[i], &level_frame_border[i]);
				}
			}
			else if(level==1){
				for(i = 0; i < numberOfEnemy; i++){
					enemy_moving_level_one(&cube_x, &cube_y, &enemy_x_one[i], &enemy_y_one[i], &level_frame_border[i]);
				}
			}
			else if(level==2){
				for(i = 0; i < numberOfEnemy; i++){
					enemy_moving_level_two(&cube_x, &cube_y, &enemy_x_two[i], &enemy_y_two[i], &level_frame_border[i]);//////////////////////two
				}

			}

		}

		// Drawing.

  		before_drawing();

		if(cube_x != old_cube_x || cube_y != old_cube_y){
			erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, old_cube_x, old_cube_y);
		}


		draw_level_two();

		if(level==2){
			for(i = 0; i < numberOfFriends; i++){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, friend_x_two[i], friend_y_two[i], friend, 'e');
				if(cube_x == friend_x_two[i] && cube_y == friend_y_two[i]){
					friend_x_two[i]=65+points*2;
					friend_y_two[i]=2;
					points++;
				}
			}
		}

		// TODO Enemies.
		int j=0;

		for(i = 0; i < numberOfStationaryEnemies; i++){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_x_two_static[i], enemy_y_two_static[i], enemy, 'e');
		}

		for(i = 0; i < numberOfEnemy; i++){
			if(level==0){//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_x[i], enemy_y[i], enemy, 'e');
				if(cube_x==enemy_x[i] && cube_y==enemy_y[i]){
					cube_x=15;
					cube_y=30;

					fails++;
				}
			}
			else if(level==1){
				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_x_one[i], enemy_y_one[i], enemy, 'e');
				if(cube_x==enemy_x_one[i] && cube_y==enemy_y_one[i]){
					cube_x=15;
					cube_y=30;
					fails++;
				}
			}
			else if(level==2){

				draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, enemy_x_two[i], enemy_y_two[i], enemy, 'e');
				if((cube_x==enemy_x_two[i] && cube_y==enemy_y_two[i])){

					for(j=1;j<5;j++){
						erase_square(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, 63+j*2, 2);
					}

					points=0;

					friend_x_two[0] = 20;
					friend_x_two[1] = 63;
					friend_x_two[2] = 16;
					friend_x_two[3] = 59;																								///////////////////////////////////////////

					friend_y_two[0] = 13;
					friend_y_two[1] = 16;
					friend_y_two[2] = 43;
					friend_y_two[3] = 46;

					cube_x=40;
					cube_y=30;
					fails++;
				}
			}
		}

		draw_bitmap(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR, cube_x, cube_y, cube, 'p');

		after_drawing();

  		frame_cnt++;


  		/* End level */

		if(level==0 || level==1){
			if(level_zero[cube_x][cube_y] == 3) {
				level++;
				break;
			}
		}
		else if(level==2){
			if(level_zero[cube_x][cube_y] == 3 && points==4) {
				level++;
				break;
			}
		}
	}
}
