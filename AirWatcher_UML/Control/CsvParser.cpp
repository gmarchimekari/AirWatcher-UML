using namespace std;
#include <iostream>
#include "CsvParser.h"

vector<Sensor *> CsvParser::createSensors()
{
    ifstream fic("./dataset/sensors.csv");
    if (!fic.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
    }
    string ligne;
    string sensorIdParsed;
    string latitudeParsed;
    string longitudeParsed;
    vector<Sensor *> sensors;

    while (getline(fic, ligne))
    {
        stringstream ss(ligne);
        getline(ss, sensorIdParsed, ';');
        getline(ss, latitudeParsed, ';');
        getline(ss, longitudeParsed, ';');
        Sensor *sensor = new Sensor(sensorIdParsed, stod(latitudeParsed), stod(longitudeParsed));
        sensors.push_back(sensor);
    }
    return sensors;
}

vector<Cleaner *> CsvParser::createCleaners()
{
    ifstream fic("./dataset/cleaners.csv");
    if (!fic.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
    }
    string ligne;
    string cleanerIdParsed;
    string latitudeParsed;
    string longitudeParsed;
    string timeStartParsed;
    string timeStopParsed;
    vector<Cleaner *> cleaners;

    while (getline(fic, ligne))
    {
        stringstream ss(ligne);
        getline(ss, cleanerIdParsed, ';');
        getline(ss, latitudeParsed, ';');
        getline(ss, longitudeParsed, ';');
        getline(ss, timeStartParsed, ';');
        getline(ss, timeStopParsed, ';');
        timeStartParsed += ":";
        timeStopParsed += ":";
        Cleaner *cleaner = new Cleaner(cleanerIdParsed, stod(latitudeParsed), stod(longitudeParsed), timeStartParsed, timeStopParsed);
        cleaners.push_back(cleaner);
    }
    return cleaners;
}

vector<Measurement *> CsvParser::createMeasurements(vector<Sensor *> sensors)
{
    ifstream fic("./dataset/measurements.csv");
    if (!fic.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
    }
    string ligne;
    string sensorIdParsed;
    string typeParsed;
    string valueParsed;
    string timeParsed;
    vector<Measurement *> measurements;
    Sensor *sensorMeasurement;

    while (getline(fic, ligne))
    {
        stringstream ss(ligne);
        getline(ss, timeParsed, ';');
        getline(ss, sensorIdParsed, ';');
        getline(ss, typeParsed, ';');
        getline(ss, valueParsed, ';');
        timeParsed += ":";
        for (vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); ++it)
        {
            if ((*it)->getSensorId() == sensorIdParsed)
            {
                sensorMeasurement = (*it);
                break;
            }
        }
        Measurement *measurement = new Measurement(sensorMeasurement, typeParsed, stod(valueParsed), timeParsed);
        measurements.push_back(measurement);
    }
    return measurements;
}

vector<Provider *> CsvParser::createProviders(vector<Cleaner *> cleaners)
{
    ifstream fic("./dataset/providers.csv");
    if (!fic.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
    }
    string ligne;
    string providerIdParsed;
    string cleanerIdParsed;
    vector<Provider *> providers;
    Cleaner *cleanerProvider;

    while (getline(fic, ligne))
    {
        stringstream ss(ligne);
        getline(ss, providerIdParsed, ';');
        getline(ss, cleanerIdParsed, ';');
        for (vector<Cleaner *>::const_iterator it = cleaners.begin(); it != cleaners.end(); ++it)
        {
            if ((*it)->getCleanerId() == cleanerIdParsed)
            {
                cleanerProvider = (*it);
                break;
            }
        }
        Provider *provider = new Provider(providerIdParsed, cleanerProvider);
        providers.push_back(provider);
    }
    return providers;
}

vector<PrivateIndividual *> CsvParser::createPrivateIndividuals(vector<Sensor *> sensors)
{
    ifstream fic("./dataset/users.csv");
    if (!fic.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
    }
    string ligne;
    string privateIndividualIdParsed;
    string sensorIdParsed;
    vector<PrivateIndividual *> privateIndividuals;
    Sensor *sensorPrivateIndividual;
    vector<Sensor *> sensorsPrivateIndividual;

    while (getline(fic, ligne))
    {
        stringstream ss(ligne);
        getline(ss, privateIndividualIdParsed, ';');
        getline(ss, sensorIdParsed, ';');
        for (vector<Sensor *>::const_iterator it = sensors.begin(); it != sensors.end(); ++it)
        {
            if ((*it)->getSensorId() == sensorIdParsed)
            {
                sensorPrivateIndividual = (*it);
                sensorsPrivateIndividual.push_back(sensorPrivateIndividual);
            }
        }
        PrivateIndividual *privateIndividual = new PrivateIndividual(privateIndividualIdParsed, sensorsPrivateIndividual);
        privateIndividuals.push_back(privateIndividual);
    }
    return privateIndividuals;
}

Data *CsvParser::createData(Data *data)
{
    // Call every create method and set the data object
    vector<Sensor *> sensors = createSensors();
    data->setAllSensors(sensors);
    vector<Cleaner *> cleaners = createCleaners();
    data->setAllCleaners(cleaners);
    vector<Measurement *> measurements = createMeasurements(sensors);
    data->setAllMeasurements(measurements);
    vector<Provider *> providers = createProviders(cleaners);
    data->setAllProviders(providers);
    vector<PrivateIndividual *> privateIndividuals = createPrivateIndividuals(sensors);
    data->setAllPrivateIndividuals(privateIndividuals);
    return data;
}

CsvParser::CsvParser()
{
#ifdef MAP
    cout << "Appel au constructeur de <CsvParser>" << endl;
#endif
}

CsvParser::~CsvParser()
{
#ifdef MAP
    cout << "Appel au destructeur de <CsvParser>" << endl;
#endif
}