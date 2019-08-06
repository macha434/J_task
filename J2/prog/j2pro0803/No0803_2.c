#include <stdio.h>

void No1(char cha[]);
void No2(char cha[]);
void No3(char cha[]);
void No4(char cha[]);

int main(){
	char cha[]= "What time is it now?\0";

	No1(cha);
	No2(cha);
	No3(cha);
	No4(cha);

	return 0;
}

void No1(char cha[]){

	printf("(1)%s\n\n", cha);
}

void No2(char cha[]){
	int i;

	printf("(2)");

	for(i=0; cha[i]!= '\0'; i++){
		if(i% 2== 0){
			printf("%c", cha[i]);
		}else{
			printf(" ");
		}
	}
	printf("\n");
}

void No3(char cha[]){
	int i, j;

	printf("(3)\n");

	for(i=0; cha[i]!= '\0'; i++){
		printf("%c\n", cha[i]);

		for(j=i+ 1; j!= 0; j--){
			printf(" ");
		}
	}
	printf("\n");
}

void No4(char cha[]){
	int i, j= 0;
	int num;
	char ch[256];

	printf("(4)何単語目を表示したいですか。:");
	scanf("%d", &num);

	while(num<= 0 || num> 5){
		printf("何単語目を表示したいですか。:");
		scanf("%d", &num);	
	}

	switch(num){
		case 1:
			for(i=0; i<4; i++){
				ch[i]= cha[j];
				j++;
			}
			ch[i]= '\0';
			break;
		case 2:
			for(i=0; i<4; i++){
				ch[i]= cha[j+5];
				j++;
			}
			ch[i]= '\0';
			break;
		case 3:
			for(i=0; i<2; i++){
				ch[i]= cha[j+ 10];
				j++;
			}
			ch[i]= '\0';
			break;
		case 4:
			for(i=0; i<2; i++){
				ch[i]= cha[j+ 13];
				j++;
			}
			ch[i]= '\0';
			break;
		case 5:
			for(i=0; i<3; i++){
				ch[i]= cha[j+ 16];
				j++;
			}			
			ch[i]= '\0';
			break;
	}

	printf("%s\n", ch);
}
