#include "teszt.h"

void test_Tarolo(){
    std::cout << "Testing Tarolo..." << std::endl;
    // Teszt Tarolo létrehozása
    Tarolo tarolo;

    // Tartalmak hozzáadása a Tarolohoz
    tarolo.hozzaad(new sorozat(Sorozat, "Monika show", 10, 1918, false, Datum(2010), "Drama", "Magyar, Cigany", 18, Datum(2001)));
    tarolo.hozzaad(new minisorozat(Minisorozat, "The billion dollar code",4, "Drama", "Angol",15,Datum(2021),Ido(0)));
    tarolo.hozzaad(new dokumentumfilm(Dokumentumfilm, "A Viszkis balladája - Szökésben", "Ambrus Attila nem tudott megélni hoki kapus fizetéséből. Ezért egy jóval veszélyesebb, ám annál jövedelmezőbb foglalkozás után nézett. Ő lett a rendszerváltás utáni Magyarország leghíresebb bűnözője. Több mint hét éven keresztül fosztogatta a pénzintézeteket, és borzolta a hatóságok idegeit. A Viszkis rablóként elhíresült bűnözőt a lakosság hamarosan egyfajta nemzeti hősnek tekintette. Annyira népszerűvé vált, hogy az emberek egyszerűen nem segítették a rendőrség munkáját. Így aztán a bűnüldöző hatóságoknak sokáig fogalmuk sem volt róla, kit is keresnek valójában.",
    "Dokumentumfilm", "Magyar", 16, Datum(2005), Ido(1, 00)));
    tarolo.hozzaad(new jatekfilm(Jatekfilm, "Az", "Horror", "Angol", 18, Datum(2017), Ido(1,34)));

    // Ellenőrzés, hogy a hozzáadott tartalmak valóban a Tarolóban vannak-e
    if (tarolo.Keres("Az") && tarolo.Keres("Monika show") &&
        tarolo.Keres("The billion dollar code") && tarolo.Keres("A Viszkis balladája - Szökésben")) {
        std::cout << "All test contents added successfully." << std::endl;
    } else {
        std::cerr << "Test failed: Not all test contents added." << std::endl;
    }

    // Teszt Keres
    Tartalom* found = tarolo.Keres("A Viszkis balladája - Szökésben");
    if (found) {
        std::cout << "Found: A Viszkis balladája - Szökésben" << found->getcim() << std::endl;
    } else {
        std::cerr << "Test failed: A Viszkis balladája - Szökésben not found" << std::endl;
    }

    //getter teszt
    std::cout << "Getter tests:" << std::endl;

    Tartalom* jatekfilm = tarolo.getTartalom();
    if (jatekfilm) {
        std::cout << "Jatekfilm found: " << jatekfilm->getcim() << std::endl;
    } else {
        std::cerr << "Jatekfilm not found!" << std::endl;
    }

    // Teszt kiir_osszes
    std::cout << "Testing kiir_osszes..." << std::endl;
    tarolo.kiir_osszes();
    std::cout << std::endl;

    // Teszt kiir_kategoriak
    std::cout << "Testing kiir_kategoriak..." << std::endl;
    tarolo.kiir_kategoriak();
    std::cout << std::endl;

    // Teszt kiir_kategoria
    std::cout << "Testing kiir_kategoria for 'Drama'..." << std::endl;
    tarolo.kiir_kategoria("Drama");
    std::cout << std::endl;

    // Teszt kiir_specifikus
    std::cout << "Testing kiir_specifikus for Sorozat..." << std::endl;
    tarolo.kiir_specifikus(Sorozat);
    std::cout << std::endl;
}

void test_Tartalom(){
    // Teszt Tartalom létrehozása
    Tartalom* tartalom = new jatekfilm(Jatekfilm, "Test Jatekfilm", "Fantasy", "Magyar", 12, Datum(2024, 5, 1), Ido(2, 30));

    // Teszt enumToString
    std::cout << "Teszt enumToString: ";
    if (strcmp(enumToString(Jatekfilm), "Játékfilm") == 0 &&
        strcmp(enumToString(Dokumentumfilm), "Dokumentumfilm") == 0 &&
        strcmp(enumToString(Minisorozat), "Minisorozat") == 0 &&
        strcmp(enumToString(Sorozat), "Sorozat") == 0) {
        std::cout << "sikeres" << std::endl;
    } else {
        std::cout << "sikertelen" << std::endl;
    }

    // Teszt intToEnum
    std::cout << "Teszt intToEnum: ";
    if (intToEnum(0) == Jatekfilm &&
        intToEnum(1) == Dokumentumfilm &&
        intToEnum(2) == Minisorozat &&
        intToEnum(3) == Sorozat) {
        std::cout << "sikeres" << std::endl;
    } else {
        std::cout << "sikertelen" << std::endl;
    }

    // Teszt stringToEnum
    std::cout << "Teszt stringToEnum: ";
    try {
        if (stringToEnum("Jatekfilm") == Jatekfilm &&
            stringToEnum("Dokumentumfilm") == Dokumentumfilm &&
            stringToEnum("Minisorozat") == Minisorozat &&
            stringToEnum("Sorozat") == Sorozat) {
            std::cout << "sikeres" << std::endl;
        } else {
            std::cout << "sikertelen" << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "sikertelen: " << e.what() << std::endl;
    }

    // Teszt getterek
    std::cout << "Teszt getterek (Tipus, Nyelv, Kat, Cim, Korhatar, Hossz, Megjelenes): " << std::endl;
    string tempTip = tartalom->getTipus();
    Tipusok tempTips;
    try{
        tempTips = stringToEnum(tempTip);
    }catch(char const* asd){
    }
    if (tempTips == Jatekfilm) std::cout << "Tipus sikeres; " << std::endl;
    else std::cout << "Tipus sikertelen; " << std::endl;
    if (tartalom->getNyelv() == "Magyar") std::cout << "Nyelv sikeres; " << std::endl;
    else std::cout << "Nyelv sikertelen; " << std::endl;
    if (tartalom->getKat() == "Fantasy") std::cout << "Kat sikeres; " << std::endl;
    else std::cout << "Kat sikertelen; " << std::endl;
    if (tartalom->getcim() == "Test Jatekfilm") std::cout << "Cim sikeres; " << std::endl;
    else std::cout << "Cim sikertelen; " << std::endl;
    if (tartalom->getKorhatar() == 12) std::cout << "Korhatar sikeres; " << std::endl;
    else std::cout << "Korhatar sikertelen; " << std::endl;
    if (tartalom->getHossz().getora() == 2 && tartalom->getHossz().getperc() == 30) std::cout << "Hossz sikeres; " << std::endl;
    else std::cout << "Hossz sikertelen; " << std::endl;
    if (tartalom->getMegjelenes().getev() == 2024 && tartalom->getMegjelenes().gethonap() == 5 && tartalom->getMegjelenes().getnap() == 1) std::cout << "Megjelenes sikeres; " << std::endl;
    else std::cout << "Megjelenes sikertelen; " << std::endl;
    std::cout << std::endl;

    // Teszt setter
    Tartalom* uj_tartalom = new dokumentumfilm(Dokumentumfilm, "Test Dokumentumfilm", "Leiras", "Dokumentum", "Angol", 0, Datum(2024, 5, 1), Ido(1, 45));
    tartalom->setKov(uj_tartalom);
    std::cout << "Teszt setter: ";
    if (tartalom->getKov()->getcim() == "Test Dokumentumfilm") std::cout << "sikeres" << std::endl;
    else std::cout << "sikertelen" << std::endl;

    delete tartalom;
    delete uj_tartalom;
}
