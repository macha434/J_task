#include <stdio.h>

void func(int val);

int main(void)
{
  int val;

  val = 7;

  printf("(1) main =%d\n", val);

  func(val);

  printf("(4) main val=%d\n", val);
  
  return 0;
}

void func(int val)
{
  printf("(2) func val=%d\n", val);
  
  val = 100;

  printf("(3) func val=%d\n", val);
}
