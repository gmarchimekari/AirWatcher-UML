using namespace std;
#include <iostream>

#include "Provider.h"

Provider::Provider ( const Provider & unProvider )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} 


Provider::Provider ( string unProviderId, Cleaner* unCleaner ) : providerId (unProviderId), cleaner(unCleaner)
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} 


Provider::~Provider ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
}


Cleaner* Provider::getCleaner (  ) const
{
    return cleaner;
}

string Provider::getProviderId (  ) const
{
    return providerId;
} 

