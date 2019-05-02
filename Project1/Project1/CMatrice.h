// Conseils pour bien d�marrer : 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet > Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet > Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier > Ouvrir > Projet et s�lectionnez le fichier .sln.

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

	//M�thodes

	MType MTPLire_Element(unsigned int uiNumLigne, unsigned int uiNumCol) { return ppMTPMatrice[uiNumLigne][uiNumCol]; } //inline
	void MTPModifier_Element(unsigned int uiNumLigne, unsigned int uiNumCol, MType uiElement) { ppMTPMatrice[uiNumLigne][uiNumCol] = uiElement; } //inline
	unsigned int MTPLire_NbLigne() { return uiMTPNbLigne; } //inline
	unsigned int MTPLire_NbColonne() { return uiMTPNbColonne; } //inline

	void MTPViderMatrice();
	void MTPAfficherMatrice();

};

#include "CMatrice.cpp"
#endif //CMATRICE_H

