#include "Ido.h"

    int Ido::getora() const {
        return ora;
    }

    int Ido::getperc() const {
        return perc;
    }

    Ido& Ido::operator=(const Ido& other) {
        if (this != &other) {  // Önhozzárendelés ellenőrzése
            ora = other.ora;
            perc = other.perc;
        }
        return *this;
    }

    Ido& Ido::operator=(int minutes) {
        ora = minutes / 60;    // Kiszámítja az órákat
        perc = minutes % 60;   // Kiszámítja a maradék perceket
        return *this;
    }

    void Ido::beolvas() {
        std::cout << "Kerem adja meg az orat: ";
        ora = readInt();
        std::cout << "Kerem adja meg a percet: ";
        perc = readInt();
    }

std::ostream& operator<<(std::ostream& os, const Ido& ido) {
    if(ido.getora() == 0 && ido.getperc() == 0) 
        return os << "Unknown";
    return os << ido.getora() << ':' << ido.getperc();
}