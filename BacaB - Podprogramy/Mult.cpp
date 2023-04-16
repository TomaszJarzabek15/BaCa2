//Tomasz Jarzabek

#include <string>
#include <cstdarg>

using namespace std;

void ScrollArray(char* wynik, string* suma, int MAX, int* licznik);
int Compare(string A, string B);
void SetupString(string liczba, string* wynik, int dlugosc, int* i, bool* NieZero, bool* ujemna);
void DodajemyDwa(int ilosc, const string* liczby, string* suma, int* i);



int potega(int x, int n){

    if(n != 1){
        return(x * potega(x, (n - 1)));
    }
    else{
        return 1;
    }
}

void Times(string pierwsza, int liczbaB, char* wynik, int* carry, int* k, int* i){

    int liczbaA = 0;
    int somma = 0;

    if(*k < 0){ 
        //koniec rekurencji pierwsza liczba sie skonczyla
    }
    else{
        if(*i >= 0){
            liczbaA = pierwsza[*i] - '0';
        }
        else{
            liczbaA = 0;
        }
        somma = liczbaA * liczbaB;

        wynik[*k] = ((somma + *carry) % 10) + '0';

        if((somma + *carry) >= 10){
            *carry = (somma + *carry) / 10;
        }
        else{
            *carry = 0;
        }

        *k = *k - 1;
        *i = *i - 1;
        Times(pierwsza, liczbaB, wynik, &(*carry), &(*k), &(*i));
    }
}

void KonkatenacjaZera(string* stringA, int* licznik){

    if(*licznik <= 0){

    }
    else{
        *stringA = *stringA + "0";
        *licznik = *licznik - 1;
        KonkatenacjaZera(&(*stringA), &(*licznik));
    }
}

void Mnozenie(string pierwsza, string druga, string* suma, char* wynik, int MAX, int* przesuniecie, int* j){

    int liczbaB;
    int i = pierwsza.length() - 1;
    int k = MAX - 1;
    int carry = 0;
    int licznik = 0;

    string stringA = "";
    string napisy[2];

    if(*j < 0){
        //koniec rekurencji druga liczba sie skonczyla
    }
    else{

        liczbaB = druga[*j] - '0';

        if(liczbaB == 0){

        }
        else{
            Times(pierwsza, liczbaB, wynik, &carry, &k, &i);
            ScrollArray(wynik, &stringA, (MAX - 1), &licznik);

            if((*suma)[0] == '-'){
                stringA = "-" + stringA;

                licznik = *przesuniecie;
                KonkatenacjaZera(&stringA, &licznik);

                napisy[0] = stringA;
                napisy[1] = *suma;
                *suma = "-";
            }
            else{

                licznik = *przesuniecie;
                KonkatenacjaZera(&stringA, &licznik);

                napisy[0] = stringA;
                napisy[1] = *suma;
                *suma = "";
            }

            licznik = 0;

            DodajemyDwa(2, napisy, &(*suma), &licznik);
        }

        *j = *j - 1;
        *przesuniecie = *przesuniecie + 1;
        Mnozenie(pierwsza, druga, &(*suma), wynik, MAX, &(*przesuniecie), &(*j));
    }
}

void GoOn(int ilosc, const string* liczby, string* suma, int* i){

    int licznik = 0;
    string wPierwsza = "";
    string wDruga = "";

    bool NieZero = false;
    bool Ujemna = false;

    int tenSamZnak = 0;
    int MAX;
    int min;
    int FirstLength;
    int SecondLength;
    int FirstIterator;
    int SecondIterator;
    int k;
    int carry = 0;
    int Comparison;

    int przesuniecie = 0;

    
    if(*i >= ilosc){
        //koniec rekurencji
    }
    else{
        string pierwsza = *suma;
        string druga = *(liczby + *i);

        SetupString(pierwsza, &wPierwsza, pierwsza.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = Ujemna;
        NieZero = Ujemna = false;
        licznik = 0;
        SetupString(druga, &wDruga, druga.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = tenSamZnak + Ujemna;   //jak maja ten sam to bedzie 0 lub 2, jak bedzie 1 to dwa rozne znaki

        licznik = 0;
        FirstLength = wPierwsza.length();
        SecondLength = wDruga.length();

        *suma = "";

        char wynik[FirstLength + SecondLength];

        //cout << (FirstLength + SecondLength) << endl;

        

        if(FirstLength >= SecondLength){
            MAX = FirstLength;
            min = SecondLength;
        }
        else{
            MAX = SecondLength;
            min = FirstLength;
        }

        SecondIterator = min - 1;


        if((wPierwsza == "0") || (wDruga == "0")){
            *suma = "0";
        }
        else if((wPierwsza == "") || (wDruga == "")){
            *suma = "";
        }
        else{

            Comparison = Compare(wPierwsza, wDruga);

            if(tenSamZnak == 1){
                //dwa rozne znaki wiec -
                *suma = "-";

                if((Comparison == 1) || (Comparison == 0)){    //pierwsza wieksza od drugiej
                
                    Mnozenie(wPierwsza, wDruga, &(*suma), wynik, (FirstLength + SecondLength), &przesuniecie, &SecondIterator);
                    //jako pierwszy argument podajemy zawsze wiekszy string

                }
                else if(Comparison == -1){  //druga wieksza od pierwszej
                    
                    Mnozenie(wDruga, wPierwsza, &(*suma), wynik, (FirstLength + SecondLength), &przesuniecie, &SecondIterator);
                }
            }
            else{
                //plus
                if((Comparison == 1) || (Comparison == 0)){    //pierwsza wieksza od drugiej
                
                    Mnozenie(wPierwsza, wDruga, &(*suma), wynik, (FirstLength + SecondLength), &przesuniecie, &SecondIterator);
                    //jako pierwszy argument podajemy zawsze wiekszy string

                }
                else if(Comparison == -1){  //druga wieksza od pierwszej
                    
                    Mnozenie(wDruga, wPierwsza, &(*suma), wynik, (FirstLength + SecondLength), &przesuniecie, &SecondIterator);
                }
            }
        }
        // for(int i = 0; i < (FirstLength + SecondLength); i++){
        //     cout << wynik[i];
        // }
        // cout << endl;
        // cout << *suma << endl;

        *i = *i + 1;
        GoOn(ilosc, liczby, &(*suma), &(*i));
    }
}


void Add2(va_list args, string* liczby, string* suma, int* i, int ilosc){    //chyba dziala

    if(*i >= ilosc){
        //koniec rekurencji
        int licznik = 0;

        *suma = liczby[0];
        licznik = licznik + 1;

        GoOn(ilosc, liczby, &(*suma), &licznik);
    }
    else{
        liczby[*i] = va_arg(args, char*);
        *i = *i + 1;

        Add2(args, liczby, &(*suma), &(*i), ilosc);
    }
}

string Mult (int ilosc, const string* liczby){

    int i = 1;
    string suma = "";

    suma = liczby[0];

    GoOn(ilosc, liczby, &suma, &i);

    return suma;
}

string Mult (int ilosc, ...){

    int i = 0;
    string suma = "";

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add2(args, liczby, &suma, &i, ilosc);
   
    va_end(args);

    return suma;
}

void Mult (string* suma, int ilosc, const string* liczby){  //zle

    int i = 0;

    *suma = liczby[0];
    i = i + 1;

    GoOn(ilosc, liczby, &(*suma), &i);
}

void Mult (string* suma, int ilosc, ...){

    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add2(args, liczby, &(*suma), &i, ilosc);
   
    va_end(args);
}

void Mult (string& suma, int ilosc, const string* liczby){  //zle

    int i = 0;

    suma = liczby[0];
    i = i + 1;

    GoOn(ilosc, liczby, &suma, &i);
}

void Mult (string& suma, int ilosc, ...){       

    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add2(args, liczby, &suma, &i, ilosc);
   
    va_end(args);
}