#ifndef DATUM_H
#define DATUM_H
#include<iostream>
#include "functions.h"

/// Datum osztály a dátum kezelésére
class Datum{
    short int ev, honap, nap;
public:
/// Konstruktor, amely paraméterként megkapja az év, hónap és nap értékeket
    /// @param e - év
    /// @param h - hónap
    /// @param n - nap
    Datum(short int e = 0, short int h = 0, short int n = 0) : ev(e), honap(h), nap(n) {}

    /// Év lekérdezése
    /// @return év értéke
    int getev() const {
        return ev;
    }

    /// Hónap lekérdezése
    /// @return hónap értéke
    int gethonap() const {
        return honap;
    }

    /// Nap lekérdezése
    /// @return nap értéke
    int getnap() const {
        return nap;
    }

    /// Értékadás operátor túlterhelése, amely napokból számítja ki az év, hónap és nap értékeket
    /// @param days - napok száma
    /// @return referencia az aktuális objektumra
    Datum& operator=(int days) {
        ev = days / 365;     // Kiszámítja az éveket
        days %= 365;         // Maradék napok az évből
        honap = days / 30;   // Kiszámítja a hónapokat
        nap = days % 30;     // Maradék napok a hónapból
        return *this;
    }

    /// Dátum beolvasása a felhasználótól
    void beolvas() {
        std::cout << "Kerem adja meg az evet: ";
        ev = readInt();
        std::cout << "Kerem adja meg a honapot: ";
        honap = readInt();
        std::cout << "Kerem adja meg a napot: ";
        nap = readInt();
    }
};

/// Globális << operátor a Datum objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param datum - Datum objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const Datum& datum);

#endif //DATUM_H