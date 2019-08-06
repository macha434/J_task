#include "h8-3052-iodef.h"
#include "lcd.h"

int main(void)
{
    char x= 5;
    char y= 1;
    char i= 0;
    char str[]= "1234567890abcdefghijklmnopqrstuvwxyz";

    lcd_init();
   
    for (; 1; x++, i++){
            
        if (i== 32, str[i]== '\0'){
            return 0;
        }
            
        lcd_cursor(x% 16, y% 2);
        lcd_printch(str[i]);

        if (x% 16+ 1== 16){
            y++;
        }
    }

  return 0;
}
