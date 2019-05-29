#include<stdio.h>
main(void)

{
  int a,b,c,d,e;

  printf("何日ですか?:");
  scanf("%d", &a);

  b=a%10;
  c=a/10;
  d=b;
  e=c;

  if((b == 1 || b == 8) && (c == 1 || c == 8)){
    printf("野菜の日\n野菜10%%引き\n");
  }else if(b == 1 || b == 8 || c == 1 || c == 8){
    printf("野菜の日\n野菜5%%引き\n");
  }
  if((d == 3 || d == 2) && (e == 3 || e == 2)){
    printf("魚の日\n魚10%%引き\n");
  }else if (d == 3 || d == 2 || e == 3 || e == 2){
    printf("魚の日\n魚5%%引き\n");
  }
}
