//Tomasz Jarzabek

#include "bitwise_operations.h"

void ToBinary(int j, int* counter, char* ciag, int* pozycja, int* inwersja){

    (*counter)++;

    if(*counter > 5){

        *pozycja = *pozycja + 5;

        *(ciag + *pozycja) = ' ';
        *pozycja = *pozycja + 1;
    }
    else{
        int reszta;
        reszta = j % 2;
        j = j / 2;
    
        if(reszta == 1){
            *(ciag + *pozycja + *inwersja) = '1';
        }
        else if(reszta == 0){
            *(ciag + *pozycja + *inwersja) = '0';
        }

        *inwersja = *inwersja - 1;

        ToBinary(j, &(*counter), ciag, &(*pozycja), &(*inwersja));
    }
}

void NaString(int zbior, char* ciag, int* pozycja, int* i){

    if(*i < 0){
        *(ciag + *pozycja - 1) = '\0';
    }
    else{
        if((zbior & (1 << *i))){

                int counter = 0;
                int j = *i;
                int inwersja = 4;

                ToBinary(j, &counter, ciag, &(*pozycja), &inwersja);

                *i = *i - 1;  
                NaString(zbior, ciag, &(*pozycja), &(*i));
        }
        else{
            *i = *i - 1;  
            NaString(zbior, ciag, &(*pozycja), &(*i));
        }
    }

}

void Print (int zbior, char* ciag){         //print od najwiekszej liczby do najmniejszej

    int pozycja = 0;
    int i = 31;

    if(ciag == 0){

    }
    else{
    
        if(Emptiness(zbior)){

            *ciag = 'e';
            *(ciag + 1) = 'm';
            *(ciag + 2) = 'p';
            *(ciag + 3) = 't';
            *(ciag + 4) = 'y';
            *(ciag + 5) = '\0';
        }
        else{
            NaString(zbior, ciag, &pozycja, &i);
        }
    }
}