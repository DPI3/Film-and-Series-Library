#include "MiniSorozat.h"

std::ostream& operator<<(std::ostream& os, const minisorozat& minisor) {
    os << "Minisorozat" << std::endl;
    os << "Cím: " << minisor.getcim() << std::endl;
    os << "Részek száma: " << minisor.getReszdb() << std::endl;
    os << "Műfaj: " << minisor.getKat() << std::endl;
    os << "Nyelv: " << minisor.getNyelv() << std::endl;
    os << "Korhatár: " << minisor.getKorhatar() << std::endl;
    os << "Megjelenés: " << minisor.getMegjelenes() << std::endl;
    os << "Időtartam: " << minisor.getHossz() << std::endl;
    return os;
}

int minisorozat::getReszdb() const{
    return reszdb;
}

void minisorozat::kiir_reszletes() const{
    std::cout << *this;
}

void minisorozat::kiir() const{
    std::cout << *this;
}

void minisorozat:: elment(std::ostream& os) const{
    os << "Minisorozat" << std::endl;
    os << "Cím: " << this->getcim() << std::endl;
    os << "Részek száma: " << this->getReszdb() << std::endl;
    os << "Műfaj: " << this->getKat() << std::endl;
    os << "Nyelv: " << this->getNyelv() << std::endl;
    os << "Korhatár: " << this->getKorhatar() << std::endl;
    os << "Megjelenés: " << this->getMegjelenes().getev() << '-' << this->getMegjelenes().gethonap() << '-' << this->getMegjelenes().getnap() << std::endl;;
    os << "Időtartam: " << this->getHossz().getora() << ":" << this->getHossz().getperc() << std::endl;
}
