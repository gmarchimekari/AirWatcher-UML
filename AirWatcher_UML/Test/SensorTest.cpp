#include <iostream>
#include <cassert>
#include "../Model/Sensor.h"
#include "../Model/PrivateIndividual.h"
#include "../Model/Measurement.h"

// g++ -o sensorTest ../Model/Statistics.cpp SensorTest.cpp ../Model/Measurement.cpp ../Model/PrivateIndividual.cpp ../Model/Data.cpp ../Model/Sensor.cpp ../Model/User.cpp

// Classe de test pour Statistics
class StatisticsTest
{
public:
    void runTests()
    {
        // testEqualOperator();
        // testCalculateDistance();
        // testGetPrivateIndividualLinkToTheSensor();
        testGetSimilarSensors();
    }

private:
    void testEqualOperator()
    {
        Sensor sensor1("sensor1", 1.0, 1.0);
        Sensor sensor2("sensor2", 1.0, 1.0);
        Sensor sensor3("sensor1", 1.0, 1.0);

        assert(sensor1 == sensor3);
        assert(!(sensor1 == sensor2));
        cout << "All test cases for equal operator passed" << endl;
    }

    void testCalculateDistance()
    {
        Sensor sensor("sensor", 45.7730669, 4.8664263);                    // Charpenne Villeurbanne
        double distance = sensor.calculateDistance(45.7730669, 4.8664263); // Charpenne Villeurbanne
        assert(distance == 0.0);                                           // Same point

        Sensor sensor2("sensor2", 45.7730669, 4.8664263);                                   // Charpenne Villeurbanne
        double distance2 = sensor2.calculateDistance(45.7680549621582, 4.8789238929748535); // 47 rue anatole france 69100 Villeurbanne
        assert(distance2 <= 0.74 && distance2 >= 0.73);

        cout << "Test case for calculateDistance passed" << endl;
    }

    void testGetPrivateIndividualLinkToTheSensor()
    {
        Data data;
        Sensor *sensor1 = new Sensor("sensor1", 1.0, 1.0);
        Sensor *sensor2 = new Sensor("sensor2", 1.0, 1.0);
        vector<Sensor *> sensorsPrivateIndividual1;
        sensorsPrivateIndividual1.push_back(sensor1);

        PrivateIndividual *privateIndividual1 = new PrivateIndividual("privateIndividual1", sensorsPrivateIndividual1);

        vector<PrivateIndividual *> privateIndividuals;
        privateIndividuals.push_back(privateIndividual1);
        data.setAllPrivateIndividuals(privateIndividuals);

        vector<Sensor *> sensors;
        sensors.push_back(sensor1);
        sensors.push_back(sensor2);
        data.setAllSensors(sensors);

        assert(sensor1->getPrivateIndividualLinkToTheSensor(&data) == privateIndividual1);
        assert(sensor2->getPrivateIndividualLinkToTheSensor(&data) == nullptr);
        cout << "Test case for getPrivateIndividualLinkToTheSensor passed" << endl;
    }

    void testGetSimilarSensors(){
        Data data;
        Sensor *sensor1 = new Sensor("sensor1", 1.0, 1.0); // Mean for PM10 equal to 3+5/2 = 4
        Sensor *sensor2 = new Sensor("sensor2", 1.0, 1.0); // Mean for PM10 equal to 10+20/2 = 15
        Sensor *sensor3 = new Sensor("sensor3", 1.0, 1.0); // Mean for PM10 equal to 40+50/2 = 45
        Measurement *measurement1 = new Measurement(sensor1, "PM10", 3.0, "2019-01-01 12:00:00");
        Measurement *measurement2 = new Measurement(sensor1, "PM10", 5.0, "2019-01-01 12:00:00"); 
        Measurement *measurement3 = new Measurement(sensor1, "SO2", 33.0, "2019-01-01 12:00:00");
        Measurement *measurement4 = new Measurement(sensor2, "PM10", 10.0, "2019-01-01 12:00:00");
        Measurement *measurement5 = new Measurement(sensor2, "PM10", 20.0, "2019-01-01 12:00:00");
        Measurement *measurement6 = new Measurement(sensor2, "SO2", 30.0, "2019-01-01 12:00:00");
        Measurement *measurement7 = new Measurement(sensor3, "PM10", 40.0, "2019-01-01 12:00:00");
        Measurement *measurement8 = new Measurement(sensor3, "PM10", 50.0, "2019-01-01 12:00:00");
        Measurement *measurement9 = new Measurement(sensor3, "SO2", 60.0, "2019-01-01 12:00:00");


        vector<Measurement *> measurements;
        measurements.push_back(measurement1);
        measurements.push_back(measurement2);
        measurements.push_back(measurement3);
        measurements.push_back(measurement4);
        measurements.push_back(measurement5);
        measurements.push_back(measurement6);
        measurements.push_back(measurement7);
        measurements.push_back(measurement8);
        measurements.push_back(measurement9);

        data.setAllMeasurements(measurements);

        vector <Sensor *> sensors;
        sensors.push_back(sensor1);
        sensors.push_back(sensor2);
        sensors.push_back(sensor3);
        data.setAllSensors(sensors);


        // The attempt order of the similar sensors of the second one is :
        // sensor2, sensor1, sensor3

        vector <Sensor *> attemptSimilarSensors1; // The expected order of the similar sensors of the first one
        attemptSimilarSensors1.push_back(sensor1);
        attemptSimilarSensors1.push_back(sensor2);
        attemptSimilarSensors1.push_back(sensor3);


        vector <Sensor *> attemptSimilarSensors2; // The expected order of the similar sensors of the second one
        attemptSimilarSensors2.push_back(sensor2);
        attemptSimilarSensors2.push_back(sensor1);
        attemptSimilarSensors2.push_back(sensor3);

        vector <Sensor *> attemptSimilarSensors3; // The expected order of the similar sensors of the third one
        attemptSimilarSensors3.push_back(sensor3);
        attemptSimilarSensors3.push_back(sensor2);
        attemptSimilarSensors3.push_back(sensor1);

        tm *timeStart = new tm();

        timeStart->tm_sec = 0;
        timeStart->tm_min = 0;
        timeStart->tm_hour = 12;
        timeStart->tm_year = 2019 - 1900;
        timeStart->tm_mon = 1 - 1;
        timeStart->tm_mday = 1;

        vector <Sensor *> similarSensors1 = sensor1->getSimilarSensors(&data, "PM10", timeStart, timeStart);
        vector <Sensor *> similarSensors2 = sensor2->getSimilarSensors(&data, "PM10", timeStart, timeStart);
        vector <Sensor *> similarSensors3 = sensor3->getSimilarSensors(&data, "PM10", timeStart, timeStart);
        

        // Verification of the order of the similar sensors for each sensor
        assert (similarSensors1.size() == 3 && similarSensors2.size() == 3 && similarSensors3.size() == 3);
        for (int i = 0; i < similarSensors1.size(); i++){
            //cout<<"sensor attempt "<<i<< " :" << attemptSimilarSensors[i]->getSensorId()<<endl;
            // cout <<"similar sensor "<<i<< " :" << similarSensors[i]->getSensorId()<<endl;
            assert(*similarSensors1[i] == *attemptSimilarSensors1[i]);
        }

        for (int i = 0; i < similarSensors2.size(); i++){
            //cout<<"sensor attempt "<<i<< " :" << attemptSimilarSensors[i]->getSensorId()<<endl;
            // cout <<"similar sensor "<<i<< " :" << similarSensors[i]->getSensorId()<<endl;
            assert(*similarSensors2[i] == *attemptSimilarSensors2[i]);
        }

        for (int i = 0; i < similarSensors3.size(); i++){
            //cout<<"sensor attempt "<<i<< " :" << attemptSimilarSensors[i]->getSensorId()<<endl;
            // cout <<"similar sensor "<<i<< " :" << similarSensors[i]->getSensorId()<<endl;
            assert(*similarSensors3[i] == *attemptSimilarSensors3[i]);
        }

        cout << "Test case for getSimilarSensors passed" << endl;
    }
};

int main()
{
    StatisticsTest test;
    test.runTests();
    return 0;
}