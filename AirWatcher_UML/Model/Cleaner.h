#if !defined(CLEANER_H)
#define CLEANER_H
#include <sstream>
#include <ctime>
using namespace std;

class Cleaner
{

public:
    Cleaner(const Cleaner &unCleaner);
    Cleaner(string unCleanerId, double uneLatitude, double uneLongitude, string start, string stop);
    virtual ~Cleaner();
    string getCleanerId() const;
    double getLatitude() const;
    double getLongitude() const;
    tm *getTimeStart() const;
    tm *getTimeStop() const;

protected:
private:
    string cleanerId;
    double latitude;
    double longitude;
    tm *timeStart;
    tm *timeStop;
    /*
    struct tm {
        int tm_sec;   // seconds of minutes from 0 to 61
        int tm_min;   // minutes of hour from 0 to 59
        int tm_hour;  // hours of day from 0 to 24
        int tm_mday;  // day of month from 1 to 31
        int tm_mon;   // month of year from 0 to 11
        int tm_year;  // year since 1900
        int tm_wday;  // days since sunday
        int tm_yday;  // days since January 1st
        int tm_isdst; // hours of daylight savings time
    }
    */
};

#endif // CLEANER_H
