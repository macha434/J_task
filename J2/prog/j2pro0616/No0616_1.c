#include <stdio.h>

int main()
{
  int i;
  unsigned char charX;

  for(i = 0; i < 256; i++){

    charX=i;
    printf("%d\n", charX);

  }

  return 0;
}
