#include <stdio.h>
#include <stdlib.h>

#define NUM 300000000

int main(void)
{
  double *array;
  char hoge;
  int i;
  
  array = (double *)malloc(sizeof(double)*NUM);

  array[0] = 123.456;
  array[NUM-1] = 987.789;

  printf("array[0]=%f\n", array[0]);
  printf("array[NUM-1]=%f\n", array[NUM-1]);

  for (i=0; i<NUM; i++) {
    array[i] = 0;
    printf("%d\n", i);
  }
  scanf("%c", &hoge);
  
  return 0;
}
