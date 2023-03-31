//Tomasz Jarzabek

#include "bitwise_operations.h"

void Union (int zbiorA, int zbiorB, int* suma){

    *suma = zbiorA | zbiorB;
}

void Intersection (int zbiorA, int zbiorB, int* iloczyn){

    *iloczyn = zbiorA & zbiorB;
}

void Symmetric (int zbiorA, int zbiorB, int* symetryczna){

    *symetryczna = zbiorA ^ zbiorB;
}

void Difference (int zbiorA, int zbiorB, int* roznica){

    *roznica = zbiorA ^ zbiorB;
    *roznica = *roznica & zbiorA;
}

void Complement(int zbior, int* dopelnienie){

    *dopelnienie = ~zbior;
}