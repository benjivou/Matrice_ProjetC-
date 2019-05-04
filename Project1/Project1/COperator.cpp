
template <class MType>
CMatrice<MType> COperator<MType>::OPETranspose_Matrice(CMatrice<MType> matElement)
{
	/**
	 *Step 1: Init
	 */
	CMatrice<MType> matTranspose(matElement.MTPLire_NbColonne(), matElement.MTPLire_NbLigne());
	/**
	 *Step 2 : Remplissage
	 */
	for (size_t iLigneElement = 0; iLigneElement < matElement.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < matElement.MTPLire_NbColonne(); iColonneElement++)
		{
			matTranspose.MTPModifier_Element(iColonneElement, iLigneElement, matElement.MTPLire_Element(iLigneElement, iColonneElement));
		}
	}
	return matTranspose;
}

template <class MType>
CMatrice<MType> COperator<MType>::OPEDivision_Externe(CMatrice<MType> matElement, MType dDiviseur)
{
	if (dDiviseur == 0)
	{
		CException EXCDenNul(DENOMINATEUR_NUL);
		throw EXCDenNul;
	}
	for (size_t iLigneElement = 0; iLigneElement < matElement.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < matElement.MTPLire_NbColonne(); iColonneElement++)
		{
			matElement.MTPModifier_Element(iLigneElement, iColonneElement, matElement.MTPLire_Element(iLigneElement, iColonneElement) / dDiviseur);
		}
	}
	return matElement;
}

template <class MType>
CMatrice<MType> COperator<MType>::OPEMultiplication_Externe(CMatrice<MType> matElement, MType dMutiplicateur)
{
	for (size_t iLigneElement = 0; iLigneElement < matElement.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < matElement.MTPLire_NbColonne(); iColonneElement++)
		{
			matElement.MTPModifier_Element(iLigneElement, iColonneElement, matElement.MTPLire_Element(iLigneElement, iColonneElement) * dMutiplicateur);
		}
	}
	return matElement;
}

template <class MType>
CMatrice<MType> &COperator<MType>::OPEMultiplication_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2)
{
	return (matElement1 * matElement2);
}

template <class MType>
CMatrice<MType> &COperator<MType>::OPEAddition_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2)
{
	return (matElement1 + matElement2);
}

template <class MType>
CMatrice<MType> &COperator<MType>::OPESoustraction_Matrice(CMatrice<MType> matElement1, CMatrice<MType> matElement2)
{
	return (matElement1 - matElement2);
}
