<<<<<<< HEAD
/*
 * GPIO.H
 *
 *  Created on: Apr 18, 2024
 *      Author: mario
 */
=======
/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.h
 *
 * Description: Header file for the ARM Cortex M4 GPIO driver
 *
 * Author: Mario kaldas
 *
 *******************************************************************************/
>>>>>>> e1a41bc (latest 10/8/24)

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

/****************************************************************************************************************************
 *                                                      Mapped registers
 ****************************************************************************************************************************/

#define SYSCTL_RCGCGPIO_R           (*((volatile uint32*)0x400FE608))
#define SYSCTL_PRGPIO_R             (*((volatile uint32*)0x400FEA08))


/*PORTA*/

#define GPIO_PORTA_DATA_BITS_R       ((volatile uint32*)0x40004000)   /* Bit banding feature */
#define GPIO_PORTA_DATA_R           (*((volatile uint32*)0x400043FC)) /* Data register */
#define GPIO_PORTA_DIR_R            (*((volatile uint32*)0x40004400)) /* Direction */
#define GPIO_PORTA_AFSEL_R          (*((volatile uint32*)0x40004420)) /* Alternative function select */
#define GPIO_PORTA_PCTL_R           (*((volatile uint32*)0x4000452C)) /* Port control (MUX mode selection) */
#define GPIO_PORTA_PUR_R            (*((volatile uint32*)0x40004510)) /* Pull-up resistor */
#define GPIO_PORTA_PDR_R            (*((volatile uint32*)0x40004514)) /* Pull-down resistor */
#define GPIO_PORTA_DEN_R            (*((volatile uint32*)0x4000451C)) /* Digital enable */
#define GPIO_PORTA_AMSEL_R          (*((volatile uint32*)0x40004528)) /* Analog mode select */
#define GPIO_PORTA_LOCK_R           (*((volatile uint32*)0x40004520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTA_CR_R             (*((volatile uint32*)0x40004524)) /* Commit register */


/*PORTB*/

#define GPIO_PORTB_DATA_BITS_R       ((volatile uint32*)0x40005000)   /* Bit banding feature */
#define GPIO_PORTB_DATA_R           (*((volatile uint32*)0x400053FC)) /* Data register */
#define GPIO_PORTB_DIR_R            (*((volatile uint32*)0x40005400)) /* Direction */
#define GPIO_PORTB_AFSEL_R          (*((volatile uint32*)0x40005420)) /* Alternative function select */
#define GPIO_PORTB_PCTL_R           (*((volatile uint32*)0x4000552C)) /* Port control (MUX mode selection) */
#define GPIO_PORTB_PUR_R            (*((volatile uint32*)0x40005510)) /* Pull-up resistor */
#define GPIO_PORTB_PDR_R            (*((volatile uint32*)0x40005514)) /* Pull-down resistor */
#define GPIO_PORTB_DEN_R            (*((volatile uint32*)0x4000551C)) /* Digital enable */
#define GPIO_PORTB_AMSEL_R          (*((volatile uint32*)0x40005528)) /* Analog mode select */
#define GPIO_PORTB_LOCK_R           (*((volatile uint32*)0x40005520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTB_CR_R             (*((volatile uint32*)0x40005524)) /* Commit register */


/*PORTC*/

#define GPIO_PORTC_DATA_BITS_R       ((volatile uint32*)0x40006000)   /* Bit banding feature */
#define GPIO_PORTC_DATA_R           (*((volatile uint32*)0x400063FC)) /* Data register */
#define GPIO_PORTC_DIR_R            (*((volatile uint32*)0x40006400)) /* Direction */
#define GPIO_PORTC_AFSEL_R          (*((volatile uint32*)0x40006420)) /* Alternative function select */
#define GPIO_PORTC_PCTL_R           (*((volatile uint32*)0x4000652C)) /* Port control (MUX mode selection) */
#define GPIO_PORTC_PUR_R            (*((volatile uint32*)0x40006510)) /* Pull-up resistor */
#define GPIO_PORTC_PDR_R            (*((volatile uint32*)0x40006514)) /* Pull-down resistor */
#define GPIO_PORTC_DEN_R            (*((volatile uint32*)0x4000651C)) /* Digital enable */
#define GPIO_PORTC_AMSEL_R          (*((volatile uint32*)0x40006528)) /* Analog mode select */
#define GPIO_PORTC_LOCK_R           (*((volatile uint32*)0x40006520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTC_CR_R             (*((volatile uint32*)0x40006524)) /* Commit register */


/*PORTD*/

#define GPIO_PORTD_DATA_BITS_R       ((volatile uint32*)0x40007000)   /* Bit banding feature */
#define GPIO_PORTD_DATA_R           (*((volatile uint32*)0x400073FC)) /* Data register */
#define GPIO_PORTD_DIR_R            (*((volatile uint32*)0x40007400)) /* Direction */
#define GPIO_PORTD_AFSEL_R          (*((volatile uint32*)0x40007420)) /* Alternative function select */
#define GPIO_PORTD_PCTL_R           (*((volatile uint32*)0x4000752C)) /* Port control (MUX mode selection) */
#define GPIO_PORTD_PUR_R            (*((volatile uint32*)0x40007510)) /* Pull-up resistor */
#define GPIO_PORTD_PDR_R            (*((volatile uint32*)0x40007514)) /* Pull-down resistor */
#define GPIO_PORTD_DEN_R            (*((volatile uint32*)0x4000751C)) /* Digital enable */
#define GPIO_PORTD_AMSEL_R          (*((volatile uint32*)0x40007528)) /* Analog mode select */
#define GPIO_PORTD_LOCK_R           (*((volatile uint32*)0x40007520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTD_CR_R             (*((volatile uint32*)0x40007524)) /* Commit register */


/*PORTE*/

#define GPIO_PORTE_DATA_BITS_R       ((volatile uint32*)0x40024000)   /* Bit banding feature */
#define GPIO_PORTE_DATA_R           (*((volatile uint32*)0x400243FC)) /* Data register */
#define GPIO_PORTE_DIR_R            (*((volatile uint32*)0x40024400)) /* Direction */
#define GPIO_PORTE_AFSEL_R          (*((volatile uint32*)0x40024420)) /* Alternative function select */
#define GPIO_PORTE_PCTL_R           (*((volatile uint32*)0x4002452C)) /* Port control (MUX mode selection) */
#define GPIO_PORTE_PUR_R            (*((volatile uint32*)0x40024510)) /* Pull-up resistor */
#define GPIO_PORTE_PDR_R            (*((volatile uint32*)0x40024514)) /* Pull-down resistor */
#define GPIO_PORTE_DEN_R            (*((volatile uint32*)0x4002451C)) /* Digital enable */
#define GPIO_PORTE_AMSEL_R          (*((volatile uint32*)0x40024528)) /* Analog mode select */
#define GPIO_PORTE_LOCK_R           (*((volatile uint32*)0x40024520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTE_CR_R             (*((volatile uint32*)0x40024524)) /* Commit register */


/*PORTF*/

#define GPIO_PORTF_DATA_BITS_R       ((volatile uint32*)0x40025000)   /* Bit banding feature */
#define GPIO_PORTF_DATA_R           (*((volatile uint32*)0x400253FC)) /* Data register */
#define GPIO_PORTF_DIR_R            (*((volatile uint32*)0x40025400)) /* Direction */
#define GPIO_PORTF_AFSEL_R          (*((volatile uint32*)0x40025420)) /* Alternative function select */
#define GPIO_PORTF_PCTL_R           (*((volatile uint32*)0x4002552C)) /* Port control (MUX mode selection) */
#define GPIO_PORTF_PUR_R            (*((volatile uint32*)0x40025510)) /* Pull-up resistor */
#define GPIO_PORTF_PDR_R            (*((volatile uint32*)0x40025514)) /* Pull-down resistor */
#define GPIO_PORTF_DEN_R            (*((volatile uint32*)0x4002551C)) /* Digital enable */
#define GPIO_PORTF_AMSEL_R          (*((volatile uint32*)0x40025528)) /* Analog mode select */
#define GPIO_PORTF_LOCK_R           (*((volatile uint32*)0x40025520))  /* LOCK register to unlock write :  0x4C4F434B (not recommended)*/
#define GPIO_PORTF_CR_R             (*((volatile uint32*)0x40025524)) /* Commit register */


/****************************************************************************************************************************
 *                                                        Definitions
 ****************************************************************************************************************************/

#define NUM_OF_PORTS           6
#define NUM_OF_PINS_PER_PORT   8


/****************************************************************************************************************************
 *                                                    User defined variables
 ****************************************************************************************************************************/
typedef enum{
    PORTA_ID,PORTB_ID,PORTC_ID,PORTD_ID,PORTE_ID,PORTF_ID
}GPIO_ports;


typedef enum
{
    PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/****************************************************************************************************************************
 *                                                    Functions prototype
 ****************************************************************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num);


#endif /* GPIO_H_ */
