#include "COperator.h"

CMatrice<double> COperator::OPETranspose_Matrice(CMatrice<double> matElement)
{
	/**
	 *Step 1: Init
	 */
	CMatrice<double> matTranspose(matElement.MTPLire_NbColonne(), matElement.MTPLire_NbLigne());
	/**
	 *Step 2 : Remplissage
	 */
	for (size_t iLigneElement = 0; iLigneElement < matElement.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < matElement.MTPLire_NbColonne(); iColonneElement++)
		{
			matTranspose.MTPModifier_Element(iColonneElement,iLigneElement, matElement.MTPLire_Element(iLigneElement,iColonneElement));
		}
	}
	return matTranspose;
}

CMatrice<double> COperator::OPEDivision_Externe(CMatrice<double> matElement, double dDiviseur)
{
	if (dDiviseur == 0)
	{
		CException EXCDenNul(Denominateur_Nul_Erreur);
		throw EXCDenNul;
	}
	for (size_t iLigneElement = 0; iLigneElement < matElement.MTPLire_NbLigne(); iLigneElement++)
	{
		for (size_t iColonneElement = 0; iColonneElement < matElement.MTPLire_NbColonne(); iColonneElement++)
		{
			matElement.MTPModifier_Element(iLigneElement, iColonneElement, matElement.MTPLire_Element(iLigneElement, iColonneElement)/dDiviseur);
		}
	}
	return matElement;
}

CMatrice<double> COperator::OPEMultiplication_Externe(CMatrice<double> matElement, double dMutiplicateur)
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
