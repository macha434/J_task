#include <stdio.h>

int main()
{
  char ch, dummy;
  int i;

  printf("英小文字を一つ入力してください :");
  scanf("%c%c", &ch, &dummy);

  for(; ch< 'a' || ch> 'z' ;){

    printf("error\n");
    printf("英小文字を一つ入力してください :");
    scanf("%c", ch);
  
  }

  printf("入力した文字は%cです。\n", ch);

  return 0;
}