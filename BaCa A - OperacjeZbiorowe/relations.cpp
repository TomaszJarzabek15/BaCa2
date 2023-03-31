//Tomasz Jarzabek

#include "bitwise_operations.h"

bool LessThen (int zbiorA, int zbiorB){

    int mocA = Cardinality(zbiorA);
    int mocB = Cardinality(zbiorB);

    if(mocA < mocB){
        return true;
    }
    else if(mocA == mocB){

        if(zbiorA < zbiorB){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool LessEqual (int zbiorA, int zbiorB){

    int mocA = Cardinality(zbiorA);
    int mocB = Cardinality(zbiorB);

    if(mocA < mocB){
        return true;
    }
    else if(mocA == mocB){

        if(zbiorA <= zbiorB){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool GreatEqual (int zbiorA, int zbiorB){

    int mocA = Cardinality(zbiorA);
    int mocB = Cardinality(zbiorB);

    if(mocA > mocB){
        return true;
    }
    else if(mocA == mocB){

        if(zbiorA >= zbiorB){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }


}

bool GreatThen (int zbiorA, int zbiorB){

    int mocA = Cardinality(zbiorA);
    int mocB = Cardinality(zbiorB);

    if(mocA > mocB){
        return true;
    }
    else if(mocA == mocB){

        if(zbiorA > zbiorB){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}