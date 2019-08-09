#include <stdio.h>

#define N 10

void Swap(int *a, int *b);

int main(){

    int i, j;
    int str[N];
    int *min;

    min = str;

    for (j = 0; j < N; j++){

        if(min > str[j]){
            min = &str[j];
        }

        if (str[j] == '\0'){
            Swap (str[i], *min);

            i++;

            j = 0;
        }
    }

    printf("%s\n", str);
}


void Swap(int *a, int *b){
    int c;

    c = *a;
    *a = *b;
    *b = c;

}
