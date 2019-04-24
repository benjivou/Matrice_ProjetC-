#include "CFichier.h"

/* */
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
	int iPos;					
	int iPos1;						// position dns la ligne
	int iValid = 1;					// dit s'il y a une erreur
	unsigned int uiLigne = 0;		// donne la ligne du fichier en cours d'�tude
	char pcLine[MAX_LONGUEUR_LINE];	// ligne d'argument pour cr�er la matrice

	/* Variable n�cessaire � la cr�ation de matrice*/
	char pcArgType[MAX_TAILLE_ARG];
	unsigned int uiColonne;
	unsigned int iLigne;

	/* Step1 : Ouverture du flux */
	FILE *pfFile;
	fopen_s(&pfFile,cAdresse, "r");

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
		while (iValid == 1 && uiLigne <4 && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL)
		{
			
			/* test de la balise */
			if (FICStartWith(ppcTestBalise[uiLigne], pcLine,iLongueurBal[uiLigne]))
			{
				// balise invalide
				iValid = 0;
				printf("Syntaxe error: ' %s '", ppcTestBalise[uiLigne]);
			}
			/* Les balises sont bonnes */
			else
			{
				// positionne le pointeur pour r�cup�r� la valeur
				iPos = iLongueurBal[uiLigne];

				/* balise type */
				if (uiLigne == 0)
				{
					iPos1 = 0;
					// Stockage des �l�ments
					while (*(pcLine+iPos+iPos1) != '\0' && iPos1 < MAX_TAILLE_ARG)
					{
						pcArgType[iPos1] = pcLine[iPos + iPos1];
						iPos1++;
					}
					// Si erreur : Type trop long
					if (iPos1 == MAX_TAILLE_ARG)
					{
						iValid = 0;
						printf("Trop de caract�re pour definir le type");
						iPos1--;
					}
					
					
					pcArgType[iPos1] = '\0'; // fermeture
				}
				/* balise restantes*/
				else
				{
					/* balise NBLigne, NBColonne*/
					if (uiLigne == 1)
					{
						uiColonne = atoi((pcLine + iPos));	// recup de la valeur
					}
					if (uiLigne == 2)
					{
						iLigne = atoi((pcLine+ iPos));	// recup de la valeur
					}
				}
			}
			
			
		}
		// Cr�ation de l'objet CMatrice	
		if (FICStartWith("double", pcArgType, MAX_TAILLE_ARG) == 1)
		{
			MTPMatrice = new CMatrice<double>(uiColonne, iLigne);
			/* Step3 : Remplissage */
			// recup�ration de la ligne

			// Remplissage case � case

			// Si erreur : fichier fini avant la fin

			// Si erreur : NaN

			// Si erreur : Syntax
		}
		// Si erreur : mauvais type
		else
		{
			printf("mauvais type de matrice");
			iValid = 0;
		}
		
	}
	// fichier � probl�me
	if (iValid == 0)
	{
		MTPMatrice = new CMatrice<double>();
		cType = '\0';
	}
	else
	{
		fclose(pfFile);
	}
}
void CFichier::FICAffiche_Contenu_Fich()
{

}

/**
 *\brief fonction cacher pour tester les balises
 *\param[in] cPrefx
 *\param[in] cMot � comparer
 *\param[out] 1 si c'est bon 0 sinon
 */
int CFichier::FICStartWith(const char * cPrefix, const char * cMot, int iLongueurPrefix)
{
	int iRes = 0;
	int iPosition = 0;

	while ( iPosition< iLongueurPrefix && cMot[iPosition] != '\0' && cPrefix[iPosition] == cMot[iPosition])
	{
		iPosition++;

		if (iPosition == iLongueurPrefix -1)
		{
			iRes = 1;
		}
	}

	return iRes;
}

