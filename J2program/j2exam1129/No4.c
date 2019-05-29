#include <stdio.h>
#include <stdlib.h>

void sum(int *num, int n);
void reverce(int *num, int n);

int main(void){
	int n;
	int i;
	int *num;

	printf("入力する数字の個数を入力してください:");
	scanf("%d", &n);

	num= (int*)malloc(sizeof (int)* n);

	for(i= 0; i< n; i++){
		printf("array[%d]= ", i);
		scanf("%d", &num[i]);
	}

	sum(num, n);

	reverce(num, n);

	free(num);

	return 0;
}

void sum(int *num, int n){
	int val;
	int i;

	for(i= 0; num[i]!= '\0'; i++){
		val+= num[i];

		printf("%d", num[i]);
		
		if(i!= n- 1){
		       printf(" + ");
		}
	}

	printf(" = %d\n\n", val);
}

void reverce(int *num, int n){
	int i;

	for(i= 0; num[i]!= '\0'; i++){

		printf("array[%d]= %d\n", n- i, num[n- i]);

	}
}
