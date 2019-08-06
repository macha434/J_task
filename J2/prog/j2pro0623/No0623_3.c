#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char pass[8+1];
  int i;
  
  srand((unsigned)time(NULL));

  for(i= 0; i< 8; i++){
    
    pass[i]= rand()% 62;

    if(pass[i]<10){
      pass[i] +='0';
    }else if(pass[i]<36){
      pass[i] +='A'- 10;
    }else{
      pass[i] +='a'- 36;
    }
  }

  pass[i]= '\0';
  
  printf("ランダムなパスワードは%sです。\n", pass);
}
