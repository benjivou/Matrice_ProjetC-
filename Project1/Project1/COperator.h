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
};
#include "COperator.cpp"
#endif // !COPERATOR