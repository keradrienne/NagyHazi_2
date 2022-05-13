/**
 *
 * \file papagaj.cpp
 *
 * Papagaj oszt�ly tagf�ggv�nyinek megval�s�t�sa (defin�ci�ja)
*/
#include <iostream>

#include "memtrace.h"
#include"papagaj.h"

Papagaj::Papagaj(const char* faj, const char* nev, const Datum& szul,
	const Tulaj& gazdi, const char* tollazat, bool nem) :Allat(faj, nev, szul), gazdi(gazdi) {
	if (tollazat != "") {
		this->tollazat = tollazat;
		this->nem = nem;
	} else throw "Hibas bemenet";
}

bool Papagaj::operator==(const Papagaj& p) const {
	return faj == p.faj && nev == p.nev && szul == p.szul &&
		gazdi == p.gazdi && tollazat == p.tollazat && nem == p.nem;
}

bool Papagaj::operator!=(const Papagaj& p) const {
	return faj != p.faj || nev != p.nev || szul != p.szul ||
		gazdi != p.gazdi || tollazat != p.tollazat || nem != p.nem;
}

std::ostream& operator<<(std::ostream& os, Papagaj& p) {
	return os << "\n\tPapagaj adatai:\n\t\tFaj: " << p.getFaj() << "\n\t\tNev: " << p.getNev() << "\n\t\tSzuletesi ido: " << p.getSzul() 
		<< "\n\t\tTollazat: " << p.getTollazat() << "\n\t\tNem: " << (p.getNem() ? "Nosteny" : "Him") <<	"\n\tTulaj adatai:\n\t" << p.getTulaj();
}

std::ofstream& operator<<(std::ofstream& of, Papagaj& p) {
	of << p.getFaj() << ";" << p.getNev() << ";" << p.getSzul().getEv() << ";" << p.getSzul().getHo() << ";" << p.getSzul().getNap() 
		<< ";" << p.getTollazat() << ";" <<	p.getNem() << ";" << p.getTulaj().getNev() << ";" << p.getTulaj().getCim() << ";" << p.getTulaj().getTel() << std::endl;
	return of;
}