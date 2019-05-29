#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  char ch[5+1], c[5];
  int i, j, k=0;

  srand ((unsigned)time(NULL));

  for(i=0; i<5; i++){
    c[i]= 0;
  }
  
  for(i=0; i<5; i++){
    ch[i]= rand()% ('z'-'a')+ 'a';
    c[i]= ch[i];
    
    for(j=0; j<5; j++){
      if(c[j]==ch[k]){
	i--;
      }
    }
    k++;
  }
  ch[i]= '\0';
    
  printf("%s\n", ch);

  return 0;
}
