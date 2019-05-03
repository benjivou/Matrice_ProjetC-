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


	// Si erreur : pas de paramètre
	if (argc > 0)
	{
		/* Etape 1 : recupération des paramèrtres */
		CMatrice<double> **ppmatEntree = (CMatrice<double>**)malloc(sizeof(void *) * argc - 1);	// Stockage des pointeurs de Matrice en entée
		CFichier **ppficBuffer_CFichier = (CFichier **)malloc(sizeof(void *) * argc - 1);		// Stockage des CFichiers généré.

		try
		{

			// recupération / génération
			for (int iPosition_Entre = 1; iPosition_Entre < argc; iPosition_Entre++)
			{

				ppficBuffer_CFichier[uiNbMatriceValide] = new CFichier(argv[iPosition_Entre]);
				ppmatEntree[uiNbMatriceValide] = ppficBuffer_CFichier[uiNbMatriceValide]->FICLire_MTMPMatrice();
				ppmatEntree[uiNbMatriceValide]->MTPAfficherMatrice();
				uiNbMatriceValide++;


			}
			printf("Generation réussite\n");

			/* Etape 2 : Saisie de L'utilisateur */
			// Recupération
			while (dSaisieUtilisateur < 0.0)
			{
				std::cout << "Saisir un valeur pour la division des matrices :\n";


				std::cin >> dSaisieUtilisateur;
				/*
				while (!dSaisieUtilisateur)
				{
					cin.clear();
					printf("Une valeur strictement positive est plus à propos dans cette situation\n");
					getchar();
					std::cin >> dSaisieUtilisateur;
				}
				*/
				cin.clear();


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
			std::cout << "Test de Multiplication termine\n";

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

			std::cout << "Test de division termine\n";

			/* Step 4 : Operations internes */
			// Addition
			cout << "Test de l'addition \n";
			// allocation d'une matrice
			CMatrice<double> *pmatBuffer = new CMatrice<double>(ppmatEntree[0][0]);

			for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					*pmatBuffer = *pmatBuffer + ppmatEntree[iPosition_Matrice][0];

				}
				catch (CException excErreur)
				{
					delete pmatBuffer;
					throw(excErreur);
				}

			}
			pmatBuffer->MTPAfficherMatrice();
			cout << "Test de l'addition termine\n";
			// Alternance addition / soustraction
			cout << "Debut du test de la soustraction" << endl;
			pmatBuffer[0] = ppmatEntree[0][0];	// reinitialisation

			for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					if (iPosition_Matrice % 2 == 1)
					{
						*pmatBuffer = ppmatEntree[iPosition_Matrice][0];
					}
					else
					{
						*pmatBuffer = *pmatBuffer + ppmatEntree[iPosition_Matrice][0];
					}


				}
				catch (CException excErreur)
				{
					delete pmatBuffer;
					throw(excErreur);
				}

			}
			pmatBuffer->MTPAfficherMatrice();
			cout << "Test de la division termine\n";
			/* Step final : Vidange memoire*/
			// Matrice d'entrée
			free(ppmatEntree);
			for (size_t iCurrentFicfichier = 0; iCurrentFicfichier < uiNbMatriceValide; iCurrentFicfichier++)
			{
				delete ppficBuffer_CFichier[uiNbMatriceValide];
			}
			free(ppficBuffer_CFichier);
			// Buffer Addition
			delete pmatBuffer;
		}
		catch (CException excErreur)
		{
			excErreur.EXCAfficherErreur();
			free(ppmatEntree);
			for (size_t iCurrentFicfichier = 0; iCurrentFicfichier < uiNbMatriceValide; iCurrentFicfichier++)
			{
				delete ppficBuffer_CFichier[uiNbMatriceValide];
			}
			free(ppficBuffer_CFichier);
			// Buffer Addition

			
		}

	}

	getchar();
	
	return 0;
}
