#include <stdio.h>

int setNumber();
int dispNumber();
int doubleNumber();

int main()
{
	int array[10+1];

	setNumber(array);
	dispNumber(array);

	doubleNumber(array);
	dispNumber(array);

	return 0;
}

int setNumber(int array[10+1])
{
	int i;

	for(i=0; i<10; i++){
		array[i]=i+ 1;
	}
	array[i]='\0';
}

int dispNumber(int array[])
{
	int i;

	for(i=0; i<10; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
	printf("\n");
}

int doubleNumber(int array[10+1])
{
	int i;

	for(i=0; i<10; i++){
		array[i]= array[i]* 2;
	}
}
