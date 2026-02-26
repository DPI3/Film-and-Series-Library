#ifndef MENU_H
#define MENU_H
#include "Tarolo.h"

class Menu{
    Tarolo tarolo;
public:
    /// Az interfész, ergo a menü
    void interface();

    /// Tartalom betöltése fájlból
    void load_tarolo();

    /// Tartalom mentése fájlba
    void save_tarolo();

    /// Tartalom hozzáadásának interfésze
    /// @return az új tartalomra mutató pointer
    Tartalom *hozzaad_interface();

    /// Fájl beolvasásához használt segédfüggvény
    /// @param file - a beolvasandó fájl
    /// @return a feldolgozott sor
    std::string readAndProcessLine(std::ifstream &file);
};

int readInt();

#endif // MENU_H