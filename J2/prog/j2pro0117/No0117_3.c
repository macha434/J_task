#include <stdio.h>
#include <stdlib.h>

#define NUM 100

void initialize(char array[]);
void disp_array(char array[]);
void sort(char array[]);
void swap(char *a, char *b);

int main(void)
{
	char array[NUM];

	initialize(array);
	disp_array(array);

	sort(array);
	disp_array(array);
  
	return 0;
}

void initialize(char array[])
{
	int i;
  
	srand(0);

	for (i=0; i<NUM; i++) {
		array[i] = rand()%26+ 97;
	}
}

void disp_array(char array[])
{
	int i;

	for (i=0; i<NUM; i++) {
		printf("%c\n", array[i]);
	}
	printf("\n");

}

void sort(char array[])
{
	int i, j;
	int min;
	int ind;

	for (i= 1; i<= NUM; i++){
		for (j= 0; j< NUM- i; j++){
			if(array[j]> array[j+1]){
				swap(&array[j], &array[j+1]);
			}
		}
	}
	printf("\n");
}

void swap(char *a, char* b){
	char tmp;

	tmp= *a;
	*a= *b;
	*b= tmp;
}
