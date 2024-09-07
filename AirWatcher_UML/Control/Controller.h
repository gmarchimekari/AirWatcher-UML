#if !defined(CONTROLLER_H)
#define CONTROLLER_H

#include "../Model/Statistics.h"
#include "CsvParser.h"

class Statistics;

class Controller
{

public:
    Controller(const Controller &unController);
    Controller();
    virtual ~Controller();

    /**
     * @brief calculates the mean air quality index during a period of time for a specific zone
     * If 
     *
     * @param data the data to use
     * @param start the start of the period (it's a date)
     * @param end the end of the period (it's a date)
     * @param lat the latitude of the center of the zone
     * @param lon the longitude of the center of the zone
     * @param radius the radius of the zone
     * @return int the mean air quality index
     */
    int getMeanAirQualityByZoneByPeriod(Data *data, tm *start, tm *end, double lat, double lon, double radius);

    /**
     * @brief calculates the mean air quality index at a specific time (a specific date) for a specific zone
     *
     * @param data the data to use
     * @param time the time at which the air quality index is calculated
     * @param lat the latitude of the center of the zone
     * @param lon the longitude of the center of the zone
     * @param radius the radius of the zone
     * @return int the mean air quality index
     */
    int getMeanAirQualityByZoneByTime(Data *data, tm *time, double lat, double lon, double radius);

    /**
     * @brief Return a list of sensors order by the similarity to the sensor that called the function,
     * the similarity is calculated by the index atmo
     *
     * @param data the data 
     * @param timeStart the start time of the period to check the similarity
     * @param timeEnd the end time of the period to check the similarity
     * @return PrivateIndividual* the private individual linked to the sensor or null if no private individual is linked to the sensor
     */
    vector<Sensor*> getSimilarSensors(Sensor* sensor, Data *data, string measurementType, tm* timeStart, tm* timeEnd) const;

    Data* getData() const;

private:
    CsvParser *csv;
    Data *data;
    Statistics *stats;
};

#endif // CONTROLLER_H
