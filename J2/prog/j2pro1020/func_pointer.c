#include <stdio.h>

#define NUM 5

void func1(int array[]);
void func2(int *array);
void func3(int array[]);

int main(void)
{
  int x[NUM];
  int i;

  for (i=0; i<NUM; i++) {
    x[i] = i*10;
  }

  for (i=0; i<NUM; i++) {
    printf("    x[%d]=%2d : %p\n", i, x[i], &x[i]);
  }
  printf("\n");

  func1(x);
  func1(&x[0]);
  func1(&x[2]);
  func2(x);
  func3(x);
  printf("x[0]=%d\n", x[0]);
  printf("x[1]=%d\n", x[1]);
  printf("x[4]=%d\n", x[4]);

  return 0;
}

void func1(int array[])
{
  int n;

  n = 0;
  printf("func1\n");
  printf("array[%d]=%2d : %p\n", n, array[n], &array[n]);
  printf("\n");
}

void func2(int *array)
{
  int n;
  n = 0;

  printf("func2\n");
  printf("array[%d]=%2d : %p\n", n, array[n], array);
  printf("\n");
}

void func3(int array[])
{
  int i;

  printf("func3\n");
  for (i=0; i<NUM; i++) {
    printf("array[%d]=%2d : %p\n", i, array[i], &array[i]);
  }
  for (i=0; i<NUM; i++) {
    array[i] += 100;
  }
}
