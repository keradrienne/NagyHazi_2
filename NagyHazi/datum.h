#ifndef DATUM_H
#define DATUM_H

/**
 * \file datum.h
 *
 * Datum osztály deklarációja és globális függvényei
 */

#include <iostream>
#include <iomanip>

#include "memtrace.h"


class Datum {
    int ev;
    int ho;
    int nap;
  public:
    /// Paraméter nélkül hívható konstruktor.
    /// Mai napot állítja be
    Datum();

    /// Adott napot beállító konstruktor
    /// @param ev - év
    /// @param hó - hónap
    /// @param nap - nap
    Datum(int ev, int ho, int nap);

    /// Év lekérdezése
    /// @return ev
    int getEv() const { return ev;}

    /// Év beállítása
    /// @param - ev
    void setEv(int ev);

    /// Hónap lekérdezése
    /// @return honap
    int getHo() const { return ho;}

    /// Hónap beállítása
    /// @param - honap
    void setHo(int ho) {
        if(ho > 12 || ho < 1) throw "Rossz datum";
        else this->ho = ho;
    }

    /// Nap lekérdezése
    /// @return nap
    int getNap() const { return nap;}

    /// Nap beállítása
    /// @param - nap
    void setNap(int nap) {
        if (nap > 31 || nap < 1) throw "Rossz datum";
        this->nap = nap;
    }

    /// Két dátum egyezőségét vizsgálja
    /// @param d - jobb oldali operandus
    /// @return true, ha egyezik a két dátum
    bool operator==(const Datum& d) const {
        return ev == d.ev && ho == d.ho && nap == d.nap;
    }

    /// Két dátum nem egyezőségét vizsgálja
    /// @param d - jobb oldali operandus
    /// @return true, ha nem egyezik a két dátum
    bool operator!=(const Datum& d) const {
        return ev != d.ev || ho != d.ho || nap != d.nap;
    }
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Datum referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Datum& d);

#endif // DATUM_H
