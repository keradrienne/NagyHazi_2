/**
 * \file: list.hpp
 * 
 * Generikus lista iter�torral
 * 
 */

#include <iostream>
#include <fstream> 
#include <stdexcept>

#include "memtrace.h"

#ifndef GENERIKUS_LISTA_ITER_HPP
#define GENERIKUS_LISTA_ITER_HPP

template<class T>
class Lista {
    struct ListaElem {
        T  adat;		    // adat
        ListaElem* kov;	    // pointer a k�vetkez�re
        ListaElem(ListaElem* p = NULL) :kov(p) {}
        
        ListaElem& operator=(const ListaElem);
    };

    ListaElem* elso;	    // pointer az els�re
    ListaElem* akt;	        // pointer az aktu�lisra

    //Lista(const Lista&);
    Lista& operator=(const Lista&);
public:
    Lista() { akt = elso = new ListaElem; }	// str�zsa l�trehoz�sa

    friend std::ostream& operator<<(std::ostream& os, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            std::cout << i->adat;
            std::cout << std::endl;
            i = i->kov;
        }
        return os;
    }

    friend std::ofstream& operator<<(std::ofstream& of, const Lista& rhs) {
        ListaElem* i = rhs.elso;
        while (i->kov != NULL)
        {
            of << i->adat;
            i = i->kov;
        }
        return of;
    }

    void beszur(const T& dat);      	        // elem besz�r�sa
    void torol(const T& dat);                   // elem t�rl�se
    void modosit(const T& dat, const T& mod);   // elem m�dos�t�sa

    class iterator;		    // el�deklar�ci�

    iterator begin() {      // l�trehoz egy iter�tort �s az elej�re �ll�tja
        return(iterator(*this));
    }

    iterator end() {     // l�trehozza �s az utols� elem ut�n �ll�tja
        return(iterator());
    }

    class iterator {		// bels� oszt�ly, a publikus r�szek kil�tszanak
        ListaElem* akt;	    // mutat� az aktu�lis elemre

    public:
        iterator() : akt(NULL) {};              // v�g�re �ll�tja az iter�tort

        iterator(const Lista& l) : akt(l.elso) {// elej�re �ll�tja
            if (akt->kov == NULL)
                akt = NULL;                     // str�zsa miatti tr�kk
        }

        iterator& operator++() {        // n�veli az iter�tort (pre)
            if (akt != NULL) {
                akt = akt->kov;  	    // k�vetkez�re
                if (akt->kov == NULL)
                    akt = NULL;         // str�zsa miatti tr�kk
            }
            return(*this);
        }

        iterator operator++(int) {  // n�veli az iter�tort (post)
            iterator tmp = *this;   // el�z� �rt�k
            operator++();	        // n�vel
            return(tmp);	        // el�z�vel kell visszat�rni
        }

        bool operator!=(const iterator& i) const { // �sszehasonl�t
            return(akt != i.akt);
        }

        T& operator*() {	// indirekci�
            if (akt != NULL) return(akt->adat);
            else throw std::out_of_range("Hiba");
        }
        T* operator->() {	// indirekci�
            if (akt != NULL) return(&akt->adat);
            else throw std::out_of_range("Hiba");
        }

    }; // iterator oszt�ly v�ge

    ~Lista();
};

template <class T>          // tagf�ggv�nysablon
Lista<T>::~Lista() {
    ListaElem* p;			// fut� pointer
    while ((p = elso) != NULL) {
        elso = p->kov;
        delete p;
    }
}

template <class T>                      // tagf�ggv�nysablon
void Lista<T>::beszur(const T& dat) {
    ListaElem* i = elso;
    while (i != NULL && i->adat != dat)
        i = i->kov;
    if (i != NULL)              // ha nincs a felt�telnek megfelel� elem
        throw "Mar van ilyen allat a listaban";
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
    ListaElem *elozo = NULL;
    ListaElem *i = elso;
    while (i != NULL && i->adat != dat)
    {
        elozo = i;
        i = i->kov;
    }

    //megatal�lt elem t�rl�se
    if (i == NULL)              // ha nincs a felt�telnek megfelel� elem
        throw "Nincs ilyen elem";
        //throw "Nincs ilyen elem";
    else if (elozo == NULL) {   // ha az els� elemet kell t�r�lni
        ListaElem *uj = i->kov;
        delete(i);
        elso = uj;
        std::cout << "Sikeres torles" << std::endl;
    }
    else {                      //ha lista bels� vagy utols� elem�t kell t�r�lni
        elozo->kov = i->kov;
        delete(i);
        std::cout << "Sikeres torles" << std::endl;
    }
}

template <class T>                      // tagf�ggv�nysablon
void Lista<T>::modosit(const T& dat, const T& mod) {
    //m�dos�tand� elem keres�se
    ListaElem * i = elso;
    while (i != NULL && i->adat != dat)
        i = i->kov;
    if (i == NULL)              // ha nincs a felt�telnek megfelel� elem
        throw "Nincs ilyen elem";
    else {
        i->adat = mod;
        std::cout << "Sikeres modositas" << std::endl;
    }
}

#endif // GENERIKUS_LISTA_ITER_HPP
