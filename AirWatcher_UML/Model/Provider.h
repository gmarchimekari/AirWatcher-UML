#if ! defined ( PROVIDER_H )
#define PROVIDER_H

#include "User.h"
#include "Cleaner.h"
#include <string>

class Provider : public User
{

public:
    Provider ( const Provider & unProvider );
    Provider ( string unProviderId, Cleaner* unCleaner );
    virtual ~Provider ( );
    Cleaner* getCleaner (  ) const;
    string getProviderId (  ) const;

private:
    string providerId;
    Cleaner* cleaner;

};

#endif // PROVIDER_H

