#include "functions.h"

void buffer_delete(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool is_number(const std::string s){
    for(unsigned int i = 0; i != strlen(s.c_str()); i++)
        if(!std::isdigit(s.c_str()[i]))
            return false;
    return true;
}

int readInt() {
    int num;
    std::string Seset; //azert kell string hogy ne legyen baj ha karaktert olvas be
    do{
        std::cin >> Seset;
        if(is_number(Seset))
            num = atoi(Seset.c_str());
        else
            std::cout << "Kérem természetes számot adjon meg ";

    }while(!is_number(Seset));
    
    return num;
}
