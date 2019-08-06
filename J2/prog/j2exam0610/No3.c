#include <stdio.h>

int main(void)
{
  int Num;

  for(Num= 1; Num<=40; Num++){

    sleep(1);
    
    if(Num% 3== 0 || Num% 10== 3 || Num/ 10== 3){
      
      printf("いまでしょ！\n");
    }
    else{
      
      printf("いつやるの？\n");
    }

  }

  return 0;
}
