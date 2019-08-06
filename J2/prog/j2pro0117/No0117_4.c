#include <stdio.h>


void swap(char* a, char* b);

int main(){
	int i;
	char str[2][255];

	printf("1つ目の単語を入力してください。");
	scanf("%s", str[0][255]);

	printf("2つ目の単語を入力してください。");
	scanf("%s", str[2][255]);

	for(i= 0; str[0][i]!= '\0' || str[1][i]!= '\0'; i++){
		swap(&str[0][i], &str[1][i]);
	}

	printf("1つ目:%s\n", str[0][i]);
	printf("2つ目:%s\n", str[1][i]);
}

void swap(char* a, char* b;){
	char keep;

	keep= *a;
	*a= *b;
	*b= keep;
}
