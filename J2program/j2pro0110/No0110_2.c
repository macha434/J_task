#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
	int array[NUM];

	initialize(array);
	disp_array(array);

	sort(array);
  
	return 0;
}

void initialize(int array[])
{
	int i;
  
	srand(0);

	for (i=0; i<NUM; i++) {
		array[i] = rand()%100;
	}
}

void disp_array(int array[])
{
	int i;

	for (i=0; i<NUM; i++) {
		printf("%d\n", array[i]);
	}
	printf("\n");

}

void sort(int array[])
{
	int i, j;
	int min;
	int ind;
	int count1= 0, count2= 0;

	for (i= 0; i< NUM- 1; i++){
		ind= i;
		for (j= i; j< NUM; j++){

			if(array[j]< array[ind]){
				ind= j;
			}

			count2++;
		}
		if(i!= ind){
			swap(&array[i], &array[ind]);
			count1++;
		}
	}
	disp_array(array);
	
	printf("比較回数%d回, 交換回数%d回\n", count2, count1);
}

void swap(int *a, int* b){
	int tmp;

	tmp= *a;
	*a= *b;
	*b= tmp;
}
