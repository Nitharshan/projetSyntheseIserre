/* ###################################################################
**     Filename    : Events.c
**     Project     : Xbee Sandbox
**     Processor   : MKL26Z128VLH4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-03, 11:48, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "utility/Clock.h"

#ifdef __cplusplus
extern "C" {
    #endif


    /* User includes (#include below this line is not maintained by Processor Expert) */
    #include "app.h"

    /*
    ** ===================================================================
    **     Callback    : uartCom1_TxCallback
    **     Description : This callback occurs when data are transmitted.
    **     Parameters  :
    **       instance - The UART instance number.
    **       uartState - A pointer to the UART driver state structure
    **       memory.
    **     Returns : Nothing
    ** ===================================================================
    */
    void uartCom1_TxCallback(uint32_t instance, void * uartState)
    {
        /* Write your code here ... */
    }

    #ifdef PIT_Timer0_IDX
    /*
    ** ===================================================================
    **     Interrupt handler : PIT_IRQHandler
    **
    **     Description :
    **         User interrupt service routine.
    **     Parameters  : None
    **     Returns     : Nothing
    ** ===================================================================
    */
    void PIT_IRQHandler(void)
    {
        /* Clear interrupt flag.*/
        PIT_HAL_ClearIntFlag(g_pitBase[PIT_Timer0_IDX], PIT_Timer0_CHANNEL);
        Clock_incrementMsCounter();
        /* Write your code here ... */
    }
    #else
        /* This IRQ handler is not used by PIT_Timer0 component. The purpose may be
    * that the component has been removed or disabled. It is recommended to
    * remove this handler because Processor Expert cannot modify it according to
    * possible new request (e.g. in case that another component uses this
    * interrupt vector). */
    #warning This IRQ handler is not used by PIT_Timer0 component.\
    It is recommended to remove this because Processor Expert cannot\
    modify it according to possible new request.
    #endif

    /* END Events */

    #ifdef __cplusplus
}  /* extern "C" */
#endif

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
