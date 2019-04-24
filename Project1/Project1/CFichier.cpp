#include "CFichier.h"

/**
 *\brief Constructeur par d�faut il sert simplement � �viter les probl�mes de cr�ations par d�faut
 */
CFichier::CFichier()
{
	MTPMatrice = nullptr;
	cType = '\0';
}


/**
 *\brief ne fait rien car on d�truit le CFichier ind�pendemment du CMatrice
 */
CFichier::~CFichier()
{
	// s'il y a une CMatrice allou�e dynamiquement
	if (*cType != '\0')
	{
		delete MTPMatrice;
	}
}

/**
 *\brief On lui passe en param�tre un chemin d'acc�s � un fichier, g�n�re une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'acc�s au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probl�me ou vide 
 * sinon c'est un Cfichier avec les bonnes valeurs
 */
CFichier::CFichier(char * cAdresse)
{
	int iPos;						// position dns la ligne
	int iValid = 1;					// dit s'il y a une erreur
	unsigned int uiLigne = 0;		// donne la ligne du fichier en cours d'�tude
	char cLine[MAX_LONGUEUR_LINE];	// repr�sente la longueur des lignes avant la matrice
	char cCaract�re;

	char ppcArgumentsMatrice[4][MAX_TAILLE_ARG];

	/* Step1 : Ouverture du flux */
	FILE *pfFile =fopen(cAdresse, "r");

	// Si erreur : Ouverture
	if (pfFile == NULL)
	{
		iValid = 0;
		printf("Chemin invalid");
	}
	else
	{
		/* Step2 : Initialisation */
		// R�cup�ration des colonnes / lignes  / types
		while (iValid == 1 && uiLigne <4 && fgets(cLine, MAX_LONGUEUR_LINE, pfFile) != NULL)
		{
			iPos = 0;
			/* test de la balise */
			while (cLine[iPos] != '\0' && )
			{

			}
			
			
		}
		// Cr�ation de l'objet CMatrice	

		/* Step3 : Remplissage */
		// Remplissage case � case

		// Si erreur : fichier fini avant la fin

		// Si erreur : NaN

		// Si erreur : Syntax
	}
	
}
void CFichier::FICAffiche_Contenu_Fich()
{

}

