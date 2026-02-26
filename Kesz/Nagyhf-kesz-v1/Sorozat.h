#ifndef SOROZAT_H
#define SOROZAT_H

#include "Tartalom.h"

class sorozat : public Tartalom{
    int evaddb;   // Évadok száma
    int reszdb;   // Részek száma
    bool tartmeg; //tart-e még, ha tart akkor értelemszerüen 0 a befDat
    Datum befDat; // Befejezés dátuma
public:
    sorozat(Tipusok tipus, std::string cim, int evaddb, int reszdb, bool tartmeg = false, Datum befDat = 0,
            std::string kat = "Unknown", std::string nyelv = "Unknown",
            short int korhatar = 0, Datum megjelenes = Datum(0, 0, 0), Ido hossz = Ido(0, 0))
        : Tartalom(tipus, cim, kat, nyelv, korhatar, megjelenes, hossz),
          evaddb(evaddb), reszdb(reszdb), tartmeg(tartmeg), befDat(befDat) {}

    // Évadok számának lekérdezése
    /// @return évadok száma
    int getEvadokSzama() const;

    /// Részek számának lekérdezése
    /// @return részek száma
    int getReszekSzama() const;

    /// Megadja, hogy tart-e még a sorozat
    /// @return true, ha tart még, egyébként false
    bool isTartMeg() const;

    /// Befejezés dátumának lekérdezése
    /// @return a befejezés dátuma
    Datum getBefejezesDatuma() const;

    /// Reszletes kiíratás a sorozat adatairól
    void kiir_reszletes() const;

    /// Kiírja a sorozat adatait
    void kiir() const;

    /// fájlba ment el
    void elment(std::ostream& os) const;
};

/// Globális << operátor a sorozat objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param soroz - sorozat objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const sorozat& soroz);   

#endif //SOROZAT_H