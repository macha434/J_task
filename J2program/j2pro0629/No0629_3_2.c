#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char cha;
  int c,f=0,ans=0;
  
  srand((unsigned)time(NULL));
  
  for(c=0; c<1000000; c++){
    cha = rand()%36;
    if(cha>=10){
      cha += 'a'-10;
    }else{
      cha += '0';
    }
      
    if(cha=='o'&&f==0){
      f++;
    }else if(cha=='e'&&f==1){
      f++;
    }else if(cha=='d'&&f==2){
      f++;
    }else if(cha=='a'&&f==3){
      ans++;
    }else{
      f=0;
    }
  }
  printf("%d回\n",ans);

  return 0;
}
