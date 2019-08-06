#include <stdio.h>

main(void)
{
  int t;
  t=17;

  if(t>=5 && t<=10){
    printf("朝です。\n");
  }else if(t>=11 && t<=15){
    printf("昼です。\n");
  }else if(t>=16 && t<=18){
    printf("夕です。\n");
  }else if(t>=19){
    printf("夜です。\n");
  }else if(t<=4){
    printf("夜です。");
  }
}
      
