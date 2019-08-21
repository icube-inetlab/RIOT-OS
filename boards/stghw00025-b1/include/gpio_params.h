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
 * @ingroup     boards_stghw00025-b1
 * @{
 *
 * @file
 * @brief       Board specific configuration of direct mapped GPIOs
 *
 * @author      Maxime PACHEU <maxime.pacheu@etu.unistra.fr>
 */

#ifndef GPIO_PARAMS_H
#define GPIO_PARAMS_H

#include "board.h"
#include "saul/periph.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief    GPIO pin configuration
 */
static const  saul_gpio_params_t saul_gpio_params[] =
{
    {
        .name = "LED 0",
        .pin = LED0_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "LED 1",
        .pin = LED1_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "LED 2",
        .pin = LED2_PIN,
        .mode = GPIO_OUT
    },
    {
        .name = "Button 1",
        .pin = PB0_PIN,
        .mode = GPIO_IN_PU,
        .flags = SAUL_GPIO_INVERTED
    }
};

#ifdef __cplusplus
}
#endif

#endif /* GPIO_PARAMS_H */
/** @} */
