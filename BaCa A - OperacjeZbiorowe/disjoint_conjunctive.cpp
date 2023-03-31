//Tomasz Jarzabek

#include "bitwise_operations.h"

bool Disjoint (int zbiorA, int zbiorB){

    if(zbiorA & zbiorB){
        return false;
    }
    else{
        return true;
    }
}

bool Conjunctive (int zbiorA, int zbiorB){

    return !Disjoint(zbiorA, zbiorB);
}