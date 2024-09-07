#if !defined(AGENCY_H)
#define AGENCY_H

#include "User.h"

class Agency : public User
{
public:
    Agency(const Agency &unAgency);
    Agency();
    virtual ~Agency();

protected:
};

#endif // AGENCY_H
