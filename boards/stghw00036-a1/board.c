/*
 * Copyright (C) 2015-2018 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/*
 * This file is inspired from the same file of the slwstk6000b board
 */

/**
 * @ingroup     boards_stghw00036-a1
 * @{
 *
 * @file
 * @brief        Board specific implementations of the STGHW00036 board
 *
 * @author      Maxime PACHEU <maxime.pacheu@etu.unistra.fr>
 */

#include "board.h"
#include "board_common.h"
#include "periph/gpio.h"

void board_init(void)
{
    /* initialize the CPU */
    cpu_init();

    /* perform common board initialization */
    board_common_init();

}
