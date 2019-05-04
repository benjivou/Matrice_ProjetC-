/*	@brief Cette classe permet de r�cup�rer
*	les informations du fichier et apr�s les stocks
*	dans une matrice et garde le type dans un attribut
*/
#include "CMatrice.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef CFICHIER_H
#define CFICHIER_H


#define MAX_LONGUEUR_LINE 80

#define MAX_TAILLE_ARG 20		// nombre de caractère dans 1 argument du fichier
/* Initialisation des balises à trouver dans le fichier */
#define NB_BALISE 4
#define TAILLE_BALISE_TYPE 13
#define TAILLE_BALISE_NBLIGNES 10
#define TAILLE_BALISE_NBCOLONNES 12
#define TAILLE_BALISE_MATRICE 10

const char pcBaliseType[TAILLE_BALISE_TYPE] = "TypeMatrice=";
const char pcBaliseNbLignes[TAILLE_BALISE_NBLIGNES] = "NBLignes=";
const char pcBaliseNbColonnes[TAILLE_BALISE_NBCOLONNES] = "NBColonnes=";
const char pcBaliseMatrice[TAILLE_BALISE_MATRICE] = "Matrice=[";
// regroupement
const int iLongueurBal[NB_BALISE] = { TAILLE_BALISE_TYPE,TAILLE_BALISE_NBLIGNES,TAILLE_BALISE_NBCOLONNES,TAILLE_BALISE_MATRICE };
const char *ppcTestBalise[NB_BALISE] = { pcBaliseType,pcBaliseNbLignes,pcBaliseNbColonnes,pcBaliseMatrice };
/* Message d'erreur */
#define CHEMIN_INVALID 11
#define BALISE_INVALID 12
#define TYPE_TROP_LONG 13
#define MAUVAIS_TYPE_MATRICE 14
#define TAILLE_MATRICE_INVALID 15

class CFichier
{
public:
	CFichier();
	CFichier(const char* adrcAdresse);
	~CFichier();

	// Getter
	CMatrice <double> *FICLire_MTMPMatrice() { return pmatStockage; };// inline
	int FICLire_NbLigne() { return pmatStockage->MTPLire_NbLigne(); } //inline
	int FICLire_NbColonne() { return pmatStockage->MTPLire_NbColonne(); } //inline
	char* FICLire_Type() { return pcType; }; // inline

	// Afficheur
	void FICAffiche_Contenu_Fich();	// affiche le contenu de la matrice

private:

	CMatrice <double> *pmatStockage;
	char pcType[MAX_TAILLE_ARG];

	char* FICTrouve_Premiere_Occurrence(char * pcLigne, char cSeparateur);
	int FICDemarre_Avec(const char* cPrefix, const char* cMot, int iLongueurPrefix);
	int FICCopie_String(char *pcSrc, char* pcDest);
	int FICStocke_Ligne_Dans_Matrice(char* pcLigne, CMatrice<double> *pmStockage, unsigned int uiCurrentLigne);
};
#include "CFichier.cpp"
#endif // !CFICHIER_H
