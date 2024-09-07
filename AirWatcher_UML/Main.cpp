//-------------------------------------------------------- Includes systemes
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

//-------------------------------------------------------- Includes personels
#include "./Control/CsvParser.h"
#include "./Model/Statistics.h"
#include "./View/View.h"

using namespace std;

int main(int argc, char **argv)
{
    View* view = new View();
    view->StartApplication();
    delete view;


    // CsvParser *csv = new CsvParser();
    // Data *data = csv->createData();

    // Tester la creation des sensors
    // vector<Sensor*> sensors = data->getAllSensors();
    // cout << "There are " << sensors.size() << " sensors" << endl << endl;
    // for (vector<Sensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it) {
    //     cout << (*it)->getSensorId() << " ( " << (*it)->getLatitude() << ", " << (*it)->getLongitude() << " )" << endl;
    // }

    // Tester la creation des cleaners
    // vector<Cleaner*> cleaners = data->getAllCleaners();
    // cout << "There are " << cleaners.size() << " cleaners" << endl << endl;
    // for (vector<Cleaner*>::const_iterator it = cleaners.begin(); it != cleaners.end(); ++it) {
    //     cout << (*it)->getCleanerId() << " ( " << (*it)->getLatitude() << ", " << (*it)->getLongitude() << " )" << " (" << asctime((*it)->getTimeStart()) << ", " << asctime((*it)->getTimeStop()) << ")" << endl;
    // }

    // Tester la creation des measurements
    // vector<Measurement*> measurements = data->getAllMeasurements();
    // cout << "There are " << measurements.size() << " measurements" << endl << endl;
    // for (vector<Measurement*>::const_iterator it = measurements.begin(); it != measurements.end(); ++it) {
    //     cout << (*it)->getSensor()->getSensorId() << " a " << asctime((*it)->getTime()) << " vaut " << (*it)->getValue() << " µg/m3 de " << (*it)->getType() << endl;
    // }

    // Tester la creation des providers
    // vector<Provider*> providers = data->getAllProviders();
    // cout << "There are " << providers.size() << " providers" << endl << endl;
    // for (vector<Provider*>::const_iterator it = providers.begin(); it != providers.end(); ++it) {
    //     cout << (*it)->getCleaner()->getCleanerId() << " est fourni par " << (*it)->getProviderId() << endl;
    // }

    // Tester la creation des privateIndividuals
    // vector<PrivateIndividual*> privateIndividuals = data->getAllPrivateIndividuals();
    // cout << "There are " << privateIndividuals.size() << " providers" << endl << endl;
    // for (vector<PrivateIndividual*>::const_iterator it = privateIndividuals.begin(); it != privateIndividuals.end(); ++it) {
    //     cout << (*it)->getPrivateIndividualId() << " possede " << (*it)->getSensor()->getSensorId() << endl;
    // }

    // Tester la methode calculateDistance dans la classe Sensor
    // Sensor *sensor = new Sensor("sensor1", 45.784872, 4.874249);
    // cout << sensor->calculateDistance(45.784872, 4.87424) << endl; => 0
    // cout << sensor->calculateDistance(45.767517, 4.873158) << endl; => 1.9

    // delete csv;
    return 0;
}