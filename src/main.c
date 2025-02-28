#include "config.h"
#include "uart.h"
#include <util/delay.h>

int main() {
  UART_init();
  while (1) {
    UART_sendString("Hello, AVR!\r\n");
    _delay_ms(1000);
  }
}
