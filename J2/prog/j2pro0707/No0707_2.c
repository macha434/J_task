#include <stdio.h>

char cha[]= "Which do you think more exciting, soccer or baseball?";
int count();

int main(){
	int c;
	int i= 0;

	c= count();

	printf("英単語数は%d個です。\n", c);

	return 0;
}

int count(){
	
	int i;
	int c= 1;

	for(i= 0; cha[i]!= '\0'; i++){
		if(cha[i]== ' '){
			c++;
		}
	}
	return c;
}
