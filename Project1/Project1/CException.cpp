#include "CException.h"
#include <iostream>
using namespace std;

CException::CException()
{
}
CException::~CException()
{
}

void CException::EXCAfficherErreur()
{
	switch (EXCLireErreur())
	{
	case 1:
		cerr << "Erreur : Initialisation taille matrice" << endl;
		break;

	case 2:
		cerr << "Erreur : Addition de deux matrices" << endl;
		break;

	case 3:
		cerr << "Erreur : Soustraction de deux matrices" << endl;
		break;

	case 4:
		cerr << "Erreur : Multiplication de deux matrices" << endl;
		break;

	case 5:
		cerr << "Erreur : Division par un scalaire egale a 0" << endl;
		break;
	case CHEMIN_INVALID:
		cerr << "Erreur : Chemin invalid " << endl;
		break;
	case BALISE_INVALID:
		cerr << "Erreur: mauvaise balises" << endl;
		break;
	case TYPE_TROP_LONG:
		cerr << "Erreur: mauvaise balises ( Type trop long )" << endl;
		break;
	case MAUVAIS_TYPE_MATRICE:
		cerr << "Erreur: Type different de double" << endl;
		break;
	}
}