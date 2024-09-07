using namespace std;
#include <iostream>

#include "User.h"

User::User ( const User & unUser )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
}


User::User ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} 


User::~User ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} 



