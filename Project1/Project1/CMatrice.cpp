// CMatrice.cpp�: fichier source correspondant � l'en-t�te pr�compil�; n�cessaire au bon d�roulement de la compilation

#include <stdio.h>

//Constructeurs et destructeurs

template<class MType>
CMatrice<MType>::CMatrice()
{
	uinbColonne = 0;
	uinbLigne = 0;
	pMTPMatrice = nullptr;
}

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiTaille)
{
	uinbColonne = uiTaille;
	uinbLigne = uiTaille;
}

template<class MType>
CMatrice<MType>::CMatrice(unsigned int uiNBCol, unsigned int uiNBLigne)
{
	uinbColonne = uiNBCol;
	uinbLigne = uiNBLigne;
}

template<class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MTPP1)
{

}

template<class MType>
CMatrice<MType>::~CMatrice()
{
}

// M�thodes

template<class MType>
void CMatrice<MType>::MTPAfficherMatrice()
{
	for (unsigned int i = 0; i < uinbLigne; i++)
	{
		for (unsigned int j = 0; j < uinbColonne; j++)
		{
			printf("pMTPMatrice[uinbLigne][uinbColonne]   ");
		}
		printf("\n");
	}
}

template<class MType>
CMatrice<MType> & CMatrice<MType>::operator=(CMatrice<MType> &MTPParam)
{

}