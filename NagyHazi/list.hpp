/**
 * \file: list.hpp
 * 
 * Generikus lista iter�torral
 * 
 */

#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <string>
#include <sstream>

#include "memtrace.h"

#ifndef GENERIKUS_LISTA_ITER_HPP
#define GENERIKUS_LISTA_ITER_HPP

template<class T>
class Lista {
    struct ListaElem {
        T  adat;		    // adat
        ListaElem* kov;	    // pointer a k�vetkez�re
        // Konstruktor
        ListaElem(ListaElem* p = NULL) :kov(p) {}
        
        ListaElem& operator=(const ListaElem);
    };

    ListaElem* elso;	    // pointer az els�re
    ListaElem* akt;	        // pointer az aktu�lisra

    //Lista(const Lista&);
    Lista& operator=(const Lista&);
public:
    // str�zsa l�trehoz�sa
    Lista() { akt = elso = new ListaElem; }	

    /// Glob�lis inserter
    /// @param os - output stream referencia
    /// @param rhs - Lista referencia
    /// @return output stream referencia
    friend std::ostream& operator<<(std::ostream& os, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            std::cout << std::endl << "\t--------------------------------------------------------------------------------";
            std::cout << i->adat;   // adat ki�r�sa
            std::cout << std::endl << "\t--------------------------------------------------------------------------------" << std::endl;
            i = i->kov;             // pointer n�vel�se
        }
        return os;
    }

    /// Glob�lis f�jlinserter
    /// @param of - output stream referencia
    /// @param rhs - Lista referencia
    /// @return output stream referencia
    friend std::ofstream& operator<<(std::ofstream& of, const Lista& rhs) {
        ListaElem* i = rhs.elso;    // fut� pointer
        while (i->kov != NULL)
        {
            of << i->adat;          // adat ki�r�s f�jlba
            i = i->kov;             // iter�tor n�vel�se
        }
        return of;
    }

    /// Elem besz�r�sa list�ba
    /// @param dat - besz�rand� adat refernci�ja
    void beszur(const T& dat);

    /// Elem t�rl�se list�b�l
    /// @param dat - t�rlend� adat refernci�ja
    void torol(const T& dat);

    /// Elem m�dos�t�sa a list�ban
    /// @param dat - m�dos�tand� adat refernci�ja
    /// @param mod - m�dos�t� adat refernci�ja
    void modosit(const T& dat, const T& mod);

    /// Elemek beolvas�sa adatf�jlb�l
    /// @param p - forr�sf�jl neve "nev.txt" form�tumban
    void beolvas(const char* p);

    class iterator;		    // el�deklar�ci�

    /// L�trehoz egy iter�tort �s az elej�re �ll�tja
    iterator begin() {      
        return(iterator(*this));
    }

    /// L�trehozza �s az utols� elem ut�n �ll�tja
    iterator end() {
        return(iterator());
    }

    class iterator {		// bels� oszt�ly, a publikus r�szek kil�tszanak
        ListaElem* akt;	    // mutat� az aktu�lis elemre

    public:
        /// Iter�tor konstruktor
        /// V�g�re �ll�tja az iter�tort
        iterator() : akt(NULL) {};              

        /// Iter�tor konstruktor
        /// Elej�re �ll�tja az iter�tort
        /// @param l - lista refernci�ja
        iterator(const Lista& l) : akt(l.elso) {
            if (akt->kov == NULL)
                akt = NULL;                     // str�zsa miatti tr�kk
        }

        /// N�veli az iter�tort (pre)
        /// @return iter�tor referencia
        iterator& operator++() {        
            if (akt != NULL) {
                akt = akt->kov;  	    // k�vetkez�re
                if (akt->kov == NULL)
                    akt = NULL;         // str�zsa miatti tr�kk
            }
            return(*this);
        }

        /// N�veli az iter�tort (post)
        /// @return iter�tor referencia
        iterator operator++(int) {  
            iterator tmp = *this;   // el�z� �rt�k
            operator++();	        // n�vel
            return(tmp);	        // el�z�vel kell visszat�rni
        }

        /// �sszehasonl�t
        /// @param i - iter�tor referencia
        /// @return bool
        bool operator!=(const iterator& i) const { 
            return(akt != i.akt);
        }

        /// Indirekci�
        /// @return oszt�ly referencia
        T& operator*() {	
            if (akt != NULL) return(akt->adat);     // visszat�r�s az adattal
            else throw std::out_of_range("Hiba");
        }

        /// Indirekci�
        /// @return oszt�ly pointer
        T* operator->() {
            if (akt != NULL) return(&akt->adat);    // visszat�r�s az adattal
            else throw std::out_of_range("Hiba");
        }

    }; // iterator oszt�ly v�ge

    /// Destruktor
    ~Lista();
};

template <class T>
Lista<T>::~Lista() {
    ListaElem* p;			// fut� pointer
    while ((p = elso) != NULL) {
        elso = p->kov;      // pointer �t�ll�t�sa
        delete p;           // t�rl�s
    }
}

template <class T>
void Lista<T>::beszur(const T& dat) {
    ListaElem* i = elso;    // fut� pointer
    // ism�tl�d�s keres�se
    while (i != NULL && i->adat != dat)
        i = i->kov;         // iter�tor n�vel�se
    if (i != NULL) {        // ha nincs a felt�telnek megfelel� elem
        std::cout << "Mar van ilyen allat a listaban" << std::endl;
        throw "Mar van ilyen allat a listaban";
    } 
    else {
        ListaElem* p;			            // fut� pointer
        for (p = elso; p->kov != NULL; p = p->kov);
        ListaElem* uj = new ListaElem(*p);  //r�git m�sol
        p->adat = dat;                      // adat be�r�sa
        p->kov = uj;                        // pointer be�ll�t�sa
        std::cout << "Sikeres hozzaadas" << std::endl;
    } 
}

template <class T>
void Lista<T>::torol(const T& dat) {
    // t�rlend� elem keres�se
    ListaElem *elozo = NULL;    // lemarad� pointer
    ListaElem *i = elso;        // fut� pointer
    while (i != NULL && i->adat != dat)
    {
        elozo = i;              //lemarad� pointer n�vel�se
        i = i->kov;             // fut� pointer n�vel�se
    }

    //megatal�lt elem t�rl�se
    if (i == NULL) {            // ha nincs a felt�telnek megfelel� elem
        std::cout << "Nincs ilyen elem" << std::endl;
        throw "Nincs ilyen elem";
    }
    else if (elozo == NULL) {   // ha az els� elemet kell t�r�lni
        ListaElem *uj = i->kov; // pointer �t�ll�t�sa
        delete(i);              // t�rlend� t�rl�se
        elso = uj;              // lista eleje pointer be�ll�t�sa
    }
    else {                      //ha lista bels� vagy utols� elem�t kell t�r�lni
        elozo->kov = i->kov;    // pointer �t�ll�t�sa
        delete(i);              // t�rlend� t�rl�se
    }
}

template <class T>
void Lista<T>::modosit(const T& dat, const T& mod) {
    //m�dos�tand� elem keres�se
    ListaElem * i = elso;       // fut� pointer
    while (i != NULL && i->adat != dat)
        i = i->kov;             // pointer n�vel�se
    if (i == NULL) {            // ha nincs a felt�telnek megfelel� elem
        std::cout << "Nincs ilyen elem" << std::endl;
        throw "Nincs ilyen elem";
    }
    else {
        i->adat = mod;          // adat m�dos�t�sa
        std::cout << "Sikeres modositas" << std::endl;
    }
}

template<class T>
void Lista<T>::beolvas(const char* p) {
    std::ifstream file(p);      // fajl megnyitasa
    std::string faj, nev, bunda, chip, tNev, cim, tel, s, line;     // valtoz�k, amibe a beolvas��s megt�rt�nik
    int ev = 0, ho = 0, nap = 0, db = 0;        // valtoz�k, amibe a beolvas��s megt�rt�nik
    bool nem;                   // valtoz�, amibe a beolvas��s megt�rt�nik
    if (file) {                 // ha l�tezik ilyen f�jl
        while (std::getline(file, line)) {      // sor beolvas�sa
            std::stringstream linestream(line);
            while (std::getline(linestream, s, ';')) {      // sor feldarabol�sa ; ment�n
                if (db == 0) {
                    faj = s;
                    db++;
                }
                else if (db == 1) {
                    nev = s;
                    db++;
                }
                else if (db == 2) {
                    std::stringstream ss;
                    ss << s;
                    ss >> ev;
                    db++;
                }
                else if (db == 3) {
                    std::stringstream ss;
                    ss << s;
                    ss >> ho;
                    db++;
                }
                else if (db == 4) {
                    std::stringstream ss;
                    ss << s;
                    ss >> nap;
                    db++;
                }
                else if (db == 5) {
                    chip = s;
                    db++;
                }
                else if (db == 6) {
                    bunda = s;
                    db++;
                }
                else if (db == 7) {
                    std::stringstream ss;
                    ss << s;
                    ss >> nem;
                    db++;
                }
                else if (db == 8) {
                    tNev = s;
                    db++;
                }
                else if (db == 9) {
                    cim = s;
                    db++;
                }
                else if (db == 10) {
                    tel = s;
                    db++;
                }
                if (db == 11) {
                    db = 0;
                    T o(faj.c_str(), nev.c_str(), Datum(ev, ho, nap), Tulaj(tNev.c_str(), cim.c_str(),      // oszt�lyp�d�ny l�trehoz�sa
                        tel.c_str()), chip.c_str(), bunda.c_str(), nem);
                    Lista<T>::beszur(o);        // p�ld�ny besz�r�sa list�ba
                }
            }
        }
    }
    else {
        std::cout << "Nincs ilyen fajl" << std::endl;
        throw "Nincs ilyen fajl";
    }
}

#endif // GENERIKUS_LISTA_ITER_HPP
