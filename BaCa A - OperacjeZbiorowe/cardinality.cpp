//Tomasz Jarzabek

#include "bitwise_operations.h"

void NaString(int zbior, int* moc, int* i){

    if(*i < 0){
    }
    else{
        if(zbior & (1 << *i)){

                *moc = *moc + 1;
                *i = *i - 1;  
                NaString(zbior, &(*moc), &(*i));
        }
        else{
            *i = *i - 1;  
            NaString(zbior, &(*moc), &(*i));
        }
    }
}

int Cardinality (int zbior){    //moc zbioru

    int moc = 0;
    int i = 31;

    NaString(zbior, &moc, &i);

    return moc;
}