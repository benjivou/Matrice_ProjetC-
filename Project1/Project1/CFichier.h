/*	@brief Cette classe permet de récupérer 
*	les informations du fichier et après les stocks
*	dans une matrice
*/
#include "CMatrice.h"
#ifndef CFICHIER_H
#define CFICHIER_H 

class CFichier
{
public:
	CFichier();
	CFichier(char* adr);
	~CFichier();

	// Getter 
	CMatrice <double> *FICLire_MTMPMatrice() { return &MTPMatrice; };// inline
	int FICLire_NbLigne() { return MTPMatrice.MTPLire_NbLigne(); } //inline
	int FICLire_NbColonne() { return MTPMatrice.MTPLire_NbColonne(); } //inline
	char* FICLire_Type() { return cType; }; // inline

	// Afficheur
	void FICAffiche_Contenu_Fich();

private:
	CMatrice <double> MTPMatrice;
	char* cType;
};

#endif // !CFICHIER_H
