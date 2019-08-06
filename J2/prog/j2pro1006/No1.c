#include <stdio.h>

int main(void)
{
  int a;
  int *px, *py;

  a = 100;
  px = &a;
  printf("a=%d, *px=%d\n", a, *px);

  py = px;
  printf("a=%d, *px=%d, *py=%d\n", 
          a, *px, *py);

  *px = 500;
  printf("a=%d, *px=%d, *py=%d\n",
          a, *px, *py);

  return 0;
}
