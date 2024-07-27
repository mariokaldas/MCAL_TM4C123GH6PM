/*
 * SysTick.h
 *
 *  Created on: Jul 8, 2024
 *      Author: mario
 */

/* Please configure the used technique (interrupt or pulling) and modify the CPU frequency */

#ifndef SYSTICK_H_
#define SYSTICK_H_


#include"std_types.h"

/****************************************************************************************************************************
 *                                                      Mapped registers
 ****************************************************************************************************************************/

#define SYSTICK_STCTRL_R      (*((volatile uint32*)0xE000E010))
#define SYSTICK_STRELOAD_R    (*((volatile uint32*)0xE000E014))
#define SYSTICK_STCURRENT_R   (*((volatile uint32*)0xE000E018))


/****************************************************************************************************************************
 *                                                        Definitions
 ****************************************************************************************************************************/

#define CPU_FREQ    16000000u

/****************************************************************************************************************************
 *                                                    Functions prototype
 ****************************************************************************************************************************/

/*********************************************************************
 * Service Name: Sysick_Init
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Time in milliseconds
 * Return value: None
 * Description: Function to initialize systick timer with required milliseconds using interrupt technique
**********************************************************************/
void SysTick_Init(uint16 a_TimeInMilliSeconds) ;


/*********************************************************************
 * Service Name: Sysick_StartBustWait
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Time in milliseconds
 * Return value: None
 * Description: Function to initialize systick timer with required milliseconds using polling technique
**********************************************************************/
void SysTick_StartBusyWait(uint16 a_TimeInMilliSeconds) ;


/*********************************************************************
 * Service Name: Sysick_SetCallBack
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): address of callback function
 * Return value: None
 * Description: Function to set the call back function
**********************************************************************/
void SysTick_SetCallBack(volatile void (*Ptr2Func) (void)) ;


/*********************************************************************
 * Service Name: Sysick_Start
 * Sync/Async: Asynchronous
 * Reentrancy: reentrant
 * Parameters (in): None
 * Return value: None
 * Description: Function to start counting the timer
**********************************************************************/
void SysTick_Start(void) ;


/*********************************************************************
 * Service Name: Sysick_Stop
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): None
 * Return value: None
 * Description: Function to Stop the counter
**********************************************************************/
void SysTick_Stop(void) ;


/*********************************************************************
 * Service Name: Sysick_DeInit
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): None
 * Return value: None
 * Description: Function to de-initialize systick timer
**********************************************************************/
void SysTick_DeInit(void) ;



#endif /* SYSTICK_H_ */
