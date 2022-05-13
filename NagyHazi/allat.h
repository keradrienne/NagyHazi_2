#ifndef ALLAT_H
#define ALLAT_H
/*
* \file allat.h
* 
* Allat oszt�ly deklar�ci�ja �s f�ggv�nyei
*/

#include "string.h"
#include "datum.h"
#include "memtrace.h"

class Allat {
protected:
	String faj;		///< faj
	String nev;		///< n�v
	Datum szul;		///< szulet�s d�tuma
public:
	///Default konstruktor
	Allat() {}

	/// Konstruktor be�ll�tja az attrib�tumokat
	/// @param faj - faj megnevez�se
	/// @param nev - n�v megad�sa
	/// @param szul - sz�let�si �v megad�sa
	Allat(const char* faj, const char* nev, const Datum& szul) :szul(szul) {
		if(faj == "" || nev == "") throw "Hibas bemenet";
		else {
			this->faj = faj;
			this->nev = nev;
		}
	}

	/// Faj lek�rdez�se
	/// @return - faj
	String getFaj() const { return faj; }

	/// N�v lek�rdez�se
	/// @return - n�v
	String getNev() const { return nev; }

	/// Sz�let�si d�tum lek�rdez�se
	/// @return - d�tum
	Datum getSzul() const { return szul; }

	/// Virtu�lis destruktor
	virtual ~Allat() {}
};

/// Glob�lis inserter
/// @param os - output stream referencia
/// @param k - Tulaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Kutya& k);

#endif // ALLAT_H