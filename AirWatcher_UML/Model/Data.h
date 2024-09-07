#if !defined(DATA_H)
#define DATA_H
#include "Sensor.h"
#include "Cleaner.h"
#include "Provider.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include <vector>

class Measurement;
class PrivateIndividual;

class Data
{

public:
    Data(const Data &unData);
    Data();
    virtual ~Data();
    vector<Sensor *> getAllSensors() const;
    vector<Cleaner *> getAllCleaners() const;
    vector<Measurement *> getAllMeasurements() const;
    vector<Provider *> getAllProviders() const;
    vector<PrivateIndividual *> getAllPrivateIndividuals() const;
    void setAllSensors(vector<Sensor *> sensors);
    void setAllCleaners(vector<Cleaner *> cleaners);
    void setAllMeasurements(vector<Measurement *> measurements);
    void setAllProviders(vector<Provider *> providers);
    void setAllPrivateIndividuals(vector<PrivateIndividual *> privateIndividuals);

private:
    vector<Sensor*> allSensors;
    vector<Cleaner*> allCleaners;
    vector<Measurement*> allMeasurements;
    vector<Provider*> allProviders;
    vector<PrivateIndividual*> allPrivateIndividuals;
};

#endif // DATA_H
