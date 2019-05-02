#ifndef COPERATOR
#define	COPERATOR
#include "CMatrice.h"
#define Denominateur_Nul_Erreur 5

template <class MType>
class COperator
{
public:
	static CMatrice<MType> OPETranspose_Matrice(CMatrice<MType> matElement);
	static CMatrice<MType> OPEDivision_Externe(CMatrice<MType> matElement, MType dDiviseur);
	static CMatrice<MType> OPEMultiplication_Externe(CMatrice<MType> matElement, MType dMutiplicateur);

	static CMatrice<MType> &OPEMultiplication_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2);
	static CMatrice<MType> &OPEAddition_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2);
	static CMatrice<MType> &OPESoustraction_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2);

};
#include "COperator.cpp"
#endif // !COPERATOR
