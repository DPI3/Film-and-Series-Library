#ifndef MINISOROZAT_H
#define MINISOROZAT_H

#include "Tartalom.h"

class minisorozat : public Tartalom{
    int reszdb; // Részek száma
public:
    minisorozat(Tipusok tipus, std::string cim, int reszdb, std::string kat = "Unknown", std::string nyelv = "Unknown",
                short int korhatar = 0, Datum megjelenes = Datum(0, 0, 0), Ido hossz = Ido(0, 0))
        : Tartalom(tipus, cim, kat, nyelv, korhatar, megjelenes, hossz), reszdb(reszdb) {}

    /// Részek számának lekérdezése
    /// @return részek száma
    int getReszdb() const;

    /// Reszletes kiíratás a minisorozat adatairól
    void kiir_reszletes() const;

    /// Kiírja a minisorozat adatait
    void kiir() const;
    
    /// fájlba mentéshez kell
    /// @param os - ostream
    void elment(std::ostream& os) const;
};

/// Globális << operátor a minisorozat objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param minisor - minisorozat objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const minisorozat& minisor);

#endif //MINISOROZAT_H