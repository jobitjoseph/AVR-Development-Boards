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
// Transfers content of EEPROM via UART.
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
  DEBUG_init();                         // init DEBUG (TX: P31, BAUD: 115200, 8N1)
  EEPROM_write(0, 0x5a);                // write value to EEPROM address 0

  // Loop
  while (1) {
    uint8_t i,j;
    uint16_t addr = 0;
    DEBUG_printf("\nEEPROM Hex Dump:\n");
    for(j=EEPROM_SIZE/16; j; j--) {
      DEBUG_printf("%04x: ", addr);
      for(i=16; i; i--) {
        DEBUG_printf("%02x ", EEPROM_read(addr++));
      }
      DEBUG_printf("\n");
    }
    DLY_ms(1000);
  }
}
