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
 * @brief       Configuration of CPU peripherals for the STGHW00036 board
 *
 * @author      Maxime PACHEU <maxime.pacheu@etu.unistra.fr>
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "cpu.h"
#include "periph_cpu.h"
#include "em_cmu.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Clock configuration
 * @{
 */
#ifndef CLOCK_HF
#define CLOCK_HF            cmuSelect_HFXO
#endif
#ifndef CLOCK_CORE_DIV
#define CLOCK_CORE_DIV      cmuClkDiv_1
#endif
#ifndef CLOCK_LFA
#define CLOCK_LFA           cmuSelect_LFRCO
#endif
#ifndef CLOCK_LFB
#define CLOCK_LFB           cmuSelect_LFRCO
#endif
#ifndef CLOCK_LFE
#define CLOCK_LFE           cmuSelect_LFRCO
#endif
/** @} */

/**
 * @name    ADC configuration
 * @{
 */
static const adc_conf_t adc_config[] = {
    {
        .dev = ADC0,
        .cmu = cmuClock_ADC0,
    }
};

static const adc_chan_conf_t adc_channel_config[] = {
    {
        .dev = 0,
        .input = adcPosSelTEMP,
        .reference = adcRef1V25,
        .acq_time = adcAcqTime8
    },
    {
        .dev = 0,
        .input = adcPosSelAVDD,
        .reference = adcRef5V,
        .acq_time = adcAcqTime8
    }
};

#define ADC_DEV_NUMOF       ARRAY_SIZE(adc_config)
#define ADC_NUMOF           ARRAY_SIZE(adc_channel_config)
/** @} */

/**
 * @name    I2C configuration
 * @{
 */
static const i2c_conf_t i2c_config[] = {
    {
        .dev = I2C1,
        .sda_pin = GPIO_PIN(PC, 10),
        .scl_pin = GPIO_PIN(PC, 11),
        .loc = I2C_ROUTELOC0_SDALOC_LOC19 |
               I2C_ROUTELOC0_SCLLOC_LOC19,
        .cmu = cmuClock_I2C1,
        .irq = I2C1_IRQn,
        .speed = I2C_SPEED_NORMAL
    }
};

#define I2C_NUMOF           ARRAY_SIZE(i2c_config)
#define I2C_0_ISR           isr_i2c1
/** @} */

/**
 * @brief   RTC configuration
 */
#define RTC_NUMOF           (1U)

/**
 * @name    RTT configuration
 * @{
 */
#define RTT_NUMOF           (1U)

#define RTT_MAX_VALUE       (0xFFFFFFFF)
#define RTT_FREQUENCY       (1U)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_dev_t spi_config[] = {
    {
        .dev = USART1,
        .mosi_pin = GPIO_PIN(PC, 6),
        .miso_pin = GPIO_PIN(PC, 7),
        .clk_pin = GPIO_PIN(PC, 8),
        .loc = USART_ROUTELOC0_RXLOC_LOC11 |
               USART_ROUTELOC0_TXLOC_LOC11 |
               USART_ROUTELOC0_CLKLOC_LOC11,
        .cmu = cmuClock_USART1,
        .irq = USART1_RX_IRQn
    }
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */

/**
 * @name    Timer configuration
 *
 * The implementation uses two timers in cascade mode.
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        {
            .dev = TIMER0,
            .cmu = cmuClock_TIMER0
        },
        {
            .dev = TIMER1,
            .cmu = cmuClock_TIMER1
        },
        .irq = TIMER1_IRQn
    }
};

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
#define TIMER_0_ISR         isr_timer1
/** @} */

/**
 * @name    UART configuration
 * @{
 *  * In order : to MCU, to Debug
 */
static const uart_conf_t uart_config[] = {
    {
        .dev = USART0,
        .rx_pin = GPIO_PIN(PA, 1),
        .tx_pin = GPIO_PIN(PA, 0),
        .loc = USART_ROUTELOC0_RXLOC_LOC0 |
               USART_ROUTELOC0_TXLOC_LOC0,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_USART0,
        .irq = USART0_RX_IRQn
    },
    {
        .dev = USART3,
        .rx_pin = GPIO_PIN(PD, 15),
        .tx_pin = GPIO_PIN(PC, 14),
        .loc = USART_ROUTELOC0_RXLOC_LOC6 |
               USART_ROUTELOC0_TXLOC_LOC6,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_USART3,
        .irq = USART3_RX_IRQn
    }
};

#define UART_NUMOF          ARRAY_SIZE(uart_config)
#define UART_0_ISR_RX       isr_usart0_rx
#define UART_1_ISR_RX       isr_usart3_rx
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
