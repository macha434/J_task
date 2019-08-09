#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define TIMER clock_t start,end
#define START start=clock()
#define END end=clock()
#define PRINT_TIME printf("Program behavior time is %lf[s]",(end-start)/(CLOCKS_PER_SEC*1.0))
#define NUM 7

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

/*配列のバブルソート(昇順)*/
void bsort(int a[], int array_size)
{
  int i, j;
  for (i = 0; i < array_size - 1; i++) {
    for (j =0; j <array_size-1; j++) {
      if (a[j] > a[j+1])
	swap(&a[j], &a[j+1]);
    }
    for(int z=0;z<array_size;z++) printf("%d ",a[z]);
    printf("\n");
  }
}

int main()
{
  TIMER;
  int array[NUM]={1,1,1,1,1,1,1};
  init(array,NUM);
  printf("-----Buble-----\n");
  for(int z=0;z<NUM;z++) printf("%d ",array[z]);
  printf("\n");
  START;
  bsort(array,NUM);
  END;
  PRINT_TIME;
}
