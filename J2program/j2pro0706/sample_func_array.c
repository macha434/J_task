#include <stdio.h>

#define NUM 3

void func(int array[]);

int main(void)
{
  int array[NUM];

  array[0] = 0;
  array[1] = 1;
  array[2] = 2;

  printf("(1) main array[0]=%d\n", array[0]);
  printf("(1) main array[1]=%d\n", array[1]);
  printf("(1) main array[2]=%d\n", array[2]);

  func(array);

  printf("(4) main array[0]=%d\n", array[0]);
  printf("(4) main array[1]=%d\n", array[1]);
  printf("(4) main array[2]=%d\n", array[2]);
  
  return 0;
}

void func(int array[])
{
  printf("(2) func array[0]=%d\n", array[0]);
  printf("(2) func array[1]=%d\n", array[1]);
  printf("(2) func array[2]=%d\n", array[2]);

  array[0] = 13;
  array[1] = 14;
  array[2] = 15;

  printf("(3) func array[0]=%d\n", array[0]);
  printf("(3) func array[1]=%d\n", array[1]);
  printf("(3) func array[2]=%d\n", array[2]);

}
