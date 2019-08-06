#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int i;

  i = 0;
  while (i<5) {
    printf("%d\n", i);
    sleep(1);
    i++;
  }

  return 0;
}
