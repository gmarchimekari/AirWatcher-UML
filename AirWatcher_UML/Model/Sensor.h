#if !defined(SENSOR_H)
#define SENSOR_H

#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include "Data.h"

using namespace std;

class PrivateIndividual;
class Data;

class Sensor
{

public:
    bool operator==(const Sensor &unSensor);
    Sensor(const Sensor &unSensor);
    Sensor(string unSensorId, double uneLatitude, double uneLongitude);
    virtual ~Sensor();
    string getSensorId() const;
    double getLatitude() const;
    double getLongitude() const;

    /**
     * @brief calculates the distance in km between a point given by its latitude and longitude and
     * the position of the sensor
     *
     * @param latitude
     * @param longitude
     * @return double the result in km
     */
    double calculateDistance(double latitude, double longitude) const;

    /**
     * @brief Get the Private Individual Link To The Sensor object
     *
     * @param data the data to check if a private individual is linked to the sensor
     * @return PrivateIndividual* the private individual linked to the sensor or null if no private individual is linked to the sensor
     */
    PrivateIndividual *getPrivateIndividualLinkToTheSensor(Data *data) const;

    /**
     * @brief Return a list of sensors order by the similarity to the sensor that called the function (of course the sensor that called the function is the first element of the list)
     * the similarity is calculated by the index atmo
     *
     * @param data the data
     * @param timeStart the start time of the period to check the similarity
     * @param timeEnd the end time of the period to check the similarity
     * @return PrivateIndividual* the private individual linked to the sensor or null if no private individual is linked to the sensor
     */
    vector<Sensor *> getSimilarSensors(Data *data, string measurementType, tm *timeStart, tm *timeEnd);

private:
    string sensorId;
    double latitude;
    double longitude;

    friend class SensorTest;
};

#endif // SENSOR_H
