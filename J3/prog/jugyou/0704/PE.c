#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define NUM 10
int sums[10];
int indexx=0;
void dfs(int array[],int index,int sum)
{
  if(sum==10){
    for(int i=0;i<indexx;i++) printf("%d ",sums[i]);
    printf("\nFind\n");
    return ;
  }
  if(index>=NUM) return ;
    if(array[index]+sum<=10){
    sums[indexx]=array[index];
    indexx++;
    dfs(array,index+1,sum+array[index]);
    indexx--;
  }
  dfs(array,index+1,sum);
}
void swap(int *a,int *b)
{
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
void set(int array[])
{
  int s1,s2;
  for(int i=0;i<100;i++){
    s1=rand_range(0,9);
    s2=rand_range(0,9);
    swap(&array[s1],&array[s2]);
  }
}
int main(void)
{
  int array[NUM]={1,2,3,4,5,6,7,8,9,10};
  set(array);
  dfs(array,0,0);
  return 0;
}