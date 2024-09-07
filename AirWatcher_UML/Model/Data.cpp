using namespace std;
#include <iostream>
#include "Data.h"

Data::Data(const Data &unData)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Data>" << endl;
#endif
}

Data::Data()
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
}

Data::~Data()
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
    for (Sensor* sensor : allSensors)
    {
        delete sensor;
    }
    for (Cleaner* cleaner : allCleaners)
    {
        delete cleaner;
    }
    for (Measurement* measurement : allMeasurements)
    {
        delete measurement;
    }
    for (Provider* provider : allProviders)
    {
        delete provider;
    }
    for (PrivateIndividual* privateIndividual : allPrivateIndividuals)
    {
        delete privateIndividual;
    }
}

void Data::setAllSensors(vector<Sensor *> sensors)
{
    allSensors = sensors;
}

void Data::setAllCleaners(vector<Cleaner *> cleaners)
{
    allCleaners = cleaners;
}

void Data::setAllMeasurements(vector<Measurement *> measurements)
{
    allMeasurements = measurements;
}

void Data::setAllProviders(vector<Provider *> providers)
{
    allProviders = providers;
}

void Data::setAllPrivateIndividuals(vector<PrivateIndividual *> privateIndividuals)
{
    allPrivateIndividuals = privateIndividuals;
}

vector<Sensor *> Data::getAllSensors() const
{
    return allSensors;
}

vector<Cleaner *> Data::getAllCleaners() const
{
    return allCleaners;
}

vector<Measurement *> Data::getAllMeasurements() const
{
    return allMeasurements;
}

vector<Provider *> Data::getAllProviders() const
{
    return allProviders;
}

vector<PrivateIndividual *> Data::getAllPrivateIndividuals() const
{
    return allPrivateIndividuals;
}
