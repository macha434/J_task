#include <stdio.h>

int count(char cha[]);

int main(){

	char cha[]= "programming\0";
	int c;

	c= count(cha);

	return 0;
}

int count(char cha[]){

	int c= 0;
	int i;

	for(i=0; cha[i]!= '\0'; i++){
		c++;
	}

	printf("文字数は%d個です\n", c);

	return c;
}
