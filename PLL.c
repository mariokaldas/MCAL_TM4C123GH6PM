/*
 * PLL.c
 *
 *  Created on: Jul 16, 2024
 *      Author: mario
 */

#include"PLL.h"


void PLL_init(uint8 frequency){


    /* allow the old frequency source till the PLL unit configured */
    SYSCTL_RCC_R &= ~(1<<22);//clock is undivided
    SYSCTL_RCC2_R |= (1<<11);// use oscillator source

    /* Use the register RCC2  */
    SYSCTL_RCC2_R |= (1<<31);

    /* Use external oscillator 16Mhz as oscillator source */
    SYSCTL_RCC2_R &= ~(00000070);

    /* (XTAL) pass the value 0x15 according to crystal value attached to main (external) oscillator */
    SYSCTL_RCC_R = (SYSCTL_RCC_R & ~0x000007C0) | (0x15<<6);

    if(frequency == 16){

        return;
    }

    /* if the desired frequency is less than 16 MHZ */
    if(!(16 % frequency)){

        /* Use system divider */
        SYSCTL_RCC_R |= (1<<22);

        /* System divider value (for ex. if you want to divide by 2 put 1) */
        SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1F800000) | (((16/frequency)-1) << 23);

        return;

    }

/************************************* In case of desired frequency above 16 Mhz **************************************/

    /* Use frequency 400 Mhz as output from PLL unit  */
    SYSCTL_RCC2_R |= (1<<30);

    /* Use system divider */
    SYSCTL_RCC_R |= (1<<22);

    /* System divider value (for ex. if you want to divide by 2 put 1) but now we have LSB also */
    SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) | (((400/frequency)-1)<<22);

    /* use PLL output */
    SYSCTL_RCC2_R &= ~(1<<11);

    /* Power on for PLL unit */
    SYSCTL_RCC2_R &= ~(1<<13);

    /* Wait for the clock to reach the desired frequency */
    while(!(SYSCTL_RIS_R & (1<<6)));



}
