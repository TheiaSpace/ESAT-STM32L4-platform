/*
 * Copyright (c) 2018 Theia Space.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimers.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimers in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Thomas Roell, nor the names of its contributors
 *     may be used to endorse or promote products derived from this Software
 *     without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.
 */

#ifndef _VARIANT_ESAT_ADCS_
#define _VARIANT_ESAT_ADCS_

/* The definitions here needs a STM32L4 core >=1.6.6 */
#define ARDUINO_STM32L4_VARIANT_COMPLIANCE 10606

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

#define STM32L4_CONFIG_LSECLK             32768
#define STM32L4_CONFIG_HSECLK             16000000
#define STM32L4_CONFIG_SYSOPT             SYSTEM_OPTION_VBAT_CHARGING
#define STM32L4_CONFIG_USB_VBUS           GPIO_PIN_PA9

#define USBCON

/* Master clock frequency. */
#define VARIANT_MCK F_CPU

#ifdef __cplusplus
#include "USBAPI.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/* Number of pins defined in PinDescription array. */
#define NUM_TOTAL_PINS       (33u)

/* General-purpose input/output. */
static const uint8_t AGPIO0 = 0; /* Analog input, digital input and output, PWM output. */
static const uint8_t AGPIO1 = 1; /* Analog input, digital input and output, PWM output. */
static const uint8_t AGPIO2 = 2; /* Analog input, digital input and output, PWM output. */
static const uint8_t AGPIO3 = 3; /* Analog input, digital input and output, PWM output. */
static const uint8_t AGPIO4 = 4; /* Digital input and output, PWM output. */
static const uint8_t AGPIO5 = 5; /* Digital input and output, PWM output. */

/* Coarse sun sensors. */
static const uint8_t CSSXMINUS = 6; /* Coarse sun sensor on X- panel. */
static const uint8_t CSSXPLUS  = 7; /* Coarse sun sensor on X+ panel. */
static const uint8_t CSSYMINUS = 8; /* Coarse sun sensor on Y- panel. */
static const uint8_t CSSYPLUS  = 9; /* Coarse sun sensor on Y+ panel. */

/* Power lines. */
static const uint8_t EN3V3 = 10; /* Enable the 3.3 V line. */
static const uint8_t EN5V  = 11; /* Enable the 5 V line. */

/* LED. */
static const uint8_t LED_A = 12;

/* Magnetorquers. */
static const uint8_t MTQXMINUS = 14; /* Magnetorquer driver (X axis, negative). */
static const uint8_t MTQXPLUS  = 13; /* Magnetorquer driver (X axis, positive). */
static const uint8_t MTQYMINUS = 16; /* Magnetorquer driver (Y axis, negative). */
static const uint8_t MTQYPLUS  = 15; /* Magnetorquer driver (Y axis, positive). */
static const uint8_t MTQZMINUS = 18; /* Magnetorquer driver (Z axis, negative). */
static const uint8_t MTQZPLUS  = 17; /* Magnetorquer driver (Z axis, positive). */

/* Electronic speed controller. */
static const uint8_t PWM_A = 19;

/* Tachometer. */
static const uint8_t TCH_A = 20;

/* Analog-to-digital conversion. */
#define ADC_RESOLUTION 12

/* Pulse-width modulation output. */
#define PWM_INSTANCE_COUNT  6

/* I2C interfaces. */
#define WIRE_INTERFACES_COUNT 2
static const uint8_t SCL_O = 21;
static const uint8_t SDA_O = 22;
static const uint8_t SCL_A = 23;
static const uint8_t SDA_A = 24;
#define WireOBC (Wire) /* OBC I2C bus. */
#define WireADCS (Wire1) /* ADCS I2C bus. */

/* I2S interfaces. */
#define I2S_INTERFACES_COUNT 0

/* Serial interfaces. */
#define SERIAL_INTERFACES_COUNT 0

/* SPI interfaces. */
#define SPI_INTERFACES_COUNT 1
static const uint8_t RST  = 24;
static const uint8_t MISO = 25;
static const uint8_t MOSI = 26;
static const uint8_t SCK  = 28;

/* USB interface. */
static const uint8_t USB_DM   = 29;
static const uint8_t USB_DP   = 30;
static const uint8_t USB_ID   = 31;
static const uint8_t USB_VBUS = 32;

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern CDC  Serial;
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      Serial
#define SERIAL_PORT_MONITOR         Serial

// Alias SerialUSB to Serial.
#define SerialUSB SERIAL_PORT_USBVIRTUAL

#endif /* _VARIANT_ESAT_ADCS_ */

