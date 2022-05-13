/**
 *
 * \file kutya.cpp
 *
 * Kutya oszt�ly tagf�ggv�nyinek megval�s�t�sa (defin�ci�ja)
*/
#include <iostream>

#include "memtrace.h"
#include"kutya.h"

/// Param�teres konstruktor
Kutya::Kutya(const char* faj, const char* nev, const Datum& szul,
	const Tulaj& gazdi, const char* chip, const char* bunda, bool nem) :Allat(faj, nev, szul), gazdi(gazdi) {
	if (chip != "" && bunda != "") {
		this->chip = chip;
		this->bunda = bunda;
		this->nem = nem;
	} else throw "Hibas bemenet";
}

/// oper�tor==
bool Kutya::operator==(const Kutya& k) const {
	return faj == k.faj && nev == k.nev && szul == k.szul &&
		gazdi == k.gazdi && chip == k.chip && bunda == k.bunda && nem == k.nem;
}

/// oper�tor!=
bool Kutya::operator!=(const Kutya& k) const {
	return faj != k.faj || nev != k.nev || szul != k.szul || 
		gazdi != k.gazdi || chip != k.chip || bunda != k.bunda || nem != k.nem;
}

/// Glob�lis inserter
std::ostream& operator<<(std::ostream& os, Kutya& k) {
	return os << "\nKutya adatai:\n\tFaj: " << k.getFaj() << "\n\tNev: " << k.getNev() << "\n\tSzuletesi ido: " << k.getSzul() <<
		"\n\tChip szam: " << k.getChip() << "\n\tBunda: " << k.getBunda() << "\n\tNem: " << (k.getNem() ? "Nosteny" : "Him") <<
		"\nTulaj adatai:\n\t" << k.getTulaj();
}

/// Glob�lis inserter
std::ofstream& operator<<(std::ofstream& of, Kutya& k) {
	of << k.getFaj() << ";" << k.getNev() << ";" << k.getSzul().getEv() << ";" << k.getSzul().getHo() << ";" << k.getSzul().getNap() 
		<< ";" << k.getChip() << ";" << k.getBunda() << ";" << k.getNem() << ";" << k.getTulaj().getNev() << ";" << k.getTulaj().getCim() 
		<< ";" << k.getTulaj().getTel() << std::endl;
	return of;
}