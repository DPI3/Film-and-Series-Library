#ifndef TAROLO_H
#define TAROLO_H
#include<iostream>
#include<cstring>
#include<string>
#include "Tartalom.h"
#include "Jatekfilm.h"
#include "MiniSorozat.h"
#include "Sorozat.h"
#include "Dokumentumfilm.h"

class Tarolo {
    Tartalom *tartalom; //láncolt lista
public:
    /// Alapértelmezett konstruktor, inicializálja a tartalom pointert nullptr-re
    Tarolo() : tartalom(nullptr) {}

    /// Konstruktor, amely egy Tartalom objektumra mutató pointert vár paraméterként
    /// @param tartalom - egy Tartalom objektumra mutató pointer
    Tarolo(Tartalom *tartalom) : tartalom(tartalom) {}

    /// Tartalom pointer lekérdezése
    /// @return a tartalomra mutató pointer
    Tartalom* getTartalom();

    /// Keresés a tartalomban a megadott név alapján
    /// @param keresett_nev - a keresett tartalom neve
    /// @return a megfelelő Tartalom objektumra mutató pointer, ha talál, egyébként nullptr
    Tartalom* Keres(const std::string& keresett_nev);

    /// Keresés és kiíratás a tartalomban a megadott név alapján
    /// @param keresett_nev - a keresett tartalom neve
    void Kereses(const std::string keresett_nev);

    /// Tartalom hozzáadása a listához
    /// @param tartalom_uj - az új Tartalom objektumra mutató pointer
    void hozzaad(Tartalom *tartalom_uj);

    /// Az összes tartalom kiírása
    void kiir_osszes();

    /// Adott típusú tartalmak részletes kiírása
    /// @param tipus - a keresett típus
    void kiir_specifikus(Tipusok tipus);

    /// Kategóriák kiírása
    void kiir_kategoriak();

    /// Adott kategóriába tartozó tartalmak kiírása
    /// @param kat - a keresett kategória
    void kiir_kategoria(const std::string& kat);

    /// Adott típusú tartalmak kiírása
    /// @param tipus - a keresett típus
    void kiir_tipus(Tipusok tipus);
    
    /// Destruktor, amely felszabadítja a tárolóban lévő Tartalom listát
    ~Tarolo();
};

#endif //TAROLO_H