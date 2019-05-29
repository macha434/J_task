#include "h8-3052-iodef.h"

#define time 1200 //1ms

void sleep(int count);

int main(void){

    char b4_old= 0;
    char b5_old= 0;
    char b4_new= 0;
    char b5_new= 0;
    char val= 0;

    P9DDR= 0x30; // P9DRの4,5ビット目を出力に設定

    while (1){

        b4_old= b4_new; // b4のバックアップ
        b5_old= b5_new; // b5のバックアップ

        b4_new= ((b4_old & b5_old) | ~(b4_old | b5_old)) & 0x01; // b4_oldとb5_oldのxorのnotに0x01をand
        b5_new= (~b5_old) & 0x01; // b5_oldのnotに0x01をand

        val= ((b4_new << 4) | (b5_new << 5)) | (val & 0xCF); // b4_newのビットを4ビット分シフトしたものとb5_newのビットを5ビット分しふとしたものをorし、P9DRの4,5ビット以外をそのままの値をor

        P9DR= val; // P9DRにvalを代入

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
