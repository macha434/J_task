#include <stdio.h>
#include <limits.h>

int main(void)
{
  char a;
  int b;
  double c;

  printf("char型は%uバイトです．\n", (unsigned int)sizeof(char));
  printf("int型は%uバイトです．\n", (unsigned int)sizeof(int));
  printf("double型は%uバイトです．\n", (unsigned int)sizeof(double));

  printf("aは%uバイトです．\n", (unsigned int)sizeof(a));
  printf("bは%uバイトです．\n", (unsigned int)sizeof(b));
  printf("cは%uバイトです．\n", (unsigned int)sizeof(c));

  return 0;
}
