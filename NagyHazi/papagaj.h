#ifndef PAPAGAJ_H
#define PAPAGAJ_H

/**
 * \file papagaj.h
 *
 * Papagaj oszt�ly deklar�ci�ja �s f�ggv�nyei
 */

#include <iostream>
#include <fstream>

#include "memtrace.h"
#include "allat.h"
#include "tulaj.h"

class Papagaj : public Allat{
private:
	Tulaj gazdi;
	String chip;
	String bunda;
	bool nem;
public:
	///Default konstruktor
	Papagaj() :nem(false) {}

	/// Konstruktor be�ll�tja az attrib�tumokat
	/// @param faj - faj megnevez�se
	/// @param nev - n�v megad�sa
	/// @param szul - sz�let�si �v megad�sa
	/// @param gazdi - tulaj megad�sa
	/// @param chip - chipsz�m megad�sa
	/// @param tollazat - tollazat jellege, sz�ne megad�sa
	/// @param nem - nem megad�sa
	Papagaj(const char* faj, const char* nev, const Datum& szul,
		const Tulaj& gazdi, const char* chip, const char* tollazat, bool nem);

	/// K�t papag�j egyez�s�g�t vizsg�lja
	/// @param p - jobb oldali operandus
	/// @return true, ha egyezik a k�t papag�j
	bool operator==(const Papagaj&) const;

	/// K�t papag�j nem egyez�s�g�t vizsg�lja
	/// @param p - jobb oldali operandus
	/// @return true, ha nem egyezik a k�t papag�j
	bool operator!=(const Papagaj&) const;

	/// Tulaj lek�rdez�se
	/// @return - gazdi
	Tulaj getTulaj() { return gazdi; }

	/// Tulaj be�ll�t�sa
	/// @param t - Tulaj referencia
	void setTulaj(Tulaj& t) { this->gazdi = t; }

	/// Chipsz�m lek�rdez�se
	/// @return - chip
	String getChip() { return chip; }

	/// Chipsz�m be�ll�t�sa
	/// @param p - karaktersorozat
	void setChip(const char* p) { 
		if (String(p) != String())
			this->chip = p;
		else throw "Rossz bemenet";
	}

	/// Tollazat lek�rdez�se
	/// @return - bunda
	String getBunda() { return bunda; }

	/// Tollazat be�ll�t�sa
	/// @param p - karaktersorozat
	void setBunda(const char* p) {
		if (String(p) != String())
			this->bunda = p;
		else throw "Rossz bemenet";
	}

	/// Nem lek�rdez�se
	/// True - n�st�ny, False - h�m
	/// @return - nem
	bool getNem() { return nem; }

	/// Nem be�ll�t�sa
	/// @param b - true/false
	void setNem(bool b) { this->nem = b; }

	/// Destruktor
	~Papagaj() {}
};

/// Glob�lis inserter
/// @param os - output stream referencia
/// @param p - Papagaj referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, Papagaj& p);

/// Glob�lis inserter
/// @param of - output stream referencia
/// @param p - Papagaj referencia
/// @return output stream referencia
std::ofstream& operator<<(std::ofstream& of, Papagaj& p);

#endif // PAPAGAJ_H