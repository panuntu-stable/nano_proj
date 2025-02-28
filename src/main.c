#include "config.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PIN5_bm

int main() {
  UART_init();
  PORTB.DIRSET = LED_PIN;
  while (1) {
    PORTB.OUTTGL = LED_PIN;
    UART_sendString("Hello, AVR!\r\n");
    _delay_ms(1000);
  }
}
