#include <stdio.h>
#include <stdlib.h>
#define rand_range(min,max) (min)+(rand())%((max)-(min)+1)
int main()
{
  
  for(int i=1;i<=200;i++) printf("%d ",rand_range(1,1000000));
}
