#include <stdio.h>

int main()
{
  int i;
  char charX;

  for(i = -128; i < 128; i++){

    charX = i;
    printf("%d\n", charX);

  }

  return 0;
}
