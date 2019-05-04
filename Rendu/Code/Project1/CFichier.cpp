#include "CFichier.h"


/**
 *\brief Constructeur par d�faut il sert simplement � �viter les probl�mes de cr�ations par d�faut
 */
CFichier::CFichier()
{
	pmatStockage = nullptr;
	*pcType = '\0';
}


/**
 *\brief ne fait rien car on d�truit le CFichier ind�pendemment du CMatrice
 */
CFichier::~CFichier()
{
	// s'il y a une CMatrice allou�e dynamiquement
	if (*pcType != '\0')
	{
		delete pmatStockage;
	}
}

/**
 *\brief On lui passe en param�tre un chemin d'acc�s � un fichier, g�n�re une matrice avec les informations du fichier
 *\param[in] cAdresse c'est le chemin d'acc�s au fichier cible
 *\return un objet CFichier, initialiser avec CFichier() si probl�me ou vide
 * sinon c'est un Cfichier avec les bonnes valeurs
 */
CFichier::CFichier(const char * cAdresse)
{
	
	printf("%s \n", cAdresse);
	unsigned int uiPosLigne;
	int iPos;						// position dns la ligne
	
	unsigned int uiLigne = 0;		// donne la ligne du fichier en cours d'�tude
	char pcLine[MAX_LONGUEUR_LINE];	// ligne d'argument pour cr�er la matrice

	/* Variable n�cessaire � la cr�ation de matrice*/
	char pcArgType[MAX_TAILLE_ARG];
	unsigned int uiColonne;
	unsigned int iLigne;

	/* Step1 : Ouverture du flux */
	FILE *pfFile;
	fopen_s(&pfFile, cAdresse, "r");

	// Si erreur : Ouverture
	if (pfFile == NULL)
	{
		
		CException EXCChemin_Invalid(CHEMIN_INVALID);
		throw EXCChemin_Invalid;
	}
	else
	{
		/* Step2 : Initialisation */
		// R�cup�ration des colonnes / lignes  / types
		while ( uiLigne < 4 && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL)
		{
			
			/* test de la balise */
			// balise invalide
			if (FICDemarre_Avec(ppcTestBalise[uiLigne], pcLine, MAX_LONGUEUR_LINE) == 0)
			{
				fclose(pfFile);
				CException EXCBalise_Invalid(BALISE_INVALID);
				throw EXCBalise_Invalid;
			}
			/* Les balises sont bonnes */
			else
			{
				// positionne le pointeur pour r�cup�r� la valeur
				iPos = iLongueurBal[uiLigne];

				/* balise type */
				if (uiLigne == 0)
				{
					// Si erreur : Type trop long
					if (FICCopie_String(pcLine + iPos-1, pcArgType) == 1)
					{
						fclose(pfFile);
						CException EXCType_Trop_Long(TYPE_TROP_LONG);
						throw EXCType_Trop_Long;
					}
				}
				/* balise restantes*/
				else
				{
					iPos--;	// repositionnement du ^pointeur sur le d�but de la value
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
		


		// Cr�ation de l'objet CMatrice
		if (FICDemarre_Avec("double", pcArgType, MAX_TAILLE_ARG) == 1)
		{
			
			FICCopie_String((char*)"double",pcType);				// Sauvegarde du type 

			uiPosLigne = 0;

			pmatStockage = new CMatrice<double>(iLigne, uiColonne);
			/* Step3 : Remplissage */
			// recup�ration de la ligne
			while (uiPosLigne < iLigne && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL )
			{
				// Remplissage case � case
				FICStocke_Ligne_Dans_Matrice(pcLine, pmatStockage, uiPosLigne);
				uiPosLigne++;		// il reste � r�cup�rer une ligne de moins
			}
		}
		// Si erreur : mauvais type
		else
		{
			fclose(pfFile);
			CException EXCTypeDifferentDeDouble(MAUVAIS_TYPE_MATRICE);
			throw EXCTypeDifferentDeDouble;
		}
	}

	fclose(pfFile);
	
}

void CFichier::FICAffiche_Contenu_Fich()
{
	printf(" \nSon type est : %s \n", pcType);
	pmatStockage->MTPAfficherMatrice();
}
	
	

/*
 *\brief trouve la premi�re occurrence de cSeparateur dansla pcLigne
 *\param[out] pointeur sur la nouvelle occurrence, sinon pointeur nullptr
 */
char * CFichier::FICTrouve_Premiere_Occurrence(char * pcLigne, char cSeparateur)
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
 *\param[in] cMot � comparer
 *\param[out] 1 si c'est bon 0 sinon
 */
int CFichier::FICDemarre_Avec(const char * cPrefix, const char * cMot, int iLongueurPrefix)
{	
	{
		
		int iRes = 0;
		int iPosition = 0;

		while (iPosition < iLongueurPrefix && cMot[iPosition] != '\0' && cPrefix[iPosition] == cMot[iPosition])
		{
			
			iPosition++;

		}
		if (cMot[iPosition] != '\0')
		{
			iRes = 1;
		}
		
		return iRes;
	}
}

int CFichier::FICCopie_String(char * pcSrc, char * pcDest)
{
	int iPos1 = 0;
	int res;
	// Stockage des �l�ments
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
 *\brief rempli la matrice du CFichier avec une ligne d'�l�ment
 */

int CFichier::FICStocke_Ligne_Dans_Matrice(char* pcLigne, CMatrice<double>* pmStockage, unsigned int uiCurrentLigne)
{
	unsigned int uiCurrentColonne = 0;
	char *pcCurrent;	// pointeur sur la derniere occurence du ' '
	pcCurrent = FICTrouve_Premiere_Occurrence(pcLigne, ' ');

	while (pcCurrent != nullptr && uiCurrentColonne != (pmStockage->MTPLire_NbColonne() - 1))
	{
		*pcCurrent = '\0';
		
		pmatStockage->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// remplissage de la matrice
		pcLigne = pcCurrent + 1;															// d�place le pointeur
		pcCurrent = FICTrouve_Premiere_Occurrence(pcLigne, ' ');
		uiCurrentColonne++;
	}

	// la derni�re occurrence est volontairement diff�rente, car il n'y a pas � repositionner pcCurrent apr�s
	pmatStockage->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// dernier �l�ment

	return 0;
}

