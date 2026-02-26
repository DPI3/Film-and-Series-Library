#include "Jatekfilm.h"

    /// Reszletes kiíratás
    void jatekfilm::kiir_reszletes() const {
        Tartalom::kiir_reszletes();
    }

    /// Kiírja a jatekfilm adatait
    void jatekfilm::kiir() const {
        Tartalom::kiir();
    }
    
    /// fájlba mentéshez kell
    /// @param os - ostream
    void jatekfilm::elment(std::ostream& os) const{
        os << "Jatekfilm\n";
        Tartalom::elment(os);
    }