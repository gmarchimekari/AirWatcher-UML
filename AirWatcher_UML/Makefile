CCFLAGS = -ansi -pedantic -Wall -std=c++11 -lm #-DMAP

exe : ./bin/Main.o ./bin/User.o ./bin/Agency.o ./bin/Cleaner.o ./bin/Sensor.o ./bin/Data.o ./bin/Measurement.o ./bin/PrivateIndividual.o ./bin/Provider.o ./bin/Statistics.o ./bin/View.o ./bin/Controller.o ./bin/CsvParser.o
	g++ -o exe ./bin/Main.o ./bin/Agency.o ./bin/Cleaner.o ./bin/Data.o ./bin/Measurement.o ./bin/PrivateIndividual.o ./bin/Provider.o ./bin/Sensor.o ./bin/Statistics.o ./bin/User.o ./bin/View.o ./bin/Controller.o ./bin/CsvParser.o 

./bin/User.o : ./Model/User.cpp ./Model/User.h
	g++ -o ./bin/User.o -c ./Model/User.cpp $(CCFLAGS)

./bin/Agency.o : ./Model/Agency.cpp ./Model/Agency.h
	g++ -o ./bin/Agency.o -c ./Model/Agency.cpp $(CCFLAGS) 
	
./bin/Cleaner.o : ./Model/Cleaner.cpp ./Model/Cleaner.h
	g++ -o ./bin/Cleaner.o -c ./Model/Cleaner.cpp $(CCFLAGS) 
	
./bin/Data.o : ./Model/Data.cpp ./Model/Data.h
	g++ -o ./bin/Data.o -c ./Model/Data.cpp $(CCFLAGS) 

./bin/Measurement.o : ./Model/Measurement.cpp ./Model/Measurement.h
	g++ -o ./bin/Measurement.o -c ./Model/Measurement.cpp $(CCFLAGS)

./bin/PrivateIndividual.o : ./Model/PrivateIndividual.cpp ./Model/PrivateIndividual.h
	g++ -o ./bin/PrivateIndividual.o -c ./Model/PrivateIndividual.cpp $(CCFLAGS)

./bin/Provider.o : ./Model/Provider.cpp ./Model/Provider.h
	g++ -o ./bin/Provider.o -c ./Model/Provider.cpp $(CCFLAGS)

./bin/Sensor.o : ./Model/Sensor.cpp ./Model/Sensor.h
	g++ -o ./bin/Sensor.o -c ./Model/Sensor.cpp $(CCFLAGS)

./bin/Statistics.o : ./Model/Statistics.cpp ./Model/Statistics.h
	g++ -o ./bin/Statistics.o -c ./Model/Statistics.cpp $(CCFLAGS)

./bin/View.o : ./View/View.cpp ./View/View.h
	g++ -o ./bin/View.o -c ./View/View.cpp $(CCFLAGS)

./bin/Controller.o : ./Control/Controller.cpp ./Control/Controller.h
	g++ -o ./bin/Controller.o -c ./Control/Controller.cpp $(CCFLAGS)

./bin/CsvParser.o : ./Control/CsvParser.cpp ./Control/CsvParser.h
	g++ -o ./bin/CsvParser.o -c ./Control/CsvParser.cpp $(CCFLAGS)

./bin/Main.o : Main.cpp ./View/View.h
	g++ -o ./bin/Main.o -c Main.cpp $(CCFLAGS)

sensorTest: 
	g++ -o sensorTest ./Model/Statistics.cpp ./Test/SensorTest.cpp ./Model/Measurement.cpp ./Model/PrivateIndividual.cpp ./Model/Data.cpp ./Model/Sensor.cpp ./Model/User.cpp $(CCFLAGS)

statTest: 
	g++ -o statTest ./Model/Statistics.cpp ./Test/StatisticsTest.cpp ./Model/Measurement.cpp ./Model/PrivateIndividual.cpp ./Model/Data.cpp ./Model/Sensor.cpp ./Model/User.cpp $(CCFLAGS)

clean: 
	rm -f ./bin/*.o
	rm -f exe
	rm -f sensorTest
	rm -f statTest