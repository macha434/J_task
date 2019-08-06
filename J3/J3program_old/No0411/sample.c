#include <stdio.h>
#include <stdlib.h>

void PrintList();

typedef struct CELL{
    int value;
    struct CELL *next;
} CELL ;

int main(void){

    int data;
    CELL *root;
    CELL *p;

    printf("Input Number");
    scanf("%d", &data);

    if(data<= 0) exit(0);
 
    root= (CELL *)malloc(sizeof(CELL));
    
    root->value= data;
    root->next= NULL;

    p= root;

    printf("Input Number");
    scanf("%d", &data);

    while(data> 0){

        p->next =(CELL *)malloc(sizeof(CELL));
        p= p->next;
        p->value= data;

        printf("Input Number");
        scanf("%d", &data);

    }

    p->next= NULL;

    for(p= root; p!= NULL; p= p->next){

        printf("%d\n", p->value);
    
    }
    
    return 0;
}
