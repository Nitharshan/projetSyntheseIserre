#include <stdint.h>
#include "common.h"
#include "uartCom1.h"

extern void UART_DRV_IRQHandler(uint32_t instance);
void UART2_IRQHandler(void)
{
  UART_DRV_IRQHandler(uartCom1_IDX);
}


uart_state_t uart_State;


// Setup et paramétrage de l'uart

void Uart_Init(uint32_t baud)
{
	///	\todo Write code here setup the uart.
	//uart_user_config_t uartConfig;
	uart_Config.baudRate = baud;
	uart_Config.bitCountPerChar =kUart8BitsPerChar;
	uart_Config.parityMode = kUartParityDisabled;
	uart_Config.stopBitCount = kUartOneStopBit;

	UART_DRV_Init(uartCom1_IDX, &uart_State, &uart_Config);

}

// Set le uart baudrate
void Uart_Setbaud(uint32_t baud)
{
	///	\todo Write code here set the uart baudrate. 
	UART_DRV_Deinit(uartCom1_IDX);
	uart_Config.baudRate = baud;

	UART_DRV_Init(uartCom1_IDX, &uart_State, &uart_Config);
}


// Verifie si le buffer est pret a recevoir des donnees
uint_fast8_t Uart_WriteBusy(void)
{
	uint_fast8_t ReturnState = TRUE;
	
	///	\todo Write code here that will get the MCU current write 
	/// buffer empty state and set ReturnState.
	
	if(UART_HAL_GetStatusFlag(g_uartBase[uartCom1_IDX], kUartTxDataRegEmpty)) {
		ReturnState = TRUE;
	}
	else
	{
		ReturnState = FALSE;
	}

	return ReturnState;
}

// Ecrit un seul byte
void Uart_WriteByte(uint8_t source)
{
	///	\todo Write code here that transmit one byte.
	UART_DRV_SendDataBlocking(uartCom1_IDX, &source, 1, 10);
}

// Lit un seul byte
uint_fast8_t Uart_ReadByte(uint8_t * destination)
{
	uint_fast8_t ReturnState = TRUE;

	///	\todo Write code here that reads one byte from uart and 
	///	set ReturnState TRUE of false depending
	///	if it was sucessful.
	
	if( UART_DRV_ReceiveDataBlocking(uartCom1_IDX, destination, 1, 10) == kStatus_UART_Success )
	{
		ReturnState = FALSE;
	}

	return ReturnState;
}
