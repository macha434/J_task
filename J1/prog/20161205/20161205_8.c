#include<stdio.h>
main(void)
{
  int a[10], b[10], c = 0, d = 9;

  while(c<10){

    printf("a[%d] = :",c);
    scanf("%d",&a[c]);
    c = c + 1;

  }

  c = 0;

  while(c<10){

    printf("a[%d] = %d  ",c,a[c]);
    b[c] = a[c];
    printf("b[%d] = %d  ",c,b[d],c,a[c]);
    a[d] = b[c];
    printf("a[%d] = %d\n",d,a[d]);
    c = c + 1;
    d = d - 1;

  }
 
}
  
