#include "h8-3052-iodef.h"

#define time 1200 //1ms

void sleep(int count);

int main(void){

    P9DDR = 0x30; // P9DRの4,5ビット目を出力に設定
    P9DR = 0x30; // P9DRに0x30を代入

    while (1){

        sleep(1000);

        P9DR= 0x10; // P9DRに0x10を代入

        sleep(1000);

        P9DR= 0x20; // P9DRに0x20を代入

        sleep(1000);

        P9DR= 0x00; // P9DRに0x00を代入

        sleep(1000);

        P9DR= 0x30; // P9DRに0x30を代入

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
