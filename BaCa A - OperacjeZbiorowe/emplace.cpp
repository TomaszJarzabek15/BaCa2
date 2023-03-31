//Tomasz Jarzabek

#include "bitwise_operations.h"

void read(char* ciag, int* zbior, int* pozycja, int* liczba, int* poczatek, int* counter){

    if((*(ciag + *pozycja) != ' ') && ((*(ciag + *pozycja) != '\0'))){

        if(*(ciag + *pozycja) == '\0'){

            *zbior = *zbior | (1 << *liczba);
            *liczba = 0;
        
        }
        else{

            if(*(ciag + *pozycja) == '0'){

                *counter = *counter + 1;

                *pozycja = *pozycja + 1; 

                if(((*(ciag + *pozycja) != '1') && (*(ciag + *pozycja) != '0')) || (*counter == 5)){
                    *zbior = *zbior | (1 << *liczba);
                    *liczba = 0;
                } 

                if(*counter == 5){
                    *counter = 0;
                    *liczba = 0;
                    *poczatek = *pozycja;
                }

                read(ciag, &(*zbior), &(*pozycja), &(*liczba), &(*poczatek), &(*counter));
            }
            else if(*(ciag + *pozycja) == '1'){

                *counter = *counter + 1;

                *liczba = *liczba | (1 << (4 - (*pozycja - *poczatek)));
                *pozycja = *pozycja + 1; 

                if(((*(ciag + *pozycja) != '1') && (*(ciag + *pozycja) != '0')) || (*counter == 5)){
                    *zbior = *zbior | (1 << *liczba);
                    *liczba = 0;
                } 

                if(*counter == 5){
                    *counter = 0;
                    *liczba = 0;
                    *poczatek = *pozycja;
                }
    
                read(ciag, &(*zbior), &(*pozycja), &(*liczba), &(*poczatek), &(*counter));
            }

        }

    }
    else if((*(ciag + *pozycja) == '\0')){

    }
    else{

        *pozycja = *pozycja + 1;        //skipujemy spacje
        *poczatek = *pozycja;

        read(ciag, &(*zbior), &(*pozycja), &(*liczba), &(*poczatek), &(*counter));
    }
}

void SameSpacje(char* ciag, int* pozycja, int* wynik){

    if(*(ciag + *pozycja) == '\0'){

    }
    else if(*(ciag + *pozycja) != ' '){
        *wynik = 0;
    }
    else if(*(ciag + *pozycja) == ' '){
        *pozycja = *pozycja + 1;
        SameSpacje(ciag, &(*pozycja), &(*wynik));
    }
}

void Emplace (char* ciag, int* zbior){

    *zbior = 0;         //zerujemy zbior bo ma on byc tworzony od nowa
    int pozycja = 0;
    int liczba = 0;
    int poczatek = 0;
    int wynik = 1;
    int counter = 0;

    if((ciag == 0) || (*(ciag) == '\0')){

    }
    else{
        SameSpacje(ciag, &pozycja, &wynik);

        pozycja = 0;

        if(wynik){

        }
        else{
            read(ciag, &(*zbior), &pozycja, &liczba, &poczatek, &counter);
        }
    }
}