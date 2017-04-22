/*
* TemperatureSensor.cpp
*
*  Created on: 2017-03-19
*      Author: iSerre
*/

#include "CommonSensor.h"
#include "Sensor.h"
#include "stdio.h"
#include "DbgCs1.h"

void TemperatureSensor :: read_sensor(float* measure) {
    readTemperature(measure);
}

void TemperatureSensor :: init_sensor() {

}

void TemperatureSensor :: exec() {
   char buffer[20]="";
    read_sensor(&temp); // Première lecture non envoyée (calibrage)
    debug_printf("%s", "temperature : ");
    snprintf(buffer, sizeof buffer, "%3.4f", temp);
    debug_printf("%s", buffer);
    debug_printf("%s", "\n");
}
