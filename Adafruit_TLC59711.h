/*!
 *  @file Adafruit_TLC59711.h
 *
 *  This is a library for the Adafruit 12-channel PWM/LED driver
 *
 *  Designed specifically to work with the Adafruit 12-channel PWM/LED driver
 *
 *  Pick one up today in the adafruit shop!
 *  ------> https://www.adafruit.com/product/1455
 *
 *  These sensor uses SPI to communicate, 3 pins are required to  
 *  interface: Data, Clock and Latch. The boards are chainable
 *
 *  Adafruit invests time and resources providing this open source code,
 *  please support Adafruit andopen-source hardware by purchasing products
 *  from Adafruit!
 *
 *  Limor Fried/Ladyada (Adafruit Industries).
 *
 *  BSD license, all text above must be included in any redistribution
 */

#ifndef _ADAFRUIT_TLC59711_H
#define _ADAFRUIT_TLC59711_H

#include <Arduino.h>


/*!
 *  @brief  Class that stores state and functions for interacting with
 *          TLC59711 Senor
 */
class Adafruit_TLC59711 {
 public:
  Adafruit_TLC59711(uint8_t n, uint8_t c, uint8_t d);
  Adafruit_TLC59711(uint8_t n);

  boolean begin();

  void setPWM(uint8_t chan, uint16_t pwm);
  void setLED(uint8_t lednum, uint16_t r, uint16_t g, uint16_t b);
  void write();
  void spiwriteMSB(uint32_t d);

 private:
  uint16_t *pwmbuffer;

  uint8_t BCr, BCg, BCb;
  int8_t numdrivers, _clk, _dat;

};


#endif
