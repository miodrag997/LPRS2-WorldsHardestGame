
/*
 * SI_main.c
 *
 *  Created on: 16.06.2015.
 *      Authors: Standzi, Marko, Dva geja (Urosko i Milan GAY)
 */

#include "SI_logic.h"
#include "SI_interrupt.h"
#include "SI_globals.h"
#include <stdlib.h>



 Xuint32 border_vertical_left[8][3]=
  {
  {0x00000000 ,0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033}
  };


 Xuint32 cornerlt[8][3]=
  {
  {0x00000000 ,0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x33333333}
  };


 Xuint32 cornerlb[8][3]=
  {
  {0x00000000 ,0x00000000, 0x33333333},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033},
  {0x00000000, 0x00000000, 0x00000033}
  };


 Xuint32 cornerrt[8][3]=
  {
  {0x33000000 ,0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33333333, 0x00000000, 0x00000000}
  };


 Xuint32 cornerrb[8][3]=
  {
  {0x33333333 ,0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000}
  };

 Xuint32 border_vertical_right[8][3]=
  {
  {0x33000000 ,0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000},
  {0x33000000, 0x00000000, 0x00000000}
  };
  
 Xuint32 border_vertical_top[8][3]=
  {
  {0x00000000 ,0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x33333333, 0x33333333, 0x33333333}
  };
  
 Xuint32 border_vertical_bottom[8][3]=
  {
  {0x33333333 ,0x33333333, 0x33333333},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000},
  {0x00000000, 0x00000000, 0x00000000}
  };

 Xuint32 base[8][3]=
  {
  {0x44444444 ,0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444},
  {0x44444444, 0x44444444, 0x44444444}
  };
  
 Xuint32 endpoint[8][3]=
  {
  {0x55555555 ,0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555},
  {0x55555555, 0x55555555, 0x55555555}
  };
  
 Xuint32 cube[8][3]=
 {
 {0x00000000,0x77777777,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x78888887,0x00000000},
 {0x00000000,0x77777777,0x00000000}
 };

 Xuint32 enemy[8][3]=
 {
 {0x00000000,0x00999900,0x00000000},
 {0x00000000,0x09666690,0x00000000},
 {0x00000000,0x96666669,0x00000000},
 {0x00000000,0x96666669,0x00000000},
 {0x00000000,0x96666669,0x00000000},
 {0x00000000,0x96666669,0x00000000},
 {0x00000000,0x09666690,0x00000000},
 {0x00000000,0x00999900,0x00000000}
 };
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 //////////////////////////////////////
 Xuint32 friend[8][3]=
 {
 {0x00000000,0x00999900,0x00000000},
 {0x00000000,0x09eeee90,0x00000000},
 {0x00000000,0x9eeeeee9,0x00000000},
 {0x00000000,0x9eeeeee9,0x00000000},
 {0x00000000,0x9eeeeee9,0x00000000},
 {0x00000000,0x9eeeeee9,0x00000000},
 {0x00000000,0x09eeee90,0x00000000},
 {0x00000000,0x00999900,0x00000000}
 };

 Xuint32 fillMe[8][3]=
 {
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee},
 {0x00000000,0xffffffff,0xeeeeeeee}
 };

 void init_gpu();
 void init_colors();
 void clear_text_screen(Xuint32 BaseAddress);
 void set_cursor(Xuint32 new_value);
 void print_string(Xuint32 BaseAddress, char string_s[], int lenght);
 void num_to_str(char *s, unsigned long bin, unsigned char n);
 int num_len(int num);
 void draw_level_zero();


 // enemy initial position level zero.

int main(){																																							//MAIN

	init_platform();
	init_gpu();
	init_colors();
	init_interrupt_controller();
	int j=0;
	level=0;

	// level looper
	for(j=0;j<3;j++){
		main_level();
	};

	return 0;
}

void init_gpu(){
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x04, 0b11); //display and text mode
	clear_text_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
	clear_graphics_screen(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR);
}

void init_colors()
{
	/* Define colors */
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x10, 0xe6ccff);	//color 0 background color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x14, 0x000000);	//color 1 text color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x18, 0xe6ccff);	//color 2
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x1C, 0x000000);	//color 3 level frame color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x20, 0xe0edff);	//color 4 base color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x24, 0x00ff00);	//color 5 endpoint color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x28, 0x0000ff);	//color 6 enemy color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x2C, 0x000000);	//color 7 cube border color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x30, 0xff0000);	//color 8 cube fill color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x34, 0x000000);	//color 9 enemy border color
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x38, 0xff6666);	//color 10 A
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x3C, 0x556b2f);	//color 11 B
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x40, 0x191970);	//color 12 C
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x44, 0xb8860b);	//color 13 D
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x48, 0xffff1a);	//color 14 E
	VGA_PERIPH_MEM_mWriteMemory(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x4C, 0xd2691e);	//color 15 F
}

void clear_text_screen(Xuint32 BaseAddress)
{
   	int i;

    for (i = 0; i < 4800; i++)
    {
        VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
    }
}

void set_cursor(Xuint32 new_value)
{
    cursor_position = new_value;
}

void print_string(Xuint32 BaseAddress, char string_s[], int lenght)
{
    int i;

    for (i = 0; i < lenght; i++)
    {
        VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
    }
}

void num_to_str(char *s, unsigned long bin, unsigned char n)
{
    s += n;
    *s = '\0';

    while (n--)
    {
        --s;
    	*s = (bin % 10) + '0';
        bin /= 10;
    }
}

int num_len(int num)
{
	int len = 0;

	if(num == 0)
	{
		len++;
	}
	else
	{
		while(num > 0)
		{
			num /= 10;
			len++;
		}
	}

	return len;
}

