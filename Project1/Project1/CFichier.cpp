#include "CFichier.h"


/* */
/**
 *\brief Constructeur par défaut il sert simplement à éviter les problèmes de créations par défaut
 */
CFichier::CFichier()
{
	MTPMatrice = nullptr;
	*pcType = '\0';
}


/**
 *\brief ne fait rien car on détruit le CFichier indépendemment du CMatrice
 */
CFichier::~CFichier()
{
	// s'il y a une CMatrice allouée dynamiquement
	if (*pcType != '\0')
	{
		delete MTPMatrice;
	}
}

/**
 *\brief On lui passe en paramètre un chemin d'accés à un fichier, génére une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'accés au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probléme ou vide
 * sinon c'est un Cfichier avec les bonnes valeurs
 */
CFichier::CFichier(const char * cAdresse)
{
	
	printf("%s \n", cAdresse);
	unsigned int uiPosLigne;
	int iPos;						// position dns la ligne
	int iValid = 1;					// dit s'il y a une erreur
	unsigned int uiLigne = 0;		// donne la ligne du fichier en cours d'étude
	char pcLine[MAX_LONGUEUR_LINE];	// ligne d'argument pour créer la matrice

	/* Variable nécessaire à la création de matrice*/
	char pcArgType[MAX_TAILLE_ARG];
	unsigned int uiColonne;
	unsigned int iLigne;

	/* Step1 : Ouverture du flux */
	FILE *pfFile;
	fopen_s(&pfFile, cAdresse, "r");

	// Si erreur : Ouverture
	if (pfFile == nullptr)
	{
		iValid = 0;
		printf("Chemin invalid\n");
	}
	else
	{
		/* Step2 : Initialisation */
		// Récupération des colonnes / lignes  / types
		while (iValid == 1 && uiLigne < 4 && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL)
		{
			
			/* test de la balise */
			// balise invalide
			if (FICStartWith(ppcTestBalise[uiLigne], pcLine, MAX_LONGUEUR_LINE) == 0)
			{

				iValid = 0;
				printf("Syntaxe error: '%s'\n", pcLine);
			}
			/* Les balises sont bonnes */
			else
			{
				// positionne le pointeur pour récupéré la valeur
				iPos = iLongueurBal[uiLigne];

				/* balise type */
				if (uiLigne == 0)
				{
					// Si erreur : Type trop long
					if (FICCopieString(pcLine + iPos-1, pcArgType) == 1)
					{
						iValid = 0;
						printf("Trop de caractère pour definir le type \n ");
						//iPos1--;
					}
				}
				/* balise restantes*/
				else
				{
					iPos--;	// repositionnement du ^pointeur sur le début de la value
					/* balise NBLigne, NBColonne*/
					if (uiLigne == 1)
					{
						
						iLigne = atoi((pcLine + iPos));	// recup de la valeur
					}
					if (uiLigne == 2)
					{
						uiColonne = atoi((pcLine + iPos));	// recup de la valeur
					}
				}
			}

			uiLigne++;
		}
		


		// Création de l'objet CMatrice
		if (FICStartWith("double", pcArgType, MAX_TAILLE_ARG) == 1)
		{
			
			FICCopieString((char*)"double",pcType);				// Sauvegarde du type 

			uiPosLigne = 0;

			MTPMatrice = new CMatrice<double>(iLigne, uiColonne);
			/* Step3 : Remplissage */
			// recupération de la ligne
			while (uiPosLigne < iLigne && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL )
			{
				// Remplissage case à case
				FICStocke_Ligne_Dans_Matrice(pcLine, MTPMatrice, uiPosLigne);
				uiPosLigne++;		// il reste à récupérer une ligne de moins
			}
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
	
	// fichier à problème
	if (iValid == 0)
	{
		MTPMatrice = new CMatrice<double>();
		*pcType = '\0';
	}
	else
	{
		fclose(pfFile);
	}
}

void CFichier::FICAffiche_Contenu_Fich()
{
	printf(" \nSon type est : %s \n", pcType);
	MTPMatrice->MTPAfficherMatrice();
}
	
	

/*
 *\brief trouve la première occurrence de cSeparateur dansla pcLigne
 *\param[out] pointeur sur la nouvelle occurrence, sinon pointeur nullptr
 */
char * CFichier::FICFindFirstChar(char * pcLigne, char cSeparateur)
{
	int iCurseur = 0;
	while (pcLigne[iCurseur] != '\0')
	{

		if (pcLigne[iCurseur] == cSeparateur)
		{
			return pcLigne + iCurseur;
		}
		iCurseur++;
	}
	return nullptr;
}

/**
 *\brief fonction cacher pour tester les balises
 *\param[in] cPrefx
 *\param[in] cMot à comparer
 *\param[out] 1 si c'est bon 0 sinon
 */
int CFichier::FICStartWith(const char * cPrefix, const char * cMot, int iLongueurPrefix)
{	
	{
		
		int iRes = 0;
		int iPosition = 0;

		while (iPosition < iLongueurPrefix && cMot[iPosition] != '\0' && cPrefix[iPosition] == cMot[iPosition])
		{
			
			iPosition++;

			// cas terminal

		}
		if (cMot[iPosition] != '\0')
		{
			iRes = 1;
		}
		
		return iRes;
	}
}

int CFichier::FICCopieString(char * pcSrc, char * pcDest)
{
	int iPos1 = 0;
	int res;
	// Stockage des éléments
	while (*(pcSrc + iPos1) != '\0' && iPos1 < MAX_TAILLE_ARG)
	{
		pcDest[iPos1] = pcSrc[iPos1];
		iPos1++;
	}

	pcSrc[iPos1] == '\0' ? res = 0  : res = 1;
	pcDest[iPos1] = '\0';
	return res;
}

/**
 *\brief rempli la matrice du CFichier avec une ligne d'élément
 */

int CFichier::FICStocke_Ligne_Dans_Matrice(char* pcLigne, CMatrice<double>* pmStockage, unsigned int uiCurrentLigne)
{
	unsigned int uiCurrentColonne = 0;
	char *pcCurrent;	// pointeur sur la derniere occurence du ' '
	pcCurrent = FICFindFirstChar(pcLigne, ' ');

	while (pcCurrent != nullptr)
	{
		*pcCurrent = '\0';
		
		MTPMatrice->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// remplissage de la matrice
		pcLigne = pcCurrent + 1;															// déplace le pointeur
		pcCurrent = FICFindFirstChar(pcLigne, ' ');
		uiCurrentColonne++;
	}
	MTPMatrice->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// dernier élément

	return 0;
}

