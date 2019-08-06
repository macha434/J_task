#include <stdio.h>

void my_strcpy(char str2[], char str1[]);

int main(){
	char str1[]= "programming";
	char str2[100];

	my_strcpy(str2, str1);
	printf("%s\n", str2);

	return 0;
}

void my_strcpy(char str2[], char str1[]){
	int i;

	for(i= 0; str1[i]!= '\0'; i++){
		str2[i]= str1[i];
	}
	str2[i]= '\0';
}
