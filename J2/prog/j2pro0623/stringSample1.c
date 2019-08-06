#include <stdio.h>

#define SIZE 5

int main(void)
{
  char str[SIZE];
  int i;
  
  str[0] = 'k';
  str[1] = 'n';
  str[2] = 'c';
  str[3] = 't';
  str[4] = '\0';

  for (i=0; i<SIZE; i++) {
    printf("%c", str[i]);
  }
  printf("\n");
  
  return 0;
}
