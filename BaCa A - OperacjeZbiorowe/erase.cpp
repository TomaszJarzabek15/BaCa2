//Tomasz Jarzabek

#include "bitwise_operations.h"

void Erase (char* elementy, int* zbior){

    int zbiorA;
    int zbiorC;

    Emplace(elementy, &zbiorA);

    zbiorC = (*zbior) & zbiorA;

    *zbior = zbiorC ^ (*zbior);
}