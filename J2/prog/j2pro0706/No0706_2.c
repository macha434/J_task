#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define car 's'
#define NUM 100

int r();
int count();

int main()
{
	int array[NUM];
	int s;

	srand((unsigned)time(NULL));

	r(array);

	s= count(array);

	printf("sの個数は%d個です。\n", s);

	return 0;
}

int r(int array[NUM])
{
	int i;

	for(i=0; i<NUM; i++){
		array[i]= rand()% 26+ 'a';
	}
}

int count(int array[NUM])
{
	int i;
	int s=0;

	for(i=0; i<NUM; i++){
		if(array[i]==car){
			s++;
		}
	}

	return s;
}
