#include <stdio.h>
main(void)
{
  int age;
  age=4 ;

  if(age<=6){
    printf("無料です。\n");
  } else if(age<=12){
    printf("子供料金です。\n");
  }else if(age>=13){
    printf("大人料金です\n");
  }
}
