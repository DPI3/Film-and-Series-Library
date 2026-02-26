#include "Tartalom.h"

Tipusok intToEnum(int szam) {
    switch (szam) {
        case 0:
            return Jatekfilm;
        case 1:
            return Dokumentumfilm;
        case 2:
            return Minisorozat;
        case 3:
            return Sorozat;
        default:
            // Ha az int nem esik az 1 és 4 közé, akkor alapértelmezett értéket adunk vissza
            return Jatekfilm;
    }
}

const char* enumToString(enum Tipusok tipus) {
    switch (tipus) {
        case Jatekfilm:
            return "Játékfilm";
        case Dokumentumfilm:
            return "Dokumentumfilm";
        case Minisorozat:
            return "Minisorozat";
        case Sorozat:
            return "Sorozat";
        default:
            return "Unknown";
    }
}

Tipusok stringToEnum(const std::string& tipusStr) {
    if (tipusStr == "Játékfilm") return Jatekfilm;
    if (tipusStr == "Jatekfilm") return Jatekfilm;
    if (tipusStr == "Dokumentumfilm") return Dokumentumfilm;
    if (tipusStr == "Minisorozat") return Minisorozat;
    if (tipusStr == "Sorozat") return Sorozat;
    throw std::invalid_argument("Unknown");
}

std::ostream& operator<<(std::ostream& os, const Tartalom& a){
    os << "Cím: " << a.getcim() << std::endl;
    os << "Kategória: " << a.getKat() << std::endl;
    os << "Nyelv: " << a.getNyelv() << std::endl;
    os << "Korhatár: " << a.getKorhatar() << std::endl;
    os << "Megjelenés: " << a.getMegjelenes() << std::endl;
    os << "Hossz: " << a.getHossz() << std::endl;
    return os;
}

Tartalom::Tartalom(const Tipusok tipus,const string &cim,const string &kat,const string &nyelv,
const short int &korhatar,const Datum &megjelenes,const Ido &hossz) :
Tipus(tipus), cim(cim), kat(kat), nyelv(nyelv), korhatar(korhatar), megjelenes(megjelenes), hossz(hossz), kov(nullptr) {}

Tartalom::Tartalom(Tartalom &ujtart) :
    Tipus(ujtart.Tipus), cim(ujtart.cim), kat(ujtart.kat), nyelv(ujtart.nyelv),
    korhatar(ujtart.korhatar), megjelenes(ujtart.megjelenes), hossz(ujtart.hossz), kov(nullptr) {}

void Tartalom::kiir() const{
    std::cout << *this;
}

void Tartalom::kiir_reszletes() const{
    std::cout << *this;
}

void Tartalom:: elment(std::ostream& os) const{
    os << "Cím: " << this->getcim() << std::endl;
    os << "Műfaj: " << this->getKat() << std::endl;
    os << "Nyelv: " << this->getNyelv() << std::endl;
    os << "Korhatár: " << this->getKorhatar() << std::endl;
    os << "Megjelenés: " << this->getMegjelenes().getev() << '-' << this->getMegjelenes().gethonap() << '-' << this->getMegjelenes().getnap() << std::endl;;
    os << "Időtartam: " << this->getHossz().getora() << ":" << this->getHossz().getperc() << std::endl;
}

Tartalom& Tartalom::operator=(const Tartalom& ujtart) {
        if (this != &ujtart) {
            Tipus = ujtart.Tipus;
            cim = ujtart.cim;
            kat = ujtart.kat;
            nyelv = ujtart.nyelv;
            korhatar = ujtart.korhatar;
            megjelenes = ujtart.megjelenes;
            hossz = ujtart.hossz;
        }
        return *this;
    }

string Tartalom:: getTipus() const{
    return enumToString(Tipus);
}
string Tartalom:: getNyelv() const{
    return nyelv;
}
string Tartalom:: getKat() const{
    return kat;
}
string Tartalom:: getcim() const{
    return cim;
}
int Tartalom:: getKorhatar() const{
    return korhatar;
}
Ido Tartalom:: getHossz() const{
    return hossz;
}
Datum Tartalom:: getMegjelenes() const{
    return megjelenes;
}
Tartalom* Tartalom:: getKov() const{
    return kov;
}
void Tartalom:: setKov(Tartalom *ujtart){
    kov = ujtart;
}
