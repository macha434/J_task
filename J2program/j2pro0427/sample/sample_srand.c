#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;
  int val;

  srand(2);

  i = 0;
  while (i < 10) {
    val = rand();
    printf("%d\n", val);
    i++;
  }

  return 0;
}
    
