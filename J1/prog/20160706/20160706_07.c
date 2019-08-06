#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
  int hit,hp=40;

  srandom(time(0));

  hit = random()%45+1;

  printf("hp=%d\nhit=%d\n",hp,hit);

  hp = hp-hit;
  

  if(hit<9){
    printf("痛くもかゆくもない\n");
  }else if(hit<20){
    printf("いたーい\n");
  }else{
  if(hp<=0){
    printf("力尽きた…\n");
  }else if(hp<10){
    printf("死にそー\n");
  }else if(hp>=10){
    printf("よゆーー\n");
  }
  }
}
  
