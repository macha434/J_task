#include "h8-3052-iodef.h"
#include "lcd.h"

int main(void)
{
    char x;
    char y;
    char str[]= "Kisarazu";

    lcd_init();

    for (y= 0; y< 2; y++){
        for (x= 0; x< 16; x++){
            
            if (str[x]== '\0'){
                return 0;
            }
            
            //lcd_cursor(x,y);
            lcd_printch(str[x]);
        }
    }

  return 0;
}
