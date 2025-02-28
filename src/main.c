#include "config.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PIN5_bm

void setup_clock_16mhz() { _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x00); }

int main() {
  setup_clock_16mhz();

  UART_init();

  PORTB.DIRSET = LED_PIN;
  while (1) {
    PORTB.OUTTGL = LED_PIN;
    UART_sendString("Hello, AVR!\r\n");
    _delay_ms(500);
  }
}
