#include <stdio.h>
main(void)
  
{
  int d,d1,d2;

  printf("何日ですか?:");
  scanf("%d", &d);
  
  d1=d%10;
  
  d2=d/10;
  
  if(d1==2||d1==9||d2==2||d2==9){
    printf("肉の日\n肉5%%引き\n");
    
  }else{
    printf("普通の日\n");
  }
}
