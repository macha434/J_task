#include <stdio.h>

#define NUM 10

void quick_sort(int seq[]);
void swap(int *i, int *j);
void print_array(int seq[]);

int main(){

    int seq[NUM] = {2, 5, 3, 1, 6, 7, 10, 9, 4, 8};

    print_array(seq);

    quick_sort(seq);

    return 0;
}

void quick_sort(int seq[]){

    int h = 0, l = 0;
    int s;

    for (int i = 0; i < NUM; i++){

        s = seq[NUM -1];

        h = 0;

        l = NUM - 1;

        while (h < l){

            for (h = 0; h < NUM; h++){

                if (seq[h] > seq[NUM - 1]) break;

            }

            for (l = NUM - i -1; l > 0; l--){

                if (seq[l] < seq[NUM - 1]) break;

            }

            swap(&seq[h], &seq[l]);

        }

        swap(&seq[h], &seq[NUM - 1]);

        print_array(seq);
    }
}

void swap(int *i, int *j){

    int tmp;

    tmp = *i;

    *i = *j;

    *j = tmp;
}

void print_array(int seq[]){

    printf("array[");

    for (int i = 0; i < NUM; i++){

        printf("%d, ", seq[i]);

    }

    printf("]\n");
}
