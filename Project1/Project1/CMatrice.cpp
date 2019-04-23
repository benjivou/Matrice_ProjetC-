// CMatrice.cpp : fichier source correspondant à l'en-tête précompilé ; nécessaire au bon déroulement de la compilation

#include "CMatrice.h"


//Constructeurs et destructeurs

template<class MType>
CMatrice<MType>::CMatrice()
{
	inbColonne = 0;
	inbLigne = 0;
	** pMTPMatrice = nullptr;
}

template<class MType>
CMatrice<MType>::CMatrice(int iTaille)
{
}

template<class MType>
CMatrice<MType>::CMatrice(int iNBCol, int iNBLigne)
{
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
}
