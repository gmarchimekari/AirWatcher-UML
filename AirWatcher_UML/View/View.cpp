using namespace std;
#include <iostream>

#include "View.h"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

View::View ( const View & unView )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <View>" << endl;
#endif
} 

View::View ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <View>" << endl;
#endif
}

View::~View ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <View>" << endl;
#endif
}

PrivateIndividual *View::ConnectionPrivateIndividual(Data* data)
{
    int c = 1;
    cout << "================================================" << endl;
    for(PrivateIndividual* privateIndividual : data->getAllPrivateIndividuals())
    {
        cout << c << ". " << privateIndividual->getPrivateIndividualId() << endl;
        c++;
    }
    cout << "================================================" << endl;
    cout << "Please enter the number of your private individual id: ";
    int choice;
    cin >> choice;
    if(choice >= 1 && static_cast<vector<PrivateIndividual*>::size_type>(choice) <= data->getAllPrivateIndividuals().size())
    {
        return data->getAllPrivateIndividuals()[choice - 1];
    }
    return nullptr;
}

void View::AgencyInterface(Controller *controller, Data *data)
{
    cout << "Welcome, Agent" << endl;
    while(1)
    {
        // Declare variables
        int choice;
        vector<string> parameters;
        stringstream ss;
        string year;
        string month;
        string day;
        double longitude;
        double latitude;
        tm* start;
        tm* end;
        tm* time;
        double radius;
        vector<Sensor*> similarSensors;
        string mesurementType;
        int meanAirQuality;
        Sensor* sensor;
        chrono::duration<double> duration;
        chrono::time_point<std::chrono::high_resolution_clock> startAlgo;
        chrono::time_point<std::chrono::high_resolution_clock> endAlgo;


        
        cout << "================================================" << endl;
        cout << "Choose a function to execute" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Get the mean air quality index during a period of time for a specific zone" << endl;
        cout << "2. Get the mean air quality index at a specific time for a specific zone" << endl;
        cout << "3. Get the sensors that are similar to a specific sensor" << endl;
        cout << "4. Disconnect" << endl;
        cout << "================================================" << endl;

        cout << "Enter the number of the function you want to execute: ";
        
        cin >> choice;
    	
        cout << endl;
        bool exit = false;
        switch(choice)
        {
            case 1:
                // Get the parameters for the method getMeanAirQualityByZoneByPeriod
                // L'ordre des parametres est le suivant: data - start - end - lat - lon - radius
                parameters = getParametersOfGetMeanAirQualityByZoneByPeriod();

                // Call the method getMeanAirQualityByZoneByPeriod with the parameters
                //ss.str(""); ss.clear();  year.clear(); month.clear(); day.clear(); // Réinitialiser le ss, year, month, day
                ss << parameters[0] << '-';
                getline(ss, year, '-');
                getline(ss, month, '-');
                getline(ss, day, '-');	
                start = new tm();
                start->tm_sec = 0;
                start->tm_min = 0;
                start->tm_hour = 0;
                start->tm_year = stoi(year) - 1900;
                start->tm_mon = stoi(month) - 1;
                start->tm_mday = stoi(day);

                //ss.str(""); ss.clear(); year.clear(); month.clear(); day.clear(); // Réinitialiser le ss, year, month, day
                ss << parameters[1] << '-';
                getline(ss, year, '-');
                getline(ss, month, '-');
                getline(ss, day, '-');
                
                end = new tm();
                end->tm_sec = 0;
                end->tm_min = 0;
                end->tm_hour = 0;
                end->tm_year = stoi(year) - 1900;
                end->tm_mon = stoi(month) - 1;
                end->tm_mday = stoi(day);

                latitude = stod(parameters[2]);
                longitude = stod(parameters[3]);
                radius = stod(parameters[4]);

                startAlgo = chrono::high_resolution_clock::now();
                meanAirQuality = controller->getMeanAirQualityByZoneByPeriod(data, start, end, latitude, longitude, radius);
                endAlgo = chrono::high_resolution_clock::now();
                duration = endAlgo - startAlgo;

                cout << "================================================" << endl;
                if(meanAirQuality == -1)
                {
                    cout << RED << "No data available for the specified time and zone" << RESET << endl;
                    cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;
                    break;
                }

                // Display the result
                cout << "The mean air quality index during the period in the zone is: " << meanAirQuality << endl;
                if(meanAirQuality == 1) cout << "Excellent" << endl;
                else if(meanAirQuality == 2) cout << GREEN << "Excellent" << RESET << endl;
                else if(meanAirQuality == 3) cout << GREEN << "Very good" << RESET << endl;
                else if(meanAirQuality == 4) cout << GREEN << "Very good" << RESET << endl;
                else if(meanAirQuality == 5) cout << YELLOW << "Average" << RESET << endl;
                else if(meanAirQuality == 6) cout << YELLOW << "Mediocre" << RESET << endl;	
                else if(meanAirQuality == 7) cout << YELLOW << "Mediocre" << RESET << endl;
                else if(meanAirQuality == 8) cout << RED << "Bad" << RESET << endl;	
                else if(meanAirQuality == 9) cout << RED << "Bad" << RESET << endl;
                else if(meanAirQuality == 10) cout << RED << "Very bad" << RESET << endl;
                cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;
                delete start;
                delete end;
                break;
            
            case 2:
            // Get the parameters for the method getMeanAirQualityByZoneByPeriod
                // L'ordre des parametres est le suivant: data - start - end - lat - lon - radius
                parameters = getParametersOfGetMeanAirQualityByZoneByTime();
                
                // Call the method getMeanAirQualityByZoneByPeriod with the parameters
                ss.str(""); ss.clear();  year.clear(); month.clear(); day.clear(); // Réinitialiser le ss, year, month, day
                ss << parameters[0] << '-';
                getline(ss, year, '-');
                getline(ss, month, '-');
                getline(ss, day, '-');	
                time = new tm();
                time->tm_sec = 0;
                time->tm_min = 0;
                time->tm_hour = 0;
                time->tm_year = stoi(year) - 1900;
                time->tm_mon = stoi(month) - 1;
                time->tm_mday = stoi(day);

                latitude = stod(parameters[1]);
                longitude = stod(parameters[2]);
                radius = stod(parameters[3]);

                startAlgo = chrono::high_resolution_clock::now();
                meanAirQuality = controller->getMeanAirQualityByZoneByTime(data, time, latitude, longitude, radius);
                endAlgo = chrono::high_resolution_clock::now();
                duration = endAlgo - startAlgo;


                cout << "================================================" << endl;
                if(meanAirQuality == -1)
                {
                    cout << RED << "No data available for the specified time and zone" << RESET << endl;
                    cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;
                    break;
                }
                // Display the result
                cout << "The mean air quality index during that time in the zone is: " << meanAirQuality << endl;
                if(meanAirQuality == 1) cout << "Excellent" << endl;
                else if(meanAirQuality == 2) cout << GREEN << "Excellent" << RESET << endl;
                else if(meanAirQuality == 3) cout << GREEN << "Very good" << RESET << endl;
                else if(meanAirQuality == 4) cout << GREEN << "Very good" << RESET << endl;
                else if(meanAirQuality == 5) cout << YELLOW << "Average" << RESET << endl;
                else if(meanAirQuality == 6) cout << YELLOW << "Mediocre" << RESET << endl;	
                else if(meanAirQuality == 7) cout << YELLOW << "Mediocre" << RESET << endl;
                else if(meanAirQuality == 8) cout << RED << "Bad" << RESET << endl;	
                else if(meanAirQuality == 9) cout << RED << "Bad" << RESET << endl;
                else if(meanAirQuality == 10) cout << RED << "Very bad" << RESET << endl;
                cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;	
                delete time;
                break;

            case 3:
                sensor = nullptr;
                while(sensor == nullptr)
                {
                    DisplayAllSensors(data->getAllSensors());
                    sensor = getChosenSensor(data->getAllSensors());
                }
                parameters = getParametersOfGetSimilarSensors();

                mesurementType = parameters[0];

                ss.str(""); ss.clear();  year.clear(); month.clear(); day.clear(); // Réinitialiser le ss, year, month, day
                ss << parameters[1] << '-';
                getline(ss, year, '-');
                getline(ss, month, '-');
                getline(ss, day, '-');
                start = new tm();
                start->tm_sec = 0;
                start->tm_min = 0;
                start->tm_hour = 0;
                start->tm_year = stoi(year) - 1900;
                start->tm_mon = stoi(month) - 1;
                start->tm_mday = stoi(day);
                
                
                ss.str(""); ss.clear();  year.clear(); month.clear(); day.clear(); // Réinitialiser le ss, year, month, day
                ss << parameters[2] << '-';
                getline(ss, year, '-');
                getline(ss, month, '-');
                getline(ss, day, '-');
                end = new tm();
                end->tm_sec = 0;
                end->tm_min = 0;
                end->tm_hour = 0;
                end->tm_year = stoi(year) - 1900;
                end->tm_mon = stoi(month) - 1;
                end->tm_mday = stoi(day);

                startAlgo = chrono::high_resolution_clock::now();
                similarSensors = controller->getSimilarSensors(sensor, data, mesurementType, start, end);
                endAlgo = chrono::high_resolution_clock::now();
                duration = endAlgo - startAlgo;

                if(similarSensors.size() == 0)
                {
                    cout << RED << "No similar sensors found" << RESET << endl;
                    cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;
                    break;
                }
                DisplaySimilarSensors(similarSensors, sensor);
                cout << BLUE << "Time taken by the algorithm: " << duration.count() << " seconds" << RESET << endl;
                delete start;
                delete end;
                break;
            
            case 4:
                exit = true;
                break;
        }

        if(exit)
        {
            break;
        }
    }
}

void View::PrivateIndividualInterface(Controller* controller, Data* data, PrivateIndividual* privateIndividual)
{
    while(1)
    {
        cout << "================================================" << endl;
        cout << "1. View my points" << endl;
        cout << "2. Disconnect" << endl;
        cout << "================================================" << endl;
        cout << "Enter the number of the function you want to execute: ";
        int choice; 
        cin >> choice;
        cout << endl;
        bool exit = false;
        switch(choice)
        {
            case 1:
                cout << "Your points: " << privateIndividual->getPoints() << endl;
                break;
            case 2:
                exit = true;
                break;
        }
        if(exit)
        {
            break;
        }
    }
}


void View::StartApplication()
{
    // Instantiate the controller
    Controller* controller = new Controller();
    Data* data = controller->getData();

    cout << "================================================" << endl;
    cout << "Welcome to the Air Watcher application" << endl;
    cout << "================================================" << endl;
    while(1)
    {
        PrivateIndividual* privateIndividual;

        cout << "================================================" << endl;
        cout << "Please identify yourself" << endl;
        cout << "1. Agency Member" << endl;
        cout << "2. Private Individual" << endl;
        cout << "3. Exit application" << endl;	
        cout << "================================================" << endl;

        cout << "Enter the number corresponding to the type of user you are: ";
        int choice;

        cin >> choice;
        cout << endl;
        bool exit = false;
        
        switch(choice)
        {
            case 1:
                AgencyInterface(controller, data);
                break;
            case 2:
                privateIndividual = ConnectionPrivateIndividual(data);
                PrivateIndividualInterface(controller, data, privateIndividual);
                break;
            case 3:
                exit = true;
                break;
        }
        if(exit)
        {
            break;
        }
    }
    


    DisplayExitMessage();
    delete controller;
}

void View::DisplayExitMessage()
{
    cout << endl << "================================================" << endl;
    cout << "Thank you for using the AirWatcher application, Goodbye!" << endl;
    cout << "================================================" << endl;
}

void View::DisplayAllSensors(vector<Sensor*> sensors)
{
    int c = 0;
    cout << "List of all sensors: " << endl;
    for(Sensor *sensor : sensors)
    {
        cout << c << ". " << sensor->getSensorId() << endl;
        c++;
    }
}

void View::DisplaySimilarSensors(vector<Sensor*> sensors, Sensor* sensor)
{
    if(sensors.size() == 1)
    {
        cout << RED << "No similar sensors found for the selected time and zone" << RESET << endl;
        return;
    }
    int c = 0;
    cout << endl << "List of all sensors that are similar to " << sensor->getSensorId() << ": - ranked by similarity " << endl;
    for(Sensor *sensor : sensors)
    {
        cout << c << ". " << sensor->getSensorId() << endl;
        c++;
    }
}



Sensor *View::getChosenSensor(vector<Sensor*> sensors)
{
    int choice;
    cout << "Please enter the number of the sensor you want to get similar sensors for: ";
    cin >> choice;
    if(choice >= 0 && static_cast<vector<Sensor*>::size_type>(choice) < sensors.size())
    {
        return sensors[choice];
    }
    return nullptr;
}

vector<string> View::getParametersOfGetMeanAirQualityByZoneByPeriod()
{
    vector<string> parameters;
    double longitude, latitude, radius;
    string startDate, endDate;
    cout << "Please enter the start date of the period (format: YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Please enter the end date of the period (format: YYYY-MM-DD): ";
    cin >> endDate;
    cout << "Please enter the longitude of the center of the zone: ";
    cin >> longitude;
    cout << "Please enter the latitude of the center of the zone: ";
    cin >> latitude;
    cout << "Please enter the radius of the zone: ";
    cin >> radius;
    parameters.push_back(startDate);
    parameters.push_back(endDate);
    parameters.push_back(to_string(latitude));
    parameters.push_back(to_string(longitude));
    parameters.push_back(to_string(radius));

    return parameters;
}

vector<string> View::getParametersOfGetMeanAirQualityByZoneByTime()
{
    vector<string> parameters;
    double longitude, latitude, radius;
    string time;
    cout << "Please enter the time (format: YYYY-MM-DD): ";
    cin >> time;
    cout << "Please enter the longitude of the center of the zone: ";
    cin >> longitude;
    cout << "Please enter the latitude of the center of the zone: ";
    cin >> latitude;
    cout << "Please enter the radius of the zone: ";
    cin >> radius;
    parameters.push_back(time);
    parameters.push_back(to_string(latitude));
    parameters.push_back(to_string(longitude));
    parameters.push_back(to_string(radius));

    return parameters;
}

vector<string> View::getParametersOfGetSimilarSensors()
{
    vector<string> parameters;
    string start, end, measurementType;
    cout << "Please enter the type of measurement you want to compare (PM10, O3, NO2, SO2): ";
    cin >> measurementType;
    cout << "Please enter the start date of the period (format: YYYY-MM-DD): ";
    cin >> start;
    cout << "Please enter the end date of the period (format: YYYY-MM-DD): ";
    cin >> end;
    parameters.push_back(measurementType);
    parameters.push_back(start);
    parameters.push_back(end);


    return parameters;
}
