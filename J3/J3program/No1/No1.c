#include <stdio.h>

int length(int A1, int A2, int B1, int B2);

struct rect {
    int X1, X2;
    int Y1, Y2;
};

int main(){

    struct rect rectA;
    struct rect rectB;

    int AX, AY;

    rectA.X1 = 4;
    rectA.X2 = 8;
    rectA.Y1 = 3;
    rectA.Y2 = 9;

    rectB.X1 = 4;
    rectB.X2 = 10;
    rectB.Y1 = 6;
    rectB.Y2 = 8;

    AX = length(rectA.X1, rectA.X2, rectB.X1, rectB.X2);
    AY = length(rectA.Y1, rectA.Y2, rectB.Y1, rectB.Y2);

    printf("area is %d.\n", AX * AY);

    return 0;
}

int length(int A1, int A2, int B1, int B2){

    int l, l1 = 0, l2 = 0;

    if (A1 > B2 && A1 < B1){

        l1 = A1;

    }else if (B1 > A2 && B1 < A1){

        l1 = B1;

    }

    if (A2 > B2 && A1 < B1){

        l2 = A2;

    }else if (B1 > A2 && B1 < A1){

        l2 = B2;

    }

    l = l1 - l2;

    return l;
}
