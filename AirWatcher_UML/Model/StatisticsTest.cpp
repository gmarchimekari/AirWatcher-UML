#include <iostream>
#include <cassert>
#include "Statistics.h"
#include "Measurement.h"
#include "Sensor.h"

// g++ -o statTest Statistics.cpp StatisticsTest.cpp Measurement.cpp PrivateIndividual.cpp Data.cpp Sensor.cpp User.cpp

// Classe de test pour Statistics
class StatisticsTest
{
public:
    void runTests()
    {
        testCalculateIndexSo2();
        testCalculateIndexNo2();
        testCalculateIndexPm10();
        testCalculateIndexO3();
        testCalculateAirQuality();
        testGetMeanAirQualityByZoneByPeriod();
    }

private:
    void testCalculateAirQuality()
    {
        Statistics statistics;

        // 498.0 => 9, 53.0 => 2 , 19.0 => 3 , 103.0 => 4
        // Test case : max => indexSo2 (9)
        int result1 = statistics.calculateAirQuality(498.0, 53.0, 19.0, 103.0);
        assert(result1 == 9);

        // 38.0 => 1, 398.0 => 9 , 19.0 => 3 , 103.0 => 4
        // Test case : max => indexNo2 (9)
        int result2 = statistics.calculateAirQuality(38.0, 398.0, 19.0, 103.0);
        assert(result2 == 9);

        // 38.0 => 1, 53.0 => 2 , 78.0 => 9 , 103.0 => 4
        // Test case : max => indexPm10 (9)
        int result3 = statistics.calculateAirQuality(38.0, 53.0, 78.0, 103.0);
        assert(result3 == 9);

        // 38.0 => 1, 53.0 => 2 , 19.0 => 3 , 238.0 => 9
        // Test case : max => indexO3 (9)
        int result4 = statistics.calculateAirQuality(38.0, 53.0, 19.0, 238.0);
        assert(result4 == 9);

        // 78.0 => 2 , 53.0 => 2, 12.0 => 2, 53.0 => 2
        // Test case : all equal (2)
        int result5 = statistics.calculateAirQuality(78.0, 53.0, 12.0, 53.0);
        assert(result5 == 2);

        std::cout << "All test cases for calculateAirQuality passed" << std::endl;
    }

    void testCalculateIndexSo2()
    {
        Statistics statistics;

        // Test case 1: concentration is negative
        int result1 = statistics.calculateIndexSo2(-10.0);
        assert(result1 == -1);

        // Test case 2: concentration is within range [0, 39]
        int result2 = statistics.calculateIndexSo2(20.0);
        assert(result2 == 1);

        // Test case 3: concentration is within range [40, 79]
        int result3 = statistics.calculateIndexSo2(60.0);
        assert(result3 == 2);

        // Test case 4: concentration is within range [80, 119]
        int result4 = statistics.calculateIndexSo2(100.0);
        assert(result4 == 3);

        // Test case 5: concentration is within range [120, 159]
        int result5 = statistics.calculateIndexSo2(140.0);
        assert(result5 == 4);

        // Test case 6: concentration is within range [160, 199]
        int result6 = statistics.calculateIndexSo2(180.0);
        assert(result6 == 5);

        // Test case 7: concentration is within range [200, 249]
        int result7 = statistics.calculateIndexSo2(220.0);
        assert(result7 == 6);

        // Test case 8: concentration is within range [250, 299]
        int result8 = statistics.calculateIndexSo2(280.0);
        assert(result8 == 7);

        // Test case 9: concentration is within range [300, 399]
        int result9 = statistics.calculateIndexSo2(350.0);
        assert(result9 == 8);

        // Test case 10: concentration is within range [400, 499]
        int result10 = statistics.calculateIndexSo2(450.0);
        assert(result10 == 9);

        // Test case 11: concentration is greater than 499
        int result11 = statistics.calculateIndexSo2(600.0);
        assert(result11 == 10);

        cout << "All test cases for calculateIndexSo2 passed" << endl;
    }

    void testCalculateIndexNo2()
    {
        Statistics statistics;
        // Test case 1: concentration is negative
        int result1 = statistics.calculateIndexNo2(-10.0);
        assert(result1 == -1);
        // Test case 2: concentration is within range [0, 29]
        int result2 = statistics.calculateIndexNo2(20.0);
        assert(result2 == 1);
        // Test case 3: concentration is within range [30, 54]
        int result3 = statistics.calculateIndexNo2(40.0);
        assert(result3 == 2);
        // Test case 4: concentration is within range [55, 84]
        int result4 = statistics.calculateIndexNo2(70.0);
        assert(result4 == 3);
        // Test case 5: concentration is within range [85, 109]
        int result5 = statistics.calculateIndexNo2(100.0);
        assert(result5 == 4);
        // Test case 6: concentration is within range [110, 134]
        int result6 = statistics.calculateIndexNo2(120.0);
        assert(result6 == 5);
        // Test case 7: concentration is within range [135, 164]
        int result7 = statistics.calculateIndexNo2(150.0);
        assert(result7 == 6);
        // Test case 8: concentration is within range [165, 199]
        int result8 = statistics.calculateIndexNo2(180.0);
        assert(result8 == 7);
        // Test case 9: concentration is within range [200, 274]
        int result9 = statistics.calculateIndexNo2(250.0);
        assert(result9 == 8);
        // Test case 10: concentration is within range [275, 399]
        int result10 = statistics.calculateIndexNo2(350.0);
        assert(result10 == 9);
        // Test case 11: concentration is greater than 399
        int result11 = statistics.calculateIndexNo2(500.0);
        assert(result11 == 10);

        cout << "All test cases for calculateIndexNo2 passed" << endl;
    }

    void testCalculateIndexPm10()
    {
        Statistics statistics;
        // Test case 1: concentration is negative
        int result1 = statistics.calculateIndexPm10(-10.0);
        assert(result1 == -1);
        // Test case 2: concentration is within range [0, 6]
        int result2 = statistics.calculateIndexPm10(4.0);
        assert(result2 == 1);
        // Test case 3: concentration is within range [7, 13]
        int result3 = statistics.calculateIndexPm10(10.0);
        assert(result3 == 2);
        // Test case 4: concentration is within range [14, 20]
        int result4 = statistics.calculateIndexPm10(18.0);
        assert(result4 == 3);
        // Test case 5: concentration is within range [21, 27]
        int result5 = statistics.calculateIndexPm10(25.0);
        assert(result5 == 4);
        // Test case 6: concentration is within range [28, 34]
        int result6 = statistics.calculateIndexPm10(32.0);
        assert(result6 == 5);
        // Test case 7: concentration is within range [35, 41]
        int result7 = statistics.calculateIndexPm10(38.0);
        assert(result7 == 6);
        // Test case 8: concentration is within range [42, 49]
        int result8 = statistics.calculateIndexPm10(46.0);
        assert(result8 == 7);
        // Test case 9: concentration is within range [50, 64]
        int result9 = statistics.calculateIndexPm10(58.0);
        assert(result9 == 8);
        // Test case 10: concentration is within range [65, 79]
        int result10 = statistics.calculateIndexPm10(72.0);
        assert(result10 == 9);
        // Test case 11: concentration is greater than 79
        int result11 = statistics.calculateIndexPm10(90.0);
        assert(result11 == 10);

        cout << "All test cases for calculateIndexPm10 passed" << endl;
    }

    void testCalculateIndexO3()
    {
        Statistics statistics;
        // Test case 1: concentration is within range [0, 29]
        int result1 = statistics.calculateIndexO3(20.0);
        assert(result1 == 1);
        // Test case 2: concentration is within range [30, 54]
        int result2 = statistics.calculateIndexO3(40.0);
        assert(result2 == 2);
        // Test case 3: concentration is within range [55, 79]
        int result3 = statistics.calculateIndexO3(70.0);
        assert(result3 == 3);
        // Test case 4: concentration is within range [80, 104]
        int result4 = statistics.calculateIndexO3(100.0);
        assert(result4 == 4);
        // Test case 5: concentration is within range [105, 129]
        int result5 = statistics.calculateIndexO3(120.0);
        assert(result5 == 5);
        // Test case 6: concentration is within range [130, 149]
        int result6 = statistics.calculateIndexO3(140.0);
        assert(result6 == 6);
        // Test case 7: concentration is within range [150, 179]
        int result7 = statistics.calculateIndexO3(160.0);
        assert(result7 == 7);
        // Test case 8: concentration is within range [180, 209]
        int result8 = statistics.calculateIndexO3(200.0);
        assert(result8 == 8);
        // Test case 9: concentration is within range [210, 239]
        int result9 = statistics.calculateIndexO3(230.0);
        assert(result9 == 9);
        // Test case 10: concentration is greater than 239
        int result10 = statistics.calculateIndexO3(250.0);
        assert(result10 == 10);

        cout << "All test cases for calculateIndexO3 passed" << endl;
    }


    void testGetMeanAirQualityByZoneByPeriod(){

        // Creation of 3 sensors and 4 measurements for each sensor
        // 2 sensors in the zone (1 and 2) and 1 sensor outside the zone (3)
        Sensor *sensor1 = new Sensor("sensor1", 45.7830905, 4.8759894); // INSA Lyon
        Sensor *sensor2 = new Sensor("sensor2", 45.7704175, 4.8633324); // Charpenne Villeurbanne
        Sensor *sensor3 = new Sensor("sensor3", 40.7127281, -74.0060152); // New York

        // Mean of PM10 for sensor 1 and 2 is 4.0 => index 1
        Measurement *measurement1 = new Measurement(sensor1, "PM10", 3.0, "2019-01-01 12:00:00");
        Measurement *measurement2 = new Measurement(sensor2, "PM10", 5.0, "2019-01-01 12:00:00");
        Measurement *measurement3 = new Measurement(sensor3, "PM10", 10.0, "2019-01-01 12:00:00");

        // Mean of SO2 for sensor 1 and 2 is 298 => index 7
        Measurement *measurement4 = new Measurement(sensor1, "SO2", 298.0, "2019-01-01 12:00:00");
        Measurement *measurement5 = new Measurement(sensor2, "SO2", 297.0, "2019-01-01 12:00:00");
        Measurement *measurement6 = new Measurement(sensor3, "SO2", 25.0, "2019-01-01 12:00:00");

        // Mean of O3 for sensor 1 and 2 is 125 => index 5
        Measurement *measurement7 = new Measurement(sensor1, "O3", 100.0, "2019-01-01 12:00:00");
        Measurement *measurement8 = new Measurement(sensor2, "O3", 150.0, "2019-01-01 12:00:00");
        Measurement *measurement9 = new Measurement(sensor3, "O3", 200.0, "2019-01-01 12:00:00");

        // Mean of NO2 for sensor 1 and 2 is 35 => index 2
        Measurement *measurement10 = new Measurement(sensor1, "NO2", 30.0, "2019-01-01 12:00:00");
        Measurement *measurement11 = new Measurement(sensor2, "NO2", 40.0, "2019-01-01 12:00:00");
        Measurement *measurement12 = new Measurement(sensor3, "NO2", 50.0, "2019-01-01 12:00:00");

        // the method should return 7 because it's the max index for the 4 measurements (for each sensor in the zone)

        Data data;
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
        measurements.push_back(measurement10);
        measurements.push_back(measurement11);
        measurements.push_back(measurement12);
        data.setAllMeasurements(measurements);

        vector<Sensor *> sensors;
        sensors.push_back(sensor1);
        sensors.push_back(sensor2);
        sensors.push_back(sensor3);
        data.setAllSensors(sensors);

        

        tm *timeStart = new tm();

        timeStart->tm_sec = 0;
        timeStart->tm_min = 0;
        timeStart->tm_hour = 12;
        timeStart->tm_year = 2018 - 1900;
        timeStart->tm_mon = 1 - 1;
        timeStart->tm_mday = 1;

        tm *timeEnd = new tm();

        timeEnd->tm_sec = 0;
        timeEnd->tm_min = 0;
        timeEnd->tm_hour = 12;
        timeEnd->tm_year = 2020 - 1900;
        timeEnd->tm_mon = 1 - 1;
        timeEnd->tm_mday = 1;

        Statistics statistics;

        // The selected zone is a circle with center (45.7704175, 4.8633324) and radius 2.0 => Charpennes with radius 2km
        int result1 = statistics.getMeanAirQualityByZoneByPeriod(&data, timeStart,timeEnd, 45.7704175, 4.8633324, 2.0);
        cout << "result1 : " << result1 << endl;
        assert(result1 == 7); // The max index is 7
        // The selected zone is a circle with center (42.3554334, -71.060511) and radius 2.0 => Boston with radius 2km
        int result2 = statistics.getMeanAirQualityByZoneByPeriod(&data, timeStart,timeEnd, 42.3554334, -71.060511, 10.0);
        assert(result2 == -1); // The max index is 0 because there is no sensor in the zone
        cout << "All test cases for getMeanAirQualityByZoneByPeriod passed" << endl;

    }
};

int main()
{
    StatisticsTest test;
    test.runTests();
    return 0;
}