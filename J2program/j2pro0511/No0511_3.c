#include <stdio.h>

int main (void)
{
  int a,b=0,c=0,d=0,e=0,f;

  printf("整数を入力してください!\n");
  scanf("%d",&a);

  while (a>10  ){
    while(a>100){
      while(a>1000){
	b = a/1000;
	a = a-1000*b;
      }
      c = a/100;
      a = a-100*c;
    }
    d = a/10;
    a = a-10*d;
  }
  f = a+b+c+d;
  printf("合計=%d\n",f);
}
    
