/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void setRowsAsHigh(GPIOx_ODR_t volatile *const);
void findConnectionCx(uint8_t, GPIOx_IDR_t volatile *const);
void delay(void);
uint8_t getCharacter(uint8_t, uint8_t);

/*
 * The pins that are going to be used as output are PD0-PD3 for the row ports (R1-R4). The pins are free to use
 * The pins that are going to be used as input are PD8-PD11 for the column ports (C1-C4). The pins are free to use
*/

int main(void)
{
	RCC_AHB1ENR_t volatile *const pAHB1ClockEnableRegister = ADDR_REG_AHB1ENR; // Memory address of RCC to enable the clock
	GPIOx_MODE_t volatile *const pGPIODPortModeRegister = ADDR_REG_GPIOD_MODE; // Memory address to change the port modes (input/output/etc) of the pins in GPIOD
	GPIOx_ODR_t volatile *const pGPIODOutputDataRegister = ADDR_REG_GPIOD_OUTPUT_DATA; // Memory address to change the output of pins
	GPIOx_IDR_t volatile *const pGPIODInputDataRegister = ADDR_REG_GPIOD_INPUT_DATA; // Memory address to read if there is any input in the pins
	GPIOx_PUPDR_t volatile *const pGPIODPullRegister = ADDR_REG_RESISTOR; // Memory address to change to pull up/down registers on specific pins

	// 2. Initialize the clock register for the port that has the pins that will be used (GPIOD)
	pAHB1ClockEnableRegister->gpiod_en = CLOCK_ENABLE;

	// 3. Initialization of variables and setup of environment for the MCU
	// a. Make all row IOs mode as output (PD0-PD3)
	pGPIODPortModeRegister->pin_0 = MODE_CONF_OUTPUT;
	pGPIODPortModeRegister->pin_1 = MODE_CONF_OUTPUT;
	pGPIODPortModeRegister->pin_2 = MODE_CONF_OUTPUT;
	pGPIODPortModeRegister->pin_3 = MODE_CONF_OUTPUT;
	// b. Make all column IOs mode as input (PD8-PD11)
	pGPIODPortModeRegister->pin_8 = MODE_CONF_INPUT;
	pGPIODPortModeRegister->pin_9 = MODE_CONF_INPUT;
	pGPIODPortModeRegister->pin_10 = MODE_CONF_INPUT;
	pGPIODPortModeRegister->pin_11 = MODE_CONF_INPUT;
	// c. Activate internal pull-up resistors for columns IOs
	pGPIODPullRegister->pin_8 = MODE_CONF_PULLUP_RESISTORS;
	pGPIODPullRegister->pin_9 = MODE_CONF_PULLUP_RESISTORS;
	pGPIODPullRegister->pin_10 = MODE_CONF_PULLUP_RESISTORS;
	pGPIODPullRegister->pin_11 = MODE_CONF_PULLUP_RESISTORS;

	// 4. Implement the key detect logic
	while (1) {
		// a. Set all row outputs as high
		setRowsAsHigh(pGPIODOutputDataRegister);


		for (uint8_t volatile pinIterator = 0; pinIterator < 4; pinIterator++) {
			// b. Set Row_i (i = pinIterator) as low
			switch(pinIterator) {
			case 0:
				pGPIODOutputDataRegister->pin_0 = SET_ROW_LOW;
				break;
			case 1:
				pGPIODOutputDataRegister->pin_1 = SET_ROW_LOW;
				break;
			case 2:
				pGPIODOutputDataRegister->pin_2 = SET_ROW_LOW;
				break;
			case 3:
				pGPIODOutputDataRegister->pin_3 = SET_ROW_LOW;
				break;
			}
			// c. Check what column changed to zero (C1-C4) - To confirm if those are the pressed key
			findConnectionCx(pinIterator, pGPIODInputDataRegister);
			// d. Reset the outputs so the printing is done correctly
			setRowsAsHigh(pGPIODOutputDataRegister);
		}
	}
}

// This function sets all the rows output state as high (as 1) so the columns are also shown all as high
void setRowsAsHigh(GPIOx_ODR_t volatile *const pGPIODOutputDataRegister)
{
	pGPIODOutputDataRegister->pin_0 = SET_ROW_HIGH;
	pGPIODOutputDataRegister->pin_1 = SET_ROW_HIGH;
	pGPIODOutputDataRegister->pin_2 = SET_ROW_HIGH;
	pGPIODOutputDataRegister->pin_3 = SET_ROW_HIGH;
}

// Function that makes a delay when printing the values
void delay()
{
	// Make a delay using a for loop
	for(uint32_t volatile iterator; iterator < DELAY_COUNT; iterator++); // Causes 150miliseconds = 0.15 seconds
}


// Returns the character that matches the row and the column
uint8_t getCharacter(uint8_t row, uint8_t column)
{
	switch(row) {
	case 0:
		if (column == 0) {
			return '1';
		} else if (column == 1) {
			return '2';
		} else if (column == 2) {
			return '3';
		} else {
			return 'A';
		}
	case 1:
		if (column == 0) {
			return '4';
		} else if (column == 1) {
			return '5';
		} else if (column == 2) {
			return '6';
		} else {
			return 'B';
		}
	case 2:
		if (column == 0) {
			return '7';
		} else if (column == 1) {
			return '8';
		} else if (column == 2) {
			return '9';
		} else {
			return 'C';
		}
	case 3:
		if (column == 0) {
			return '*';
		} else if (column == 1) {
			return '0';
		} else if (column == 2) {
			return '#';
		} else {
			return 'D';
		}
	default:
		return 255;
	}
}

// Finds which column is matched with the row called
void findConnectionCx(uint8_t row, GPIOx_IDR_t volatile *const pGPIODInputDataRegister)
{
	// Check which column is on
	uint8_t C0IsOn = !pGPIODInputDataRegister->pin_8;
	uint8_t C1IsOn = !pGPIODInputDataRegister->pin_9;
	uint8_t C2IsOn = !pGPIODInputDataRegister->pin_10;
	uint8_t C3IsOn = !pGPIODInputDataRegister->pin_11;

	uint8_t columnOn = C0IsOn ? 0 : C1IsOn ? 1 : C2IsOn ? 2 : C3IsOn ? 3 : 255; // Check which column is the one in the ground. 255 if there is no column on
	if (columnOn != 255) {
		delay(); // Apply delay before printing
		// Print only when a column is on
		printf("%c\n", getCharacter(row, columnOn));
	}
}
