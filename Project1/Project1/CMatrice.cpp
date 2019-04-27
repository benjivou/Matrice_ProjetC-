// CMatrice.cpp : fichier source correspondant à l'en-tête précompilé ; nécessaire au bon déroulement de la compilation

#include <stdio.h>
#include <stdlib.h>

//Constructeurs et destructeurs

template<class MType>
CMatrice<MType>::CMatrice()
{
	uinbColonne = 0;
	uinbLigne = 0;
	ppMTPMatrice = nullptr;
}

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiTaille)
{
	uinbColonne = uiTaille;
	uinbLigne = uiTaille;
	
	ppMTPMatrice = new MType*[uinbLigne];

	for (unsigned int iMTPBoucle1 = 0; iMTPBoucle1 < uinbLigne; iMTPBoucle1++)
	{
			ppMTPMatrice[iMTPBoucle1] = new MType[uinbColonne];
	}

	for (unsigned int iMTPBoucle = 0; iMTPBoucle < uinbLigne; iMTPBoucle++)
	{
		for (unsigned int jMTPBoucle = 0; jMTPBoucle < uinbColonne; jMTPBoucle++)
		{
			ppMTPMatrice[iMTPBoucle][jMTPBoucle] = 0;
		}
	}
}

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiNBLigne, unsigned int uiNBCol)
{
	uinbColonne = uiNBCol;
	uinbLigne = uiNBLigne;
	
	ppMTPMatrice = new MType*[uinbLigne];

	for (unsigned int iMTPBoucle1 = 0; iMTPBoucle1 < uinbLigne; iMTPBoucle1++)
	{
		ppMTPMatrice[iMTPBoucle1] = new MType[uinbColonne];
	}

	for (unsigned int iMTPBoucle = 0; iMTPBoucle < uinbLigne; iMTPBoucle++)
	{
		for (unsigned int jMTPBoucle = 0; jMTPBoucle < uinbColonne; jMTPBoucle++)
		{
			ppMTPMatrice[iMTPBoucle][jMTPBoucle] = 0;
		}
	}
}

template<class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MTPP1)
{

}

template<class MType>
CMatrice<MType>::~CMatrice()
{
}

// Méthodes

template<class MType>
void CMatrice<MType>::MTPAfficherMatrice()
{
	printf("Matrice : \n");
	for (unsigned int iMTPBoucle = 0; iMTPBoucle < uinbLigne; iMTPBoucle++)
	{
		for (unsigned int jMTPBoucle = 0; jMTPBoucle < uinbColonne; jMTPBoucle++)
		{
			printf(" %f ",(double)ppMTPMatrice[iMTPBoucle][jMTPBoucle]);
		}
		printf("\n");
	}
	printf("\n");
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> &MTPParam)
{

}