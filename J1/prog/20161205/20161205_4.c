#include<stdio.h>
main(void)
{
  int a[23], b = 0, c = 0;

  while(b<24){
    
    printf("a[%d]=:",b);
    scanf("%d",&a[b]);
    b = b + 1;
    
  }

  b = 0;

  while(b<24){

    c = c + a[b];
    printf("a[%d] = %d\n",b,c);
    b = b + 1;

  }

}
