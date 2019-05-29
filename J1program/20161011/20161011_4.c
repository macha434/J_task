#include<stdio.h>
main(void)

{
  int a,s=1,i;
  
  printf("aは？:");
  scanf("%d",&a);
  

  while(i<=a-1){
    i=i+1;
    s=s*i;
    printf("i=%d\ns=%d\n",i,s);
  }  
  printf("終了後のsは%dです。\n",s);
}
