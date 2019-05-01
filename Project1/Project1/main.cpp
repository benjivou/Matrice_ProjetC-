// main.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
// Ex�cuter le programme : Ctrl+F5 ou menu D�boguer > Ex�cuter sans d�bogage
// D�boguer le programme : F5 ou menu D�boguer > D�marrer le d�bogage

#include "CFichier.h"
#include "COperator.h"
#include <iostream>
#include <stdlib.h>
#include <cstdio>


int main(int argc, char *argv[]
)
{
	double dSaisieUtilisateur = -1.0;
	unsigned int uiNbMatriceValide = 0;
	CMatrice<double>* pmatBuffer;

	// Si erreur : pas de paramètre 
	if (argc > 0)
	{
		/* Etape 1 : recupération des paramèrtres */
		CMatrice<double> **ppmatEntree = (CMatrice<double>**)malloc(sizeof(void*) * argc);	// Stockage des pointeurs de Matrice en entée

		// recupération / génération
		for (int iPosition_Entre = 1; iPosition_Entre <= argc; iPosition_Entre++)
		{

			try
			{
				printf("chemin du fichier : %s \n", argv[iPosition_Entre]);
				ppmatEntree[uiNbMatriceValide] = CFichier(argv[iPosition_Entre]).FICLire_MTMPMatrice();
				ppmatEntree[uiNbMatriceValide]->MTPAfficherMatrice();
				uiNbMatriceValide++;
			}
			catch (const std::exception&)
			{
				std::cout << "erreur intialisation de la matrice :" << iPosition_Entre << '\n';
			}

		}
		printf("Generation réussite\n");

		/* Etape 2 : Saisie de L'utilisateur */
		// Recupération
		while (dSaisieUtilisateur < 0.0)
		{
			std::cout << "Saisir un valeur pour la division des matrices :\n";
			try
			{
				std::cin >> dSaisieUtilisateur;
			}
			catch (const std::exception&)
			{
				dSaisieUtilisateur = -1.0;
				std::cout << "Une valeur strictement positive est plus à propos dans cette situation\n";
			}

		}
		std::cout << "Saisie réussite\n";

		/* Step 3 : Operations externes */

		// Multiplication
		for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
		{
			try
			{
				COperator<double>::OPEMultiplication_Externe(ppmatEntree[iPosition_Matrice][0], dSaisieUtilisateur).MTPAfficherMatrice();
			}
			catch (const std::exception&)
			{
				std::cout << "Probléme de Multiplication sur la matrice numéro : " << iPosition_Matrice << '\n';
			}

		}
		std::cout << "Test de Multiplication terminé\n";

		// Division
		for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
		{
			try
			{
				COperator<double>::OPEDivision_Externe(ppmatEntree[iPosition_Matrice][0], dSaisieUtilisateur).MTPAfficherMatrice();
			}
			catch (const std::exception&)
			{
				std::cout << "Probléme de Division sur la matrice numéro : " << iPosition_Matrice << '\n';
			}

		}

		std::cout << "Test de division terminé\n";

		/* Step 4 : Operations internes */
		// Addition
		for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
		{
			try
			{
				// allocation d'une matrice
				pmatBuffer = new CMatrice<double>(ppmatEntree[iPosition_Matrice][0]);

				COperator<double>::OPEDivision_Externe(ppmatEntree[iPosition_Matrice][0], dSaisieUtilisateur).MTPAfficherMatrice();
			}
			catch (const std::exception&)
			{
				std::cout << "Probléme de Division sur la matrice numéro : " << iPosition_Matrice << '\n';
			}

		}
		/* Step final : Vidange memoire*/
		free(ppmatEntree);
	}


	getchar();
	return 0;
}
