#include<stdio.h>
main(void)
{
  int a[9], b = 0;

  while(b<10){

    a[b] = b;
    printf("a[%d]=%d\n",b,a[b]);
    b = b + 1;

  }
}
