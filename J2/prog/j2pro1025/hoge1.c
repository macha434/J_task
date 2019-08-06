#include <stdio.h>

int main(void)
{
  int a;

  a = 7;

  printf("(1):%d\n", a);
  printf("(2):%d\n", a=8);
  printf("(3):%d\n", a==9);
  
  printf("(4)\n");
  a = 8;
  if(a==8) {
    printf("yes\n");
  }
  else {
    printf("No\n");
  }

  printf("(5)\n");
  a = 8;
  if(a=8) {
    printf("yes\n");
  }
  else {
    printf("No\n");
  }

  printf("(6)\n");
  a = -1;
  if(a=8) {
    printf("yes\n");
  }
  else {
    printf("No\n");
  }

  printf("(7)\n");
  a = 0;
  if(a) {
    printf("yes\n");
  }
  else {
    printf("No\n");
  }
  return 0;
}
