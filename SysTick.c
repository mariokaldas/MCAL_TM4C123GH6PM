/*
 * SysTick.c
 *
 *  Created on: Jul 8, 2024
 *      Author: mario
 */

#include"SysTick.h"

/***************************************************************************
 *                            Global variables
 *************************************************************************** */

/* Pointer to function to hold the call back function */
static volatile void (*g_callBackPtr) (void) = NULL_PTR;

static volatile uint16 g_remainingTime = 0;
static volatile uint32 g_currentReload = 0;

/* To reserve the original passed argument */
static volatile uint16 g_originalArgument = 0;

/* This flag indicates that reload value directly fits in the reload register or not (flag == 0 then it fits) */
static volatile uint8 flag = 0;


/***************************************************************************
 *                            Interrupt handler
 *************************************************************************** */

void SysTick_Handler(void) {

    if(flag){ // we cannot load the reload register directly

        if(g_remainingTime){ // don't update the remaining time if it's already zero

            /* This equation updates the remaining time according to the reload value 10,000,000 */
            g_remainingTime = g_remainingTime - (((uint64)10000000*1000)/CPU_FREQ);
            g_currentReload = g_currentReload - 10000000;
        }

        if(!g_remainingTime){

            /* reset the global variables with the original passed argument (required milliseconds) */
            g_remainingTime = g_originalArgument;
            g_currentReload = ((g_remainingTime*1000) * (CPU_FREQ/1000000));
            (*g_callBackPtr)();
        }
        else{

            if(g_currentReload <= 16000000){

                SYSTICK_STRELOAD_R = g_currentReload - 1;
                g_remainingTime = g_remainingTime - (((uint64)g_currentReload*1000)/CPU_FREQ);

            }
            else{

                SYSTICK_STRELOAD_R = 10000000 - 1;
            }
        }

    }

    else{

        (*g_callBackPtr)();
    }



}


/***************************************************************************
 *                          Functions definition
 *************************************************************************** */

void SysTick_Init(uint16 a_TimeInMilliSeconds) {

    // as an initialization
    SYSTICK_STCTRL_R = 0;
    SYSTICK_STCURRENT_R = 0;

    /* Use system clock as clock source */
    SYSTICK_STCTRL_R |= (1<<2);


    /* Enable interrupt for sysTick timer */
    SYSTICK_STCTRL_R |= (1<<1);

    /* Disable counter (pending to be enabled for accuracy) */
    SYSTICK_STCTRL_R &= ~(1<<0);


    g_originalArgument = a_TimeInMilliSeconds;

    /* This equation convert the passed milliseconds to reload value depending on the system frequency */
    g_currentReload = ((a_TimeInMilliSeconds*1000) * (CPU_FREQ/1000000));

    /* 16000000 is the capacity of the reload register (almost) */
    if(g_currentReload <= 16000000){

        /* Load the register directly */
        SYSTICK_STRELOAD_R = g_currentReload - 1;
        flag = 0;

    }
    else{

        /* In case the register doesn't fit load the register with 10 000 000 and subtract this value from original value */
        SYSTICK_STRELOAD_R = 10000000 - 1;
        g_remainingTime = a_TimeInMilliSeconds;
        flag = 1;
    }

}

void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds) {

    uint32 currentReload = 0;

    // as an initialization
    SYSTICK_STCTRL_R = 0;
    SYSTICK_STCURRENT_R = 0;

    /* Use system clock as clock source */
    SYSTICK_STCTRL_R |= (1<<2);

    /* Disable interrupt for sysTick timer */
    SYSTICK_STCTRL_R &= ~(1<<1);

    /* This equation converts milliseconds into reload value */
    currentReload = ((a_TimeInMilliSeconds*1000) * (CPU_FREQ/1000000));

    while(1){

        if(currentReload <= 16000000){

            SYSTICK_STRELOAD_R = currentReload - 1;

            flag = 0;
        }
        else{

            SYSTICK_STRELOAD_R = 10000000 - 1;

            currentReload = currentReload - 10000000;

            flag = 1;


        }

        /* Enable sysTick timer */
        SYSTICK_STCTRL_R |= 1;
        /* wait for the flag to be set meaning the time passed */
        while(!(SYSTICK_STCTRL_R & (1<<16)));
        /* disable sysTick timer */
        SYSTICK_STCTRL_R &= ~1;

        if(!flag)
            return;

    }

}

void SysTick_SetCallBack(volatile void (*Ptr2Func) (void)){

    g_callBackPtr = Ptr2Func;
}


void SysTick_Start(void) {


    /* Enable sysTick timer */
    SYSTICK_STCTRL_R |= 1;

}

void SysTick_Stop(void) {

    /* Disable counter */
    SYSTICK_STCTRL_R &= ~(1<<0);
}

void SysTick_DeInit(void) {

    SYSTICK_STRELOAD_R = 0;
    SYSTICK_STCURRENT_R = 0;
    SYSTICK_STCTRL_R = 0;
}




