#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000
#define NUM 100000

int main(void)
{
  double *array;
  int i;
  int count;

  count = 0;
  while (count<NUM) {
    if(count%10==0) {
      printf("%d\n", count);
    }

    array = (double *)malloc(sizeof(double)*SIZE);
    
    for (i=0; i<SIZE; i++) {
      array[i] = 123.456;
    }

    // この1行が超重要！！！！！！
    free(array);
    
    count++;
  }
  
  return 0;
}
