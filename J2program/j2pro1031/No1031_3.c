#include <stdio.h>
#include <stdlib.h>

int main(){
    int dec;
    int tmp;
    int *bin;
    int i, j, k;
    
    printf("input number:");
    scanf("%d", &dec);

    tmp= dec;

    for (i=0; tmp> 0; i++){
        tmp= tmp/ 2;
    }

    bin= (int *)malloc(sizeof (int)* (i+ 1));

    for (j=0; dec>0; j++){
        bin[j]= dec% 2;
        dec= dec/ 2;
    }

    printf("bin= ");

    for (k=i- 1; k>= 0; k--){
        printf("%d", bin[k]);
    }

    printf("\n");
}
