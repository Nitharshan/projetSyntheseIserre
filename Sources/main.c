#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "uart_xb.h"
#include "DbgCs1.h"
#include "uartCom1.h"
#include "WAIT1.h"
#include "KSDK1.h"

#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

// User includes
#include "app.h"

// Lance l'exécution du programme
int main(void)
{
  /*Initialisation de Processor Expert*/
   PE_low_level_init();

	  app_run();

  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
 
  for(;;){}
  
} 

