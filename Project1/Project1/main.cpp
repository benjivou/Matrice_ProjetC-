// main.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

#include "CMatrice.h"

#include <iostream>



int main()
{
	printf("Hello World!\n");

	CMatrice <int> MatriceEntier1;
	MatriceEntier1.MTPAfficherMatrice();



	getchar();
	return 0;
}


