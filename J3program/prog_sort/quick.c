#include <stdio.h>

void quick_sort(int seq[]);

int main(){

    int seq[10] = {2, 5, 3, 1, 6, 7, 10, 9, 4, 8};

    quick_sort(seq);

    return 0;
}

void quick_sort(int seq[]){

    int h, l;
    int s;

    for (int i = 0; i < 10; i++){

        s = seq[9];

        for (int j = 0; j < 10; j++){

            if (seq[j] > s){

                h = seq[j];

                break;

            }
        }

        for (int j =10 - i; j > 0; j--){

            if (seq[j] < s){

                s = seq[j];

                break;

            }
        }
    }
}
