#include <stdio.h>

int main(void)
{
  int j, a;
  int key;

  printf("key = ");
  scanf("%d", &key);

  a = key;
  j = 0;
  while (j<key) {
    a = key - j;
    while (a > 0) {
      printf("*");
      a = a - 1;
    }
    printf("\n");
    j = j + 1;
  }

  return 0;
}
  
  

