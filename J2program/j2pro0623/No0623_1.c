#include <stdio.h>

#define NUM 5

int main()
{
  char ch[NUM+ 1], cha[NUM+ 1], dummy;
  int i;
  
  for(i= 0; i< NUM; i++){
    
    printf("文字を一つ入力してください :");
    scanf("%c%c", &ch[i], &dummy);

  }

  ch[i]= '\0';

  for(i= 0; i< NUM; i++){

    cha[NUM- 1- i]= ch[i];

  }

  cha[i]= '\0';

  printf("%s\n", cha);

  return 0;
}
