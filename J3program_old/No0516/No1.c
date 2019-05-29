#include <stdio.h>
#include <stdlib.h>
#include "../include/typedef.h"

void PrintList(CELL *root);

int main(void){

    CELL *root;

    root= (CELL *) malloc (sizeof (CELL));

    root-> value= 5;

    root-> next= (CELL *) malloc (sizeof (CELL));

    root-> next-> value= 2;

    root-> next-> next= (CELL *) malloc (sizeof (CELL));

    root-> next-> next-> value= 3;

    root-> next-> next-> next= NULL;

    PrintList(root);
}
