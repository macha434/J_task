#include <stdio.h>
#include <string.h>
#include <time.h>
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

/*配列のクイックソート(昇順)*/
void quick_sort(int array[],int left , int right)
{
    int l = left;
    int r = right;
    int pivot = array[(left + right) / 2]; 

    while (1) {
        while (array[l] < pivot) l++;
        while (array[r] > pivot) r--;

        if (l > r) break;
        swap(&array[l],&array[r]);
        l++, r--;
    }
    for(int z=0;z<NUM;z++){
	printf("%d ",array[z]);
    }
    printf("\n");
    if (left < r)  quick_sort(array, left, r);
    if (l < right) quick_sort(array, l, right);
    for(int z=0;z<NUM;z++) printf("%d ",array[z]);
    printf("\n");
}
int main()
{
  TIMER;
  int array[NUM]={0,1,2,5,3,47,15};
  printf("-----Quick-----\n");
  for(int z=0;z<NUM;z++) printf("%d ",array[z]);
  printf("\n");
  START;
  quick_sort(array,0,NUM-1);
  END;
  PRINT_TIME;
}
