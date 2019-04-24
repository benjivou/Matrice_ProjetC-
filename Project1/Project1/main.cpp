// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

#include "CMatrice.h"

#include <iostream>



int main()
{
	printf("Hello World!\n");

	CMatrice <int> MatriceEntier1(3,2);

	/*for (unsigned int i = 0; i < MatriceEntier1.MTPLire_NbLigne(); i++)
	{
		for (unsigned int j = 0; j < MatriceEntier1.MTPLire_NbColonne(); j++)
		{
			MatriceEntier1.MTPModifier_Element(i, j, i);
		}
	}*/

	MatriceEntier1.MTPAfficherMatrice();



	getchar();
	return 0;
}


