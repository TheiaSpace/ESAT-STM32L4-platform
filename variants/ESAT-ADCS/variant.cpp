/*
 * Copyright (c) 2019 Theia Space, Universidad Politécnica de Madrid.
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

#include "Arduino.h"
#include "stm32l4_wiring_private.h"

// PWM timers.
#define PWM_INSTANCE_TIM2  0
#define PWM_INSTANCE_TIM3  1
#define PWM_INSTANCE_TIM4  2
#define PWM_INSTANCE_TIM5  3
#define PWM_INSTANCE_TIM16 4
#define PWM_INSTANCE_TIM17 5

extern const unsigned int g_PWMInstances[PWM_INSTANCE_COUNT] =
{
    TIMER_INSTANCE_TIM2,
    TIMER_INSTANCE_TIM3,
    TIMER_INSTANCE_TIM4,
    TIMER_INSTANCE_TIM5,
    TIMER_INSTANCE_TIM16,
    TIMER_INSTANCE_TIM17,
};

// Pin description table.
extern const PinDescription g_APinDescription[NUM_TOTAL_PINS] =
{
    // 0: AGPIO0 general-purpose input and output line.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA6),  GPIO_PIN_PA6_TIM16_CH1,  (PIN_ATTR_EXTI|PIN_ATTR_ADC|PIN_ATTR_PWM),        PWM_INSTANCE_TIM16, PWM_CHANNEL_1,    ADC_INPUT_11   },
    // 1: AGPIO1 general-purpose input and output line.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA7),  GPIO_PIN_PA7_TIM17_CH1,  (PIN_ATTR_EXTI|PIN_ATTR_ADC|PIN_ATTR_PWM),        PWM_INSTANCE_TIM17, PWM_CHANNEL_1,    ADC_INPUT_12   },
    // 2: AGPIO2 general-purpose input and output line.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB0),  GPIO_PIN_PB0_TIM3_CH3,   (PIN_ATTR_EXTI|PIN_ATTR_ADC|PIN_ATTR_PWM),        PWM_INSTANCE_TIM3,  PWM_CHANNEL_3,    ADC_INPUT_15   },
    // 3: AGPIO3 general-purpose input and output line.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB1),  GPIO_PIN_PB1_TIM3_CH4,   (PIN_ATTR_EXTI|PIN_ATTR_ADC|PIN_ATTR_PWM),        PWM_INSTANCE_TIM3,  PWM_CHANNEL_4,    ADC_INPUT_16   },
    // 4: AGPIO4 general-purpose input and output line.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB10), GPIO_PIN_PB10_TIM2_CH3,  (PIN_ATTR_EXTI|PIN_ATTR_PWM),                     PWM_INSTANCE_TIM2,  PWM_CHANNEL_3,    ADC_INPUT_NONE },
    // 5: AGPIO5 general-purpose input and output line.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB11), GPIO_PIN_PB11_TIM2_CH4,  (PIN_ATTR_EXTI|PIN_ATTR_PWM),                     PWM_INSTANCE_TIM2,  PWM_CHANNEL_4,    ADC_INPUT_NONE },
    // 6: CSSX- analog input.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA4),  GPIO_PIN_PA4,            (PIN_ATTR_ADC),                                   PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_9    },
    // 7: CSSX+ analog input.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA5),  GPIO_PIN_PA5,            (PIN_ATTR_ADC),                                   PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_10   },
    // 8: CSSY- analog input.
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC3),  GPIO_PIN_PC3,            (PIN_ATTR_ADC),                                   PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_4    },
    // 9: CSSY+ analog input.
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC2),  GPIO_PIN_PC2,            (PIN_ATTR_ADC),                                   PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_3    },
    // 10: EN3V3 digital output.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB3),  GPIO_PIN_PB3,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 11: EN5V digital output.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA3),  GPIO_PIN_PA3,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 12: LED PWM output.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA2),  GPIO_PIN_PA2_TIM5_CH3,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM5,  PWM_CHANNEL_3,    ADC_INPUT_NONE },
    // 13: MTQX+ PWM output.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB5),  GPIO_PIN_PB5_TIM3_CH2,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM3,  PWM_CHANNEL_2,    ADC_INPUT_NONE },
    // 14: MTQX- PWM output.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB4),  GPIO_PIN_PB4_TIM3_CH1,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM3,  PWM_CHANNEL_1,    ADC_INPUT_NONE },
    // 15: MTQY+ PWM output.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB7),  GPIO_PIN_PB7_TIM4_CH2,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM4,  PWM_CHANNEL_2,    ADC_INPUT_NONE },
    // 16: MTQY- PWM output.
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB6),  GPIO_PIN_PB6_TIM4_CH1,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM4,  PWM_CHANNEL_1,    ADC_INPUT_NONE },
    // 17: MTQZ+ PWM output.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA1),  GPIO_PIN_PA1_TIM5_CH2,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM5,  PWM_CHANNEL_2,    ADC_INPUT_NONE },
    // 18: MTQZ- PWM output.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA0),  GPIO_PIN_PA0_TIM5_CH1,   (PIN_ATTR_PWM),                                   PWM_INSTANCE_TIM5,  PWM_CHANNEL_1,    ADC_INPUT_NONE },
    // 19: PWM_A PWM output.
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC6),  GPIO_PIN_PC6,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 20: TCH_A external interrupt digital input.
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC7),  GPIO_PIN_PC7,            (PIN_ATTR_EXTI),                                  PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 21: SCL_O I2C clock line (OBC).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB8),  GPIO_PIN_PB8,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 22: SDA_O I2C data line (OBC).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB9),  GPIO_PIN_PB9,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 23: SCL_A I2C clock line (ADCS).
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC0),  GPIO_PIN_PC0,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 24: SDA_A I2C data line (ADCS).
    { GPIOC, GPIO_PIN_MASK(GPIO_PIN_PC1),  GPIO_PIN_PC1,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 25: MISO digital input line (electronic speed controller programming interface).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB14), GPIO_PIN_PB14,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 26: MOSI digital output line (electronic speed controller programming interface).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB15), GPIO_PIN_PB15,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 27: RST digital output line (electronic speed controller programming interface).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB12), GPIO_PIN_PB12,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 28: SCK digital output line (electronic speed controller programming interface).
    { GPIOB, GPIO_PIN_MASK(GPIO_PIN_PB13), GPIO_PIN_PB13,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 29: USB DM.
    { NULL,  GPIO_PIN_MASK(GPIO_PIN_PA11), GPIO_PIN_PA11,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 30: USB DP
    { NULL,  GPIO_PIN_MASK(GPIO_PIN_PA12), GPIO_PIN_PA12,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 31: USB ID.
    { GPIOA, GPIO_PIN_MASK(GPIO_PIN_PA10), GPIO_PIN_PA10,           0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
    // 32: USB VBUS.
    { NULL,  GPIO_PIN_MASK(GPIO_PIN_PA9),  GPIO_PIN_PA9,            0,                                                PWM_INSTANCE_NONE,  PWM_CHANNEL_NONE, ADC_INPUT_NONE },
};

// I2C bus (OBC).
extern const stm32l4_i2c_pins_t g_WirePins = { GPIO_PIN_PB8_I2C1_SCL, GPIO_PIN_PB9_I2C1_SDA };
extern const unsigned int g_WireInstance = I2C_INSTANCE_I2C1;
extern const unsigned int g_WireMode = I2C_MODE_RX_DMA;

// I2C bus (ADCS).
extern const stm32l4_i2c_pins_t g_Wire1Pins = { GPIO_PIN_PC0_I2C3_SCL, GPIO_PIN_PC1_I2C3_SDA };
extern const unsigned int g_Wire1Instance = I2C_INSTANCE_I2C3;
extern const unsigned int g_Wire1Mode = 0;

// SPI bus.
extern const stm32l4_spi_pins_t g_SPIPins = { GPIO_PIN_PB15_SPI2_MOSI, GPIO_PIN_PB14_SPI2_MISO, GPIO_PIN_PB13_SPI2_SCK, GPIO_PIN_NONE };
extern const unsigned int g_SPIInstance = SPI_INSTANCE_SPI2;
extern const unsigned int g_SPIMode = SPI_MODE_RX_DMA | SPI_MODE_TX_DMA;

// Disable JTAG on MTQX- control line and set it to high impedance during startup.
void initVariant()
{
  pinMode(MTQXMINUS, INPUT);
}
