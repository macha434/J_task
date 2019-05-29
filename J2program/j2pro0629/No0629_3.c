#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  char ch, oeda[4];
  int i, eda=0;
  
  srand((unsigned)time(NULL));

  for(i= 0; i< 1000000; i++){
    ch = rand()% 36;

    if(ch< 10){
      ch +='0';
    }else{
      ch +='a'- 10;
    }

    oeda[0]= oeda[1];
    oeda[1]= oeda[2];
    oeda[2]= oeda[3];
    oeda[3]= ch;

    if(oeda[0]=='o' && oeda[1]=='e' && oeda[2]=='d' && oeda[3]=='a'){
      eda++;
    }
  }
  printf("oedaが出た回数%d回\n", eda);

  return 0;
}
