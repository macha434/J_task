#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i = 0, num=0, e=0, f=0, g=0, h=0, j=0, k=0;

  srand (time(NULL));
    
  for (i = 0; i < 6000000; i++){
    num = rand() % 7 + 1;

    if (num==7){
      num = 2;
    }
    printf("%d回目 : %d\n",i+1 ,num);
    switch (num){
    case 1:
      e = e + 1;
      break;
    case 2:
      f = f + 1;
      break;
    case 3:
      g = g + 1;
      break;
    case 4:
      h = h + 1;
      break;
    case 5:
      j = j + 1;
      break;
    case 6:
      k = k + 1;
      break;
    }
  }
  printf("1 = %d\n2 = %d\n3 = %d\n4 = %d\n5 = %d\n6 = %d\n",e,f,g,h,j,k);
  return 0;
}
