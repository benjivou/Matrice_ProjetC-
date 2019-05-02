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
	/*
	 * Test des différentes clases séparement 
	 */
	double dSaisieUtilisateur = -1.0;
	unsigned int uiNbMatriceValide = 0;
	printf("Hello World!\n");

	CMatrice <double> MatriceEntier1(3, 2);
	CMatrice <double> MatriceEntier2(MatriceEntier1);

	for (unsigned int i = 0; i < MatriceEntier1.MTPLire_NbLigne(); i++)
	{
		for (unsigned int j = 0; j < MatriceEntier1.MTPLire_NbColonne(); j++)
		{
			MatriceEntier1.MTPModifier_Element(i, j, (double)i);
		}
	}


	MatriceEntier1.MTPAfficherMatrice();
	MatriceEntier2.MTPAfficherMatrice();

	// Test Coperator 
	printf("Test COperator\n");


	COperator<double>::OPETranspose_Matrice(MatriceEntier1).MTPAfficherMatrice();
	COperator<double>::OPEDivision_Externe(MatriceEntier1, 3.0).MTPAfficherMatrice();
	COperator<double>::OPEMultiplication_Externe(MatriceEntier1, 3.0).MTPAfficherMatrice();
	/*MatriceEntier1.MTPViderMatrice();
	MatriceEntier2.MTPViderMatrice();
	*/
	//printf("\n %d", MatriceEntier1.MTPLire_NbColonne());



	printf("TEst des CFichier\n");

	CFichier Fichier0("Matrice_Qui_n'existe_pas.JcpOuT");
	CFichier Fichier2("CFichier.cpp");
	// cas qui marche
	CFichier Fichier1("../Test/Matrice_Valide.txt");
	Fichier1.FICAffiche_Contenu_Fich();



	/* Teste classe CMatrice */


	//CMatrice<double>* pmatBuffer;

	// Si erreur : pas de paramètre 
	if (argc > 0)
	{
		/* Etape 1 : recupération des paramèrtres */
		CMatrice<double> **ppmatEntree = (CMatrice<double>**)malloc(sizeof(void *) * argc -1);	// Stockage des pointeurs de Matrice en entée
		CFichier **ppficBuffer_CFichier = (CFichier **) malloc(sizeof(void * ) * argc - 1);		// Stockage des CFichiers généré.

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
		cout << "Test de l'addition \n";
		// allocation d'une matrice
		CMatrice<double> *pmatBuffer = new CMatrice<double>(ppmatEntree[0][0]);
		pmatBuffer->MTPAfficherMatrice();
		for (size_t iPosition_Matrice = 1; iPosition_Matrice < uiNbMatriceValide; iPosition_Matrice++)
		{
			try
			{
				*pmatBuffer = *pmatBuffer + ppmatEntree[iPosition_Matrice][0];
				pmatBuffer->MTPAfficherMatrice();
			}
			catch (const std::exception&)
			{
				std::cout << "Probléme de Division sur la matrice numéro : " << iPosition_Matrice << '\n';
			}

		}
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


	getchar();
	return 0;
}
