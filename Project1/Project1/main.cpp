// main.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

#include "CMatrice.h"

#include <iostream>


int main()
{
	printf("Hello World!\n");

	CMatrice <int> MatriceEntier1(3,2);
	CMatrice <int> MatriceEntier2(MatriceEntier1);

	for (unsigned int i = 0; i < MatriceEntier1.MTPLire_NbLigne(); i++)
	{
		for (unsigned int j = 0; j < MatriceEntier1.MTPLire_NbColonne(); j++)
		{
			MatriceEntier1.MTPModifier_Element(i, j, i);
		}
	}

	MatriceEntier1.MTPAfficherMatrice();
	MatriceEntier2.MTPAfficherMatrice();

	MatriceEntier1.MTPViderMatrice();
	MatriceEntier2.MTPViderMatrice();

	//printf("\n %d", MatriceEntier1.MTPLire_NbColonne());

	getchar();
	return 0;
}


