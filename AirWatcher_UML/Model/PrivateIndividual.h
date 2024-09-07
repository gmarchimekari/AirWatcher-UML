#if !defined(PRIVATEINDIVIDUAL_H)
#define PRIVATEINDIVIDUAL_H

#include "User.h"
#include "Sensor.h"
using namespace std;

class Sensor;

class PrivateIndividual : public User
{

public:
    PrivateIndividual(const PrivateIndividual &unPrivateIndividual);
    PrivateIndividual(string unPrivateIndividualId, vector<Sensor *> sensors, bool isTrustable = true, int nbPoints = 0);
    virtual ~PrivateIndividual();
    vector<Sensor *> getSensors() const;
    string getPrivateIndividualId() const;
    bool getTrustable() const;
    void setTrustable(bool trustable);
    int getPoints() const;
    void setPoints(int points);

private:
    string privateIndividualId;
    vector<Sensor *> sensors; // list of sensors linked to the private
    bool trustable;           // true if the private is trustable, false otherwise
    int points;               // number of the private's individual points
};

#endif // PRIVATEINDIVIDUAL_H
