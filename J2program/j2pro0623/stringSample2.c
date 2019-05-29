#include <stdio.h>

int main(void)
{
  int i;
  char str[5+1];
  
  for (i=0; i<5; i++) {
    str[i] = 'a' + i;
  }
  str[i] = '\0';
  
  for (i=0; i<5; i++) {
    printf("%c", str[i]);
  }
  printf("\n");
  
  printf("(%s)\n", str);

  return 0;
}
