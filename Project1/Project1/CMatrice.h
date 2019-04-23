
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
	unsigned int uinbColonne;
	unsigned int uinbLigne;
	MType ** pMTPMatrice; 

	//Constructeurs et Destructeurs

public:
	CMatrice<MType>();
	CMatrice<MType>(unsigned int iTaille);
	CMatrice<MType>(unsigned int iNBCol, unsigned int iNBLigne);
	CMatrice<MType>(CMatrice<MType> & MTPP1);

	~CMatrice<MType>();

	CMatrice<MType> &operator=(CMatrice<MType> &MTPParam);

	//Méthodes

	unsigned int MTPLire_Element(unsigned int iNumCol, unsigned int iNumLigne) { return pMTPMatrice[iNumLigne][iNumCol]; } //inline
	void MTPModifier_Element(unsigned int iNumCol, unsigned int iNumLigne, unsigned int iElement) { pMTPMatrice[iNumLigne][iNumCol] = iElement; } //inline
	unsigned int MTPLire_NbLigne() { return uinbLigne; } //inline
	unsigned int MTPLire_NbColonne() { return uinbColonne; } //inline

	void MTPAfficherMatrice();

};


#endif //CMATRICE_H

#include "CMatrice.cpp"
