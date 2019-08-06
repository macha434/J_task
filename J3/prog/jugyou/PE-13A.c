#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define TIMER clock_t start,end
#define START start=clock()
#define END end=clock()
#define Print_Time printf("%lf[ms]",((end-start)*1.0)/(CLOCKS_PER_SEC*1.0))
struct Hash_Table{
	char words[500];
	int num;
};
typedef struct Hash_Table Hash;
void Add_Table(Hash *Table,Hash *END_Table,char word[])
{
  static int times;
  static int hit;
  for(int i=0;Table+i!=END_Table,i++){
    if(strcmp(Table->words,word)==0){
      hit++;
      return ;
    }
  }
}
void Check_Table(Hash *Table,Hash *END_Table)
{
	int hit=0;
	while(Table!=END_Table+1){
		hit+=(Table->num)-1;
		Table++;
	}
	printf("%d",hit);
}
int main()
{
  int i=0,j=0;
  int c=0;
  int val;
  int hit=0;
  char word[1000][1000];
  char str[1000];
  Hash Table[200];
  bool flag=true; 
  scanf("%[^\n]",str);
  TIMER;
  START;
  printf("Ok");
  for(i=0;i<strlen(str);i++){
    if(str[i]==' '||str[i]==','){i++;j++;c=0;}
    word[j][c]=str[i];
    c++;
  }
  c=j;
  for(i=0;i<=c;i++){
    Add_Table(Table,Table+i,word[i]);
  }

    Check_Table(Table,Table+c);
  printf("hit = %d\n",hit);
  END;
  Print_Time;
  return 0;
}
