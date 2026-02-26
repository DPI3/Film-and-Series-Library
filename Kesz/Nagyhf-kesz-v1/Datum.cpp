#include "Datum.h"

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
    if(datum.getev() == 0) 
        return os << "Unknown";
    if(datum.gethonap() == 0)
        return os << datum.getev();
    return os << datum.getev() << '-' << datum.gethonap() << '-' << datum.getnap();
}
