//Tomasz Jarzabek

#include <string>
#include <cstdarg>

using namespace std;

void ScrollArray(char* wynik, string* suma, int MAX, int* licznik){

    if(*licznik > MAX){
        //koniec rekurencji
    }
    else{

        *suma = *suma + wynik[*licznik];
        *licznik = *licznik + 1;
        ScrollArray(wynik, &(*suma), MAX, &(*licznik));
    }
}

void Scroll(string A, string B, int* i, int* ktora){    //1 A wieksze, -1 B wieksze, 0 rowne

    if(*i >= A.length()){

    }
    else{
        if(A[*i] > B[*i]){
            *ktora = 1;
        }
        else if(A[*i] < B[*i]){
            *ktora = -1;
        }
        else{
            *i = *i + 1;
            Scroll(A, B, &(*i), &(*ktora));
        }
    }
}

int Compare(string A, string B){    //porownywanie bez znaku

    int Adlugosc = A.length();
    int Bdlugosc = B.length();

    if(Adlugosc > Bdlugosc){
        return 1;
    }
    else if(Bdlugosc > Adlugosc){
        return -1;
    }
    else{
        int i = 0;
        int ktora = 0;
        Scroll(A, B, &i, &ktora);

        return ktora;
    }
}

void SetupString(string liczba, string* wynik, int dlugosc, int* i, bool* NieZero, bool* ujemna){

    if(*i >= dlugosc){

    }
    else{
        //najpierw wszystkie przypadki ktore skipujemy przy formatowaniu
        if(liczba[*i] == '+'){

        }
        else{
            if(liczba[*i] == '-'){
                *ujemna = true;
            }
            else{
                if(liczba[*i] == '0' && (*i == (liczba.length() - 1))){
                    *wynik = *wynik + liczba[*i];
                }
                else{
                    if(liczba[*i] == '0' && (*NieZero == false)){

                    }
                    
                    else{
                        *NieZero = true;
                        *wynik = *wynik + liczba[*i];
                    }
                }
            }
        }

        *i = *i + 1;
        SetupString(liczba, &(*wynik), dlugosc, &(*i), &(*NieZero), &(*ujemna));
    }
}

void SameSign(string pierwsza, string druga, string* suma, char* wynik, int MAX, int* k, int* i, int* j, int tenSamZnak, int* carry){ 
    //tu wchodzimy po tym jak w juz wykonalismy setup string i wiemy ze maja ten sam znak
    //dla ujemnych dziala tak samo wystarczy pamietac ze sa ujemne
                                                                        
    //jak tenSamZnak == 0 to oba dodatnie, jak == 1 oba ujemne bedzie ujemne                                     

    int liczbaA;
    int liczbaB;
    int somma;

    if(*k >= 0){

        if(*k == MAX){
            //pierwsza iteracja petli ustawiamy znak wyjscia
            if(tenSamZnak == 2){
                *suma = *suma + '-';
            }
        }
        
        liczbaA = 0;
        liczbaB = 0;

        if(*i >= 0){
            liczbaA = pierwsza[*i] -  '0';                       //zeby z ASCII otrzymac liczbe, '0' to pierwsza liczba ich kody sa po kolei
            *i = *i - 1;
        }
        else{
            liczbaA = 0;
        }
        if(*j >= 0){
            liczbaB = druga[*j] - '0';
            *j = *j - 1;
        }
        else{
            liczbaB = 0;
        }

        somma = liczbaA + liczbaB;

        wynik[*k] = ((somma + *carry) % 10) + '0';                 //z liczby otrzymujamy char
        
        if((somma + *carry) >= 10){
            *carry = 1;  //attenzione
        }
        else{
            *carry = 0;
        }
        
        *k = *k - 1;
        SameSign(pierwsza, druga, &(*suma), wynik, MAX, &(*k), &(*i), &(*j), tenSamZnak, &(*carry));
    }
    else{
        //koniec rekurencji
        //dopisujemy wszystko do sumy
        int licznik = 0;
        ScrollArray(wynik, &(*suma), MAX, &licznik);
    }
}
//sprawdzamy ktora jest wiekza w dodajemy dwa tam ustawiamy juz znak,
void DifferentSign(string pierwsza, string druga, string* suma, char* wynik, int* carry, int MAX, int min, int* k, int* i, int* j){

                     
    int liczbaA;
    int liczbaB;
    int somma;

    if(*k < MAX){

        liczbaA = 0;
        liczbaB = 0;

        if(*k < MAX){
            liczbaA = pierwsza[pierwsza.length() - 1 - *k] -  '0';                       //zeby z ASCII otrzymac liczbe, '0' to pierwsza liczba ich kody sa po kolei
            
            liczbaA = liczbaA - *carry;
            if(liczbaA > 0){
                *carry = 0;
            }
        }
        if(*j < min){
            liczbaB = druga[druga.length() - 1 - *j] - '0';
            *j = *j + 1;
        }
        else{
            liczbaB = 0;
        }

        if((liczbaA - liczbaB) < 0){
            *carry = 1;      //pozyczamy z przodu
            somma = 10 + (liczbaA - liczbaB);
        }
        else{
            somma = liczbaA - liczbaB;
        }

        wynik[MAX - 1 - *k] = (somma % 10) + '0';
 
        *k = *k + 1;

        DifferentSign(pierwsza, druga, &(*suma), wynik, &(*carry), MAX, min, &(*k), &(*i), &(*j));
    }
    else{
        //koniec rekurencji

        int licznik = 0;
        ScrollArray(wynik, &(*suma), (MAX - 1), &licznik);
        //wyjscie ma dodatkowe zera
    }
}

void DodajemyDwa(int ilosc, const string* liczby, string* suma, int* i){

    string wPierwsza = "";
    string wDruga = "";

    bool NieZero = false;
    bool Ujemna = false;
    int licznik = 0;

    int tenSamZnak = 0;
    int MAX;
    int min;
    int FirstLength;
    int SecondLength;
    int FirstIterator;
    int SecondIterator;
    int k;

    bool pUjemna;
    bool dUjemna;
    int Comparison;
    int roznica = 0;
    int carry = 0;

    if(*i >= ilosc){
        //koniec rekurencji
        string wynik = "";

        SetupString(*suma, &wynik, (*suma).length(), &licznik, &NieZero, &Ujemna);
        if(Ujemna){
            *suma = "-" + wynik;
        }
        else{
            *suma = wynik;
        }
    }
    else if(*i == 0){
        string pierwsza = *(liczby + *i);
        string druga = *(liczby + (*i + 1));

        SetupString(pierwsza, &wPierwsza, pierwsza.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = Ujemna;
        NieZero = Ujemna = false;
        licznik = 0;
        SetupString(druga, &wDruga, druga.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = tenSamZnak + Ujemna;   //jak maja ten sam to bedzie 0 lub 2, jak bedzie 1 to dwa rozne znaki

        // cout << wPierwsza << endl;
        // cout << wDruga << endl;

        licznik = 0;
        FirstLength = wPierwsza.length();
        SecondLength = wDruga.length();
        FirstIterator = FirstLength - 1;
        SecondIterator = SecondLength - 1;

        if(tenSamZnak == 1){

            k = 0;
            FirstIterator = 0;
            SecondIterator = 0;

            if(pierwsza[0] == '-'){
                pUjemna = true;
            }
            else{
                pUjemna = false;
            }

            if(druga[0] == '-'){
                dUjemna = true;
            }
            else{
                dUjemna = false;
            }

            if(FirstLength >= SecondLength){
                MAX = FirstLength;
                min = SecondLength;
                roznica = FirstLength - SecondLength;
            }
            else{
                MAX = SecondLength;
                min = FirstLength;
                roznica = SecondLength - FirstLength;
            }

            Comparison = Compare(wPierwsza, wDruga);

            char wynik[MAX];

            if(Comparison == 1){    //pierwsza wieksza od drugiej
                if(pUjemna){
                    *suma = *suma + '-';  //wynik wyjdzie ujemny
                }
                else{
                    //min = min - 1;
                }

                if(dUjemna){
                    
                }
                else{
                    //MAX = MAX - 1;
                }

                DifferentSign(wPierwsza, wDruga, &(*suma), wynik, &carry, MAX, min, &k, &FirstIterator, &SecondIterator);
                //jako pierwszy argument podajemy zawsze wiekszy string

            }
            else if(Comparison == -1){  //druga wieksza od pierwszej
                if(dUjemna){
                    *suma = *suma + '-';  //wynik wyjdzie ujemny
                }
                else{
                    //min = min - 1;
                }

                if(pUjemna){

                }
                else{
                    //MAX = MAX - 1;
                }

                DifferentSign(wDruga, wPierwsza, &(*suma), wynik, &carry, MAX, min, &k, &FirstIterator, &SecondIterator);
            }
            else if (Comparison == 0){  //sa rowne wynik 0
                *suma = "0";
            }
        }
        else{

            if((wPierwsza == "0") && (wDruga == "0") && (tenSamZnak == 2)){
                *suma = "0";
            }
            else{

                if(SecondLength >= FirstLength){
                    MAX = SecondLength;
                }
                else{
                    MAX = FirstLength;
                }

                k = MAX;

                char wynik[MAX + 1];

                SameSign(wPierwsza, wDruga, &(*suma), wynik, MAX, &k, &FirstIterator, &SecondIterator, tenSamZnak, &carry);        
                //come ci ricordiamo di che segno è il risultato per la prossima operazione?
            }
        }

        *i = *i + 2;
        DodajemyDwa(ilosc, liczby, &(*suma), &(*i));
    }
    else{
        //na koniec trzeba to jeszcze przeformatowac
        //teraz dodajemy po jednym z tablicy
        string pierwsza = *suma;
        string druga = *(liczby + (*i));

        SetupString(pierwsza, &wPierwsza, pierwsza.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = Ujemna;
        NieZero = Ujemna = false;
        licznik = 0;
        SetupString(druga, &wDruga, druga.length(), &licznik, &NieZero, &Ujemna);
        tenSamZnak = tenSamZnak + Ujemna;   //jak maja ten sam to bedzie 0 lub 2, jak bedzie 1 to dwa rozne znaki

        licznik = 0;
        FirstLength = wPierwsza.length();
        SecondLength = wDruga.length();
        FirstIterator = FirstLength - 1;
        SecondIterator = SecondLength - 1;

        if(tenSamZnak == 1){

            *suma = "";

            k = 0;
            FirstIterator = 0;
            SecondIterator = 0;

            if(pierwsza[0] == '-'){
                pUjemna = true;
            }
            else{
                pUjemna = false;
            }

            if(druga[0] == '-'){
                dUjemna = true;
            }
            else{
                dUjemna = false;
            }

            if(FirstLength >= SecondLength){
                MAX = FirstLength;
                min = SecondLength;
                roznica = FirstLength - SecondLength;
            }
            else{
                MAX = SecondLength;
                min = FirstLength;
                roznica = SecondLength - FirstLength;
            }

            Comparison = Compare(wPierwsza, wDruga);

            char wynik[MAX];

            if(Comparison == 1){    //pierwsza wieksza od drugiej
                if(pUjemna){
                    *suma = *suma + '-';  //wynik wyjdzie ujemny
                }
                else{
                    //min = min - 1;
                }

                if(dUjemna){
                    
                }
                else{
                    //MAX = MAX - 1;
                }

                DifferentSign(wPierwsza, wDruga, &(*suma), wynik, &carry, MAX, min, &k, &FirstIterator, &SecondIterator);
                //jako pierwszy argument podajemy zawsze wiekszy string

            }
            else if(Comparison == -1){  //druga wieksza od pierwszej
                if(dUjemna){
                    *suma = *suma + '-';  //wynik wyjdzie ujemny
                }
                else{
                    //min = min - 1;
                }

                if(pUjemna){

                }
                else{
                    //MAX = MAX - 1;
                }

                DifferentSign(wDruga, wPierwsza, &(*suma), wynik, &carry, MAX, min, &k, &FirstIterator, &SecondIterator);
            }
            else if (Comparison == 0){  //sa rowne wynik 0
                *suma = "0";
            }
        }
        else{

            if((wPierwsza == "0") && (wDruga == "0") && (tenSamZnak == 2)){
                *suma = "0";
            }
            else{

                if(SecondLength >= FirstLength){
                    MAX = SecondLength;
                }
                else{
                    MAX = FirstLength;
                }

                k = MAX;

                char wynik[MAX + 1];

                *suma = "";

                SameSign(wPierwsza, wDruga, &(*suma), wynik, MAX, &k, &FirstIterator, &SecondIterator, tenSamZnak, &carry);        
                //come ci ricordiamo di che segno è il risultato per la prossima operazione?
            }
        }

        *i = *i + 1;
        DodajemyDwa(ilosc, liczby, &(*suma), &(*i));
    }
}

string Sum (int ilosc, const string* liczby){       //chyba dziala

    int i = 0;
    string suma = "";
    
    DodajemyDwa(ilosc, liczby, &suma, &i);

    return suma;
}

void Add(va_list args, string* liczby, string* suma, int* i, int ilosc){    //chyba dziala

    if(*i >= ilosc){
        //koniec rekurencji
        int licznik = 0;
        DodajemyDwa(ilosc, liczby, &(*suma), &licznik);
    }
    else{
        liczby[*i] = va_arg(args, char*);
        *i = *i + 1;

        Add(args, liczby, &(*suma), &(*i), ilosc);
    }
}

string Sum (int ilosc, ...){        //chyba dziala

    int i = 0;
    string suma = "";

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add(args, liczby, &suma, &i, ilosc);
   
    va_end(args);

    return suma;
}

void Sum (string* suma, int ilosc, const string* liczby){       //chyba dziala

    int i = 0;

    *suma = "";
    
    DodajemyDwa(ilosc, liczby, &(*suma), &i);
}

void Sum (string* suma, int ilosc, ...){

    *suma = "";

    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add(args, liczby, &(*suma), &i, ilosc);
   
    va_end(args);
}

void Sum (string& suma, int ilosc, const string* liczby){

    suma = "";

    int i = 0;
    
    DodajemyDwa(ilosc, liczby, &suma, &i);
}

void Sum (string& suma, int ilosc, ...){

    suma = "";

    int i = 0;

    va_list args;
    va_start(args, ilosc);

    string liczby[ilosc];

    Add(args, liczby, &suma, &i, ilosc);
   
    va_end(args);
}