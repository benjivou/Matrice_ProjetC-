// CMatrice.cpp : fichier source correspondant à l'en-tête précompilé ; nécessaire au bon déroulement de la compilation

#include <stdlib.h>
#include <iostream>

using namespace std;
//Constructeurs et destructeurs

/**
 *\brief ne fait rien car on détruit le CFichier indépendemment du CMatrice
 */
template<class MType>
CMatrice<MType>::CMatrice()
{
	uiMTPNbColonne = 0;
	uiMTPNbLigne = 0;
	ppMTPMatrice = nullptr;
}

/**
 *\brief On lui passe en paramètre un chemin d'accés à un fichier, génére une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'accés au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probléme ou vide
 * sinon c'est un Cfichier avec les bonnes valeurs
 */

 ////////////////////PostCond :Ne pas mettre de taille négatif
template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiTaille)
{
	uiMTPNbColonne = uiTaille;
	uiMTPNbLigne = uiTaille;

	if (uiTaille <= 0)
	{
		CException EXCNbLigColErreur(PARAM_MATRICE_INVALID);
		throw EXCNbLigColErreur;
	}
	ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		ppMTPMatrice[uiMTPBoucle] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = 0;
		}
	}
}

////////////////////PostCond :Ne pas mettre de taille négatif
template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiNbLigne, unsigned int uiNBCol)
{
	

	if (uiNbLigne <= 0 || uiNBCol <= 0)
	{
		CException EXCNbLigColDiffErreur(PARAM_MATRICE_INVALID);
		throw EXCNbLigColDiffErreur;
	}
	uiMTPNbColonne = uiNBCol;
	uiMTPNbLigne = uiNbLigne;

	ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		ppMTPMatrice[uiMTPBoucle] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbLigne; uiMTPBoucle1++)
	{
		for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbColonne; uiMTPBoucle2++)
		{
			ppMTPMatrice[uiMTPBoucle1][uiMTPBoucle2] = 0;
		}
	}
}

template<class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MTPParam)
{
	uiMTPNbColonne = MTPParam.uiMTPNbColonne;
	uiMTPNbLigne = MTPParam.uiMTPNbLigne;

	ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
}

template<class MType>
CMatrice<MType>::~CMatrice()
{
	uiMTPNbColonne = 0;
	uiMTPNbLigne = 0;
	if (ppMTPMatrice)
	{
		for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
			delete[] ppMTPMatrice[uiMTPBoucle];
		delete[] ppMTPMatrice;
	}
}

// Méthodes

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> &MTPParam)
{
	uiMTPNbColonne = MTPParam.uiMTPNbColonne;
	uiMTPNbLigne = MTPParam.uiMTPNbLigne;

	ppMTPMatrice = new MType*[uiMTPNbLigne];


	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}
	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return *this;
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator+(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbColonne() || uiMTPNbLigne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(PARAM_ADD_ERREUR);
		throw EXCNbLigColDiff;
	}
	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);

	MTPMatriceResultat->ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] + MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return *MTPMatriceResultat;
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbColonne() || uiMTPNbLigne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(PARAM_SUB_ERREUR);
		throw EXCNbLigColDiff;
	}

	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);

	MTPMatriceResultat->ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] - MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return *MTPMatriceResultat;

}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(PARAM_MULTI_ERREUR);
		throw EXCNbLigColDiff;
	}
	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);

	MTPMatriceResultat->ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle2] = new MType[MTPParam.MTPLire_NbColonne()];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < MTPParam.MTPLire_NbColonne(); uiMTPBoucle1++)
		{
			for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbColonne; uiMTPBoucle2++)
			{
				MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] += ppMTPMatrice[uiMTPBoucle][uiMTPBoucle2] * MTPParam.ppMTPMatrice[uiMTPBoucle2][uiMTPBoucle1];
			}
		}
	}
	return *MTPMatriceResultat;
}

template<class MType>
void CMatrice<MType>::MTPAfficherMatrice()
{
	cout <<"Matrice : " << endl;
	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			cout << " " << ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

