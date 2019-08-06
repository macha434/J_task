#include<stdio.h>
main(void)

{
  int tate = 1, n;

  printf("nの値を入力してください:");
  scanf("%d",&n);

  while (tate <= n){
    printf("%d行目です\n",tate);
    tate = tate + 1;
  }
}
