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
	String faj;
	String nev;
	Datum szul;
public:
	///Default konstruktor
	Allat() {}

	/// Konstruktor be�ll�tja az attrib�tumokat
	/// @param faj - faj megnevez�se
	/// @param nev - n�v megad�sa
	/// @param szul - sz�let�si �v megad�sa
	Allat(const char* faj, const char* nev, const Datum& szul) :szul(szul) {
		if (String(faj) == String() || String(nev) == String()) throw "Hibas bemenet";
		else {
			this->faj = faj;
			this->nev = nev;
		}
	}

	/// Faj lek�rdez�se
	/// @return - faj
	String getFaj() const { return faj; }

	/// Faj be�ll�t�sa
	/// @param p - karaktersorozat
	void setFaj(const char* p) {
		if (String(p) != String())
			this->faj = p;
		else throw "Rossz bemenet";
	}

	/// N�v lek�rdez�se
	/// @return - n�v
	String getNev() const { return nev; }

	/// Nev be�ll�t�sa
	/// @param p - karaktersorozat
	void setNev(const char* p) {
		if (String(p) != String())
			this->nev = p;
		else throw "Rossz bemenet";
	}

	/// Sz�let�si d�tum lek�rdez�se
	/// @return - d�tum
	Datum getSzul() const { return szul; }

	/// Szulet�si d�tum be�ll�t�sa
	/// @param d - d�tum referencia
	void setSzul(Datum& d) { this->szul = d; }

	/// Virtu�lis destruktor
	virtual ~Allat() {}
};

#endif // ALLAT_H