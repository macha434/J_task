#include <stdio.h>
main(void)

{
  int a,b,d;

  printf("何日ですか?:");
  scanf("%d", &d);

  a=d%10;
  b=d/10;
  
  if((a==2 || a==9) && (b==2 || b==9)){
    printf("肉の日\n肉10%%引き\n");
  }else if(a == 2 || a == 9 || b == 2 || b == 9){
    printf("肉の日\n肉5%%引き\n");
  }else{
    printf("普通の日\n");
  }
}
