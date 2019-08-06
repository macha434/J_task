#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define TIMER clock_t start,end
#define START start=clock()
#define END end=clock()
#define Print_Time printf("%lf[ms]",((end-start)*1.0)/(CLOCKS_PER_SEC*1.0))
bool check_word(char wordA[],char wordB[])
{
  int i,j;
  int a,b;
  a=strlen(wordA);
  b=strlen(wordB);
  if(a!=b) return false;

  for(i=0;i<a;i++){
    if(wordA[i]!=wordB[i]) return false;
  }

  return true;
}
int main()
{
  int i=0,j=0;
  int c=0;        
  char word[1000][1000];
  char str[1000];
  char ss[1000];  
  bool flag=true; 
  scanf("%[^\n]",str);
  TIMER;
  START;
  for(i=0;i<strlen(str);i++){
    if(str[i]==' '||str[i]==','){i++;j++;c=0;}
    word[j][c]=str[i];
    c++;
  }
  c=j;
  for(i=0;i<=c;i++){
    for(j=i-1;j>=0;j--){
      if(check_word(word[i],word[j])) flag=false;
    }
    if(flag){strcat(ss,word[i]);strcat(ss," ");}
    flag=true;
  }
  printf("%s",ss);
  END;
  Print_Time;
  return 0;
}
