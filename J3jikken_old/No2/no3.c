#include "h8-3052-iodef.h"
#include "lcd.h"

#define time 1200

void sleep(int count){

    int i;
    int k;
    int j;

    for (i= 0; i< count* time; i++){
        k= i* k;
        j= j* 114;
    }
}

int main(void)
{
    char x= 0;
    char X= 0;
    char y= 0;
    char i= 0;
    char str[]= "abcdefghijklmnopqrstuvwxyz";

    lcd_init();
   
    for (X= 0; 1; X++){
        for (x= X+ 1, i= 0, y= 0; x> 0; x--, i++){

            lcd_cursor(x- 1% 16, ((x- 1% 32)/ 16)% 2);
            lcd_printch(str[i% 32]);
            
            if (str[i]== '\n'){
                break;
            }

        }

        sleep(1000);
    }

  return 0;
}
