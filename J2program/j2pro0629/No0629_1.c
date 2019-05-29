#include <stdio.h>

int main(void)
{
  char ch;

  for(ch='f'; ch!='y'+1; ch++){
    printf("%c",ch);
  }
  printf("\n");
  
  return 0;
}
