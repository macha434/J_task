#include <stdio.h>

int main(){
	char ciphertex[]= "hayakikoikoinatsuyasumi\0";
	int i;

	for(i=0; ciphertex[i]!='\0' ;i++){
		ciphertex[i]+= 1;
	}
	printf("%s\n", ciphertex);
	
	for(i=0; ciphertex[i]!='\0' ;i++){
		ciphertex[i]-= 1;
	}
	printf("%s\n", ciphertex);


	return 0;
}
