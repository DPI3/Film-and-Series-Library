#ifndef IDO_H
#define IDO_H
#include<iostream>
#include "functions.h"

class Ido{
    short int ora, perc;
public:
    /// Konstruktor, amely paraméterként megkapja az óra és perc értékeket
    /// @param o - óra
    /// @param p - perc
    Ido(short int o = 0, short int p = 0) : ora(o), perc(p) {}

    /// Óra lekérdezése
    /// @return óra értéke
    int getora() const {
        return ora;
    }

    /// Perc lekérdezése
    /// @return perc értéke
    int getperc() const {
        return perc;
    }

    /// Értékadás operátor túlterhelése másik Ido objektum alapján
    /// @param other - másik Ido objektum
    /// @return referencia az aktuális objektumra
    Ido& operator=(const Ido& other) {
        if (this != &other) {  // Önhozzárendelés ellenőrzése
            ora = other.ora;
            perc = other.perc;
        }
        return *this;
    }

    /// Értékadás operátor túlterhelése percek alapján
    /// @param minutes - percek száma
    /// @return referencia az aktuális objektumra
    Ido& operator=(int minutes) {
        ora = minutes / 60;    // Kiszámítja az órákat
        perc = minutes % 60;   // Kiszámítja a maradék perceket
        return *this;
    }

    /// Idő beolvasása a felhasználótól
    void beolvas() {
        std::cout << "Kerem adja meg az orat: ";
        ora = readInt();
        std::cout << "Kerem adja meg a percet: ";
        perc = readInt();
    }
};

/// Globális << operátor az Ido objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param ido - Ido objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const Ido& ido);

#endif //IDO_H