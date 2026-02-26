#include "Ido.h"

std::ostream& operator<<(std::ostream& os, const Ido& ido) {
    if(ido.getora() == 0 && ido.getperc() == 0) 
        return os << "Unknown";
    return os << ido.getora() << ':' << ido.getperc();
}