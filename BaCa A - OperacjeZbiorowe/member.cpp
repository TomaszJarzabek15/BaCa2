//Tomasz Jarzabek

#include "bitwise_operations.h"

bool Member (char* element, int zbior){     //czy nalezy do zbioru

    int zbiorA;

    Emplace(element, &zbiorA);

    if(zbior & zbiorA){
        return true;
    }
    else{
        return false;
    }

}