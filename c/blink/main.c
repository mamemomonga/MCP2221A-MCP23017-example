#include "../easymcp2221.h"

int main(void) {
	if(init_app()){ return 1; }

	uint8_t sweep[]={0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
	uint8_t szSweep=sizeof(sweep);

	// 0x00: IODIRA
	mcp23017Write(0x00,0x00);
	while(1) {
		for(uint8_t i=0; i<szSweep; i++) {
			// 0x14: OLATA
			mcp23017Write(0x14,sweep[i]);
			sleep_ms(40);
		}
		for(uint8_t i=0; i<3; i++) {
			mcp23017Write(0x14,0xFF); sleep_ms(50);
			mcp23017Write(0x14,0x00); sleep_ms(50);
		}
		for(uint8_t i=szSweep; i>0; i--) {
			mcp23017Write(0x14,sweep[i]);
			sleep_ms(40);
		}
		for(uint8_t i=0; i<3; i++) {
			mcp23017Write(0x14,0xFF); sleep_ms(50);
			mcp23017Write(0x14,0x00); sleep_ms(50);
		}
	}
	return 0;
}

