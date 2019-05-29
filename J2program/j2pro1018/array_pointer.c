#include <stdio.h>

#define NUM 5

int main(void)
{
  int i;
  int vc[NUM] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = &vc[2];

  for (i=0; i<NUM; i++) {
  printf("[%p]: vc[%d] = %d   ptr[%d] = %d   *(ptr+%d) = %d\n",
           &vc[i], i, vc[i], i, ptr[i], i, *ptr+i );
  }

  return 0;
}
