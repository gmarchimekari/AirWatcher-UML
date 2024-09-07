using namespace std;
#include <iostream>
#include "Measurement.h"

Measurement::Measurement(const Measurement &unMeasurement)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif
}

Measurement::Measurement(Sensor *unSensor, string unType, double uneValue, string timeString)
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif

    sensor = unSensor;
    type = unType;
    value = uneValue;

    string day, month, year, hour, min, sec;
    stringstream ss(timeString);

    getline(ss, year, '-');
    getline(ss, month, '-');
    getline(ss, day, ' ');
    getline(ss, hour, ':');
    getline(ss, min, ':');
    getline(ss, sec, ':');

    time = new tm();

    time->tm_sec = stoi(sec);
    time->tm_min = stoi(min);
    time->tm_hour = stoi(hour);
    time->tm_year = stoi(year) - 1900;
    time->tm_mon = stoi(month) - 1;
    time->tm_mday = stoi(day);
}

Measurement::~Measurement()
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
}

Sensor *Measurement::getSensor() const
{
    return sensor;
}

string Measurement::getType() const
{
    return type;
}

double Measurement::getValue() const
{
    return value;
}

tm *Measurement::getTime() const
{
    return time;
}

bool Measurement::isInPeriod(tm *start, tm *end)
{
    // time_t t = mktime(time);
    // time_t tStart = mktime(start);
    // time_t tEnd = mktime(end);

    // return t >= tStart && t <= tEnd;
    int yearStart = start->tm_year;	
    int yearEnd = end->tm_year;
    int monthStart = start->tm_mon;
    int monthEnd = end->tm_mon;
    int dayStart = start->tm_mday;
    int dayEnd = end->tm_mday;

    if (time->tm_year < yearStart || time->tm_year > yearEnd)
    {
        return false;
    }
    else if (time->tm_year == yearStart)
    {
        if (time->tm_mon < monthStart)
        {
            return false;
        }
        else if (time->tm_mon == monthStart)
        {
            if (time->tm_mday < dayStart)
            {
                return false;
            }
        }
    }
    else if (time->tm_year == yearEnd)
    {
        if (time->tm_mon > monthEnd)
        {
            return false;
        }
        else if (time->tm_mon == monthEnd)
        {
            if (time->tm_mday > dayEnd)
            {
                return false;
            }
        }
    }
    return true;
}