#if !defined(MEASUREMENT_H)
#define MEASUREMENT_H

#include <ctime>
#include <sstream>
#include "Sensor.h"

class Sensor;

class Measurement
{

public:
    Measurement(const Measurement &unMeasurement);
    Measurement(Sensor *sensor, string type, double value, string timeString);
    virtual ~Measurement();
    Sensor *getSensor() const;
    string getType() const;
    double getValue() const;
    tm *getTime() const;

    /**
     * @brief check if the measurement is in the period defined by the start and end parameters
     *
     * @param start the start of the period
     * @param end the end of the period
     * @return bool true if the measurement is in the period, false otherwise
     */
    bool isInPeriod(tm *start, tm *end);

private:
    Sensor *sensor;
    string type;
    double value;
    tm *time;
};
#endif // MEASUREMENT_H
