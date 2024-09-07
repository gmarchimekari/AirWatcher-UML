#include <iostream>
#include "Cleaner.h"

Cleaner::Cleaner(const Cleaner &unCleaner)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
}

Cleaner::Cleaner(string unCleanerId, double uneLatitude, double uneLongitude, string start, string stop)
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
    cleanerId = unCleanerId;
    latitude = uneLatitude;
    longitude = uneLongitude;

    string dayStart, dayStop, monthStart, monthStop, yearStart, yearStop, hourStart, hourStop, minStart, minStop, secStart, secStop;
    stringstream ssStart(start);
    stringstream ssStop(stop);

    getline(ssStart, yearStart, '-');
    getline(ssStart, monthStart, '-');
    getline(ssStart, dayStart, ' ');
    getline(ssStart, hourStart, ':');
    getline(ssStart, minStart, ':');
    getline(ssStart, secStart, ':');

    getline(ssStop, yearStop, '-');
    getline(ssStop, monthStop, '-');
    getline(ssStop, dayStop, ' ');
    getline(ssStop, hourStop, ':');
    getline(ssStop, minStop, ':');
    getline(ssStop, secStop, ':');

    timeStart = new tm();
    timeStop = new tm();

    timeStart->tm_sec = stoi(secStart);
    timeStart->tm_min = stoi(minStart);
    timeStart->tm_hour = stoi(hourStart);
    timeStart->tm_year = stoi(yearStart) - 1900;
    timeStart->tm_mon = stoi(monthStart) - 1;
    timeStart->tm_mday = stoi(dayStart);

    timeStop->tm_sec = stoi(secStop);
    timeStop->tm_min = stoi(minStop);
    timeStop->tm_hour = stoi(hourStop);
    timeStop->tm_year = stoi(yearStop) - 1900;
    timeStop->tm_mon = stoi(monthStop) - 1;
    timeStop->tm_mday = stoi(dayStop);
}

Cleaner::~Cleaner()
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
    delete timeStart;
    delete timeStop;
}

string Cleaner::getCleanerId() const
{
    return cleanerId;
}

double Cleaner::getLatitude() const
{
    return latitude;
}

double Cleaner::getLongitude() const
{
    return longitude;
}

tm *Cleaner::getTimeStart() const
{
    return timeStart;
}

tm *Cleaner::getTimeStop() const
{
    return timeStop;
}