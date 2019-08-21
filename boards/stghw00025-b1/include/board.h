/*
 * Copyright (C) 2015-2018 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

 /*
  * This file is inspired from the same file of the stk3700 board
  */

/**
 * @defgroup    boards_stghw00025-b1 Strataggem STGHW00025 board REV B1
 * @ingroup     boards
 * @brief       Support for the Strataggem STGHW00025 board
 * @{
 *
 * @file
 * @brief       Board specific definitions for the STGHW00025 board
 *
 * @author      Maxime PACHEU <maxime.pacheu@etu.unistra.fr>
 */

#ifndef BOARD_H
#define BOARD_H

#include "cpu.h"
#include "periph_conf.h"
#include "periph/gpio.h"
#include "periph/spi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Xtimer configuration
 *
 * The timer runs at 250 KHz to increase accuracy.
 * @{
 */
#define XTIMER_HZ           (250000UL)
#define XTIMER_WIDTH        (16)
/** @} */

/**
 * @name    Board controller configuration
 *
 * Define the GPIO pin to enable the BC, to allow serial communication
 * via the USB port.
 * @{
 */
#define BC_PIN              GPIO_PIN(PE, 1)
/** @} */

/**
 * @name    Push button pin definitions
 * @{
 */
#define PB0_PIN             GPIO_PIN(PC, 9)
#define PB1_PIN             GPIO_UNDEF
/** @} */

/**
 * @name    LED pin definitions
 * @{
 */
#define LEDR_PIN            GPIO_PIN(PE, 5)
#define LEDG_PIN            GPIO_PIN(PE, 6)
#define LEDB_PIN            GPIO_PIN(PE, 7)

#define LED0_PIN            LEDR_PIN
#define LED1_PIN            LEDG_PIN
#define LED2_PIN            LEDB_PIN
/** @} */

/**
 * @name    Macros for controlling the on-board LEDs
 * @{
 */
#define LED0_ON             gpio_set(LED0_PIN)
#define LED0_OFF            gpio_clear(LED0_PIN)
#define LED0_TOGGLE         gpio_toggle(LED0_PIN)
#define LED1_ON             gpio_set(LED1_PIN)
#define LED1_OFF            gpio_clear(LED1_PIN)
#define LED1_TOGGLE         gpio_toggle(LED1_PIN)
#define LED2_ON             gpio_set(LED2_PIN)
#define LED2_OFF            gpio_clear(LED2_PIN)
#define LED2_TOGGLE         gpio_toggle(LED2_PIN)
/** @} */

/**
 * @name    XLBees configuration
 * @{
 * In order : XLBee 1, XLBee 2, XLBee 3.
 */
 #define XLBEE1_EN            GPIO_PIN(PB, 9)
 #define XLBEE2_EN            GPIO_PIN(PB, 12)
 #define XLBEE3_EN            GPIO_PIN(PB, 10)

 #define XLBEE1_ON             gpio_set(XLBEE1_EN)
 #define XLBEE1_OFF            gpio_clear(XLBEE1_EN)
 #define XLBEE2_ON             gpio_set(XLBEE2_EN)
 #define XLBEE2_OFF            gpio_clear(XLBEE2_EN)
 #define XLBEE3_ON             gpio_set(XLBEE3_EN)
 #define XLBEE3_OFF            gpio_clear(XLBEE3_EN)
 /** @} */

/**
 * @name    Temperature sensor configuration
 *
 * Connection to the on-board temperature/humidity sensor (Si7021).
 * @{
 */
#define SI7021_I2C              I2C_DEV(1)
#define SI7021_EN_PIN           GPIO_PIN(PD, 14)

#define SI70XX_PARAM_I2C_DEV    SI7021_I2C
/** @} */

/**
 * @brief   Initialize the board (GPIO, sensors, clocks).
 */
void board_init(void);

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
