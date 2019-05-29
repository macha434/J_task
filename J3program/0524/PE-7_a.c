#include <stdio.h>

void Swap(int *a, int *b);

int main(){
    int i, j;
    int str[] = {4, 2, 6, 19, 7, 12, 3, 1, 9};
    int *min;

    min = str;

    for (j = 0; str[i] != '\0'; j++){

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
