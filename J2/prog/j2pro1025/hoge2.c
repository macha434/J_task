#include <stdio.h>

int main(void)
{
  int i;
  int a, b;

  for (i=1; i<100; i++) {
    printf("[%d]\n", i);
    if (i==15) {
      printf("15!!!!!\n");
    }
  }

  return 0;
}
