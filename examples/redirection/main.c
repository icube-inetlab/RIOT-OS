/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "board.h"
#include "stdio_uart.h"
#include "periph/uart.h"

static uart_t dev_debug = UART_DEV(0);
static uart_t dev_xlb = UART_DEV(2);
static char* endl = "\r\n";

static void rx_debug(void *arg, uint8_t data)
{
  uart_t dev = (uart_t)arg;
  if (dev == dev_debug) {
    if(data == '\n'){
      uart_write(dev_xlb, (uint8_t*)endl, 2);
    }
    else{
      uart_write(dev_xlb, &data, 1);
    }
  }
}

static void rx_xlb(void *arg, uint8_t data)
{
  uart_t dev = (uart_t)arg;
  if (dev == dev_xlb) {
    uart_write(dev_debug, &data, 1);
  }
}

int main(void)
{

  int res;
  uint32_t baud_debug = 115200;
  uint32_t baud_xlb = 115200;
  puts("Hello World!");
  printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
  printf("This board features a(n) %s MCU.\n\n", RIOT_MCU);

  /* Initialize XLBEEs*/
  XLBEE1_ON;
  XLBEE2_ON;
  XLBEE3_ON;
  /* initialize UARTs for redirection */
  res = uart_init(UART_DEV(dev_xlb), baud_xlb, rx_xlb, (void *)dev_xlb);
  if (res == UART_NOBAUD) {
    printf("Error: Given baudrate (%u) not possible\n", (unsigned int)baud_xlb);
    return 1;
  }
  else if (res != UART_OK) {
    puts("Error: Unable to initialize UART xlb3");
    return 1;
  }

  printf("Success: Initialized UART_DEV(%i) at BAUD %li\n\n", dev_xlb, baud_xlb);

  res = uart_init(UART_DEV(dev_debug), baud_debug, rx_debug, (void *)dev_debug);
  if (res == UART_NOBAUD) {
    printf("Error: Given baudrate (%u) not possible\n", (unsigned int)baud_debug);
    return 1;
  }
  else if (res != UART_OK) {
    puts("Error: Unable to initialize UART device");
    return 1;
  }
  printf("Success: Initialized UART_DEV(%i) at BAUD %li\n\n", dev_debug, baud_debug);

  return 0;
}
