#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i;
  int val;

  srand((unsigned)time(NULL));
  
  for (i = 0; i < 20; i++){
    val = rand() % 27 + 23;
    printf("%2d - %2d\n", i+1, val);
  }

  return 0;
}
