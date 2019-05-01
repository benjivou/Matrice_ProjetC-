
#ifndef COPERATOR
#define	COPERATOR
#include "CMatrice.h"

#define Denominateur_Nul_Erreur 5

class COperator
{
public:
	static CMatrice<double> OPETranspose_Matrice(CMatrice<double> matElement);
	static CMatrice<double> OPEDivision_Externe(CMatrice<double> matElement, double dDiviseur);
	static CMatrice<double> OPEMultiplication_Externe(CMatrice<double> matElement, double dMutiplicateur);
};
#endif // !COPERATOR
