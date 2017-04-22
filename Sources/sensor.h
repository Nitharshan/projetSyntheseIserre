/*
* DS18B20driver.h
*
*  Created on: Oct 28, 2016
*      Author: Kadiatou
*/

#ifndef SOURCES_SENSOR_H_
#define SOURCES_SENSOR_H_

#define DS18B20_CMD_READ_ROM  			0x33
#define DS18B20_CMD_MATCH_ROM 			0x55
#define DS18B20_CMD_SEARCH_ROM 			0xF0
#define DS18B20_CMD_ALARM_SEARCH 		0xEC
#define DS18B20_CMD_SKIP_ROM 			0xCC
#define DS18B20_CMD_CONVERT_T 			0x44
#define DS18B20_CMD_READ_SCRATCHPAD 	0xBE
#define DS18B20_CMD_WRITE_SCRATCHPAD 	0x4E
#define DS18B20_CMD_COPY_SCRATCHPAD 	0x48
#define DS18B20_CMD_RECALL_E2 			0xB8
#define DS18B20_CMD_READ_POWER_SUPPLY 	0xB4

#define DS18B20_SCRATCHPAD_SIZE			(9U)

#include "stdint.h"
#include "1wire/onewire.h"

typedef struct DS18B20_scratchpad_s
{
    uint8_t data[DS18B20_SCRATCHPAD_SIZE];

} scratchpad_t;

void readTemperature(float *temperature );
void readScratchpad(scratchpad_t* scratchpad);
void readROM();



#endif /* SOURCES_SENSOR_H_ */
