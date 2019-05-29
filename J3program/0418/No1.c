#include <stdio.h>

int anser_X(int XA1, XA2, XB1, XB2, CA, CB);
int anser_Y(int YA1, YA2, YB1, YB2, CA, CB);

struct rect {
    int X1, X2;
    int Y1, Y2;
    int CX, CY;
}

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

    rectA.CX = rectA.X1 + (rectA.X2 - rectA.X1) / 2;
    rectA.CY = rectA.Y1 + (rectA.Y2 - rectA.Y1) / 2;

    rectB.CX = rectB.X1 + (rectB.X2 - rectB.X1) / 2;
    rectB.CY = rectB.Y1 + (rectB.Y2 - rectB.Y1) / 2;

    AX = anser_X(rectA.X1, rectA.X2, rectB.X1, rectB.X2, re);
    AY = anser_Y(rectA.Y1, rectA.Y2, rectB.Y1, rectB.Y2);

    printf("area is %d.\n", AX * AY);
}

int anser_X(int XA1, XA2, XB1, XB2, CA, CB){


}
