#ifndef JATEKFILM_H
#define JATEKFILM_H
#include "Tartalom.h"

class jatekfilm : public Tartalom{
public:
    jatekfilm(Tipusok tipus, const string &cim, const string &kat = "Unknown", const string &nyelv = "Unknown",
    const short int &korhatar = 0,const Datum &megjelenes = 0, const Ido &hossz = 0):
    Tartalom(tipus, cim, kat, nyelv, korhatar, megjelenes, hossz){}

    /// Reszletes kiíratás
    void kiir_reszletes() const {
        Tartalom::kiir_reszletes();
    }

    /// Kiírja a jatekfilm adatait
    void kiir() const {
        Tartalom::kiir();
    }
    
    /// fájlba mentéshez kell
    /// @param os - ostream
    void elment(std::ostream& os) const{
        os << "Jatekfilm\n";
        Tartalom::elment(os);
    }
};

#endif //JATEKFILM_H