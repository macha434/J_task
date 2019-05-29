#include <stdio.h>

int main(void)
{
  int vc[] = {10, 20, 30, 40, 50};
  int *ptr;

  ptr = &vc[0];
  printf("(1) = %d\n", *ptr);
  printf("(2) = %d\n", *(ptr+3));
  printf("(3) = %d\n\n", *ptr+3);

  ptr = &vc[3];
  printf("(4) = %d\n", *ptr);
  printf("(5) = %d\n", *(ptr+1));
  printf("(6) = %d\n\n", *ptr+1);

  ptr = vc;
  printf("(7) = %d\n", *ptr);
  printf("(8) = %d\n", ptr[0]);
  printf("(9) = %d\n\n", ptr[2]);
  
  ptr = &vc[2];
  printf("(10) = %d\n", ptr[0]);
  printf("(11) = %d\n", ptr[2]);
  printf("(12) = %d\n\n", *(ptr+2));

  return 0;
}
