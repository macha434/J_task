#include <stdio.h>
#include <stdlib.h>

void my_strcpy(char *str1, char *str2);
char *my_strcpy2(char *str1, char *str3);

int main(){
	int i;
	char *str1;
	char *str2;
	char *str3;

	printf("文字数を入力してください:");
	scanf("%d", &i);

	str1= (char *)malloc(sizeof(char)* (i+ 1));
	str2= (char *)malloc(sizeof(char)* (i+ 1));
	str3= (char *)malloc(sizeof(char)* (i+ 1));

	printf("文字を入力してください:");
	scanf("%s", str1);

	my_strcpy(str1, str2);
	str3= my_strcpy2(str1, str3);

	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);

	free(str1);
	free(str2);
	free(str3);

	return 0;
}

void my_strcpy(char *str1, char *str2){
	int i;

	for(i= 0; str1[i]!= '\0'; i++){
		str2[i]= str1[i];
	}

	str2[i]= '\0';
}

char *my_strcpy2(char *str1, char *str3){

	str3= str1;

	return str3;
}
