#ifndef EASYMCP2221_H_
#define EASYMCP2221_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <libmcp2221.h>

#define MCP23017_ADDR 0x20

#define mcp23017Write(a,b) { i2cWrite2byte(MCP23017_ADDR,a,b); }
#define mcp23017Read(a,b) { i2cWrite1byte(MCP23017_ADDR,a); *b=i2cRead1byte(MCP23017_ADDR); }
#define sleep_ms(a) { usleep( a*1000 ); }

extern int init_app(void);
extern void i2cWrite2byte(uint8_t, uint8_t, uint8_t);
extern void i2cWrite1byte(uint8_t, uint8_t);
extern uint8_t i2cRead1byte(uint8_t);
extern void gpioInterrupt(void(*)(void));

mcp2221_t*   myMCP2221;

#endif /* EASYMCP2221_H_ */
