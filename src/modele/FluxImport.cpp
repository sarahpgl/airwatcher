#include "FluxImport.h"
#include "../utile/LecteurCsv.h"
#include "Capteur.h"
#include "Entreprise.h"
#include "Mesure.h"
#include <vector>
#include <iostream>

using namespace std;

vector<Capteur> FluxImport::importerCapteurs(string cheminDossier)
{
    // Chargement des capteurs et affectation de base au gouvernement
    vector<vector<string>> donnees = LecteurCsv::lireCsv(cheminDossier + "sensors.csv");

    vector<vector<string>>::const_iterator iterateur;
    vector<Capteur> capteurs;

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Capteur capteur((*iterateur)[0], stof((*iterateur)[2]), stof((*iterateur)[1]), "gouvernement");
        capteurs.push_back(capteur);
    }
    // Affectation des capteurs privés aux utilisateurs
    donnees = LecteurCsv::lireCsv(cheminDossier + "users.csv");
    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Capteur>::iterator capteur;
        for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
        {
            if ((*iterateur)[1] == (capteur->id)){
                capteur->proprietaire = (*iterateur)[0];
                break;
            }
        }
    }
    // Chargement des mesures
    donnees = LecteurCsv::lireCsv(cheminDossier + "measurements.csv");
    map<string, map<Date, Mesure>> mesures;
    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Date date((*iterateur)[0]);
        if (mesures.find((*iterateur)[1]) != mesures.end())
        {
            // Le capteur ID existe déjà
            if (mesures[(*iterateur)[1]].find(date) != mesures[(*iterateur)[1]].end())
            {
                // La date existe déjà
                mesures[(*iterateur)[1]][date].setAttribute((*iterateur)[2], stof((*iterateur)[3]));
            }
            else
            {
                // La date existe pas
                Mesure mesure;
                mesure.setAttribute((*iterateur)[2], stof((*iterateur)[3]));
                mesures[(*iterateur)[1]].insert({date, mesure});
            }
        }
        else
        {
            // Le capteur ID existe pas
            Mesure mesure;
            mesure.setAttribute((*iterateur)[2], stof((*iterateur)[3]));
            map<Date, Mesure> donneesCapteur;
            donneesCapteur.insert({date, mesure});
            mesures.insert({(*iterateur)[1], donneesCapteur});
        }
    }

    vector<Capteur>::iterator capteur;
    for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        if (mesures.find(capteur->id) != mesures.end())
            capteur->mesures = mesures[capteur->id];
    }

    return capteurs;
}

vector<Capteur> FluxImport::retirerCapteursErrones(vector<Capteur> capteurs, float margeErreur)
{
    Mesure moyenne;
    int nbMesures = 0;
    vector<Capteur>::iterator capteur;
    for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        MapMesures::iterator mesure;
        if (capteur->proprietaire == "gouvernement")
            for (mesure = capteur->mesures.begin(); mesure != capteur->mesures.end(); mesure++)
            {
                moyenne.concentrationO3 += mesure->second.concentrationO3;
                moyenne.concentrationNO2 += mesure->second.concentrationNO2;
                moyenne.concentrationPM10 += mesure->second.concentrationPM10;
                moyenne.concentrationSO2 += mesure->second.concentrationSO2;
                nbMesures++;
            }
    }
    moyenne.concentrationO3 /= nbMesures;
    moyenne.concentrationNO2 /= nbMesures;
    moyenne.concentrationPM10 /= nbMesures;
    moyenne.concentrationSO2 /= nbMesures;

    for (capteur = capteurs.begin(); capteur < capteurs.end(); capteur++)
    {
        MapMesures::iterator mesure;
        if (capteur->proprietaire != "gouvernement")
            for (mesure = capteur->mesures.begin(); mesure != capteur->mesures.end(); mesure++)
            {
                if(abs(mesure->second.concentrationO3 - moyenne.concentrationO3) > margeErreur)
                {
                    capteurs.erase(capteur);
                }
                else if(abs(mesure->second.concentrationNO2 - moyenne.concentrationNO2) > margeErreur)
                {
                    capteurs.erase(capteur);
                }
                else if(abs(mesure->second.concentrationPM10 - moyenne.concentrationPM10) > margeErreur)
                {
                    capteurs.erase(capteur);
                }
                else if(abs(mesure->second.concentrationSO2 - moyenne.concentrationSO2) > margeErreur)
                {
                    capteurs.erase(capteur);
                }
            }
    }
    return capteurs;
}

vector<Purificateur> FluxImport::importerPurificateurs(string cheminDossier)
{
    vector<vector<string>> donnees = LecteurCsv::lireCsv(cheminDossier + "cleaners.csv");
    vector<vector<string>>::const_iterator iterateur;
    vector<Purificateur> purificateurs;

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        Purificateur purificateur((*iterateur)[0], Coordonnees(stof((*iterateur)[1]), stof((*iterateur)[2])), Date((*iterateur)[3]), Date((*iterateur)[4]), "");
        purificateurs.push_back(purificateur);
    }
    donnees = LecteurCsv::lireCsv(cheminDossier + "providers.csv");

    for (iterateur = donnees.begin(); iterateur < donnees.end(); iterateur++)
    {
        vector<Purificateur>::iterator purificateur;
        for (purificateur = purificateurs.begin(); purificateur < purificateurs.end(); purificateur++)
        {
            if ((*iterateur)[1] == (purificateur->id))
                purificateur->entrepriseId = (*iterateur)[0];
            break;
        }
    }

    return purificateurs;
}