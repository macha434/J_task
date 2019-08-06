#include<stdio.h>

int main(void)
{
  int a;
  
  printf("年齢を入力してください。:\n");
  scanf("%d",&a);

  if(a<0 || a>110){
    printf("入力出来ません。\n");
  }
  else{
    if(a<6){
      printf("無料です。\n");
    }else if(a<12){
      printf("350円です。\n");
    }else{
      printf("700円です。\n");
    }
  }
  
  return 0;
}
