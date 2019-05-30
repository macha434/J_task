#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct CELL{

    int value;
    struct CELL *next;

}CELL;

CELL *sort_List (CELL *p, CELL *q);
void print_List (CELL *root);
void free_List (CELL *root);

int main(){

    int data;
    CELL *stru;
    CELL *root;
    CELL *new;

    printf ("Input data : ");
    scanf ("%d", &data);

    if (data <= 0) exit(0);

    root = (CELL *) malloc (sizeof (CELL));

    root -> value = data;
    root -> next = NULL;

    stru = root;

    printf ("Input data : ");
    scanf ("%d", &data);

    while (data > 0){

        stru -> next = (CELL *) malloc (sizeof (CELL));

        stru = stru -> next;

        stru -> value = data;

        stru -> next = NULL;

        stru = sort_List (root, stru);

        printf ("Input data : ");
        scanf ("%d", &data);

    }

    print_List (root);

    free_List (root);
}

CELL *sort_List (CELL *p, CELL *q){

    for ( ; q != NULL ; p = p -> next, q = q -> next){

        if (p -> value > q -> value){

            p = q;
            q -> next = p -> next;
            p -> next = q;

        }

    }

    return p;
}

void print_List (CELL *root){
    CELL *p= root;

    printf ("\nprint_List START\n\n");

    for ( ; p != NULL ; p = p -> next ){

        printf ("%d\n", p -> value);

    }

    printf ("\nprint_List END\n");

}

void free_List (CELL *root){
    int i;
    CELL *p;

    printf ("\nfree START\n");

    for (p = root ; root != NULL ; root = p, i++){

        p = p -> next;

        free (root);
    }

    printf ("\nfree END\n%d times\n\n", i);
}
