#include <stdio.h>
#include <stdlib.h>

int main(){
    int XA1, XA2, XB1, XB2;
    int YA1, YA2, YB1, YB2;
    int x, y, area;

    printf("input 8 data");
    scanf ("%d, %d, %d, %d, %d, %d, %d, %d", &XA1, &XA2, &XB1, &XB2, &YA1, &YA2, &YB1, &YB2);

    if (XA2 < XB1){
        x = XA1 - XB2;
    }else if (XB2 < XA1){
        x = XA1 - XB2;
    }else{
        printf("area is 0 !\n");
        return 0;
    }

    if (YA2 < YB1){
        y = YB1 - YA2;
    }else if (YB2 < YA1){
        y = YA1 - YB2;
    }else{
        printf("area is 0 !\n");
        return 0;
    }

    area = x * y;

    printf("area is %d\n", area);

    return 0;
}
