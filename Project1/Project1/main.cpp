// main.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
// Ex�cuter le programme : Ctrl+F5 ou menu D�boguer > Ex�cuter sans d�bogage
// D�boguer le programme : F5 ou menu D�boguer > D�marrer le d�bogage

#include "CFichier.h"
#include "COperator.h"
#include <iostream>


int main()
{
	printf("Hello World!\n");

	CMatrice <double> MatriceEntier1(3, 2);
	CMatrice <double> MatriceEntier2(MatriceEntier1);

	for (unsigned int i = 0; i < MatriceEntier1.MTPLire_NbLigne(); i++)
	{
		for (unsigned int j = 0; j < MatriceEntier1.MTPLire_NbColonne(); j++)
		{
			MatriceEntier1.MTPModifier_Element(i, j, (double )i);
		}
	}


	MatriceEntier1.MTPAfficherMatrice();
	MatriceEntier2.MTPAfficherMatrice();

	// Test Coperator 
	printf("Test COperator\n");

	
	COperator::OPETranspose_Matrice(MatriceEntier1).MTPAfficherMatrice();
	COperator::OPEDivision_Externe(MatriceEntier1, 3.0).MTPAfficherMatrice();
	COperator::OPEMultiplication_Externe(MatriceEntier1, 3.0).MTPAfficherMatrice();
	MatriceEntier1.MTPViderMatrice();
	MatriceEntier2.MTPViderMatrice();

	//printf("\n %d", MatriceEntier1.MTPLire_NbColonne());



	printf("TEst des CFichier\n");

	CFichier Fichier0("Matrice_Qui_n'existe_pas.JcpOuT");
	CFichier Fichier2("CFichier.cpp");
	// cas qui marche
	CFichier Fichier1("Test/Matrice_Valide.txt");
	Fichier1.FICAffiche_Contenu_Fich();
	getchar();
	return 0;
}
