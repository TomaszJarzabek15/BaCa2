//Tomasz Jarzabek

#include "bitwise_operations.h"

bool Equality (int zbiorA, int zbiorB){

    if(zbiorA == zbiorB){
        return true;
    }
    else{
        return false;
    }

}

bool Inclusion (int zbiorA, int zbiorB){

    int Xor;

    Xor = zbiorA ^ zbiorB;

    if(Xor & zbiorA){
        return false;
    }
    else{
        return true;
    }

}