#include <stdio.h>

int function(int num)
{
  int ans;
  
  ans = num * 4;
  
  return ans;
}

int main(void)
{
  int x;
  int y;

  x = 3;

  y = function(x);
  printf("function(%d)=%d\n", x, y);

  return 0;
}
