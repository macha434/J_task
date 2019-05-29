#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void setData(int x[]);
void dispData(int x[]);
void sort(int x[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];

  setData(array);
  dispData(array);

  sort(array);

  dispData(array);

  return 0;
}

void setData(int x[])
{
  int i;

  srand(208);
  
  for (i=0; i<NUM; i++) {
    x[i] = rand()%100;
  }
  
}

void dispData(int x[])
{
  int i;
  
  for (i=0; i<NUM; i++) {
    printf("[%d] = %2d\n", i, x[i]);
  }
  printf("\n");
}

void sort(int x[]){
	int i, j;
	int min;	

	for (i=0; i<NUM; i++){
		
		min= i;

		for (j=i; j< NUM; j++){

			if (x[min]> x[j]){
				min= j;
			}
		}

		swap(&x[min], &x[i]);
	}
}

void swap(int *a, int *b){
	int tmp;

	tmp= *a;
	*a= *b;
	*b= tmp;
}
