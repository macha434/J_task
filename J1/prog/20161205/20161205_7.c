#include<stdio.h>
main(void)
{
  int a[10], b[10], c = 0, d = 9;

  while(c<10){

    a[c] = c;
    b[d] = a[c];
    printf("a[%d] = %d  b[%d] = %d\n",c,a[c],d,b[d]);
    c = c + 1;
    d = d - 1;

  }

}
    
