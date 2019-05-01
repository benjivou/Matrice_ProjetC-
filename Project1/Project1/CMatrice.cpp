// CMatrice.cpp : fichier source correspondant à l'en-tête précompilé ; nécessaire au bon déroulement de la compilation

#include <stdio.h>
#include <stdlib.h>

//Constructeurs et destructeurs

template<class MType>
CMatrice<MType>::CMatrice()
{
	uiMTPNbColonne = 0;
	uiMTPNbLigne = 0;
	ppMTPMatrice = nullptr;
}

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiTaille)
{
	uiMTPNbColonne = uiTaille;
	uiMTPNbLigne = uiTaille;

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

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiNbLigne, unsigned int uiNBCol)
{
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
	//Ne fais rien
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
	CMatrice <MType> MatriceResultat(uiMTPNbLigne, uiMTPNbColonne);

	MatriceResultat.ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MatriceResultat.ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MatriceResultat.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] + MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return MatriceResultat;
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator-(CMatrice<MType> &MTPParam)
{
	CMatrice <MType> MatriceResultat(uiMTPNbLigne, uiMTPNbColonne);

	MatriceResultat.ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MatriceResultat.ppMTPMatrice[uiMTPBoucle2] = new MType[uiMTPNbColonne];
	}

	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			MatriceResultat.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] = ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] - MTPParam.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1];
		}
	}
	return MatriceResultat;
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator*(CMatrice<MType> &MTPParam)
{
	CMatrice <MType> MatriceResultat(uiMTPNbLigne, MTPParam.MTPLire_NbColonne());

	MatriceResultat.ppMTPMatrice = new MType*[uiMTPNbLigne];

	for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbLigne; uiMTPBoucle2++)
	{
		MatriceResultat.ppMTPMatrice[uiMTPBoucle2] = new MType[MTPParam.MTPLire_NbColonne()];
	}

	//exception : ligne  if(colonne == m1.ligne) // si nb colonnes = nb lignes de l'autre matrice 
	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < MTPParam.MTPLire_NbColonne(); uiMTPBoucle1++)
		{
			for (unsigned int uiMTPBoucle2 = 0; uiMTPBoucle2 < uiMTPNbColonne; uiMTPBoucle2++)
			{
				MatriceResultat.ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1] += ppMTPMatrice[uiMTPBoucle][uiMTPBoucle2] * MTPParam.ppMTPMatrice[uiMTPBoucle2][uiMTPBoucle1];
			}
		}
	}
	return MatriceResultat;
}

template<class MType>
void CMatrice<MType>::MTPAfficherMatrice()
{
	printf("Matrice : \n");
	for (unsigned int uiMTPBoucle = 0; uiMTPBoucle < uiMTPNbLigne; uiMTPBoucle++)
	{
		for (unsigned int uiMTPBoucle1 = 0; uiMTPBoucle1 < uiMTPNbColonne; uiMTPBoucle1++)
		{
			printf(" %f ", (double)ppMTPMatrice[uiMTPBoucle][uiMTPBoucle1]);
		}
		printf("\n");
	}
	printf("\n");
}

template<class MType>
void CMatrice<MType>::MTPViderMatrice()
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