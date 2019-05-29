#include <stdio.h>
#define NUM 4

int my_strlen1(char cha[]);
int my_strlen2(char *cha);
int my_strlen3(char cha[]);
void my_strlen4(char cha[], int *i);

int main(void){
	int i;
	int strlen[NUM];
	char cha[255];
	
	scanf("%s", cha);

	strlen[0]= my_strlen1(cha);

	strlen[1]= my_strlen2(cha);

	strlen[2]= my_strlen3(cha);

	my_strlen4(cha, &strlen[3]);

	for(i= 0; i< NUM; i++){
		printf("%d= %d\n", i+ 1, strlen[i]);
	}

	return 0;
}

int my_strlen1(char cha[]){
	int i;

	for(i= 0; cha[i]!= '\0'; i++){
	}

	return i;
}

int my_strlen2(char *cha){
	int i;

	for(i= 0; cha[i]!= '\0'; i++){
	}

	return i;
}

int my_strlen3(char cha[]){
	int i;

	for(i= 0; ; i++){
		if(cha[i]== '\0'){
			break;
		}
	}
	return i;
}

void my_strlen4(char cha[], int *strlen){
	int i;

	for(i= 0; cha[i]!= '\0'; i++){
	}

	*strlen= i;
}
