#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

int main(void)
{
  int *pt;
  int i;

  pt = (int *)malloc(NUM*sizeof(int));

  for (i=0; i<NUM; i++) {
    pt[i] = i;
  }

  for (i=0; i<NUM; i++) {
    printf("pt[%d]=%d\n", i, pt[i]);
  }

  return 0;
}
