/*
 * SI_init.c
 *
 *  Created on: 16.06.2015.
 *      Author: student
 */

#include "SI_interrupt.h"
#include <stdbool.h>

static volatile bool free_to_draw = false;

void before_drawing(void) {
	int i;
	while(!free_to_draw){

	}
}

void after_drawing(void) {
	free_to_draw = false;
}

void vga_interrupt_handler(void *BaseAddress)
{

	free_to_draw = true;
}

void init_interrupt_controller()
{
	XStatus Status;

	XIo_Out32(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x54, 0x1E0); //init terminal counter on 524
	XIo_Out32(XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + 0x58, 1);		//enable timer

	//initialize interrupt controller
	Status = XIntc_Initialize (&Intc, XPAR_INTC_0_DEVICE_ID);
	if (Status != XST_SUCCESS)
		xil_printf ("\r\nInterrupt controller initialization failure");
	else
		xil_printf("\r\nInterrupt controller initialized");

	// Connect interrupt_handler
	Status = XIntc_Connect (&Intc, 0, (XInterruptHandler) vga_interrupt_handler, (void *)0);

	if (Status != XST_SUCCESS)
		xil_printf ("\r\nRegistering MY_TIMER Interrupt Failed");
	else
		xil_printf("\r\nMY_TIMER Interrupt registered");

	//Start the interrupt controller in real mode
	Status = XIntc_Start(&Intc, XIN_REAL_MODE);

	//Enable interrupt controller
	XIntc_Enable (&Intc, 0);
	microblaze_enable_interrupts();

}
