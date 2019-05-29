#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char cha,chc;
  int c,f=0,ans=0;
  double chk[36];

  for(c=0; c<36; c++){
    chk[c]=0;
  }
  
  srand((unsigned)time(NULL));
  
  for(c=0; c<1000000; c++){
    cha = rand()%36;
    if(cha>=10){
      cha += 'a'-10;
    }else{
      cha += '0';
    }

    switch(cha){
    case '0':
      chk[0]++;;
      
      break;      
    case '1':
      chk[1]++;
      break;      
    case '2':
      chk[2]++;
      break;      
    case '3':
      chk[3]++;
      break;      
    case '4':
      chk[4]++;
      break;
      
    case '5':
      chk[5]++;
      break;
    case '6':
      chk[6]++;
      break;      
    case '7':
      chk[7]++;
      break;      
    case '8':
      chk[8]++;
      break;      
    case '9':
      chk[9]++;
      break;

    case 'a':
      chk[10]++;
      break;      
    case 'b':
      chk[11]++;
      break;      
    case 'c':
      chk[12]++;
      break;      
    case 'd':
      chk[13]++;
      break;      
    case 'e':
      chk[14]++;
      break;

    case 'f':
      chk[15]++;
      break;
    case 'g':
      chk[16]++;
      break;      
    case 'h':
      chk[17]++;
      break;      
    case 'i':
      chk[18]++;
      break;      
    case 'j':
      chk[19]++;
      break;

    case 'k':
      chk[20]++;
      break;      
    case 'l':
      chk[21]++;
      break;      
    case 'n':
      chk[22]++;;
      
      break;      
    case 'm':
      chk[23]++;
      break;      
    case 'o':
      chk[24]++;
      break;

    case 'p':
      chk[25]++;
      break;
    case 'q':
      chk[26]++;
      break;      
    case 'r':
      chk[27]++;
      break;   ;
         
    case 's':
      chk[28]++;
      break;      
    case 't':
      chk[29]++;
      break;

    case 'u':
      chk[30]++;
      break;      
    case 'v':
      chk[31]++;
      break;      
    case 'w':
      chk[32]++;
      break;      
    case 'x':
      chk[33]++;
      break;      
    case 'y':
      chk[34]++;
      break;;
      
      
    case 'z':
      chk[35]++;
      break;
    }
    
  }

  for(c=0; c<36; c++){
    if(c>=10){
      chc = c + 'a'-10;
    }else{
      chc = c + '0';
    }
    printf("[%c] は %7.0f回で",chc,chk[c]);
    chk[c] = chk[c]/1000000*100;
    printf(" %.2f%%\n",chk[c]);
  }

  return 0;
}
