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
 * @brief       Configuration of CPU peripherals for the STGHW00025 board
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
#define CLOCK_HF            cmuSelect_HFRCO
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
/* Special SILICON_LABS_32B_SERIES_1*/
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
        .dev = I2C0,
        .sda_pin = GPIO_PIN(PC, 0),
        .scl_pin = GPIO_PIN(PC, 1),
        .loc = I2C_ROUTELOC0_SDALOC_LOC4 |
               I2C_ROUTELOC0_SCLLOC_LOC4,
        .cmu = cmuClock_I2C0,
        .irq = I2C0_IRQn,
        .speed = I2C_SPEED_NORMAL
    },
    {
        .dev = I2C1,
        .sda_pin = GPIO_PIN(PC, 4),
        .scl_pin = GPIO_PIN(PC, 5),
        .loc = I2C_ROUTELOC0_SDALOC_LOC0 |
               I2C_ROUTELOC0_SCLLOC_LOC0,
        .cmu = cmuClock_I2C1,
        .irq = I2C1_IRQn,
        .speed = I2C_SPEED_NORMAL
    }
};

#define I2C_NUMOF           ARRAY_SIZE(i2c_config)
#define I2C_0_ISR           isr_i2c0
#define I2C_1_ISR           isr_i2c1


/**
 * @name    RTC configuration
 * @{
 */
#define RTC_NUMOF           (1U)
/** @} */

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
    /*{
        .dev = USART3,
        .mosi_pin = GPIO_PIN(PD, 0),
        .miso_pin = GPIO_PIN(PD, 1),
        .clk_pin = GPIO_PIN(PD, 2),
        .loc = USART_ROUTE_LOCATION_LOC0,
        .cmu = cmuClock_USART3,
        .irq = USART3_RX_IRQn
    },*/
    {
        .dev = USART2,
        .mosi_pin = GPIO_PIN(PA, 7),
        .miso_pin = GPIO_PIN(PC, 8),
        .clk_pin = GPIO_PIN(PC, 9),
        .loc = USART_ROUTELOC0_RXLOC_LOC0 |
               USART_ROUTELOC0_TXLOC_LOC0 |
               USART_ROUTELOC0_CLKLOC_LOC0,
        .cmu = cmuClock_USART2,
        .irq = USART2_RX_IRQn
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
 * In order : Debug, XLBee 1, XLBee 2, XLBee 3.
 */
static const uart_conf_t uart_config[] = {
    {
        .dev = UART0,
        .rx_pin = GPIO_PIN(PE, 1),
        .tx_pin = GPIO_PIN(PE, 0),
        .loc = USART_ROUTELOC0_RXLOC_LOC1 |
               USART_ROUTELOC0_TXLOC_LOC1,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_UART0,
        .irq = UART0_RX_IRQn
    },
    {
        .dev = USART1,
        .rx_pin = GPIO_PIN(PD, 1),
        .tx_pin = GPIO_PIN(PD, 0),
        .loc = USART_ROUTELOC0_TXLOC_LOC1 |
               USART_ROUTELOC0_TXLOC_LOC1,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_USART1,
        .irq = USART1_RX_IRQn
    },
    {
        .dev = USART4,
        .rx_pin = GPIO_PIN(PB, 8),
        .tx_pin = GPIO_PIN(PB, 7),
        .loc = USART_ROUTELOC0_TXLOC_LOC0 |
               USART_ROUTELOC0_TXLOC_LOC0,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_USART4,
        .irq = USART4_RX_IRQn
    },
    {
        .dev = UART1,
        .rx_pin = GPIO_PIN(PC, 13),
        .tx_pin = GPIO_PIN(PC, 12),
        .loc = USART_ROUTELOC0_RXLOC_LOC0 |
               USART_ROUTELOC0_TXLOC_LOC0,
#if EFM32_UART_MODES
        .mode = UART_MODE_8N1,
#endif
        .cmu = cmuClock_UART1,
        .irq = UART1_RX_IRQn
    }
};

#define UART_NUMOF          ARRAY_SIZE(uart_config)
#define UART_0_ISR_RX       isr_uart0_rx
#define UART_1_ISR_RX       isr_usart1_rx
#define UART_2_ISR_RX       isr_usart4_rx
#define UART_3_ISR_RX       isr_uart1_rx
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
/** @} */
