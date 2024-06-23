# Embedded Keypad Interaction System with STM32F407 - NEW

## Overview
This project is developed to show STM32F407 connected with a matrix keypad. This repository is a continuation of [this](https://github.com/Joel-Milla/keypad_interface) repository, with new changes to enhace readability.
## Changes
Created `main.h` file to improve interaction with hardware registers:
- **Structured Register Access**: Introduced structured definitions using bitfields for registers like `RCC_AHB1ENR`, `GPIOx_MODE_t`, `GPIOx_ODR_t`, `GPIOx_IDR_t`, and `GPIOx_PUPDR_t`. This change allows for more direct and error-free register manipulation.
- **Register Definitions**:
  - **RCC_AHB1ENR_t**: Controls the clock enable register, making it easier to manage clock settings for GPIOs.
  - **GPIOx_MODE_t**: Simplifies the configuration of GPIO port modes (input/output/analog/alternate).
  - **GPIOx_ODR_t**: Defines the output data register structure to control the output state of GPIO pins.
  - **GPIOx_IDR_t**: Structure for the input data register to check real-time pin values.
  - **GPIOx_PUPDR_t**: Allows setting pull-up/pull-down resistors on GPIO pins, enhancing input signal.

## Hardware and Tools
- **Microcontroller**: STM32F407
- **IDE**: STM32CubeIDE
- **Additional Components**:
  - Matrix Keypad
  - Jumping wires
  - Optional: Protoboard for easier wiring

## Setup and Run
1. Setup the STM32CubeIDE with the necessary project files.
2. Wire the matrix keypad to the STM32F407 according to the defined pin configurations (PD0-PD3 && PD8-PD11).
3. Compile the code onto the STM32F407 board.
4. Press keys on the keypad and observe the output on the console or debugger (Recomendation: Use SWV to see the printing statements).

## Testing
- Test by pressing various keys on the keypad and verifying that the correct characters are displayed in the output console or debugger.

