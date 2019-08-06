#include <stdio.h>

int main(){
	char ciphertex[]= "lpvtfotbjlpvuboptijjob\0";
	int i, j;

	for(i=0; i<26; i++){
		for(j=0; ciphertex[j]!='\0' ;j++){
			ciphertex[j]-= 1;
		}
		printf("%s\n", ciphertex);
	}

	return 0;
}
