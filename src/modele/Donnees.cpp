#include <iostream>
using namespace std;

#include "Donnees.h"


        Donnees::Donnees()
        {
            FluxImport flux;

            
            donneesCapteurs.listeCapteurs = flux.importerCapteurs();
            donneesUtilisateurs.listeUtilisateurs = flux.importerUtilisateur();
            donneesPurificateurs.listePurificateurs = flux.importerPurificateur();
        }
        
        Donnees::~Donnees()
        {

        }
    
