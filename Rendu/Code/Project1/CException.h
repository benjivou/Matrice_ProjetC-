#ifndef CEXCEPTION_H
#define CEXCEPTION_H



class CException
{

private:
	//Attributs

	unsigned int uiEXCErreur;

public:

	//Constructeurs et Destructeurs

	CException(); //Constructeur qui ne fait rien
	CException(unsigned int uiErreur) { uiEXCErreur = uiErreur; } //inline
	~CException(); //Destructeur qui n'a pas d'utilité

	//Méthodes
	unsigned int EXCLire_Erreur() { return uiEXCErreur; } //inline
	void EXCModifier_Erreur(unsigned int uiErreur) { uiEXCErreur = uiErreur; } //inline
	void EXCAfficher_Erreur();
};

#endif //CEXCEPTION_H
