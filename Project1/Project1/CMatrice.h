// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.

#ifndef CMATRICE_H
#define CMATRICE_H

template <class MType>
class CMatrice
{
	//Attributs
private:
	unsigned int uiMTPNbColonne;
	unsigned int uiMTPNbLigne;
	MType ** ppMTPMatrice;

	//Constructeurs et Destructeurs

public:
	CMatrice<MType>();
	CMatrice<MType>(unsigned int uiTaille);
	CMatrice<MType>(unsigned int uiNBLigne, unsigned int uiNBCol);
	CMatrice<MType>(CMatrice<MType> & MTPParam);

	~CMatrice<MType>();

	CMatrice<MType> &operator=(CMatrice<MType> &MTPParam);

	//Méthodes

	MType MTPLire_Element(unsigned int uiNumLigne, unsigned int uiNumCol) { return ppMTPMatrice[uiNumLigne][uiNumCol]; } //inline
	void MTPModifier_Element(unsigned int uiNumLigne, unsigned int uiNumCol, MType uiElement) { ppMTPMatrice[uiNumLigne][uiNumCol] = uiElement; } //inline
	unsigned int MTPLire_NbLigne() { return uiMTPNbLigne; } //inline
	unsigned int MTPLire_NbColonne() { return uiMTPNbColonne; } //inline

	void MTPViderMatrice();
	void MTPAfficherMatrice();

};

#include "CMatrice.cpp"
#endif //CMATRICE_H

