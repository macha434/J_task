#include <stdio.h>
#include <stdlib.h>

char *word_count(char *s1, char *s2, char *str1, char *str2);
char *exchange(char *s1, char *s2, char *str1, char *str2);

int main(void){
	char *str1, *str2;
	char s1[255], s2[255];

	printf("Please enter two strings\n");
	printf("1:");
	scanf("%s", s1);

	printf("2:");
	scanf("%s", s2);

	*word_count(s1, s2, str1, str2);
	*exchange(s1, s2, str1, str2);

	printf("str1= %s\n", str1);
	printf("str2= %s\n", str2);

	free(str1);
	free(str2);

	return 0;
}

char *word_count(char  s1[], char s2[], char *str1, char *str2){
	int i, j;

	for(i= 0; s1[i]!= '\0'; i++){
	}

	for(j= 0; s2[i]!= '\0'; i++){
	}

	str1= (char *)malloc(sizeof(char)* j);
	str2= (char *)malloc(sizeof(char)* i);

}

char *exchange(char s1[], char s2[], char *str1, char *str2){
	int i, j;

	for(i= 0; s1[i]!= '\0'; i++){
		str2[i]= s1[i];
	}

	for(j= 0; s2[j]!= '\0'; j++){
		str1[i]= s2[j];
	}
}
