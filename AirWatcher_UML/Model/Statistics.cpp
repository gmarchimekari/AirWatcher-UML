using namespace std;
#include <iostream>
#include "Statistics.h"

Statistics::Statistics()
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistics>" << endl;
#endif
}

Statistics::~Statistics()
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistics>" << endl;
#endif
}

Statistics::Statistics(const Statistics &unStatistics)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Statistics>" << endl;
#endif
}

// Helper function to calculate the maximum of 4 integers
int max(int a, int b, int c, int d)
{
    int max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    if (d > max)
    {
        max = d;
    }
    return max;
}

int Statistics::calculateAirQuality(double cSo2, double cNo2, double cPm10, double cO3)
{
    int indexSo2 = calculateIndexSo2(cSo2);
    int indexNo2 = calculateIndexNo2(cNo2);
    int indexPm10 = calculateIndexPm10(cPm10);
    int indexO3 = calculateIndexO3(cO3);


    // Return the maximum of the 4 indexes
    return max(indexSo2, indexNo2, indexPm10, indexO3);
}

int Statistics::calculateIndexSo2(double concentration)
{
    if (concentration < 0)
    {
        return -1;
    }
    if (concentration <= 39)
    {
        return 1;
    }
    else if (concentration <= 79)
    {
        return 2;
    }
    else if (concentration <= 119)
    {
        return 3;
    }
    else if (concentration <= 159)
    {
        return 4;
    }
    else if (concentration <= 199)
    {
        return 5;
    }
    else if (concentration <= 249)
    {
        return 6;
    }
    else if (concentration <= 299)
    {
        return 7;
    }
    else if (concentration <= 399)
    {
        return 8;
    }
    else if (concentration <= 499)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int Statistics::calculateIndexNo2(double concentration)
{
    if (concentration < 0)
    {
        return -1;
    }
    if (concentration <= 29)
    {
        return 1;
    }
    else if (concentration <= 54)
    {
        return 2;
    }
    else if (concentration <= 84)
    {
        return 3;
    }
    else if (concentration <= 109)
    {
        return 4;
    }
    else if (concentration <= 134)
    {
        return 5;
    }
    else if (concentration <= 164)
    {
        return 6;
    }
    else if (concentration <= 199)
    {
        return 7;
    }
    else if (concentration <= 274)
    {
        return 8;
    }
    else if (concentration <= 399)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int Statistics::calculateIndexPm10(double concentration)
{
    if (concentration < 0)
    {
        return -1;
    }
    if (concentration <= 6)
    {
        return 1;
    }
    else if (concentration <= 13)
    {
        return 2;
    }
    else if (concentration <= 20)
    {
        return 3;
    }
    else if (concentration <= 27)
    {
        return 4;
    }
    else if (concentration <= 34)
    {
        return 5;
    }
    else if (concentration <= 41)
    {
        return 6;
    }
    else if (concentration <= 49)
    {
        return 7;
    }
    else if (concentration <= 64)
    {
        return 8;
    }
    else if (concentration <= 79)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int Statistics::calculateIndexO3(double concentration)
{
    if (concentration < 0)
    {
        return -1;
    }
    if (concentration <= 29)
    {
        return 1;
    }
    else if (concentration <= 54)
    {
        return 2;
    }
    else if (concentration <= 79)
    {
        return 3;
    }
    else if (concentration <= 104)
    {
        return 4;
    }
    else if (concentration <= 129)
    {
        return 5;
    }
    else if (concentration <= 149)
    {
        return 6;
    }
    else if (concentration <= 179)
    {
        return 7;
    }
    else if (concentration <= 209)
    {
        return 8;
    }
    else if (concentration <= 239)
    {
        return 9;
    }
    else
    {
        return 10;
    }
}

int Statistics::getMeanAirQualityByZoneByPeriod(Data *data, tm *start, tm *end, double lat, double lon, double radius)
{
    double meanConcentrationSo2=0, countSo2 = 0;
    double meanConcentrationNo2=0, countNo2 = 0;
    double meanConcentrationPm10=0, countPm10 = 0;
    double meanConcentrationO3=0, countO3 = 0;

    // get all measurement from the database
    vector<Measurement *> measurements = data->getAllMeasurements();

    // for each measurement, check if it is in the zone and in the period
    for (Measurement *measurement : measurements)
    {
        if (measurement->getSensor()->calculateDistance(lat, lon) <= radius && measurement->isInPeriod(start, end))
        {
            PrivateIndividual *privateIndividual = measurement->getSensor()->getPrivateIndividualLinkToTheSensor(data);
            if ((privateIndividual == nullptr) || (privateIndividual != nullptr && privateIndividual->getTrustable()))
            {
                if (measurement->getType() == "SO2")
                {
                    meanConcentrationSo2 += measurement->getValue();
                    countSo2++;
                }
                else if (measurement->getType() == "NO2")
                {
                    meanConcentrationNo2 += measurement->getValue();
                    countNo2++;
                }
                else if (measurement->getType() == "PM10")
                {
                    meanConcentrationPm10 += measurement->getValue();
                    countPm10++;
                }
                else if (measurement->getType() == "O3")
                {
                    meanConcentrationO3 += measurement->getValue();
                    countO3++;
                }

                // If the sensor is linked to a private individual we increment his number of points
                if (privateIndividual != nullptr)
                {
                    privateIndividual->setPoints(privateIndividual->getPoints() + 1);
                }
            }
        }
    }

    if (countSo2 != 0)
    {
        meanConcentrationSo2 /= countSo2;
    }

    if (countNo2 != 0)
    {
        meanConcentrationNo2 /= countNo2;
    }

    if (countPm10 != 0)
    {
        meanConcentrationPm10 /= countPm10;
    }

    if (countO3 != 0)
    {
        meanConcentrationO3 /= countO3;
    }

    // In the case where we have no data (no sensor in the zone or no data in the period)
    if(countSo2 == 0 && countNo2 == 0 && countPm10 == 0 && countO3 == 0){
        return -1;
    }

    return this->calculateAirQuality(meanConcentrationSo2, meanConcentrationNo2, meanConcentrationPm10, meanConcentrationO3);
}

int Statistics::getMeanAirQualityByZoneByTime(Data *data, tm *time, double lat, double lon, double radius)
{
    // we return the mean air quality for the period [time, time] (start is equal to end)
    return this->getMeanAirQualityByZoneByPeriod(data, time, time, lat, lon, radius);
}