#include "h8-3052-iodef.h"

#define time 12000 //1ms

void sleep(int count);

int main(void){

    char val= 0;

    P9DDR = 0x30;
    P9DR = 0x20;

    while (1){

        val= ~val;
        P9DR= val << 5;

        sleep(1000);



    }
}

void sleep(int count){

    int i;
    int k;
    int j;

    for (i= 0; i< count* time; i++){
        k= i* k;
        j= j* 114;
    }
}
