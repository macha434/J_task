#include <stdio.h>
#include <stdlib.h>

#define NUM 500
#define MAX 1000

void initialize(int data[]);
void disp_top10(int data[]);
void average(int data[]);
void sort(int data[]);
void swap(int *a, int *b);
void median(int data[]);
void more_num(int data[]);

int main(void)
{
  int data[NUM];
  
  srand(207);
  
  initialize(data);
	
  disp_top10(data);

  average(data);

  sort(data);

  disp_top10(data);

  median(data);

  more_num(data);
  
  return 0;
}

void initialize(int data[])
{
  int i;
  
  for (i=0; i<NUM; i++) {
    data[i] = rand()%MAX;
  }
}

void disp_top10(int data[])
{
  int i;
  
  for (i=0; i<10; i++) {
    printf("%2d %3d\n", i, data[i]);
  }
  printf("\n");
}

void average(int data[]){
	int i;
	int sum;
	double ave;

	for (i=0; i<NUM; i++){
		sum+= data[i];
	}

	ave= sum/ NUM;

	printf("\n\nave= %f\n\n", ave);
}

void sort(int data[]){
	int i, j;
	int min;

	for (i=0; i<NUM; i++){

		for(j=NUM- 1; j>i; j--){

			if(data[j-1]> data[j]){

				swap(&data[j-1], &data[j]);
			}
		}
	}
}

void swap(int *a, int *b){
	int tmp;

	tmp= *a;
	*a= *b;
	*b= tmp;
}

void median(int data[]){
	int med;
	int a;

	a= NUM/ 2;

	printf("\n\nmedian= ");

	if(NUM% 2 == 0){
		printf("%d\n\n", data[a]);
	}else{
		printf("%d, %d\n\n", data[a], data[a- 1]);
	}
}

void more_num(int data[]){
	int i, j;
	int a[MAX];
	int b= 0;
	int tmp;

	for (i=0; i<NUM; i++){
		tmp= data[i];

		a[tmp]++;
	}

	for (j=0; j<NUM; j++){
		if(a[b]< a[j]){
			b= j;
		}
	}

	printf("\n\n最頻値は%d\n\n", data[b]);
}
