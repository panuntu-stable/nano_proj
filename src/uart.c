#include "uart.h"
#include "config.h"
#include <stdint.h>

void UART_init() {
  PORTMUX.USARTROUTEA = PORTMUX_USART3_DEFAULT_gc;

  USART3.CTRLC |= USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc |
                  USART_SBMODE_1BIT_gc;

  PORTD.DIRSET = PIN0_bm;
  PORTD.DIRCLR = PIN1_bm;
  USART3.BAUD = (uint16_t)((F_CPU * 64) / (16 * BAUD_RATE));
  USART3.CTRLB |= USART_TXEN_bm;
}

void UART_sendChar(char c) {
  while ((USART3.STATUS & USART_DREIF_bm) == 0)
    ;
  USART3.TXDATAL = c;
}

void UART_sendString(const char *str) {
  // for (; *str != '\0'; str++) {
  //  UART_sendChar(*str++);
  while (*str) {
    UART_sendChar(*str);
    str++;
  }
}
