#include "Menu.h"
#include "teszt.h"
#include "memtrace.h"

int main(){
    test_Tarolo();
    test_Tartalom();
    std::cout << std::endl << std::endl;
    Menu menu;
    menu.load_tarolo();
    menu.interface();
    menu.save_tarolo();
}