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
    for(int z=0;z<array_size;z++) printf("%d ",array[z]);
    printf("\n");
  }
}

/*配列の挿入ソート(昇順)*/
void insertion_sort (int array[], int array_size)
{
  int i, j;
  int array[]={1,51,20,51,21,561,4,56,16};
  for (i = 1; i < array_size; i++) {   // 先頭から順にソート
    j = i;
    while ((j > 0) && (array[j-1] > array[j])) {   //整列済みの場合は処理しない
      swap(&array[j-1], &array[j]);   // 整列されていない要素を交換
      j--;
    }
    for(int z=0;z<array_size;z++) printf("%d ",array[z]);
    printf("\n");
  }
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
  int array[NUM]={1,1,1,1,1,1,1};
  printf("-----Insert-----\n");
  for(int z=0;z<NUM;z++) printf("%d ",array[z]);
  printf("\n");
  START;
  insertion_sort(array,NUM);
  END;
  PRINT_TIME;
}
