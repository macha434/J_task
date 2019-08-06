#include <stdio.h>

main(void)
  
{
  int hp = 100,hit;

  printf("だめーじは？");
  scanf("%d",&hit);

  if (hp-hit<=0){
    printf("あなたは、力尽きた…。\n");
  }else if(hp-hit<10){
    printf("死にそうだ\n");
  }else if(hp-hit>=10 && (hit>0 && hit<10)){
    printf("いたたっ\n");
  }else if(hp-hit>=10 && hit>=10){
    printf("うっ、やられた\n");
  }
}
