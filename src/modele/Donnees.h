#ifndef Donnees_H // Directives du préprocesseur pour éviter les inclusions multiples
#define Donnees_H

#include <iostream>
#include <string>
using namespace std;

#include "DonneesCapteurs.h"
#include "DonneesUtilisateurs.h"
#include "DonneesPurificateurs.h"
//#include "FluxImport.h"

class Donnees{
    public:
        Donnees();
        ~Donnees();
        DonneesCapteurs donneesCapteurs;
        DonneesUtilisateurs donneesUtilisateurs;
        DonneesPurificateurs donneesPurificateurs;
};

#endif