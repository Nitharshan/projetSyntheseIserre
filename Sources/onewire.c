#include <stdint.h>
#include "common.h"
#include "uart.h"


///	\brief	This is the data used to reset the 1 wire node
static const uint_fast8_t ResetData = 0xF0;

///	\brief	Define the true state
static const uint_fast8_t OneWireTrue = 0XFF;

///	\brief	Define the false state
static const uint_fast8_t OneWireFalse = 0X00;

///	\brief	Baudrate for 9600
static const uint_fast16_t Baudrate9600 = 9600;

///	\brief	Baudrate for 115200
static const uint_fast16_t Baudrate115200 = 115200;

///	\brief	Defines how many bytes in the bit state
static const uint_fast8_t OneWireBitLength = 0x08;

///	\brief	Bit mask
static const uint_fast8_t OneWireBitMask = 0x01;

// Lit un byte du device
int_fast8_t OneWire_Read(uint8_t *data)
{
    uint8_t Index = OneWireBitLength;
    uint8_t ReturnValue = 0;
    uint8_t Temp;
    
		Uart_Setbaud(Baudrate115200);
	
    while(Index)
    {
        //write a true
        Uart_WriteByte(OneWireTrue);

        //Dummy Read
        if(Uart_ReadByte(&Temp))
        {
					// Error while waiting for data to be received
					return TRUE;
				}
		
        ReturnValue = ReturnValue >> 1; //ShiftData
				
        if( Temp == OneWireTrue)
        {
            ReturnValue += 0x80;
        }
		
        //Count Away
        Index--;
    }

    *data = ReturnValue;
	
    return FALSE;
}

// Ecrit un seul byte
int_fast8_t OneWire_Write(const uint8_t source)
{
	uint8_t Index = OneWireBitLength;
	uint8_t Temp = source;
	uint8_t Dummy = 0;
	
	Uart_Setbaud(Baudrate115200);
	
    while(Index) // Read one byte
    {
				//Wait here until there space to send the next bit of data
				while(!Uart_WriteBusy()) ;
			
        if(Temp & OneWireBitMask)
        {
            //write a true
            Uart_WriteByte(OneWireTrue);
        }
        else
        {
            //write a false
            Uart_WriteByte(OneWireFalse);
        }
        
        //Dummy Read
        if(Uart_ReadByte(&Dummy))
        {
					// Error no data was received
					return TRUE;
				}

        Temp = Temp >> 1; //Shift over to next byte
        Index--; //decrement count
    }
    
    return FALSE;    
}

// Reset le terminal 1wire connecté
uint8_t OneWire_Reset(void)
{
	uint8_t Data = 0;
	Uart_Setbaud(Baudrate9600);
	
	Uart_WriteByte(ResetData); //Send the reset command
	
	//wait for data to be received
	if(Uart_ReadByte(&Data))
	{
		return TRUE; // Error while waiting for data to be received
	}
	
	// check if device is in the network
	if(Data == ResetData)
	{
		return TRUE; //Error device not found
	}
	
	return FALSE; // Device is available
}

// Initialise l'interface 1wire
void OneWire_Init(void)
{
	Uart_Init(Baudrate9600);
	OneWire_Reset();
}

// Calcule le 1wire CRC a partir du tableau fourni
uint8_t OneWire_CalculateCRC(uint8_t * source, uint8_t length) 
{ 
	uint8_t BitIndex;
	uint8_t CRC = 0;

	while(length)
	{
		CRC = CRC ^ *source;
		
		for (BitIndex = 0; BitIndex < 8; BitIndex++) 
		{ 
			if (CRC & 0x01) 
			{
				CRC = (CRC >> 1) ^ 0x8C; 
			}
			else
			{
				CRC >>= 1; 
			}
		} 
		
		source++;
		length--;
	}
	return CRC; 
}
