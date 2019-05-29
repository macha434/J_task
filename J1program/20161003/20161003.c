#include<stdio.h>

main(void)
{
  int i,a;

  printf("好きな数字を入れてね!:");
  scanf("%d",&i);

  printf("終らしたい数字を入れてね!:");
  scanf("%d",&a);
  
  while (i <= a){
    printf("%d\n",i);
    i = i + 1;
  }
  printf("***終了後iの値=%d***\n",i);
}
