// ===================================================================================
// Project:   Example for ATtiny814
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
// Sends a message via UART once a second.
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
#include "system.h"                     // for system functions
#include "debug_serial.h"               // serial debug functions

// ===================================================================================
// Main Function
// ===================================================================================
int main (void) {
  // Setup
  CLK_init();                           // set system clock frequency
  DEBUG_init();                         // init DEBUG (TX: PB2, BAUD: 115200, 8N1)

  // Loop
  while (1) {
    DEBUG_println("Hello world!");      // send message via UART
    DLY_ms(1000);                       // wait a bit
  }
}
