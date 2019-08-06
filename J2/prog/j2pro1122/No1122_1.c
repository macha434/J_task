#include <stdio.h>

void change_pointer(char *str1, char *str2);

int main(void){
	int i;
	char *str1= "abcde";
	char *str2= "xyz";

	change_pointer(str1, str2);

	return 0;
}

void change_pointer(char *str1, char *str2){
	char *tem= str1;

	str1= str2;
	str2= tem;

	printf("str1= %s\n", str1);
	printf("str2= %s\n", str2);
}
