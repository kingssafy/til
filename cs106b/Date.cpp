#include "Date.h"

Date::Date(int m, int d) { //constructor
    month = m;
    day = d;
}


int Date::getMonth() { // member functions
    return month;
}
