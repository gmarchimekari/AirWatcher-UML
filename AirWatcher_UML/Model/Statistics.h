#if !defined(STATISTICS_H)
#define STATISTICS_H
#include <string>
#include <ctime>
#include "Data.h"

class Statistics
{

public:
    Statistics(const Statistics &unStatistics);
    Statistics();
    virtual ~Statistics();

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

private:
    /**
     * @brief calculates the air quality index based on the concentration of the pollutants, the arguments given
     * corresponds respectively to the concentration of So2, No2, Pm10 and O3 (in that order).
     *
     * @param cSo2 the concentration of So2
     * @param cNo2 the concentration of No2
     * @param cPm10 the concentration of Pm10
     * @param cO3 the concentration of O3
     * @return int the ATMO Index corresponding to the air quality
     */
    int calculateAirQuality(double cSo2, double cNo2, double cPm10, double cO3);

    /**
     * @brief calculates the index of the So2 pollutant based on its concentration
     *
     * @param concentration the concentration of the So2 pollutant
     * @return int the index of the So2 pollutant
     */
    int calculateIndexSo2(double concentration);

    /**
     * @brief calculates the index of the No2 pollutant based on its concentration
     *
     * @param concentration the concentration of the No2 pollutant
     * @return int the index of the No2 pollutant
     */
    int calculateIndexNo2(double concentration);

    /**
     * @brief calculates the index of the Pm10 pollutant based on its concentration
     *
     * @param concentration the concentration of the Pm10 pollutant
     * @return int the index of the Pm10 pollutant
     */
    int calculateIndexPm10(double concentration);

    /**
     * @brief calculates the index of the O3 pollutant based on its concentration
     *
     * @param concentration the concentration of the O3 pollutant
     * @return int the index of the O3 pollutant
     */
    int calculateIndexO3(double concentration);

    friend class StatisticsTest;
};

#endif // STATISTICS_H
