#include "Tarolo.h"
#include "Menu.h"
#include <fstream>
#include "functions.h"

using std::string;

//hozzaad segedfuggveny
Tipusok tipus_beolvas(){
    int intTipus;
    std::cout << "Mi a tartalom típusa? " << std::endl
    << "1. Jatekfilm\n 2. Dokumentumfilm\n 3. Minisorozat\n 4. Sorozat\n";
    string stringTipus; //azert kell string hogy ne legyen baj ha karaktert olvas be
    std::cin >> stringTipus;
    intTipus = atoi(stringTipus.c_str()) - 1;
    return intToEnum(intTipus);
}

Tartalom* Menu::hozzaad_interface(){
    string cim, kat, nyelv, leiras;
    Tipusok Tipus;
    short int korhatar;
    Datum megjelenes;
    Ido hossz;
    int evaddb, reszdb;
    bool tartmeg;
    Datum befDat;

    Tipus = tipus_beolvas();
    buffer_delete();

    // Beolvassuk az adatokat a felhasználótól
    std::cout << "Kerem adja meg a cimet: ";
    std::getline(std::cin, cim);
    
    std::cout << "Kerem adja meg a kategoriat: ";
    std::getline(std::cin, kat);

    std::cout << "Kerem adja meg a nyelvet: ";
    std::getline(std::cin, nyelv);

    std::cout << "Kerem adja meg a korhatart: ";
    korhatar = readInt(); // A korhatár beolvasása - helytelen karakter esetén 0

    std::cout << "Kerem adja meg a megjelenes datumat: " << std::endl;
    megjelenes.beolvas();

    switch (Tipus){
        case Jatekfilm:
            std::cout << "Kerem adja meg a hosszt: " << std::endl;
            hossz.beolvas();
            return new jatekfilm(Jatekfilm, cim, kat, nyelv, korhatar, megjelenes, hossz);
            break;
        case Dokumentumfilm:
            std::cout << "Kerem adja meg a hosszt: " << std::endl;
            hossz.beolvas();
            std::cout << "Kerem adja meg a leirast: ";
            std::cin >> leiras;
            return new dokumentumfilm(Dokumentumfilm, cim, leiras, kat, nyelv, korhatar, megjelenes, hossz);
            break;
        case Minisorozat:
            std::cout << "Kerem adja meg a reszek szamat: ";
            std::cin >> reszdb;
            return new minisorozat(Minisorozat, cim, reszdb, kat, nyelv, korhatar, megjelenes, hossz);
            break;
        case Sorozat:
            std::cout << "Kerem adja meg az evadok szamat: ";
            std::cin >> evaddb;

            std::cout << "Kerem adja meg a reszek szamat: ";
            std::cin >> reszdb;

            std::cout << "Kerem adja meg, hogy tartalmaz-e befejezes datumot (0/1): ";
            std::cin >> tartmeg;

            if (!tartmeg) {
                std::cout << "Kerem adja meg a befejezes datumat: " << std::endl;
                befDat.beolvas();
                return new sorozat(Sorozat, cim, evaddb, reszdb, 0, befDat, kat, nyelv, korhatar, megjelenes, hossz);
            }
            return new sorozat(Sorozat, cim, evaddb, reszdb, 1, 0, kat, nyelv, korhatar, megjelenes, hossz);
            break;
        default:
            break;
    }
    return NULL;
}

void Menu::interface(){
    int eset = 8;
    do{
        std::cout << "1. Összes listázás" << std::endl;
        std::cout << "2. Filmek listázása" << std::endl;
        std::cout << "3. Sorozatok listázása" << std::endl;
        std::cout << "4. Részletes listázás" << std::endl;
        std::cout << "5. Kategória szerinti listázás" << std::endl;
        std::cout << "6. Keresés" << std::endl;
        std::cout << "7. Tartalom hozzáadása" << std::endl;
        std::cout << "8. Kilépés" << std::endl;

        string Seset; //azert kell string hogy ne legyen baj ha karaktert olvas be
        std::cin >> Seset;
        eset = atoi(Seset.c_str());
        
        switch(eset){
            case 1:
                tarolo.kiir_osszes();
                break;
            case 2:
                tarolo.kiir_tipus(Jatekfilm);
                break;
            case 3:
                tarolo.kiir_tipus(Sorozat);
                break;
            case 4:{
                tarolo.kiir_specifikus(tipus_beolvas()); // helytelen tipus valasztas esetén az összes játékfilmet listázza
                break;
            }
            case 5:{
                tarolo.kiir_kategoriak();
                std::cout << "Valassz kategoriat: ";
                string tempkat;
                std::cin >> tempkat; // helytelen kategoria valasztas esetén nem listáz semmit
                tarolo.kiir_kategoria(tempkat);
                break;
            }
            case 6:{
                std::cout << "Mi a tartalom pontos cime? " << std::endl;
                string cim;
                std::cin >> cim;
                try{
                    tarolo.Kereses(cim);
                }catch(char const* asd){
                    std::cout << asd << std::endl;
                }
                break;
            }
            case 7:{
                Tartalom *user = hozzaad_interface();
                user->kiir_reszletes();
                tarolo.hozzaad(user);
                break;
            }
            case 8:
                break;
            default:
                std::cout << "Kérem helyes számot üssön be" << std::endl;
                break;
        }
    }while(eset != 8);
}

Datum parseDatum(const std::string& datumStr) {
    size_t pos1 = datumStr.find('-');
    if (pos1 == std::string::npos) {
        throw std::runtime_error("Invalid date format: " + datumStr);
    }
    size_t pos2 = datumStr.find('-', pos1 + 1);
    if (pos2 == std::string::npos) {
        throw std::runtime_error("Invalid date format: " + datumStr);
    }

    int ev = std::stoi(datumStr.substr(0, pos1));
    int honap = std::stoi(datumStr.substr(pos1 + 1, pos2 - pos1 - 1));
    int nap = std::stoi(datumStr.substr(pos2 + 1));

    return Datum(ev, honap, nap);
}

Ido parseIdo(const std::string& idoStr) {
    size_t pos = idoStr.find(':');
    if (pos == std::string::npos) {
        throw std::runtime_error("Invalid time format: " + idoStr);
    }

    int ora = std::stoi(idoStr.substr(0, pos));
    int perc = std::stoi(idoStr.substr(pos + 1));

    return Ido(ora, perc);
}

void Menu::load_tarolo() {
    string filename = "tartalmak.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Sikertelen fajl megnyitas");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        Tipusok tipus;
        try {
            tipus = stringToEnum(line);
        } catch (const std::invalid_argument&) {
            std::cerr << "Invalid type: " << line << std::endl;
            continue; // Skip this entry
        }

        std::string cim, leiras, mufaj, nyelv, datumStr, idoStr, befejezesDatumStr, befejezettStr;
        int korhatar = 0, evadokSzama = 0, reszekSzama = 0;
        bool befejezett = false;
        Datum befejezesDatum;

        try {
            // Function to read and process lines
            cim = readAndProcessLine(file);
            
            if (tipus == Dokumentumfilm) {
                leiras = readAndProcessLine(file);
            }

            if (tipus == Minisorozat) {
                reszekSzama = std::stoi(readAndProcessLine(file));
            }

            if (tipus == Sorozat) {
                evadokSzama = std::stoi(readAndProcessLine(file));
                reszekSzama = std::stoi(readAndProcessLine(file));
                befejezettStr = readAndProcessLine(file);
                befejezett = (befejezettStr == "true");
                befejezesDatumStr = readAndProcessLine(file);
                befejezesDatum = parseDatum(befejezesDatumStr);
            }

            mufaj = readAndProcessLine(file);
            nyelv = readAndProcessLine(file);
            korhatar = std::stoi(readAndProcessLine(file));
            datumStr = readAndProcessLine(file);
            Datum datum = parseDatum(datumStr);
            
            Ido ido;
            if (tipus != Sorozat){
                //std::cout << "Sad";
                idoStr = readAndProcessLine(file);
                ido = parseIdo(idoStr);
            }
            
            switch (tipus) {
                case Jatekfilm: {
                    tarolo.hozzaad(new jatekfilm(Jatekfilm, cim, mufaj, nyelv, korhatar, datum, ido));
                    break;
                }
                case Dokumentumfilm: {
                    tarolo.hozzaad(new dokumentumfilm(Dokumentumfilm, cim, leiras, mufaj, nyelv, korhatar, datum, ido));
                    break;
                }
                case Minisorozat: {
                    tarolo.hozzaad(new minisorozat(Minisorozat, cim, reszekSzama, mufaj, nyelv, korhatar, datum, ido));
                    break;
                }
                case Sorozat: {
                    tarolo.hozzaad(new sorozat(Sorozat, cim, evadokSzama, reszekSzama, befejezett, befejezesDatum, mufaj, nyelv, korhatar, datum));
                    break;
                }
                default:
                    throw std::runtime_error("Unknown type");
            }
        } catch (const std::exception& e) {
            std::cerr << "Helytelen beolvasas: " << e.what() << std::endl;
            continue; // Skip this entry
        }
    }
}

std::string Menu::readAndProcessLine(std::ifstream &file) {
    std::string line;
    if (!std::getline(file, line)) {
        throw std::runtime_error("Hamarabb vege van a fajlnak"); 
    }
    size_t pos = line.find(": ");
    if (pos == std::string::npos) {
        throw std::runtime_error("Helytelen sor formatum: " + line);
    }
    return line.substr(pos + 2);
}

void Menu::save_tarolo(){
    string filename = "tartalmak.txt";
    std::ofstream file(filename);
    Tartalom* elem = tarolo.getTartalom();
    while (elem != nullptr){
        elem->elment(file);
        file << std::endl;
        elem = elem->getKov();
    }
    delete elem;
    file.close();
}