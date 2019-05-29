#include <stdio.h>

#define NUM 3

int main(void)
{
  int i;
  char array_c[NUM];
  int array_i[NUM];
  double array_d[NUM];

  for (i=0; i<NUM; i++) {
    printf("array_c[%d]のアドレスは%p\n", i, &array_c[i]);
  }

  for (i=0; i<NUM; i++) {
    printf("array_i[%d]のアドレスは%p\n", i, &array_i[i]);
  }

  for (i=0; i<NUM; i++) {
    printf("array_d[%d]のアドレスは%p\n", i, &array_d[i]);
  }


  return 0;
}
