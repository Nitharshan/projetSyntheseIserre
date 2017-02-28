#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 

#include "app.h"

/*
** ===================================================================
**     Callback    : uart_xb_RxCallback
**     Description : This callback occurs when data are received.
**     Parameters  :
**       instance - The UART instance number.
**       uartState - A pointer to the UART driver state structure
**       memory.
**     Returns : Nothing
** ===================================================================
*/

	//Callback réalisé lors de la réception de donnée, rajoute la donnée dans la structure UART
void uart_xb_RxCallback(uint32_t instance, void * uartState)
{
  /* Write your code here ... */
	uart_state_t *state = (uart_state_t*)uartState;
	struct Fifo* fifo = (struct Fifo*)(state->rxCallbackParam);

	fifo->data[fifo->end] = state->rxBuff[0];
	fifo->end++;
	if(fifo->end == FIFO_SIZE)
		fifo->end = 0;

}


#ifdef __cplusplus
}  /* extern "C" */
#endif 

