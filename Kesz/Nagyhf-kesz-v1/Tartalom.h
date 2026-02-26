#ifndef TARTALOM_H
#define TARTALOM_H
#include<iostream>
#include<string>
#include "Datum.h"
#include "Ido.h"

using std::string;

enum Tipusok{
    Jatekfilm, Dokumentumfilm, Minisorozat, Sorozat
};

/// Függvény, amely átalakítja az enum értékét szöveges reprezentációvá
/// @param tipus - a felsorolás típusa
/// @return a felsorolás típusa szöveges formában
const char* enumToString(enum Tipusok tipus);

/// Függvény, amely átalakítja az int értékét enum típussá
/// @param szam - a szám értéke
/// @return az enum típusa a megadott számnak
Tipusok intToEnum(int szam);

/// Függvény, amely átalakítja a szöveget enum típussá
/// @param tipusStr - a szöveges reprezentáció
/// @return az enum típusa a megadott szövegnek
Tipusok stringToEnum(const std::string& tipusStr);

class Tartalom {
    Tipusok Tipus; //enum
    string cim;
    string kat; //kat = mufaj
    string nyelv; 
    short int korhatar;
    Datum megjelenes;
    Ido hossz;
    Tartalom *kov; // Pointer a következő tartalomra
    
public:
    
    Tartalom(const Tipusok tipus = Jatekfilm, const string &cim = "", const string &kat = "Unknown", const string &nyelv = "Unknown",
    const short int &korhatar = 0,const Datum &megjelenes = 0, const Ido &hossz = 0);
    Tartalom(Tartalom &ujtart);
    
    //kiíró függvények
    virtual void kiir() const = 0;
    virtual void kiir_reszletes() const = 0;

    /// a fájlba mentéshez használt függvény
    /// @param os - ostream objektum
    virtual void elment(std::ostream& os) const = 0;
    
    /// getterek
    string getTipus() const;
    string getNyelv() const;
    string getKat() const;
    string getcim() const;
    int getKorhatar() const;
    Tartalom *getKov()const;
    Ido getHossz() const;
    Datum getMegjelenes() const;

    /// @param ujtart - másik Tartalom objektum
    /// @return referencia az aktuális objektumra
    Tartalom& operator=(const Tartalom& ujtart);

    /// Pointer beállítása a következő Tartalom objektumra
    /// @param ujtart - a következő Tartalom objektum pointer-e
    void setKov(Tartalom *ujtart);

    /// Virtuális destruktor
    virtual ~Tartalom() {}
};

/// Globális << operátor a Tartalom objektum adatainak kiírásához
/// @param os - ostream objektum
/// @param a - Tartalom objektum
/// @return os - ostream objektum
std::ostream& operator<<(std::ostream& os, const Tartalom& a);

#endif //TARTALOM_H