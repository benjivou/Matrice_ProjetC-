#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#define CHEMIN_INVALID 11
#define BALISE_INVALID 12
#define TYPE_TROP_LONG 13
#define MAUVAIS_TYPE_MATRICE 14

class CException
{

private:
	unsigned int uiEXCErreur;

public:
	CException();
	CException(unsigned int uiErreur) { uiEXCErreur = uiErreur; }
	~CException();

	unsigned int EXCLireErreur() { return uiEXCErreur; }
	void EXCModifierErreur(unsigned int uiErreur) { uiEXCErreur = uiErreur; }
	void EXCAfficherErreur();
};

#endif //CEXCEPTION_H
