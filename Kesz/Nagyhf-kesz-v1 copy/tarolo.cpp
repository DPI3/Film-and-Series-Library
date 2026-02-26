#include<iostream>
#include<set>
#include "Tarolo.h"
#include "memtrace.h"

Tartalom* Tarolo::getTartalom(){
  return tartalom;
}

Tartalom* Tarolo::Keres(const std::string& keresett_nev) {
  Tartalom* iter = tartalom;
    while (iter != nullptr){
      if(strcmp(iter->getcim().c_str(),keresett_nev.c_str()) == 0){
        return iter;
      }
      iter = iter->getKov();
  }
  delete iter;
  return NULL;
}

void Tarolo::Kereses(const std::string keresett_nev) {
  Tartalom *temp = Keres(keresett_nev);
  if(temp == NULL)
    throw "Nincs a tárolóban ilyen film";
  Keres(keresett_nev)->kiir();
}

void Tarolo::hozzaad(Tartalom *tartalom_uj) {
    Tartalom* uj = tartalom_uj;
    uj->setKov(tartalom);
    tartalom = uj;
}

void Tarolo::kiir_osszes() {
    Tartalom* iter = tartalom;
    while (iter != nullptr){
        iter->kiir();
        std::cout << std::endl;
        iter = iter->getKov();
    }
    delete iter;
}

void Tarolo::kiir_kategoriak() {
    std::set<std::string> kiirtKategoriak; // Segéd adatszerkezet a már kiírt kategóriák tárolására

    Tartalom* iter = tartalom;
    while (iter != nullptr) {
        const std::string& kategoria = iter->getKat();
        if (kiirtKategoriak.find(kategoria) == kiirtKategoriak.end()) {
            std::cout << kategoria << std::endl;
            kiirtKategoriak.insert(kategoria); // Kategória hozzáadása a már kiírtakhoz
        }
        iter = iter->getKov();
    }
    delete iter;
}

void Tarolo::kiir_kategoria(const std::string& kat) {
      Tartalom* iter = tartalom;
      while (iter != nullptr){
        if(iter->getKat() == kat){
          iter->kiir();
          std::cout << std::endl;
        }
        iter = iter->getKov();
    }
    delete iter;
}

void Tarolo::kiir_tipus(Tipusok tipus) {
    Tartalom* iter = tartalom;
    while (iter != nullptr){
      if(iter->getTipus() == enumToString(tipus)){
        iter->kiir();
        std::cout << std::endl;
      }
 
      iter = iter->getKov();
    }
    delete iter;
}

void Tarolo::kiir_specifikus(Tipusok tipus){
    Tartalom* iter = tartalom;
    while (iter != nullptr){
      if(iter->getTipus() == enumToString(tipus)){
        iter->kiir_reszletes();
        std::cout << std::endl;
      }
      iter = iter->getKov();
    }
    delete iter;
}

Tarolo::~Tarolo(){
  while (tartalom != nullptr) {
      Tartalom* temp = tartalom;
      tartalom = tartalom->getKov();
      delete temp;
  }
}