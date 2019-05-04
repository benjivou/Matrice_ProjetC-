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
 *\brief desalloue le CMatrice avant de finir 
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
		while (uiLigne < 4 && fgets(pcLine, MAX_LONGUEUR_LINE, pfFile) != NULL)
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
				iPos = iLongueurBal[uiLigne];					// positionne le pointeur pour r�cup�r� la valeur

				/* balise type */
				if (uiLigne == 0)
				{
					// Si erreur : Type trop long
					if (FICCopie_String(pcLine + iPos - 1, pcArgType) == 1)
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
					if (uiLigne == 1)					// Balise NBLigne
					{
						iLigne = atoi((pcLine + iPos));

						{

						}
					}
					if (uiLigne == 2)					// Balise NBColonne
					{
						uiColonne = atoi((pcLine + iPos));
					}
					else
					{
						if (uiLigne <= 0 || uiColonne <= 0)
						{
							fclose(pfFile);
							throw(new CException(TAILLE_MATRICE_INVALID));
						}
					}


					
				}
				uiLigne++;
			}
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
				// Remplissage Ligne � Ligne
				FICStocke_Ligne_Dans_Matrice(pcLine, pmatStockage, uiPosLigne);
				uiPosLigne++;		
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

/*
 *\brief Affiche un fichier
 */
void CFichier::FICAffiche_Contenu_Fich()
{
	printf(" \nSon type est : %s \n", pcType);
	pmatStockage->MTPAfficherMatrice();
}
	
	

/*
 *\brief trouve la premi�re occurrence de cSeparateur dans la pcLigne
 *\param[in] pcLigne Ligne � parser 
 *\param[in] cSeparateur �leemnt � chercher
 *\param[out] pointeur sur la nouvelle occurrence, sinon nullptr
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
 *\param[in] cPrefx	le pr�fix recherch�
 *\param[in] cMot � comparer
 *\param[in] iLongueurPrefix Taille du prefix
 *\param[out] 1 si c'est bon 0 sinon
 */
int CFichier::FICDemarre_Avec(const char * cPrefix, const char * cMot, int iLongueurPrefix)
{	
	{
		
		int iRes = 0;
		int iPosition = 0;
		/*
		 * Etats de sorties des 3 tests du while
		 * Cas 1: On a compar� toutes les caract�res du Prefix 
		 * Cas 2: le mot est trop cours 
		 * Cas 3: les caract�res ne correspond pas
		 */
		while (iPosition < iLongueurPrefix && cMot[iPosition] != '\0' && cPrefix[iPosition] == cMot[iPosition])
		{
			
			iPosition++;

		}
		// Les prefix est bien le bon
		if (cMot[iPosition] != '\0')
		{
			iRes = 1;
		}
		
		return iRes;
	}
}


/**
 *\brief Rempli pcDest avec les elements de pcSrc
 *\param[in] pcSrc
 *\param[in] pcDest
 *\param[out] 1 si c'est bon 0 sinon
 */
int CFichier::FICCopie_String(char * pcSrc, char * pcDest)
{
	int iPos1 = 0;
	int res;
	// Stockage des �l�ments
	while (*(pcSrc + iPos1) != '\0' && iPos1 < MAX_TAILLE_ARG)	// MAX_TAILLE_ARG donne la taille max du buffer pcDest
	{
		pcDest[iPos1] = pcSrc[iPos1];			
		iPos1++;
	}

	pcSrc[iPos1] == '\0' ? res = 0  : res = 1;	// donne 1 s'il n'y a pas de probl�me
	pcDest[iPos1] = '\0';						// fermeture de la chaine destinataire
	return res;
}

/**
 *\brief rempli la matrice du CFichier avec une ligne d'�l�ment
 *\param[in] pcLigne Ligne de d�part
 *\param[in] pmStockage	Matrice � remplir 
 *\param[in] uiCurrentLigne	Donne la ligne � remplir
 *\param[out] 1 si c'est bon 0 sinon
 *\warning pcLigne est deplacer sur la derni�re valeur, ne pas utiliser avec des listes allou� dynamiquement, car pc Ligne est modifi�
 */

int CFichier::FICStocke_Ligne_Dans_Matrice(char* pcLigne, CMatrice<double>* pmStockage, unsigned int uiCurrentLigne)
{
	unsigned int uiCurrentColonne = 0;
	char *pcCurrent;					// pointeur sur la derniere occurence du ' '
	pcCurrent = FICTrouve_Premiere_Occurrence(pcLigne, ' ');

	/* L'id�e c'est de retrouver le prochaine espace, le remplacer par un caract�re de fin de chaine. 
		Ensuite on d�place la position de pcLigne*/
	while (pcCurrent != nullptr && uiCurrentColonne != (pmStockage->MTPLire_NbColonne() - 1))
	{
		*pcCurrent = '\0';
		
		pmatStockage->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// remplissage de la matrice
		pcLigne = pcCurrent + 1;															// d�placement le pointeur
		pcCurrent = FICTrouve_Premiere_Occurrence(pcLigne, ' ');							// Recherche de la prochaine valeur
		uiCurrentColonne++;
	}

	// la derni�re occurrence est volontairement diff�rente, car il n'y a pas � repositionner pcCurrent apr�s
	pmatStockage->MTPModifier_Element(uiCurrentLigne, uiCurrentColonne, atof(pcLigne));	// dernier �l�ment

	return 0;
}

