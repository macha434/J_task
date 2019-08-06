#include<stdio.h>
main(void)

{
  int a,i,s;

  printf("aの値は？:");
  scanf("%d",&a);

  while(i<a){
    i=i+1;
    s=s+i*i;
    printf("s=%d\ni=%d\n",s,i);
  }
  printf("終了後の値は%dです。\n",s);
}
