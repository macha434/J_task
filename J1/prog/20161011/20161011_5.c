#include<stdio.h>
main(void)

{
  int a,i=1;

  printf("a=:");
  scanf("%d",a);

  while(i<a){
    i=i+1;
    a=a-i;
    printf("a=%d\ni=%d\n",a,i);
  }
  
  printf("終了後aの値は%dです。",a);
}
    
