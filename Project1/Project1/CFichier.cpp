#include "CFichier.h"

/**
 *\brief Constructeur par d�faut il sert simplement � �viter les probl�mes de cr�ations par d�faut
 */
CFichier::CFichier()
{
	MTPMatrice = nullptr;
	cType = '\0';
}


/**
 *\brief ne fait rien car on d�truit le CFichier ind�pendemment du CMatrice
 */
CFichier::~CFichier()
{
	// s'il y a une CMatrice allou�e dynamiquement
	if (*cType != '\0')
	{
		delete MTPMatrice;
	}
}

/**
 *\brief On lui passe en param�tre un chemin d'acc�s � un fichier, g�n�re une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'acc�s au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probl�me ou vide 
 * sinon c'est un Cfichier avec les bonnes valeurs
 */
CFichier::CFichier(char * cAdresse)
{
	/* Step1 : Ouverture du flux */

	// Si erreur : Ouverture

	/* Step2 : Iniialisation */
	// R�cup�ration des colonnes / lignes  / types

	// Cr�ation de l'objet CMatrice

	/* Step3 : Remplissage */
	// Remplissage case � case

	// Si erreur : fichier fini

	// Si erreur : NaN

	// Si erreur : Syntax
}
void CFichier::FICAffiche_Contenu_Fich()
{

}

