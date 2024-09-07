using namespace std;
#include <iostream>

#include "Sensor.h"

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor(const Sensor &unSensor)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
}

Sensor::Sensor(string unSensorId, double uneLatitude, double uneLongitude) : sensorId(unSensorId), latitude(uneLatitude), longitude(uneLongitude)
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
}

bool Sensor::operator==(const Sensor &unSensor)
{
    return this->sensorId == unSensor.getSensorId();
}

Sensor::~Sensor()
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
}

string Sensor::getSensorId() const
{
    return sensorId;
}

double Sensor::getLatitude() const
{
    return latitude;
}

double Sensor::getLongitude() const
{
    return longitude;
}

double Sensor::calculateDistance(double latitude, double longitude) const
{
    double earthRadius = 6371.0;
    double latSensor = this->latitude;
    double longSensor = this->longitude;

    // conversion of lat and long to radians
    double dLat = (latitude - latSensor) * M_PI / 180.0;
    double dLon = (longitude - longSensor) * M_PI / 180.0;
    latSensor = latSensor * M_PI / 180.0;
    latitude = latitude * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) + sin(dLon / 2) * sin(dLon / 2) * cos(latitude) * cos(longitude);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return earthRadius * c;
}

PrivateIndividual *Sensor::getPrivateIndividualLinkToTheSensor(Data *data) const
{
    for (PrivateIndividual *privateIndividual : data->getAllPrivateIndividuals())
    {
        for (Sensor *sensor : privateIndividual->getSensors())
        {
            if (*sensor == *this) // if the sensor is the same
            {
                return privateIndividual;
            }
        }
    }
    return nullptr;
}



vector<Sensor *> Sensor::getSimilarSensors(Data *data, string measurementType, tm *timeStart, tm *timeEnd) 
{
    vector<Sensor *> similarSensors;
    map<Sensor *, pair<double, double> > unSortedSensors;              // pair<counter, sumIndex>
    

    for (Measurement *m : data->getAllMeasurements())
    {
        if (m->isInPeriod(timeStart, timeEnd) && m->getType() == measurementType)
        {
            Sensor *sensor = m->getSensor();
            PrivateIndividual* p = sensor->getPrivateIndividualLinkToTheSensor(data); // to check if the sensor is linked to a private individual (if not, we don't take it into account
            if ((p == nullptr) || (p != nullptr && p->getTrustable()))
            {
                if (unSortedSensors.find(sensor) == unSortedSensors.end())
                {
                    unSortedSensors[sensor] = make_pair(1.0, m->getValue());
                }
                else
                {
                    unSortedSensors[sensor].first++;
                    unSortedSensors[sensor].second += m->getValue();
                }

                // If the sensor is linked to a private individual we increment his number of points
                if (p != nullptr)
                {
                    p->setPoints(p->getPoints() + 1);
                }
            }
        }
    }
    
    double meanSensorToCompare = unSortedSensors[this].second/unSortedSensors[this].first;

    struct customCompare
    {
        double meanSensorToCompare;

        customCompare(double mean) : meanSensorToCompare(mean) {}
        bool operator()(const pair<double, double> &sensor1, const pair<double, double> &sensor2) const
        {
            return abs((sensor1.second / sensor1.first)-meanSensorToCompare) < abs((sensor2.second / sensor2.first)-meanSensorToCompare);
        }
    };

    auto comparator = customCompare(meanSensorToCompare);
    map<pair<double, double>, Sensor *, decltype(comparator)> sortedSensors(comparator); // pair<counter, sumIndex>

    for (map<Sensor *, pair<double, double> >::const_iterator it = unSortedSensors.begin(); it != unSortedSensors.end(); it++)
    {
        sortedSensors.insert(make_pair((*it).second, (*it).first));
    }

    for (map<pair<double, double>, Sensor *>::const_iterator it = sortedSensors.begin(); it != sortedSensors.end(); it++)
    {
        similarSensors.push_back(it->second);
    }
    return similarSensors;
}
