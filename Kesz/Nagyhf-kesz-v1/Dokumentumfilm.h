#ifndef DOKUMENTUMFILM_H
#define DOKUMENTUMFILM_H

#include "Tartalom.h"

class dokumentumfilm : public Tartalom{
    std::string leiras; // Leírás
public:
    dokumentumfilm(Tipusok tipus, std::string cim, std::string leiras,
    std::string kat = "Unknown", std::string nyelv = "Unknown",
    short int korhatar = 0, Datum megjelenes = Datum(0, 0, 0), Ido hossz = Ido(0, 0)): 
    Tartalom(tipus, cim, kat, nyelv, korhatar, megjelenes, hossz), leiras(leiras) {}

    /// Leírás lekérdezése
    /// @return a dokumentumfilm leírása
    std::string getLeiras() const;

    /// Reszletes kiíratás a dokumentumfilm adatairól, ergo leírással eggyütt
    void kiir_reszletes() const;

    /// Kiírja a dokumentumfilm adatait
    void kiir() const;

    /// fájlba mentéshez kell
    /// @param os - ostream
    void elment(std::ostream& os) const;
};

/// Globális << operátor a dokumentumfilm objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param doks - dokumentumfilm objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const dokumentumfilm& doks);

#endif //DOKUMENTUMFILM_H 