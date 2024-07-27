/*
 * NVIC.c
 *
 *  Created on: Jul 27, 2024
 *      Author: mario
 */


#include"NVIC.h"


/*******************************************************************************
 *                           Functions definition                               *
 *******************************************************************************/

void NVIC_EnableIRQ(NVIC_IRQType IRQ_Num){

    switch(IRQ_Num / 32){

    case 0:

        NVIC_IRQ_EN0_R |= (1<<(IRQ_Num % 32));
        break;

    case 1:

        NVIC_IRQ_EN1_R |= (1<<(IRQ_Num % 32));
        break;

    case 2:

        NVIC_IRQ_EN2_R |= (1<<(IRQ_Num % 32));
        break;

    case 3:

        NVIC_IRQ_EN3_R |= (1<<(IRQ_Num % 32));
        break;

    case 4:

        NVIC_IRQ_EN4_R |= (1<<(IRQ_Num % 32));
        break;

    }
}

void NVIC_DisableIRQ(NVIC_IRQType IRQ_Num){

    switch(IRQ_Num / 32){

    case 0:

        NVIC_IRQ_DIS0_R |= (1<<(IRQ_Num % 32));
        break;

    case 1:

        NVIC_IRQ_DIS1_R |= (1<<(IRQ_Num % 32));
        break;

    case 2:

        NVIC_IRQ_DIS2_R |= (1<<(IRQ_Num % 32));
        break;

    case 3:

        NVIC_IRQ_DIS3_R |= (1<<(IRQ_Num % 32));
        break;

    case 4:

        NVIC_IRQ_DIS4_R |= (1<<(IRQ_Num % 32));
        break;

    }

}

void NVIC_SetPriorityIRQ(NVIC_IRQType IRQ_Num, NVIC_IRQPriorityType IRQ_Priority){



    /*
     * -  To determine which combination of bits required : apply equation (IRQ_Num % 4),
     * this equation result 0 or 1 or 2 or 3 according to the following 3 cases
     *
     * -  To determine which register required : consider the IRQ number (0-138) is the offset of
     * the base register IRQ's priority registers
     *
     * */
    switch(IRQ_Num % 4){

    case 0:

        NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] = (NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03]  & 0xFFFFFF1F) | ((IRQ_Priority & 0x07)<<5);
        break;

    case 1:

        NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] = (NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] & 0xFFFF1FFF) | ((IRQ_Priority & 0x07)<<13);
        break;

    case 2:

        NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] = (NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] & 0xFF1FFFFF) | ((IRQ_Priority & 0x07)<<21);
        break;

    case 3:

        NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] = (NVIC_IRQ_PRI_BASE[IRQ_Num & 0x03] & 0x1FFFFFFF) | ((IRQ_Priority & 0x07)<<29);
        break;


    }

}

void NVIC_EnableException(NVIC_ExceptionType Exception_Num){

    Enable_Faults();

    switch(Exception_Num){

    case EXCEPTION_MEM_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R |= (1<<16);
        break;

    case EXCEPTION_BUS_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R |= (1<<17);
        break;

    case EXCEPTION_USAGE_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R |= (1<<18);
        break;



    }

}

void NVIC_DisableException(NVIC_ExceptionType Exception_Num){

    switch(Exception_Num){

    case EXCEPTION_MEM_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R &= ~(1<<16);
        break;

    case EXCEPTION_BUS_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R &= ~(1<<17);
        break;

    case EXCEPTION_USAGE_FAULT_TYPE:

        NVIC_SYSHNDCTRL_R &= ~(1<<18);
        break;

    }

}


void NVIC_SetPriorityException(NVIC_ExceptionType Exception_Num, NVIC_ExceptionPriorityType Exception_Priority){

    switch(Exception_Num){

    case EXCEPTION_MEM_FAULT_TYPE:

        NVIC_SYSPRI1_R = (NVIC_SYSPRI1_R & 0xFFFFFF1F) | ((Exception_Priority & 0x07)<<5);
        break;

    case EXCEPTION_BUS_FAULT_TYPE:

        NVIC_SYSPRI1_R = (NVIC_SYSPRI1_R & 0xFFFF1FFF) | ((Exception_Priority & 0x07)<<13);
        break;

    case EXCEPTION_USAGE_FAULT_TYPE:

        NVIC_SYSPRI1_R = (NVIC_SYSPRI1_R & 0xFF1FFFFF) | ((Exception_Priority & 0x07)<<21);
        break;

    case EXCEPTION_SVC_TYPE :

        NVIC_SYSPRI2_R = (NVIC_SYSPRI2_R & 0x1FFFFFFF) | ((Exception_Priority & 0x07)<<29);
        break;

    case EXCEPTION_DEBUG_MONITOR_TYPE :

        NVIC_SYSPRI3_R = (NVIC_SYSPRI3_R & 0xFFFFFF1F) | ((Exception_Priority & 0x07)<<5);
        break;

    case EXCEPTION_PEND_SV_TYPE :

        NVIC_SYSPRI3_R = (NVIC_SYSPRI3_R & 0xFF1FFFFF) | ((Exception_Priority & 0x07)<<21);
        break;

    case EXCEPTION_SYSTICK_TYPE :

        NVIC_SYSPRI3_R = (NVIC_SYSPRI3_R & 0x1FFFFFFF) | ((Exception_Priority & 0x07)<<29);
        break;
    }

}



