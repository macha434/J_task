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

	for (i= 1; i<= NUM; i++){
		for (j= 0; j< NUM- i; j++){
			if(array[j]> array[j+1]){
				swap(&array[j], &array[j+1]);
				count2++;
			}
			count1++;
		}
	}
	disp_array(array);

	printf("比較回数%d回, 交換回数%d回\n", count1, count2);
}

void swap(int *a, int* b){
	int tmp;
	int count;

	tmp= *a;
	*a= *b;
	*b= tmp;
}
