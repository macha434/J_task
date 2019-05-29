#include <stdio.h>
#include <stdlib.h>

char **reverse_words(char **str, char **str_, int wc);

int main(void){
	char **str;
	char **str_;
	int word[255];
	int wc;
	int i, j, k;

	printf("単語数を入力してください:");
	scanf("%d", &wc);

	str= (char **)malloc(sizeof(char *)* wc);
	str_= (char **)malloc(sizeof(char *)* wc);

	for(i= 0; i< wc; i++){
		printf("%d単語目を入力してください:", i+ 1);
		scanf("%s", word);

		for(j= 0; word[j]!= '\0'; j++){
		}

		str[i]= (char *)malloc(sizeof(char)* j);
		str_[i]= (char *)malloc(sizeof(char)* j);

		for(j= 0; word[j]!= '\0'; j++){
			str[i][j]= word[j];
		}
		printf("a");
	}

	printf("a");

	str_= reverse_words(str, str_, wc);

	for(i= 0; i< wc; i++){
		printf("%s", str[i]);
		printf(" ");
	}

	for(i= 0; i< wc; i++){
		printf("%s", str_[i]);
		printf(" ");
	}

	for(i= 0; i< wc; i++){
		free(str[i]);
		free(str_[i]);
	}
	free(str);
	free(str_);

	return 0;
}

char **reverse_words(char **str, char **str_, int wc){
	int i, j;

	for(i= 0; i< wc; i++){
		for(j= 0; str[i][j]!= '\0'; j++){
			str_[i][j]= str[wc- i][j];		
		}
	}

	return str_;
}
