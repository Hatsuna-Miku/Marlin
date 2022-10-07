/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Espressif ESP32 (Tensilica Xtensa LX6) pin assignments
 */

#include "env_validate.h"

#define BOARD_INFO_NAME "MINITREE_MINIS"

//
// I2S (steppers & other output-only pins)
//
#define I2S_STEPPER_STREAM
#define I2S_WS                                26 //输出时序
#define I2S_BCK                               25 //采样时序
#define I2S_DATA                              27 //数据时序
#undef LIN_ADVANCE

//
// Limit Switches
//
#define X_MIN_PIN                             15
#ifndef Y_MAX_ZERO
#define Y_MIN_PIN                             13
#else
#define Y_MAX_PIN                             13
#endif
#define Z_MIN_PIN                             17
#define FIL_RUNOUT_PIN                        16

#define I2S_PINSET(PIN) (128 + PIN)
//
// Steppers
//
#define X_STEP_PIN                           I2S_PINSET(0)
#define X_DIR_PIN                            I2S_PINSET(1)
#define X_ENABLE_PIN                         33

#define Y_STEP_PIN                           I2S_PINSET(2)
#define Y_DIR_PIN                            I2S_PINSET(3)
#define Y_ENABLE_PIN                         X_ENABLE_PIN

#define Z_STEP_PIN                           I2S_PINSET(4)
#define Z_DIR_PIN                            I2S_PINSET(5)
#define Z_ENABLE_PIN                         X_ENABLE_PIN

#define E0_STEP_PIN                          I2S_PINSET(6)
#define E0_DIR_PIN                           I2S_PINSET(7)
#define E0_ENABLE_PIN                        X_ENABLE_PIN

//
// Temperature Sensors
//
#define TEMP_0_PIN                            39  // Analog Input
#define TEMP_BED_PIN                          36  // Analog Input
#define ADC_REFERENCE_VOLTAGE                 2.992

//
// Heaters / Fans / Servo
//

#define HEATER_0_PIN                          12
#ifdef BED_FAN_TUNE
#define FAN_PIN                                4
#define HEATER_BED_PIN                         0
#else
#define FAN_PIN                                0
#define HEATER_BED_PIN                         4
#endif
#define FAN_LASER                                 //FAN0 -> LASER
#define SERVO0_PIN                             2
#define SPINDLE_LASER_PWM_PIN                  I2S_PINSET(8)  //占位符
#define Z_MIN_PROBE_PIN                        2

// Screen
#define BTN_ENC                               32
#define BTN_EN1                               34
#define BTN_EN2                               35

#define I2C_SCL_PIN                           22
#define I2C_SDA_PIN                           21

// SD-SPI
#define SD_MOSI_PIN                           18
#define SD_MISO_PIN                           23
#define SD_SCK_PIN                            19
#define SDSS                                  5

// TMC-SHARE-UART
/**
   * 地址    | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
*/
//                                             ↓ 地址
#define  X_SLAVE_ADDRESS                       0
#define  Y_SLAVE_ADDRESS                       1
#define  Z_SLAVE_ADDRESS                       2
#define  E0_SLAVE_ADDRESS                      3

#define HARDWARE_TMC_SERIAL

#if ENABLED(HARDWARE_TMC_SERIAL)
#define X_HARDWARE_SERIAL                      Serial2
#define Y_HARDWARE_SERIAL                      Serial2
#define Z_HARDWARE_SERIAL                      Serial2
#define E0_HARDWARE_SERIAL                     Serial2

#define TMC_BAUD_RATE 19200

#define HARDWARE_SERIAL2_RX                   14
#define HARDWARE_SERIAL2_TX                   14

#define TMC_UART_NOCHECK

#else
  #define X_SERIAL_TX_PIN                  14
  #define X_SERIAL_RX_PIN                  X_SERIAL_TX_PIN

  #define Y_SERIAL_TX_PIN                  X_SERIAL_TX_PIN
  #define Y_SERIAL_RX_PIN                  X_SERIAL_TX_PIN

  #define Z_SERIAL_TX_PIN                  X_SERIAL_TX_PIN
  #define Z_SERIAL_RX_PIN                  X_SERIAL_TX_PIN

  #define E0_SERIAL_TX_PIN                 X_SERIAL_TX_PIN
  #define E0_SERIAL_RX_PIN                 X_SERIAL_TX_PIN
  #define TMC_BAUD_RATE 19200
#endif
