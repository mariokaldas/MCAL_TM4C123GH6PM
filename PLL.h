/*
 * PLL.h
 *
 *  Created on: Jul 16, 2024
 *      Author: mario
 */

#ifndef PLL_H_
#define PLL_H_

#include "std_types.h"

/****************************************************************************************************************************
 *                                                      Mapped registers
 ****************************************************************************************************************************/

#define SYSCTL_RIS_R        (*((volatile uint32*)0x400FE050))
#define SYSCTL_RCC_R        (*((volatile uint32*)0x400FE060))
#define SYSCTL_RCC2_R       (*((volatile uint32*)0x400FE070))

/****************************************************************************************************************************
 *                                                    Functions prototype
 ****************************************************************************************************************************/

/* This function initialize PLL unit for desired passed frequency * PASS WITHOUT ZEROS *
 *
 * the supported frequencies :
 *
 * 1 MHZ
 * 2 MHZ
 * 4 MHZ
 * 5 MHZ
 * 8 MHZ
 * 10 MHZ
 * 16 MHZ (Default)
 * 20 MHZ
 * 25 MHZ
 * 40 MHZ
 * 50 MHZ
 * 80 MHZ
 *
 *  */
void PLL_init(uint8 frequency);


#endif /* PLL_H_ */
