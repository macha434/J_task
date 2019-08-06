#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#define TIMER clock_t start,end
#define START start=clock()
#define END end=clock()
#define PER 2525
#define HASH 123+rand()%4545
#define Print_Time printf("%lf[ms]",((end-start)*1.0)/(CLOCKS_PER_SEC*1.0))
#define max(num1,num2) num1>num2?num1:num2
void set_hash(char words[],int hasher[])
{
  static int rand_time;
  int times=1;
  int hash_val=0;
  srand(rand_time);
  for(int i=0;i<strlen(words);i++){
    hash_val+=(abs((int)words[i]-'~')+strlen(words)*times)%114514+(rand()%PER);
    times++;
  }
  hash_val-=2000;
  hasher[(abs(hash_val)%255)^HASH]++;
  rand_time++;
}
int hash(char words[])
{
  static int rand_time;
  int times=1;
  int hash_val=0;
  srand(rand_time);
  for(int i=0;i<strlen(words);i++){
    hash_val+=(abs((int)words[i]-'~')+strlen(words)*times)%114514+(rand()%PER);
    times++;
  }
  hash_val-=2000;
  rand_time++;
  return (abs(hash_val)%255)^HASH;
}
int main()
{
  int i=0,j=0;
  int c=0;
  int val;
  int hit=0;
  int max_val=-1;
  char word[1000][1000];
  char str[1000];
  static int hasher[114514];
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
    set_hash(word[i],hasher);
  }

  for(i=0;i<=c;i++){
    val=hash(word[i]);
    max_val=max(max_val,val);
    printf("val=%d\n",val);
    if(hasher[val]==1){
      printf("%s ",word[i]);
      hasher[val]=0;
    }
    else if(hasher[val]>1){
      hit++;
      hasher[val]=1;
    }
  }
  printf("\nhit = %d\nmax=%d\n",hit,max_val);
  END;
  Print_Time;
  return 0;
}
