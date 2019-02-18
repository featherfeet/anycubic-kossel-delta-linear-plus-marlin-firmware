l/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
/**
 *                                                             {===================================================]
 *                                                                     Anycubic linear plus - Marlin v1.1.8
 *                                                                                    01/2018
 *                                                             {===================================================]
 */
/**
 *                                                            Changelog :
 *                                                            -Configuration.h :
 *                                                               -Delta setting | Autoleveling |Z prob |speed XYZ | temp extr/bed | m600 | TMC2208 sur X Y Z | sens moteur inverser
 *                                                               
 *                                                            -Configuration_adv.h :   
 *                                                               -M600 : activer
 *                                                               - CUSTOM_MENU :
 *                                                                 #define USER_DESC_1 "Home & level"         USER_GCODE_1 "G28\nG29" 
 *                                                                 #define USER_DESC_2 "Home & stat"          USER_GCODE_2 "G28\nM78"
 *                                                                 #define USER_DESC_3 "Home & steppers off"  USER_GCODE_3 "G28\nM84"
 *                                                                 #define USER_DESC_4 "Extruder 25mm de PLA" USER_GCODE_4 "M140 S"PREHEAT_2_TEMP_HOTEND"\nM104 S70\nG91 E25 F300\nG92 E0\nG1 E-1 F300 " //chauffe,extrude 25mm de pla et retract 1mm
 *                                                                 #define USER_DESC_5 "Changer de filament"  USER_GCODE_5 "M600"
 *                                                               
 *                                                               
 *                                                               
 *                                                               
 *                                                               
 *                                                               
 */
/**
 * About Marlin
 *
 * This firmware is a mashup between Sprinter and grbl.
 *  - https://github.com/kliment/Sprinter
 *  - https://github.com/simen/grbl/tree
 */

#include "MarlinConfig.h"

#if ENABLED(ULTRA_LCD)
  #if ENABLED(LCD_I2C_TYPE_PCF8575)
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
  #elif ENABLED(LCD_I2C_TYPE_MCP23017) || ENABLED(LCD_I2C_TYPE_MCP23008)
    #include <Wire.h>
    #include <LiquidTWI2.h>
  #elif ENABLED(LCM1602)
    #include <Wire.h>
    #include <LCD.h>
    #include <LiquidCrystal_I2C.h>
  #elif ENABLED(DOGLCD)
    #include <U8glib.h> // library for graphics LCD by Oli Kraus (https://github.com/olikraus/U8glib_Arduino)
  #else
    #include <LiquidCrystal.h> // library for character LCD
  #endif
#endif

#if HAS_DIGIPOTSS
  #include <SPI.h>
#endif

#if ENABLED(DIGIPOT_I2C)
  #include <Wire.h>
#endif

#if ENABLED(HAVE_TMCDRIVER)
  #include <SPI.h>
  #include <TMC26XStepper.h>
#endif

#if ENABLED(HAVE_TMC2130)
  #include <SPI.h>
  #include <TMC2130Stepper.h>
#endif

#if ENABLED(HAVE_L6470DRIVER)
  #include <SPI.h>
  #include <L6470.h>
#endif
