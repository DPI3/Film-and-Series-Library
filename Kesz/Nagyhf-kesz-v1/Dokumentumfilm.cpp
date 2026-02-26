#include "Dokumentumfilm.h"

std::ostream& operator<<(std::ostream& os, const dokumentumfilm& doks){
    os << "Dokumentumfilm" << std::endl;
    os << "Cím: " << doks.getcim() << std::endl;
    os << "Leírás: " << doks.getLeiras() << std::endl;
    os << "Műfaj: " << doks.getKat() << std::endl;
    os << "Nyelv: " << doks.getNyelv() << std::endl;
    os << "Korhatár: " << doks.getKorhatar() << std::endl;
    os << "Megjelenés: " << doks.getMegjelenes() << std::endl;
    os << "Időtartam: " << doks.getHossz() << std::endl;
    return os;
}

void dokumentumfilm::kiir_reszletes() const{
    std::cout << *this;
}

void dokumentumfilm::kiir() const{
    Tartalom::kiir();
}

std::string dokumentumfilm::getLeiras() const { 
    return leiras; 
}

void dokumentumfilm:: elment(std::ostream& os) const{
    os << "Dokumentumfilm" << std::endl;    
    os << "Cím: " << this->getcim() << std::endl;
    os << "Leírás: " << this->getLeiras() << std::endl;
    os << "Műfaj: " << this->getKat() << std::endl;
    os << "Nyelv: " << this->getNyelv() << std::endl;
    os << "Korhatár: " << this->getKorhatar() << std::endl;
    os << "Megjelenés: " << this->getMegjelenes().getev() << '-' << this->getMegjelenes().gethonap() << '-' << this->getMegjelenes().getnap() << std::endl;
    os << "Időtartam: " << this->getHossz().getora() << ":" << this->getHossz().getperc() << std::endl;
}