#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;
  int val;

  for (i = 0 ; i < 100 ; i++){
    val = rand();
    printf("%d = %d\n", i+1, val);
  }
  return 0;

}
