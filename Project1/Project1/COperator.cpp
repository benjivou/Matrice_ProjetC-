/**
 *\brief : Fonction qui fait la transposée d'une matrice donnée
 *\param : MTPParam :La matrice à transposée
 *\return : MTPMatTranspose : Retourne par référence la matrice transposée
 */
template <class MType>
CMatrice<MType> COperator<MType>::OPETranspose_Matrice(CMatrice<MType> MTPParam)
{
	/**
	 *Step 1: Init
	 */
	CMatrice<MType> *MTPMatTranspose = new CMatrice<MType>(MTPParam.MTPLire_NbColonne(), MTPParam.MTPLire_NbLigne());
	/**
	 *Step 2 : Remplissage
	 */
	for (size_t iLigneElement = 0; iLigneElement < MTPParam.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < MTPParam.MTPLire_NbColonne(); iColonneElement++)
		{
			MTPMatTranspose->MTPModifier_Element(iColonneElement, iLigneElement, MTPParam.MTPLire_Element(iLigneElement, iColonneElement));
		}
	}
	return *MTPMatTranspose;
}

/**
 *\brief : Fonction qui fait la division d'une matrice par un scalaire
 *\param : MTPParam : La matrice à diviser
 *         dDiviseur : Le scalaire par lequel on divise la matrice
 *\return : MTPMatriceResultat : Retourne par référence de la matrice divisée
 */
template <class MType>
CMatrice<MType> COperator<MType>::OPEDivision_Externe(CMatrice<MType> MTPParam, MType dDiviseur)
{
	if (dDiviseur == 0)
	{
		CException EXCDenNul(Denominateur_Nul_Erreur);
		throw EXCDenNul;
	}

	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(MTPParam.MTPLire_NbLigne(), MTPParam.MTPLire_NbColonne());

	for (size_t iLigneElement = 0; iLigneElement < MTPParam.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < MTPParam.MTPLire_NbColonne(); iColonneElement++)
		{
			MTPMatriceResultat->MTPModifier_Element(iLigneElement, iColonneElement, MTPParam.MTPLire_Element(iLigneElement, iColonneElement) / dDiviseur);
		}
	}
	return *MTPMatriceResultat;
}

/**
 *\brief : Fonction qui fait la division d'une matrice par un scalaire
 *\param : MTPParam : La matrice à multiplier
 *         dMutiplicateur : Le scalaire par lequel on multiplie la matrice
 *\return : MTPMatriceResultat : Retourne par référence de la matrice multipliée
 */
template <class MType>
CMatrice<MType> COperator<MType>::OPEMultiplication_Externe(CMatrice<MType> MTPParam, MType dMutiplicateur)
{
	CMatrice <MType> *MTPMatriceResultat = new CMatrice<MType>(MTPParam.MTPLire_NbLigne(), MTPParam.MTPLire_NbColonne());

	for (size_t iLigneElement = 0; iLigneElement < MTPParam.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < MTPParam.MTPLire_NbColonne(); iColonneElement++)
		{
			MTPMatriceResultat->MTPModifier_Element(iLigneElement, iColonneElement, MTPParam.MTPLire_Element(iLigneElement, iColonneElement) * dMutiplicateur);
		}
	}
	return *MTPMatriceResultat;
}

/**
 *\brief : Fonction qui fait appel à l'opérateur* pour multiplier deux matrices
 *\param : MTPParam1 : La première matrice 
		   MTPParam2 : La deuxième matrice
 *\return : le résultat de l'opération
 */
template <class MType>
CMatrice<MType> &COperator<MType>::OPEMultiplication_Matrice(CMatrice<MType> MTPParam1, CMatrice<MType> MTPParam2)
{
	return (MTPParam1 * MTPParam2);
}

/**
 *\brief : Fonction qui fait appel à l'opérateur+ pour additionner deux matrices
 *\param : MTPParam1 : La première matrice
		   MTPParam2 : La deuxième matrice
 *\return : le résultat de l'opération
 */
template <class MType>
CMatrice<MType> &COperator<MType>::OPEAddition_Matrice(CMatrice<MType> MTPParam1, CMatrice<MType> MTPParam2)
{
	return (MTPParam1 + MTPParam2);
}

/**
 *\brief : Fonction qui fait appel à l'opérateur- pour soustraire deux matrices
 *\param : MTPParam1 : La première matrice
 *         MTPParam2 : La deuxième matrice
 *\return : le résultat de l'opération
 */
template <class MType>
CMatrice<MType> &COperator<MType>::OPESoustraction_Matrice(CMatrice<MType> MTPParam1, CMatrice<MType> MTPParam2)
{
	return (MTPParam1 - MTPParam2);
}