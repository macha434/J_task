#include <stdio.h>

int main(){
	char num1[]= {33, 35, 25, 43, 26, 43, 18, 23, 33, 29, 23, 37, 19, 29, 23, 33, 29, 23, 24, 29, 23, 25, 39, 30, 31, 29, 30, 37, 43, 33, 33, 29, 23, '\0'};
	int i, j;

	for(j=0; num1[j]!= '\0'; j++){
	
		num1[j]-= 18;printf("%d,", num1[j]);
	
		num1[j]+= 'a';
		printf("%d\n", num1[j]);
	}
	printf("%s\n", num1);

	return 0;
}
