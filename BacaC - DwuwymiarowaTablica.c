//Tomasz Jarzabek

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//zakaz kwadratowych, uzywamy arytmetyki wskaznikow

void ShortPushBack(unsigned short** dlugosci, unsigned short wiersze, unsigned short ilosc){

    int i;

    if(wiersze == 1){
        *(*dlugosci + 0) = ilosc;
        //printf("dziala1\n");
    }
    else{
        for(i = (wiersze - 1); i > 0; i--){
            if(i == 1){
                *(*dlugosci + i) = *(*dlugosci + 0);
                *(*dlugosci + 0) = ilosc;
                //printf("dziala2\n");
            }
            else{
                *(*dlugosci + i) = *(*dlugosci + (i - 1));
            }
        }
    }
}

void ShortPushBack3(unsigned short** dlugosci, unsigned short wiersze, unsigned short ilosc, int odTad){ //argument domyslny zeby uzywac w roznych przypadkach

    int i;

    if(wiersze == 1){
        *(*dlugosci + 0) = ilosc;
        //printf("dziala1\n");
    }
    else{
        for(i = (wiersze - 1); i > odTad; i--){
            if(i == (odTad + 1)){
                *(*dlugosci + i) = *(*dlugosci + odTad);
                *(*dlugosci + odTad) = ilosc;
                //printf("dziala2\n");
            }
            else{
                *(*dlugosci + i) = *(*dlugosci + (i - 1));
            }
        }
    }
}

void ShortPushBack2(int*** tablica, unsigned short wiersze){
    
    int i;

    if(wiersze == 1){
        //printf("dziala2\n");
    }
    else{
        for(i = (wiersze - 1); i > 0; i--){
          
            if(i == 0){

            }
            else{
                *(*tablica + i) = *(*tablica + (i - 1));
            }
        }
    }
}

void ShortPushBack4(int*** tablica, unsigned short wiersze, int odTad, int ilosc){  //no leaks its ok
    
    int i;
    int* temp;

    if(wiersze == 1){
        //printf("dziala2\n");
    }
    else{
        for(i = (wiersze - 1); i > odTad; i--){

            if(i == (odTad + 1)){
                *(*tablica + i) = *(*tablica + odTad);
                *(*tablica + odTad) = (int*)malloc(ilosc * sizeof(int));
            }
            else{
                *(*tablica + i) = *(*tablica + (i - 1));
            }
        }
    }
}

void IntPushBack(int** wiersz, unsigned short dlugosc, int liczba){

    int i;

    for(i = (dlugosc - 1); i > 0; i--){
        if(i == 1){
            *(*wiersz + i) = *(*wiersz + 0);
            *(*wiersz + 0) = liczba;
        }
        else{
            *(*wiersz + i) = *(*wiersz + (i - 1));
        }
    }
}

void IntPushBackOdTad(int** wiersz, unsigned short dlugosc, int liczba, int odTad){

    int i;

    for(i = (dlugosc - 1); i > odTad; i--){
        if(i == (odTad + 1)){
            *(*wiersz + i) = *(*wiersz + odTad);
            *(*wiersz + odTad) = liczba;
        }
        else{
            *(*wiersz + i) = *(*wiersz + (i - 1));
        }
    }
}

void RemoveLine(int*** tablica, unsigned short wiersze, int ktory){

    int i;
    int* temp;

    for(i = ktory; i < wiersze; i++){

        if(i == ktory){
            temp = *(*tablica + i);
            *(*tablica + i) = *(*tablica + (i + 1));
        }
        else if(i == (wiersze - 1)){

        }
        else{
            *(*tablica + i) = *(*tablica + (i + 1));
        }
    }
    
    if(temp != NULL){
        free(temp);
    }
}

void RemoveLength(unsigned short** dlugosci, unsigned short wiersze, int ktory){

    int i;

    for(i = ktory; i < wiersze; i++){
        if(i == (wiersze - 1)){
            *(*dlugosci + i) = 0;
        }
        else{
            *(*dlugosci + i) = *(*dlugosci + (i + 1));
        }
    }
}

void RemoveOne(int** tablica, unsigned short dlugosc, int ktory){

    int i;

    for(i = ktory; i < dlugosc; i++){

        if(i == (dlugosc - 1)){
            *(*tablica + i) = 0;
        }
        else{
            *(*tablica + i) = *(*tablica + (i + 1));
        }
    }
}

void ISB(int*** tablica, unsigned short** dlugosci, unsigned short* wiersze, int numerWiersza, int numerKolumny, int iloscWierszy, int iloscKolumn){

    int pozycja;
    int liczba;
    int k = 0;
    int i = 0;
    int j = 0;

    for(i = 0; i < iloscWierszy; i++){

        pozycja = numerWiersza + i;
        //printf("Pozycja: %d \n", pozycja);

        if(pozycja < *wiersze){
            //jestesmy dalej w zakresie tablicy dodajemy elementy do kolumn
            //nie musimy dodawac wierszy bo juz sa
            if(numerKolumny >= *(*dlugosci + pozycja)){
                //printf("Wchodzi2\n");
                //dodajemy elementy na koniec bo numer kolumny poza zakresem
                for(j = 0; j < iloscKolumn; j++){

                    scanf("%i", &liczba);

                    *(*dlugosci + pozycja) = *(*dlugosci + pozycja) + 1; //inkrementujemy dlugosc wiersza
                    *(*tablica + pozycja) = (int*)realloc(*(*tablica + pozycja), *(*dlugosci + pozycja) * sizeof(int));

                    *(*(*tablica + pozycja) + (*(*dlugosci + pozycja) - 1)) = liczba;
                }
            }
            else{
                //printf("wchodzi \n");
                for(j = 0; j < iloscKolumn; j++){

                    scanf("%i", &liczba);

                    *(*dlugosci + pozycja) = *(*dlugosci + pozycja) + 1; //inkrementujemy dlugosc bo wstawiamy elementy
                    *(*tablica + pozycja) = (int*)realloc(*(*tablica + pozycja), *(*dlugosci + pozycja) * sizeof(int));
                    IntPushBackOdTad(&(*(*tablica + pozycja)), *(*dlugosci + pozycja), liczba, (numerKolumny + j));
                }
            }
        }
        else{
            //printf("Wchodzi 3 \n");
            //poza tablica trzeba dodawac nowe wiersze
            *wiersze = *wiersze + 1; //dodajemy wiersz wiec inkrementujemy zmienna

            //dodajemy wiersz o dlugosci ilosc wiec idzie tez do tablicy dlugosci
            *dlugosci = (unsigned short*)realloc(*dlugosci, (*wiersze * sizeof(unsigned short)));
            *(*dlugosci + (*wiersze - 1)) = iloscKolumn;

            //nie potrzebujemy push back bo dodajemy na koniec

            *tablica = (int**)realloc(*tablica, (*wiersze * sizeof(int*)));
            *(*tablica + (*wiersze - 1)) = (int*)malloc((iloscKolumn * sizeof(int)));

            for(k = 0; k < iloscKolumn; k++){

                scanf("%i", &liczba);
                *(*(*tablica + (*wiersze - 1)) + k) = liczba;
            }
        }
    }
}

void RMB(int*** tablica, unsigned short** dlugosci, unsigned short* wiersze, int numerWiersza, int numerKolumny, int iloscWierszy, int iloscKolumn){
    
    int i = 0;
    int j = 0;
    int pozycja = 0;
    int miejsce = 0;
    int startLength = 0;
    int licznik = 0;
    int licznikKolumn = 0;

    for(i = 0; i < iloscWierszy; i++){

        if(*wiersze == 0){
            if(*tablica != NULL){
                free(*tablica);
                *tablica = NULL;
            }
            
            break;
        }

        pozycja = numerWiersza + licznik;

        if(pozycja < *wiersze){
            //wiersz istnieje mozna odejmowac
            if(numerKolumny >= *(*dlugosci + pozycja)){
                //poza zakresem wiersza nic nie odejmujemy
            }
            else{
                //poprawny zakres
                startLength = *(*dlugosci + pozycja);

                for(j = 0; j < iloscKolumn; j++){
                    miejsce = numerKolumny + licznikKolumn;

                    if(miejsce < *(*dlugosci + pozycja)){
                        //printf("wchodzi3\n");
                        //w zakresie wiersza
                        if(*(*dlugosci + pozycja) > 1){
                            //printf("wchodzi\n");
                            RemoveOne(&(*(*tablica + pozycja)), *(*dlugosci + pozycja), miejsce);
                            *(*dlugosci + pozycja) = *(*dlugosci + pozycja) - 1;
                            licznikKolumn = licznikKolumn - 1;
                        }
                        else{
                            //wiersz za krotki trzeba go skasowac
                            //printf("wchodzi2\n");
                            RemoveLength(&(*dlugosci), *wiersze, pozycja);
                            RemoveLine(&(*tablica), *wiersze, pozycja);

                            *wiersze = *wiersze - 1;
                            licznik = licznik - 1;
                            j = iloscKolumn;
                        }
                    }

                    licznikKolumn = licznikKolumn + 1;
                }
            }
        }
        else{
            //jestesmy poza nic nie robimy
        }

        licznik = licznik + 1;
        licznikKolumn = 0;
    }
}

int main(){

    char* wybor;
    char* nazwa;
    char znak;

    int i = 0;
    int j = 0;
    int hWierszy = 0;

    unsigned short wiersze = 0; //ilosc wierszy, normalna zmienna

    unsigned short* dlugosci = NULL;
    int** tablica = NULL;

    unsigned short ilosc;
    int liczba;

    int numerWiersza;
    int numerKolumny;
    int iloscWierszy;
    int iloscKolumn;

    int numerWiersza2;
    int numerKolumny2;
    int wartosc;

    int startRows;

    unsigned short zamieniony;
    int poSwapie;

    //osobna tablica do dlugosci
    //ilosc wierszow to tylko normalna zmienna

    do{  //0 jesli rowne

        i = 0;
        j = 0;
        ilosc = 0;
        liczba = 0;
        
        wybor = (char*)calloc(4, sizeof(char));

        scanf("%s", wybor);

        if(!strcmp(wybor, "AFR")){   //niepusty wiersz na poczatek

            scanf("%hi", &ilosc);

            wiersze = wiersze + 1; //dodajemy wiersz wiec inkrementujemy zmienna

            //dodajemy wiersz o dlugosci ilosc wiec idzie tez do tablicy dlugosci
            dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));
            ShortPushBack(&dlugosci, wiersze, ilosc);
            
            
            tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
            ShortPushBack2(&tablica, wiersze);
            
            *(tablica + i) = (int*)malloc((*(dlugosci + i) * sizeof(int)));

            for(i = 0; i < ilosc; i++){

                scanf("%i", &liczba);
                *(*(tablica + 0) + i) = liczba;
                //printf("dziala i: %d\n", i);
            }
        }
        else if(!strcmp(wybor, "ALR")){  //niepusty wiersz na koniecth

            scanf("%hi", &ilosc);

            wiersze = wiersze + 1; //dodajemy wiersz wiec inkrementujemy zmienna

            //dodajemy wiersz o dlugosci ilosc wiec idzie tez do tablicy dlugosci
            dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));
            *(dlugosci + (wiersze - 1)) = ilosc;

            //nie potrzebujemy push back bo dodajemy na koniec

            tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
            *(tablica + (wiersze - 1)) = (int*)malloc((ilosc * sizeof(int)));

            for(i = 0; i < ilosc; i++){

                scanf("%i", &liczba);
                *(*(tablica + (wiersze - 1)) + i) = liczba;
            }
        }
        else if(!strcmp(wybor, "AFC")){  //dodaje kolumne na poczatek do h pierwszych wierszy

            scanf("%i", &hWierszy);

            if(hWierszy > 0){

                for(i = 0; i < hWierszy; i++){

                    scanf("%i", &liczba);

                    if(i < wiersze){
                        *(dlugosci + i) = *(dlugosci + i) + 1; //dlugosc wiersza inkrementujemy
                        *(tablica + i) = (int*)realloc(*(tablica + i), (*(dlugosci + i) * sizeof(int)));    //powiekszamy tablice
                        IntPushBack(&(*(tablica + i)), *(dlugosci + i), liczba);
                    }
                    else{
                        //dodajemy nastepne wiersze
                        wiersze = wiersze + 1;
                        dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));
                        *(dlugosci + (wiersze - 1)) = 1;

                        tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
                        *(tablica + (wiersze - 1)) = (int*)malloc(1 * sizeof(int));   //nowy wiersz mozemy malloc

                        *(*(tablica + (wiersze - 1)) + 0) = liczba;
                    }
                    
                }

            }
        }
        else if(!strcmp(wybor, "ALC")){     //dodaje kolumne na koniec do h pierwszych wierszy

            scanf("%i", &hWierszy);

            if(hWierszy > 0){

                for(i = 0; i < hWierszy; i++){

                    scanf("%i", &liczba);

                    if(i < wiersze){
                        *(dlugosci + i) = *(dlugosci + i) + 1; //dlugosc wiersza inkrementujemy
                        *(tablica + i) = (int*)realloc(*(tablica + i), (*(dlugosci + i) * sizeof(int)));    //powiekszamy tablice
                        *(*(tablica + i) + *(dlugosci + i) - 1) = liczba;
                    }
                    else{
                        //dodajemy nastepne wiersze
                        wiersze = wiersze + 1;
                        dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));
                        *(dlugosci + (wiersze - 1)) = 1;

                        tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
                        *(tablica + (wiersze - 1)) = (int*)malloc(1 * sizeof(int));   //nowy wiersz mozemy malloc

                        *(*(tablica + (wiersze - 1)) + 0) = liczba;
                    }
                    
                }

            }

        }
        else if(!strcmp(wybor, "IBR")){     //przed wierszem o numerze r wstaw wiersz

            scanf("%d", &numerWiersza);

            if(numerWiersza >= 0){
                if(numerWiersza < wiersze){
                    //poprawany numer dzialamy
                    scanf("%hi", &ilosc);

                    wiersze = wiersze + 1; //dodajemy wiersz wiec inkrementujemy zmienna

                    //dodajemy wiersz o dlugosci ilosc wiec idzie tez do tablicy dlugosci
                    dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));
                    ShortPushBack3(&dlugosci, wiersze, ilosc, numerWiersza);
                    *(dlugosci + numerWiersza) = ilosc;

                    tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
                    *(tablica + (wiersze - 1)) = (int*)malloc((*(dlugosci + (wiersze - 1)) * sizeof(int)));
                    ShortPushBack4(&tablica, wiersze, numerWiersza, ilosc);

                    for(i = 0; i < ilosc; i++){

                        scanf("%i", &liczba);
                        *(*(tablica + numerWiersza) + i) = liczba;
                    }
                }
            }
        }
        else if(!strcmp(wybor, "IAR")){     //po wierszu wstaw nowy

             scanf("%d", &numerWiersza);

            if(numerWiersza >= 0){
                if(numerWiersza < wiersze){
                    
                    //poprawany numer dzialamy
                    scanf("%hi", &ilosc);

                    wiersze = wiersze + 1; //dodajemy wiersz wiec inkrementujemy zmienna

                    //dodajemy wiersz o dlugosci ilosc wiec idzie tez do tablicy dlugosci
                    dlugosci = (unsigned short*)realloc(dlugosci, (wiersze * sizeof(unsigned short)));

                    if((numerWiersza + 1) == (wiersze - 1)){

                        *(dlugosci + (wiersze - 1)) = ilosc;
                    }
                    else{
                        ShortPushBack3(&dlugosci, wiersze, ilosc, (numerWiersza + 1));
                        *(dlugosci + (numerWiersza + 1)) = ilosc;
                    }
                    

                    tablica = (int**)realloc(tablica, (wiersze * sizeof(int*)));
                    *(tablica + (wiersze - 1)) = (int*)malloc((*(dlugosci + (wiersze - 1)) * sizeof(int)));

                    if((numerWiersza + 1) == (wiersze - 1)){

                    }
                    else{
                        ShortPushBack4(&tablica, wiersze, (numerWiersza + 1), ilosc);
                    }

                    for(i = 0; i < ilosc; i++){

                        scanf("%i", &liczba);
                        *(*(tablica + (numerWiersza + 1)) + i) = liczba;
                    }
                }
            }

        }
        else if(!strcmp(wybor, "IBC")){ //w poczatkowych h wierszach przed kolumna c wstaw nowa kolumne
            
            scanf("%i", &numerKolumny);
            scanf("%i", &iloscWierszy);

            if(iloscWierszy > 0){
                

                if(numerKolumny >= 0){
                    
                    ISB(&tablica, &dlugosci, &wiersze, 0, numerKolumny, iloscWierszy, 1);
                }
            }

        }
        else if(!strcmp(wybor, "IAC")){     //w poczatkowych h wierszach po kolumnie c wstaw nowa kolumne

            scanf("%i", &numerKolumny);
            scanf("%i", &iloscWierszy);

            if(iloscWierszy > 0){
                
                if(numerKolumny >= 0){
                    
                    ISB(&tablica, &dlugosci, &wiersze, 0, (numerKolumny + 1), iloscWierszy, 1);
                }
            }
        }
        else if(!strcmp(wybor, "SWR")){     //zamnien wartosciami wiersze

            int* temp;
            unsigned short length;

            scanf("%i", &numerWiersza);
            scanf("%i", &numerWiersza2);

            if((numerWiersza >= 0) && (numerWiersza < wiersze)){
                if((numerWiersza2 >= 0) && (numerWiersza2 < wiersze)){

                    //najpierw zamieniamy wiersze
                    temp = *(tablica + numerWiersza);
                    *(tablica + numerWiersza) = *(tablica + numerWiersza2);
                    *(tablica + numerWiersza2) = temp;

                    //teraz zamieniamy dlugosci
                    length = *(dlugosci + numerWiersza);
                    *(dlugosci + numerWiersza) = *(dlugosci + numerWiersza2);
                    *(dlugosci + numerWiersza2) = length;
                }
            }
        }
        else if(!strcmp(wybor, "SWC")){     //zamiana wartosciami kolumn, jak wiersz nie ma tych kolumn to nic sie nie dzieje
            //we wszystkich wierszach mamy zamienic te elementy, oprocz tych w ktorych tych elementow nie ma
            scanf("%i", &numerKolumny);
            scanf("%i", &numerKolumny2);

            if((numerKolumny >= 0) && (numerKolumny2 >= 0)){

                for(i = 0; i < wiersze; i++){
                    if( (numerKolumny < *(dlugosci + i)) && (numerKolumny2 < *(dlugosci + i)) ){
                        wartosc = *(*(tablica + i) + numerKolumny);
                        *(*(tablica + i) + numerKolumny) = *(*(tablica + i) + numerKolumny2);
                        *(*(tablica + i) + numerKolumny2) = wartosc;
                    }
                }
            }
        }
        else if(!strcmp(wybor, "DFR")){

            if(tablica != NULL){
                RMB(&tablica, &dlugosci, &wiersze, 0, 0, 1, *(dlugosci + 0));
            }
        }
        else if(!strcmp(wybor, "DLR")){     //kasowanie ostatniego wiersza

            if(tablica != NULL){
                RMB(&tablica, &dlugosci, &wiersze, (wiersze - 1), 0, 1, *(dlugosci + (wiersze - 1)));
            }
        }
        else if(!strcmp(wybor, "DFC")){

            startRows = wiersze;

            if(tablica != NULL){
                for(i = 0; i < startRows; i++){
                    RMB(&tablica, &dlugosci, &wiersze, i, 0, 1, 1); //problem all elements are the same in a row

                    if(wiersze < startRows){
                        startRows = wiersze;
                        i--;
                    }
                }
            }
        }
        else if(!strcmp(wybor, "DLC")){

            startRows = wiersze;

            if(tablica != NULL){
                for(i = 0; i < startRows; i++){
                    RMB(&tablica, &dlugosci, &wiersze, i, (*(dlugosci + i) - 1), 1, 1);

                    if(wiersze < startRows){
                        startRows = wiersze;
                        i--;
                    }
                }
            }
        }
        else if(!strcmp(wybor, "RMR")){     //usun wiersz o numerze r

            scanf("%i", &numerWiersza);

            if((numerWiersza >= 0) && (numerWiersza < wiersze)){
                RMB(&tablica, &dlugosci, &wiersze, numerWiersza, 0, 1, *(dlugosci + numerWiersza));
            }

        }
        else if(!strcmp(wybor, "RMC")){     //ze wszytskich wierszy usuwamy kolumne c

            scanf("%i", &numerKolumny);

            if(numerKolumny >= 0){
                RMB(&tablica, &dlugosci, &wiersze, 0, numerKolumny, wiersze, 1);
            }

        }
        else if(!strcmp(wybor, "RMB")){ //usuwa blok od pewnego wiersza w pewnej ilosci i od pewnej kolumny w pewnej ilosci

            scanf("%i", &numerWiersza);

            if((numerWiersza >= 0) && (numerWiersza < wiersze)){
                scanf("%i", &iloscWierszy);
                scanf("%i", &numerKolumny);
                if(numerKolumny >= 0){
                    
                    scanf("%i", &iloscKolumn);

                    if((iloscWierszy > 0) && (iloscKolumn > 0)){
                        RMB(&tablica, &dlugosci, &wiersze, numerWiersza, numerKolumny, iloscWierszy, iloscKolumn);
                    }

                }
            }
        }
        else if(!strcmp(wybor, "ISB")){ //wstaw blok o h kolumnach i r wierszach do wierszy od r i kolumn od c

            scanf("%i", &numerWiersza);

            if(numerWiersza >= 0){
                scanf("%i", &numerKolumny);
                scanf("%i", &iloscWierszy);
                scanf("%i", &iloscKolumn);

                if((numerKolumny >= 0) && (iloscWierszy > 0) && (iloscKolumn > 0)){
                    ISB(&tablica, &dlugosci, &wiersze, numerWiersza, numerKolumny, iloscWierszy, iloscKolumn);
                }
            }

        }
        else if(!strcmp(wybor, "WRF")){     //do pliku o danej nazwie zapisuje

            nazwa = (char*)calloc(17, sizeof(char));

            scanf("%s", nazwa);

            FILE* plikWynikowy = fopen(nazwa, "wb");

            znak = '\n';
            
            fprintf(plikWynikowy, "%hu\n", wiersze);

            for(i = 0; i < wiersze; i++){

                zamieniony = (*(dlugosci + i) >> 8) | (*(dlugosci + i) << 8);   //konwersja na Big Endian
                fwrite(&zamieniony, sizeof(unsigned short), 1, plikWynikowy);
                
                for(j = 0; j < *(dlugosci + i); j++){
                    
                    poSwapie = (( *(*(tablica + i) + j) >> 24) & 0xff) | (( *(*(tablica + i) + j) << 8) & 0xff0000) | (( *(*(tablica + i) + j) >> 8) & 0xff00) | (( *(*(tablica + i) + j) << 24) & 0xff000000);
                    fwrite(&poSwapie, sizeof(int), 1, plikWynikowy);
                }
            }

            fclose(plikWynikowy);

            if(nazwa != NULL){
                free(nazwa);
            }
            
            nazwa = NULL;
        }
        else if(!strcmp(wybor, "RDF")){

            nazwa = (char*)calloc(17, sizeof(char));
            scanf("%s", nazwa);

            FILE* plikInput = fopen(nazwa, "rb");

            //zwalniamy pamiec starej tablicy, teraz wczyutjemy nowa
            
            if(dlugosci != NULL){
                free(dlugosci);
                dlugosci = NULL;
            }

            for(i = (wiersze - 1); i >= 0; i--){

                if(*(tablica + i) != NULL){
                    free(*(tablica + i));
                    *(tablica + i) = NULL;
                }
            }

            if(tablica != NULL){
                free(tablica);
                tablica = NULL;
            }
            
            wiersze = 0;
            
            fscanf(plikInput, "%hu", &wiersze);
            fread(&znak, sizeof(char), 1, plikInput);   //zczytujemy znak nowej linii

            dlugosci = (unsigned short*)malloc(wiersze * sizeof(unsigned short));
            tablica = (int**)malloc(wiersze * sizeof(int*));

            for(i = 0; i < wiersze; i++){
                fread(&zamieniony, sizeof(unsigned short), 1, plikInput);
                *(dlugosci + i) = (zamieniony >> 8) | (zamieniony << 8);

                *(tablica + i) = (int*)malloc((*(dlugosci + i) * sizeof(int)));

                for(j = 0; j < *(dlugosci + i); j++){

                    fread(&poSwapie, sizeof(int), 1, plikInput);
                    *(*(tablica + i) + j) = (( poSwapie >> 24) & 0xff) | (( poSwapie << 8) & 0xff0000) | (( poSwapie >> 8) & 0xff00) | (( poSwapie << 24) & 0xff000000);
                }
            }

            fclose(plikInput);

            if(nazwa != NULL){
                free(nazwa);
                nazwa = NULL;
            }
        }
        else if(!strcmp(wybor, "PRT")){ //print zawartosci

            if(tablica == NULL){
                printf("0\n");
            }
            else{
                printf("%d\n", wiersze);    //w pierwszej linii liczba wierszy
                //teraz zawartosc kazdego wiersza, liczba kolumn spacja elementy

                for(i = 0; i < wiersze; i++){

                    printf("%d ", *(dlugosci + i));

                    for(j = 0; j < *(dlugosci + i); j++){
                        
                        printf("%d ", *(*(tablica + i) + j));
                    }
                    printf("\n");
                }
            }
        }
        
    }while(strcmp(wybor, "END"));

    //zwalniamy pamiec przed koncem

    if(dlugosci != NULL){
        free(dlugosci);
        dlugosci = NULL;
    }

    for(i = (wiersze - 1); i >= 0; i--){

        if(*(tablica + i) != NULL){
            free(*(tablica + i));
            *(tablica + i) = NULL;
        }
    }


    if(tablica != NULL){
        free(tablica);
        tablica = NULL;
    }
    if(wybor != NULL){
        free(wybor);
        wybor = NULL;
    }

    return 0;
}

/*
testy

AFR 3 1 2 3
PRT
END

ALR 3 1 2 3
ALR 3 4 5 6
PRT

ALR 3 1 2 3
AFR 4 5 6 7 8
AFC 3 1 1 1
IBR 0 3 9 9 9
PRT

ALR 3 1 2 3
AFR 4 5 6 7 8
AFC 3 1 1 1
IBR 0 3 9 9 9
ISB 9 9 2 2 3 3 3 3
ISB 3 4 2 2 9 9 9 9
PRT

ALR 3 1 2 3
AFR 4 5 6 7 8
AFC 3 1 1 1
IBR 0 3 9 9 9
ISB 3 4 2 2 9 9 9 9
PRT
 

*/


