
// Conseils pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.

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

	//M�thodes

	unsigned int MTPLire_Element(unsigned int iNumCol, unsigned int iNumLigne) { return pMTPMatrice[iNumLigne][iNumCol]; } //inline
	void MTPModifier_Element(unsigned int iNumCol, unsigned int iNumLigne, unsigned int iElement) { pMTPMatrice[iNumLigne][iNumCol] = iElement; } //inline
	unsigned int MTPLire_NbLigne() { return uinbLigne; } //inline
	unsigned int MTPLire_NbColonne() { return uinbColonne; } //inline

	void MTPAfficherMatrice();

};


#endif //CMATRICE_H

#include "CMatrice.cpp"
