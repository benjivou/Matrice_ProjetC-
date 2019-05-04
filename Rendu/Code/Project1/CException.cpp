#include "CException.h"
#include <iostream>
using namespace std;

CException::CException()
{
}
CException::~CException()
{
}

void CException::EXCAfficher_Erreur()
{
	switch (EXCLire_Erreur())
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
	case 11:
		cerr << "Erreur : Chemin invalid " << endl;
		break;
	case 12:
		cerr << "Erreur: mauvaise balises" << endl;
		break;
	case 13:
		cerr << "Erreur: mauvaise balises ( Type trop long )" << endl;
		break;
	case 14:
		cerr << "Erreur: Type different de double" << endl;
		break;
	case 15:
		cerr << "Erreur: Taille invalid de matrice, Corrigez le fichier en param" << endl;
	}
}