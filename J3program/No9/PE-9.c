#include <stdio.h>

#define N 11

void set_array(int n, int array[]);
void Pascal_tri(int n, int array[]);
void make_tri(int i, int array[]);

int main(){

    int array[N];

    set_array(N, array);

    array[0] = 1;

    Pascal_tri(0, array);

    return 0;
}

void set_array(int n, int array[]){

    if (n <= 1){

        array[0] = 0;

        return ;

    } else{

        set_array(n -1, array);
    }

    array[n] = array[n -1];
}

void Pascal_tri(int i, int array[]){

    make_tri(i, array);

    printf("\n");

    if (i >= N){

        return ;

    } else {

        Pascal_tri(i + 1, array);
    }
}

void make_tri(int i, int array[]){

    if (i < 1){

        printf(" %3d ", array[i]);

        return ;

    } else {

        array[i] += array[i -1];

        printf(" %3d ", array[i]);

        make_tri(i - 1, array);
    }
}
