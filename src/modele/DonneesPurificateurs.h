/*************************************************************************
                           DonneesPurificateurs  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <DonneesPurificateurs> (fichier DonneesPurificateurs.h) ----------------
#if ! defined ( DonneesPurificateurs_H )
#define DonneesPurificateurs_H

//--------------------------------------------------- Interfaces utilisées
#include "Purificateur.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DonneesPurificateurs>
//
//
//------------------------------------------------------------------------
typedef vector<Purificateur> ListePurificateur;
class DonneesPurificateurs 
{
//----------------------------------------------------------------- PUBLIC

public:
    ListePurificateur listePurificateurs;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    DonneesPurificateurs & operator = ( const DonneesPurificateurs & unDonneesPurificateurs );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    DonneesPurificateurs( const DonneesPurificateurs& unDonneesPurificateurs);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    DonneesPurificateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~DonneesPurificateurs( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DonneesDonneesDonneesPurificateursss>

#endif // DonneesDonneesDonneesPurificateursss_H
