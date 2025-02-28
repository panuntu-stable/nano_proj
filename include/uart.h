#ifndef UART_H
#define UART_H

#include <avr/io.h>

void UART_init(void);
void UART_sendChar(char c);
void UART_sendString(const char *str);

#endif
