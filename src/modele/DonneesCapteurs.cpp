/*************************************************************************
                           DonneesCapteurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <DonneesCapteurs> (fichier DonneesCapteurs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "DonneesCapteurs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DonneesCapteurs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

DonneesCapteurs::DonneesCapteurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <DonneesCapteurs>" << endl;
#endif
} //----- Fin de DonneesCapteurs


DonneesCapteurs::~DonneesCapteurs ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <DonneesCapteurs>" << endl;
#endif
} //----- Fin de ~DonneesCapteurs


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
