#include "Datum.h"

    int Datum::getev() const{
        return ev;
    }

    int Datum::gethonap() const {
        return honap;
    }

    int Datum::getnap() const {
        return nap;
    }

    Datum& Datum::operator=(int days) {
        ev = days / 365;     // Kiszámítja az éveket
        days %= 365;         // Maradék napok az évből
        honap = days / 30;   // Kiszámítja a hónapokat
        nap = days % 30;     // Maradék napok a hónapból
        return *this;
    }

    void Datum::beolvas() {
        std::cout << "Kerem adja meg az evet: ";
        ev = readInt();
        std::cout << "Kerem adja meg a honapot: ";
        honap = readInt();
        std::cout << "Kerem adja meg a napot: ";
        nap = readInt();
    }

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
    if(datum.getev() == 0) 
        return os << "Unknown";
    if(datum.gethonap() == 0)
        return os << datum.getev();
    return os << datum.getev() << '-' << datum.gethonap() << '-' << datum.getnap();
}
