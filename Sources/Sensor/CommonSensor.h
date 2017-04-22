/*
* CommonSensor.h
*
*  Created on: 2017-03-19
*      Author: iSerre
*/

#ifndef SOURCES_SENSOR_COMMONSENSOR_H_
#define SOURCES_SENSOR_COMMONSENSOR_H_

class CommonSensor
{
    public:
    virtual void read_sensor(float* measure) = 0;
    virtual void init_sensor() = 0;
};

class TemperatureSensor : public CommonSensor
{
    public:
    void read_sensor(float* measure);
    void init_sensor();
    void exec();
    private :
    float temp;
};

#endif /* SOURCES_SENSOR_COMMONSENSOR_H_ */
