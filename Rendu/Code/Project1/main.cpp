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
	if (argc > 1)
	{
		/* Etape 1 : récupération des paramètres */
		CMatrice<double> **ppMATEntree = (CMatrice<double>**)malloc(sizeof(void *) * argc - 1);	// Stockage des pointeurs de Matrice en entrée
		CFichier **ppFICBuffer_CFichier = (CFichier **)malloc(sizeof(void *) * argc - 1);		// Stockage des CFichiers généré.

		try
		{
			printf("Debut de Generation\n");
			// récupération / génération
			for (int iPosition_Entre = 1; iPosition_Entre < argc; iPosition_Entre++)
			{

				ppFICBuffer_CFichier[uiNbMatriceValide] = new CFichier(argv[iPosition_Entre]);
				ppMATEntree[uiNbMatriceValide] = ppFICBuffer_CFichier[uiNbMatriceValide]->FICLire_MTMPMatrice();
				ppMATEntree[uiNbMatriceValide]->MTPAfficherMatrice();
				uiNbMatriceValide++;


			}
			printf("Generation réussite\n");

			/* Etape 2 : Saisie de l'utilisateur */
			// Récupération
			
			std::cout << "Saisir une valeur pour la division des matrices :\n"<< "Tous caracteres autre qu'un nombre vaut 0\n";


			std::cin >> dSaisieUtilisateur;
			cin.clear();


			
			std::cout << "Saisie reussite\n";

			/* Step 3 : Opérations externes */

			// Multiplication
			for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					COperator<double>::OPEMultiplication_Externe(ppMATEntree[iPosition_Matrice][0], dSaisieUtilisateur).MTPAfficherMatrice();
				}
				catch (CException excErreur)
				{
					throw(excErreur);
				}

			}
			std::cout << "Test de Multiplication termine\n";

			// Division
			for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					COperator<double>::OPEDivision_Externe(ppMATEntree[iPosition_Matrice][0], dSaisieUtilisateur).MTPAfficherMatrice();
				}
				catch (CException excErreur)
				{
					throw(excErreur);
				}

			}

			std::cout << "Test de division termine\n";

			/* Step 4 : Operations internes */
			// Addition
			cout << "Test de l'addition \n";
			// allocation d'une matrice
			CMatrice<double> *pmatBuffer = new CMatrice<double>(ppMATEntree[0][0]);

			for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					*pmatBuffer = *pmatBuffer + ppMATEntree[iPosition_Matrice][0];

				}
				catch (CException EXCErreur)
				{
					delete pmatBuffer;
					throw(EXCErreur);
				}

			}
			pmatBuffer->MTPAfficherMatrice();
			cout << "Test de l'addition termine\n";
			// Alternance addition / soustraction
			cout << "Debut du test de la soustraction/addition" << endl;
			pmatBuffer[0] = ppMATEntree[0][0];	// réinitialisation

			for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					if (iPosition_Matrice % 2 == 1)
					{
						*pmatBuffer = ppMATEntree[iPosition_Matrice][0];
						*pmatBuffer = *pmatBuffer - ppMATEntree[iPosition_Matrice][0];
					}
					else
					{
						*pmatBuffer = *pmatBuffer + ppMATEntree[iPosition_Matrice][0];
					}


				}
				catch (CException EXCErreur)
				{
					delete pmatBuffer;
					throw(EXCErreur);
				}

			}
			pmatBuffer->MTPAfficherMatrice();
			cout << "Test de la soustraction/addition termine\n";

			

			// Test Multiplication des Matrices passez en paramètre
			cout << "Debut du test de la multiplication interne" << endl;
			pmatBuffer[0] = ppMATEntree[0][0];	// reinitialisation

			for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					*pmatBuffer = *pmatBuffer * ppMATEntree[iPosition_Matrice][0];
				}
				catch (CException excErreur)
				{
					delete pmatBuffer;
					throw(excErreur);
				}

			}
			pmatBuffer->MTPAfficherMatrice();
			cout << "Test de la multiplication interne termine\n";

			/* Step bonus : Transposition des matrices*/
			cout << "Debut du test de la transposee" << endl;
			for (size_t iPosition_Matrice = 0; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
			{
				try
				{
					COperator<double>::OPETranspose_Matrice(ppMATEntree[iPosition_Matrice][0]).MTPAfficherMatrice();
				}
				catch (CException excErreur)
				{
					throw(excErreur);
				}

			}
			cout << "Test de la transposee termine\n";
			
			/* Step final : Vidange memoire*/
			// Matrice d'entrée
			free(ppMATEntree);

			for (size_t iCurrentFicfichier = 0; iCurrentFicfichier < uiNbMatriceValide; iCurrentFicfichier++)
			{
				delete ppFICBuffer_CFichier[iCurrentFicfichier];
			}
			free(ppFICBuffer_CFichier);
			// Buffer Addition
			delete pmatBuffer;
		}
		catch (CException EXCErreur)
		{
			EXCErreur.EXCAfficher_Erreur();
			free(ppMATEntree);
			for (size_t iCurrentFicfichier = 0; iCurrentFicfichier < uiNbMatriceValide; iCurrentFicfichier++)
			{
				delete ppFICBuffer_CFichier[iCurrentFicfichier];
			}
			free(ppFICBuffer_CFichier);
			// Buffer Addition

		}
	}
	else
	{
		cout << "Donner un fichier la prochaine fois" << endl;
	}

	return 0;
}
