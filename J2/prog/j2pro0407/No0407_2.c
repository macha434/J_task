#include<stdio.h>

int main(void)
{
  int a[10];
  int b = 0, c, d;

  while(b<10){
    c = b * 2;
    a[b] = 1 + c;
    d = a[b] + d;
    b = b + 1;
  }

  printf("d = %d\n",d);

  return 0;
}
