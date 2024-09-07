#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller()
{
#ifdef MAP
    cout << "Appel au constructeur de <Controller>" << endl;
#endif
	csv = new CsvParser();
	stats = new Statistics();
	data = new Data();
    data = csv->createData(data);
}

Controller::~Controller()
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
	delete csv;
	delete data;
	delete stats;
}

Controller::Controller(const Controller &unController)
{
	// TODO : implement the constructor with parameters 
}

int Controller::getMeanAirQualityByZoneByPeriod(Data *data, tm *start, tm *end, double lat, double lon, double radius)
{
	return this->stats->getMeanAirQualityByZoneByPeriod(data, start, end, lat, lon, radius);
}

int Controller::getMeanAirQualityByZoneByTime(Data *data, tm *time, double lat, double lon, double radius)
{
	return this->stats->getMeanAirQualityByZoneByTime(data, time, lat, lon, radius);
}	

vector<Sensor*> Controller::getSimilarSensors(Sensor* sensor, Data *data, string measurementType, tm* timeStart, tm* timeEnd) const
{
	return sensor->getSimilarSensors(data, measurementType, timeStart, timeEnd);
}

Data* Controller::getData() const
{
    return this->data;
}
