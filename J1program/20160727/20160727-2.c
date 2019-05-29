#include<stdio.h>

main(void)

{
  int t=13;

  if(t<12){
    printf("午前%d時\n",t);
  }else{
    t=t-12;
    printf("午後%d時\n",t);
  }
}
