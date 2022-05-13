/**
 * \file tulaj.cpp
 *
 * Tulaj oszt�ly tagf�ggv�nyinek megval�s�t�sa (defin�ci�ja)
 */

#include <iostream>

#include "memtrace.h"
#include "tulaj.h"

Tulaj::Tulaj(const char* nev, const char* cim, const char* tel) {
	if (nev != "" && cim != "" && tel != "") {
		this->tNev = nev;
		this->cim = cim;
		this->tel = tel;
	} else throw "Hibas bemenet";
}

std::ostream& operator<<(std::ostream& os, const Tulaj& t) {
	return os <<"\tNev: " << t.getNev() << "\n\t\tCim: " << t.getCim() << "\n\t\tTelefonszam: " << t.getTel();
}
