
// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

#ifndef CMATRICE_H
#define CMATRICE_H

template <class MType>
class CMatrice
{
	//Attributs
private : 
	int inbColonne;
	int inbLigne;
	MType ** pMTPMatrice; 

	//Constructeurs et Destructeurs

public:
	CMatrice<MType>();
	CMatrice<MType>(int iTaille);
	CMatrice<MType>(int iNBCol, int iNBLigne);
	CMatrice<MType>(CMatrice<MType> & MTPP1);

	~CMatrice<MType>();

	//Méthodes

	MType **MTPLire_Element(int iNumCol, int iNumLigne) { return pMTPMatrice[iNumLigne][iNumCol]; } //inline
	void MTPModifier_Element(int iNumCol, int iNumLigne, int iElement) { pMTPMatrice[iNumLigne][iNumCol] = iElement; } //inline
	int MTPLire_NbLigne() { return inbLigne; } //inline
	int MTPLire_NbColonne() { return inbColonne; } //inline

	void MTPAfficherMatrice();

};


#endif //CMATRICE_H

#include "CMatrice.cpp"
