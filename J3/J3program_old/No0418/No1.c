#include <stdio.h>

void sankaku1(int n);

void starts(int n, int i);

int main(){

    sankaku1(3);
    
    return 0;

}

void sankaku1(int n){

    if (n>= 1){

        starts(n, 0);

    }
}

void starts(int n, int i){;

    i++;

    printf("*");

    if(n> 1){

        starts(n- 1, i);

    }

    printf("\n");

    sankaku1(i- 1);

}

