/*
 * DS18B20_driver.c
 *
 *  Created on: Oct 28, 2016
 *      Author: Kadiatou
 */

#include "sensor.h"


void DS18B20_LireScratchpad(DS18B20_scratchpad_t* scratchpad)
{
	if(OneWire_Reset() == 1)
		debug_printf("Fail reset\n\r");
	OneWire_Write(DS18B20_CMD_SKIP_ROM);
	OneWire_Write(DS18B20_CMD_READ_SCRATCHPAD);

	for(int i = 0 ; i < DS18B20_SCRATCHPAD_SIZE ; i++)
		if(OneWire_Read(&scratchpad->data[i]) == 1)
			debug_printf("fail read_scratchpad\n\r");
}

void DS18B20_LireROM()
{
	if(OneWire_Reset() == 1)
			debug_printf("fail\n\r");
	uint8_t rom[8] = {1,1,1,1,1,1,1,1};
	OneWire_Write(DS18B20_CMD_READ_ROM);
	for(int i = 0 ; i < 8 ; i++)
	{
		OneWire_Read(&rom[i]);
	}

	debug_printf("ROM : ");

	for(int i = 0 ; i < 8 ; i++)
	{
		debug_printf("%x ",(int)rom[i]);
	}

	debug_printf("\n\n\r");
}

void DS18B20_LireTemperature(float *temperature )
{
	DS18B20_scratchpad_t scratchpad;
	int HighByte, LowByte, TReading, SignBit, Whole, Fract;
	float Tc_100;

	if(OneWire_Reset() == 1)
		debug_printf("Fail reset\n\r");
	OneWire_Write(DS18B20_CMD_SKIP_ROM);
	OneWire_Write(DS18B20_CMD_CONVERT_T);

	DS18B20_LireScratchpad(&scratchpad);

	// Conversion HEX -> Decimal pour la temperature
	LowByte = scratchpad.data[0];
	HighByte = scratchpad.data[1];

	// Temperature en binaire sur 16 bits
	TReading = (HighByte << 8) + LowByte;
	SignBit = TReading & 0x8000;  // test most significant bit
	if (SignBit) // negative
	{
		TReading = (TReading ^ 0xffff) + 1; // Complement 2 si le signe est negatif
	}

	// 0.0625deg est la precision du capteur et 100 sert a separer partie entiere et decimale
	Tc_100 = ((6. * TReading) + TReading / 4.)/100;    // multiply by (100 * 0.0625) or 6.25

//	Whole = Tc_100 / 100;  // separate off the whole and fractional portions
//	Fract = Tc_100 % 100;

	 *temperature = Tc_100;
	// Affichage temperature
	// debug_printf("Température = ");
	if (SignBit) // If negative
	{
		*temperature =-Tc_100;
		//  debug_printf("-");
	}
	// debug_printf("%d",Whole);
	// debug_printf(".");
	if (Fract < 10)
	{

	}
	// debug_printf("%d",Fract);

//	*temperature =Tc_100 + Fract;

}
