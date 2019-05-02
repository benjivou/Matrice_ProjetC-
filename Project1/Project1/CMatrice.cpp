// CMatrice.cpp : fichier source correspondant à l'en-tête précompilé ; nécessaire au bon déroulement de la compilation

#include <stdlib.h>
#include <iostream>

using namespace std;
//Constructeurs et destructeurs

/**
 *\brief : Constructeur par défaut d'une matrice 
 */
template<class MType>
CMatrice<MType>::CMatrice()
{
	uiMTPNbColonne = 0;
	uiMTPNbLigne = 0;
	ppMTPMatrice = nullptr;
}

/**
 *\brief : Constructeur par défaut qui initialise une matrice carrée
 *\param : uiTaille : La taille de la matrice à initialiser
 *\post condition : Ne pas initialiser avec une taille négatif ou égale à 0
 */
template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiTaille)
{
	uiMTPNbColonne = uiTaille;
	uiMTPNbLigne = uiTaille;

	if (uiTaille <= 0)
	{
		CException EXCNbLigColErreur(Nb_Colonne_Ligne_Erreur);
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

/**
 *\brief : Constructeur par défaut qui initialise une matrice de taille souhaitée
 *\param : uiNbLigne : La taille de la ligne de la matrice à initialiser
 *		   uiNBCol : La taille de la colonne de la matrice à initialiser
 *\post condition : Ne pas initialiser avec une taille négatif ou égale à 0
 */
template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiNbLigne, unsigned int uiNBCol)
{
	

	if (uiNbLigne <= 0 || uiNBCol <= 0)
	{
		CException EXCNbLigColDiffErreur(Nb_Colonne_Ligne_Erreur);
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

/**
 *\brief : Constructeur de recopie qui initialise une matrice de taille de la matrice passée en paramètre
 *\param : MTPParam : La matrice dont on recopie la taille et les éléments
 */
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

/**
 *\brief : Destructeur d'une matrice qui vide la matrice avant de la supprimer
 */
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

/**
 *\brief : Surcharge de l'opérateur d'affectation qui facilite la recopie d'une matrice dans une autre
 *\param : MTPParam : La matrice dont on recopie la taille et les éléments
 */
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

/**
 *\brief : Surcharge de l'opérateur + qui facilite l'addition de deux matrices
 *\param : MTPParam :La matrice à droite de l'addition 
 *\return : MTPMatriceResultat : La matrice résultat de l'opération
 */
template<class MType>
CMatrice<MType> & CMatrice<MType>::operator+(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbColonne() || uiMTPNbLigne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(Nb_Colonne_Ligne_Diff_Add_Erreur);
		throw EXCNbLigColDiff;
	}

	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);


	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] + MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return *MTPMatriceResultat;
}

/**
 *\brief : Surcharge de l'opérateur - qui facilite la soustraction de deux matrices
 *\param : MTPParam :La matrice à droite de la soustraction
 *\return : MTPMatriceResultat : La matrice résultat de l'opération
 */
template<class MType>
CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbColonne() || uiMTPNbLigne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(Nb_Colonne_Ligne_Diff_Sub_Erreur);
		throw EXCNbLigColDiff;
	}

	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MTPMatriceResultat->ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] - MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return *MTPMatriceResultat;

}

/**
 *\brief : Surcharge de l'opérateur * qui facilite la multiplication de deux matrices
 *\param : MTPParam :La matrice à droite de la multiplication
 *\return : MTPMatriceResultat : La matrice résultat de l'opération
 */
template<class MType>
CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> &MTPParam)
{
	if (uiMTPNbColonne != MTPParam.MTPLire_NbLigne())
	{
		CException EXCNbLigColDiff(Nb_Colonne_Ligne_Diff_Mult_Erreur);
		throw EXCNbLigColDiff;
	}
	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(uiMTPNbLigne, uiMTPNbColonne);

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

/**
 *\brief : Affiche les éléments de la matrice courante
 */
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