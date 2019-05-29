#include <stdio.h>

typedef struct POINT{
        int x;
        int y;
        } PO;

int main(){
    PO P;

    P.x= 5;
    P.y= 10;

    PO *pp;

    int *i;

    int size= sizeof(i);

    pp= &P;

    printf("%d\n", size);

    printf("%d\n", pp->x);

    return 0;
}
