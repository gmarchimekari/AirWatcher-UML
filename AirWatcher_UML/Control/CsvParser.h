#if !defined(CSVPARSER_H)
#define CSVPARSER_H

#include "../Model/Sensor.h"
#include "../Model/Cleaner.h"
#include "../Model/Provider.h"
#include "../Model/Measurement.h"
#include "../Model/PrivateIndividual.h"
#include "../Model/Data.h"
#include <fstream>
#include <sstream>
#include <vector>

class CsvParser
{

public:
    Data *createData(Data *data);
    CsvParser();
    virtual ~CsvParser();

private:
    vector<Sensor *> createSensors();
    vector<Cleaner *> createCleaners();
    vector<Provider *> createProviders(vector<Cleaner *> cleaners);
    vector<Measurement *> createMeasurements(vector<Sensor *> sensors);
    vector<PrivateIndividual *> createPrivateIndividuals(vector<Sensor *> sensors);
};

#endif // CSVPARSER_H
