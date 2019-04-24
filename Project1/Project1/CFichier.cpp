#include "CFichier.h"

/**
 *\brief Constructeur par défaut il sert simplement à éviter les problèmes de créations par défaut
 */
CFichier::CFichier()
{
	MTPMatrice = nullptr;
	cType = '\0';
}


/**
 *\brief ne fait rien car on détruit le CFichier indépendemment du CMatrice
 */
CFichier::~CFichier()
{
	// s'il y a une CMatrice allouée dynamiquement
	if (*cType != '\0')
	{
		delete MTPMatrice;
	}
}

/**
 *\brief On lui passe en paramètre un chemin d'accés à un fichier, génére une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'accés au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probléme ou vide 
 * sinon c'est un Cfichier avec les bonnes valeurs
 */
CFichier::CFichier(char * cAdresse)
{
	/* Step1 : Ouverture du flux */

	// Si erreur : Ouverture

	/* Step2 : Iniialisation */
	// Récupération des colonnes / lignes  / types

	// Création de l'objet CMatrice

	/* Step3 : Remplissage */
	// Remplissage case à case

	// Si erreur : fichier fini

	// Si erreur : NaN

	// Si erreur : Syntax
}
void CFichier::FICAffiche_Contenu_Fich()
{

}

