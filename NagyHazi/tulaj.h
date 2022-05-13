#ifndef TULAJ_H
#define TULAJ_H
/*
* \file tualj.h
*
* Tulaj oszt�ly deklar�ci�ja �s f�ggv�nyei
*/

#include "string.h"
#include "memtrace.h"

class Tulaj {
private:
	String tNev;		///< n�v
	String cim;		///< c�m
	String tel;		///< telefonsz�m
public:
	///Default konstruktor
	Tulaj() {}

	/// Konstruktor be�ll�tja az attrib�tumokat
	/// @param nev - n�v megad�sa
	/// @param cim - c�m megad�sa
	/// @param tel - telefonsz�m megad�sa
	Tulaj(const char* nev, const char* cim, const char* tel);

	/// K�t tulaj egyez�s�g�t vizsg�lja
	/// @param d - jobb oldali operandus
	/// @return true, ha egyezik a k�t tulaj
	bool operator==(const Tulaj& t) const {
		return tNev == t.tNev && cim == t.cim && tel == t.tel;
	}

	/// K�t tulaj nem egyez�s�g�t vizsg�lja
	/// @param d - jobb oldali operandus
	/// @return true, ha nem egyezik a k�t tulaj
	bool operator!=(const Tulaj& t) const {
		return tNev != t.tNev || cim != t.cim || tel != t.tel;
	}

	/// N�v lek�rdez�se
	/// @return - n�v
	String getNev() const { return tNev; }

	/// C�m lek�rdez�se
	/// @return - c�m
	String getCim() const { return cim; }

	/// Telefonsz�m lek�rdez�se
	/// @return - telefonsz�m
	String getTel() const { return tel; }

	/// Destruktor
	~Tulaj() {}
};

/// Glob�lis inserter
/// @param os - output stream referencia
/// @param s - Tulaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Tulaj& t);

#endif // TULAJ_H