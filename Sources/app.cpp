#include "app.h"
#include "sensor.h"
#include "iSN\ZbeeStack.h"
#include "1wire/onewire.h"
#include "stdio.h"
#include <string>
#include "DbgCs1.h"
#include "Sensor/CommonSensor.h"
#include "iSN\iSN.h"
#include "uart_xb.h"


using namespace tomyClient;

void app_run() {

    TemperatureSensor capteur;

    XBeeConfig theAppConfig = {
        57600,          //Baudrate (bps)
        0,              //Serial PortNo
        0               //Device (for linux App)
    };

    Network net(UART2_IDX, &uart_xb_InitConfig0, &uart_xb_State);
    net.initialize(theAppConfig);

    IsnClient client(&net, ISN_SENSOR_TEMP);
    client.setSensor(&capteur);

    while (true)
    {
        client.exec();
    }
}
