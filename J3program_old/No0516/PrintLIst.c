#include <stdio.h>
#include <stdlib.h>
#include "../include/typedef.h"

void PrintList(CELL *root){

    for (CELL *p= root; p!= NULL; p= p-> next){

        printf("%d\n", p-> value);
    }
}
