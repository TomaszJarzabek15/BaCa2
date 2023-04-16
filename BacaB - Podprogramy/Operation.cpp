//Tomasz Jarzabek

#include <string>
#include <cstdarg>

using namespace std;

void Add3(va_list args, string* liczby, int* i, int ilosc){    //chyba dziala

    if(*i >= ilosc){
        //koniec rekurencji
    }
    else{
        liczby[*i] = va_arg(args, char*);
        *i = *i + 1;

        Add3(args, liczby, &(*i), ilosc);
    }
}

string Operation (string (*naglowek)(int, const string* ), int ilosc, const string* liczby){

    string suma = naglowek(ilosc, liczby);

    return suma;
}

string Operation (string (*naglowek)(int, const string* ), int ilosc, ...){

    string suma = "";
    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add3(args, liczby, &i, ilosc);

    suma = naglowek(ilosc, liczby);

    return suma;
}

void Operation (string* suma, string (*naglowek)(int, const string*), int ilosc, ...){

    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add3(args, liczby, &i, ilosc);

    *suma = naglowek(ilosc, liczby);
}

void Operation (string* suma, string (*naglowek)(int, const string*), int ilosc, const string* liczby){

    *suma = naglowek(ilosc, liczby);
}

void Operation (string& suma, void (*naglowek)(string*, int, const string*), int ilosc, const string* liczby){

    string wynik;

    naglowek(&wynik, ilosc, liczby);

    suma = wynik;
}

void Operation (string& suma, void (*naglowek)(string*, int, const string*), int ilosc, ...){
    
    int i = 0;
    string wynik;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add3(args, liczby, &i, ilosc);

    naglowek(&wynik, ilosc, liczby);

    suma = wynik;
}