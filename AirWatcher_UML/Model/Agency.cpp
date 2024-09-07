using namespace std;
#include <iostream>
#include "Agency.h"

Agency::Agency(const Agency &unAgency)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Agency>" << endl;
#endif
}

Agency::Agency()
{
#ifdef MAP
    cout << "Appel au constructeur de <Agency>" << endl;
#endif
}

Agency::~Agency()
{
#ifdef MAP
    cout << "Appel au destructeur de <Agency>" << endl;
#endif
}
