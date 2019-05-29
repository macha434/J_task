#include <stdio.h>

int main(){
    int a[10];
    int *p;
    int i;

    p= &a[0];

    for(i=0; i<10; i++){
        *(p+ i)= 0;
    }
    
    for(i=0; i<10; i++){

        printf("%d", *(p+i));
    }

    printf("\n");
}
