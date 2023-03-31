//Tomasz Jarzabek

#include "bitwise_operations.h"

bool Emptiness (int zbior){

    if(zbior == 0){
        return true;
    }
    else{
        return false;
    }

}

bool Nonempty (int zbior){

    return !(Emptiness(zbior));
}