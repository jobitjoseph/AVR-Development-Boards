// ===================================================================================
// Project:   Example for ATtiny3216
// Version:   v1.0
// Year:      2021
// Author:    Stefan Wagner
// Github:    https://github.com/wagiminator
// EasyEDA:   https://easyeda.com/wagiminator
// License:   http://creativecommons.org/licenses/by-sa/3.0/
// ===================================================================================
//
// Description:
// ------------
// Blink built-in LED using millis counter.
//
// Compilation Instructions:
// -------------------------
// - Make sure GCC toolchain (gcc-avr, avr-libc) and Python3 with PySerial is
//   installed. If necessary, a driver for the USB-to-serial converter used by the
//   SerialUPDI programmer must be installed.
// - Connect the SerialUPDI programmer to the UPDI pin of the MCU.
// - Run 'make flash'.


// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================
#include "system.h"                   // for system functions
#include "gpio.h"                     // for GPIO functions
#include "millis.h"

#define PIN_LED   PA7                 // define LED pin

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  // Setup
  CLK_init();                         // set system clock frequency
  MIL_init();                         // init and start millis counter
  PIN_output(PIN_LED);                // set LED pin to output
  
  uint32_t next = 100;                // next event in 100ms

  // Loop
  while(1) {
    while(MIL_read() < next);         // wait for next event
    PIN_toggle(PIN_LED);              // toggle LED
    next += 100;                      // next event in 100ms
  }
}
