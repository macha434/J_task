#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i;
  int val;
  int seed;

  seed = (unsigned)time(NULL);
  printf("seed=%d\n", seed);
  srand(seed);

  i = 0;
  while (i < 10) {
    val = rand();
    printf("%d\n", val);
    i++;
  }

  return 0;
}
    
