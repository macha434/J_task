#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kaisuu(void)
{
  int a, b, aka= 0, shiro= 0;
  
  for(b= 0; b< 10000; b++){
    
    a= rand()% 11;
    
    if (a<= 4){
      
      aka++;
      
    }
  }
  
  return aka;
}
  
int main(void)
{
  int aka;
  
  srand((unsigned)time(NULL));
  
  aka= kaisuu();
  
  printf("赤がでる確立は、%d/10000 です。\n", aka);
  
  return 0;
}
