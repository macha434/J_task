#include <stdio.h>
#include <stdlib.h>

void randum(double base[10]);
void cope(double *base, double *rev);

int main(){
    double base[10];
    double rev[10];
    int i;

    randum(&base[0]);

    cope(&base[0], &rev[0]);

    for(i=0; i<10; i++){
        printf("base[%d]:%f, rev[%d]:%f\n", i, base[i], i, rev[i]);
    }

    return 0;
}

void randum(double base[]){
    int i;

    srand(1);

    for(i=0; i<10; i++){
        base[i]= (float)rand()/ 12348.0;
        if(base[i]>1.0){
            i--;
        }
    }
}

void cope(double *base, double *rev){
    int i;

    for (i=0; i<10; i++){
        *(rev+ (9- i)) = *(base+ i);
    }
}
