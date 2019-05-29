#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int len;
  char *name;
  char dummy;
  
  printf("名前の文字数を入力してください:");
  scanf("%d", &len);
  scanf("%c", &dummy); //改行コードを読み飛ばす
  
  name = (char *)malloc(sizeof(char)*(len+1));
  
  printf("名前をローマ字で入力してください:");
  fgets(name, len+1, stdin);

  printf("あなたの名前は%sです\n", name);

  return 0;
}
