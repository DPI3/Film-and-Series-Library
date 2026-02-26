#include "Sorozat.h"

std::ostream& operator<<(std::ostream& os, const sorozat& soroz) {
    os << "Sorozat" << std::endl;
    os << "Cím: " << soroz.getcim() << std::endl;
    os << "Évadok száma: " << soroz.getEvadokSzama() << std::endl;
    os << "Részek száma: " << soroz.getReszekSzama() << std::endl;
    os << "Befejezett: " << (soroz.isTartMeg() ? "true" : "false") << std::endl;
    if(!soroz.isTartMeg()) os << "Befejezés dátuma: " << soroz.getBefejezesDatuma() << std::endl;
    else os << "Befejezés dátuma: 0" << std::endl;;
    os << "Műfaj: " << soroz.getKat() << std::endl;
    os << "Nyelv: " << soroz.getNyelv() << std::endl;
    os << "Korhatár: " << soroz.getKorhatar() << std::endl;
    os << "Megjelenés: " << soroz.getMegjelenes() << std::endl;
    return os;
}

int sorozat::getEvadokSzama() const {
    return evaddb;
}

int sorozat::getReszekSzama() const {
    return reszdb;
}

bool sorozat::isTartMeg() const {
    return tartmeg;
}

Datum sorozat::getBefejezesDatuma() const {
    return befDat;
}

void sorozat::kiir_reszletes() const{
    std::cout << *this;
}

void sorozat::kiir() const{
    std::cout << *this;
}

void sorozat::elment(std::ostream& os) const{
    os << "Sorozat" << std::endl;
    os << "Cím: " << this->getcim() << std::endl;
    os << "Évadok száma: " << this->getEvadokSzama() << std::endl;
    os << "Részek száma: " << this->getReszekSzama() << std::endl;
    os << "Befejezett: " << (this->isTartMeg() ? "true" : "false") << std::endl;
    os << "Befejezés dátuma: " << this->getBefejezesDatuma().getev() << '-' << this->getBefejezesDatuma().gethonap() << '-' << this->getBefejezesDatuma().getnap() << std::endl;
    os << "Műfaj: " << this->getKat() << std::endl;
    os << "Nyelv: " << this->getNyelv() << std::endl;
    os << "Korhatár: " << this->getKorhatar() << std::endl;
    os << "Megjelenés: " << this->getMegjelenes().getev() << '-' << this->getMegjelenes().gethonap() << '-' << this->getMegjelenes().getnap() << std::endl;
}
