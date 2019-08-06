#include<stdio.h>
main(void)
{
  int a,i,s;

  printf("aの数字は？:");
  scanf("%d",&a);

  while(i<=a){
    s=s+i;
    i=i+1;
    printf("s=%d\ni=%d\n",s,i);
  }
  printf("終了後のs=%d\n",s);
}
