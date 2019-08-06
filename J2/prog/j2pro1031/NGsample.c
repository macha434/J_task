#include <stdio.h>

int main(void)
{
  int *pt;
  int i;

  pt[0] = 1114;
  pt[1] = 1115;
  pt[2] = 1116;

  for (i=0; i<3000; i++) {
    printf("pt[%d]=%d\n", i, pt[i]);
  }

  return 0;
}
