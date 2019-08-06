#include <stdio.h>

int main(void)
{
  int max, number;
  int *count, *value;

  count = &max;
  value = &number;
  *value = 123;
  number = 456;
  max = *value;
  
  printf("max=%d, number=%d, *count=%d, *value=%d\n",
	 max, number, *count, *value);

  count = &number;
  *count = 634;
  
  printf("max=%d, number=%d, *count=%d, *value=%d\n",
	 max, number, *count, *value);
  
  return 0;
}
