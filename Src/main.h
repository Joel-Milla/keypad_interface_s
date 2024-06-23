/*
 * main.h
 *
 *  Created on: Jun 22, 2024
 *      Author: jAlej
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>


// Type for AHB1 peripheral clock enable register to enable the clocks on AHB1 (RCC_AHB1ENR)
typedef struct
{
	uint32_t gpioa_en 		: 1;
	uint32_t gpiob_en 		: 1;
	uint32_t gpioc_en 		: 1;
	uint32_t gpiod_en 		: 1;
	uint32_t gpioe_en 		: 1;
	uint32_t gpiof_en 		: 1;
	uint32_t gpiog_en 		: 1;
	uint32_t gpioh_en 		: 1;
	uint32_t gpioi_en 		: 1;
	uint32_t reserved_1		: 3;
	uint32_t crc_en	 		: 1;
	uint32_t reserved_2		: 5;
	uint32_t bkpsramen 		: 1;
	uint32_t reserved_3		: 1;
	uint32_t ccmdataramen	: 1;
	uint32_t dma_1en		: 1;
	uint32_t dma_2en		: 1;
	uint32_t reserved_4		: 2;
	uint32_t ethmac_en		: 1;
	uint32_t ethmac_txen	: 1;
	uint32_t ethmac_rxen	: 1;
	uint32_t ethmac_ptpen	: 1;
	uint32_t otghs_en		: 1;
	uint32_t otghs_ulpien	: 1;
	uint32_t reserved_5		: 1;
} RCC_AHB1ENR_t;


// Type definition of port mode register to change the port mode (input/output/analog/alternate)
typedef struct
{
	uint32_t pin_0 		: 2;
	uint32_t pin_1 		: 2;
	uint32_t pin_2 		: 2;
	uint32_t pin_3 		: 2;
	uint32_t pin_4 		: 2;
	uint32_t pin_5 		: 2;
	uint32_t pin_6 		: 2;
	uint32_t pin_7 		: 2;
	uint32_t pin_8 		: 2;
	uint32_t pin_9 		: 2;
	uint32_t pin_10 	: 2;
	uint32_t pin_11 	: 2;
	uint32_t pin_12 	: 2;
	uint32_t pin_13 	: 2;
	uint32_t pin_14 	: 2;
	uint32_t pin_15 	: 2;
} GPIOx_MODE_t;


// Type definition of GPIO port output data register, which control the output energy of a port
typedef struct
{
	uint32_t pin_0 		: 1;
	uint32_t pin_1 		: 1;
	uint32_t pin_2 		: 1;
	uint32_t pin_3 		: 1;
	uint32_t pin_4 		: 1;
	uint32_t pin_5 		: 1;
	uint32_t pin_6 		: 1;
	uint32_t pin_7 		: 1;
	uint32_t pin_8 		: 1;
	uint32_t pin_9 		: 1;
	uint32_t pin_10		: 1;
	uint32_t pin_11		: 1;
	uint32_t pin_12		: 1;
	uint32_t pin_13		: 1;
	uint32_t pin_14		: 1;
	uint32_t pin_15		: 1;
	uint32_t reserved	: 16;
} GPIOx_ODR_t;

// Type definition of GPIO port input data register, which reads if there is information passing through a pin
typedef struct
{
	uint32_t pin_0 		: 1;
	uint32_t pin_1 		: 1;
	uint32_t pin_2 		: 1;
	uint32_t pin_3 		: 1;
	uint32_t pin_4 		: 1;
	uint32_t pin_5 		: 1;
	uint32_t pin_6 		: 1;
	uint32_t pin_7 		: 1;
	uint32_t pin_8 		: 1;
	uint32_t pin_9 		: 1;
	uint32_t pin_10		: 1;
	uint32_t pin_11		: 1;
	uint32_t pin_12		: 1;
	uint32_t pin_13		: 1;
	uint32_t pin_14		: 1;
	uint32_t pin_15		: 1;
	uint32_t reserved	: 16;
} GPIOx_IDR_t;

// Type definition of GPIO port pull-up/pull-down register, which sets pull-up/pull-down resistors on specific ports
typedef struct
{
	uint32_t pin_0 		: 2;
	uint32_t pin_1 		: 2;
	uint32_t pin_2 		: 2;
	uint32_t pin_3 		: 2;
	uint32_t pin_4 		: 2;
	uint32_t pin_5 		: 2;
	uint32_t pin_6 		: 2;
	uint32_t pin_7 		: 2;
	uint32_t pin_8 		: 2;
	uint32_t pin_9 		: 2;
	uint32_t pin_10 	: 2;
	uint32_t pin_11 	: 2;
	uint32_t pin_12 	: 2;
	uint32_t pin_13 	: 2;
	uint32_t pin_14 	: 2;
	uint32_t pin_15 	: 2;
} GPIOx_PUPDR_t;

#endif /* MAIN_H_ */
