#include <stdio.h>

char my_toupper(char ch);

int main()
{
  char ch, dummy;

  printf("英小文字を一つ入力してください :");
  scanf("%c%c", &ch, &dummy);

  ch= my_toupper(ch);

  if(ch>= 'A' && ch<= 'Z'){

    printf("入力した英小文字の英大文字は%cです。\n", ch);
  }else{
    
    printf("入力した文字は%cです。\n", ch);
  }
  
  return 0;
}

char my_toupper(char ch)
{
  if(ch>= 'a' && ch<= 'z'){
    
    ch= ch- ('a' - 'A');
  }
  
  return ch;
}
