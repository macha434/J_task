#include<stdio.h>
main(void)
{
  int a[10], b[10], c = 1;

  while(c<10){

    a[c] = c;
    b[c] = a[c];
    printf("a[%d]=%d,b[%d]=%d\n",c,a[c],c,b[c]);
    c = c + 1;
    
  }

}
