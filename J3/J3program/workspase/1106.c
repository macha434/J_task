#include <stdio.h>

int main(){
    int a;
    int b;
    int *p;

    a= 5;

    p= &a;

    printf("%d\n", *p);

    return 0;
}
