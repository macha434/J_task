#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define TIMER clock_t start,end
#define START start=clock()
#define END end=clock()
#define PRINT_TIME printf("Program behavior time is %lf[s]\n",(end-start)/(CLOCKS_PER_SEC*1.0))
#define NUM 11

void swap(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}

void init(int array[],int array_size)
{
  int i;
  for(i=0;i<array_size;i++) array[i]=rand_range(0,NUM);
}
/*配列の単純選択ソート(昇順)*/
void select_sort(int array[],int array_size)
{
  int i,j;
  int min;
  int num;

  for(i=0;i<array_size-1;i++){
    min=array[i];
    num=i;

    for(j=i+1;j<array_size;j++){
      if(min>array[j]){min=array[j];num=j;}
    }
    swap(&array[i],&array[num]);
    for(int z=0;z<array_size;z++) printf("%d ",array[z]); //コメントアウト
    printf("\n");
  }
}
int main(void)
{
  TIMER;
  int array[NUM]={1,1,1,1,1,1,1};
  init(array,NUM);
  printf("-----Select-----\n");
  for(int z=0;z<NUM;z++) printf("%d ",array[z]); // コメントアウト
  printf("\n");
  START;
  select_sort(array,NUM);
  END;
  PRINT_TIME;
}
