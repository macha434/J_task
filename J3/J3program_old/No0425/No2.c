#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
    int value;
    struct CELL *next;
} CELL;

int main(){

    int data;
    CELL root;
    CELL *p= &root;

    p->next= NULL;

    scanf("%d", &data);

    while (data>0){

        if (p-> next= (CELL *)malloc (sizeof (CELL)));

        else exit(1);

        p= p-> next;
        p-> value= data;

        scanf("%d", &data);
    }

    p-> next= NULL;

    for (p= root.next; p!= NULL; p= p-> next){

        printf("%d\n", p-> value);

    }

    //free;

    return 0;

}
