// CMatrice.cpp�: fichier source correspondant � l'en-t�te pr�compil�; n�cessaire au bon d�roulement de la compilation

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

// M�thodes

template<class MType>
void CMatrice<MType>::MTPAfficherMatrice()
{
}
