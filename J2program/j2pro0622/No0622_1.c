#include <stdio.h>

int main()
{
  char ch, dummy;
  int i;

  ch= 0x61;
  
  for(i= 0; i< 26; i++){

    printf("%d = %c\n", ch, ch);
    ch++;

  }

  return 0;
}
