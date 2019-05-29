#include <stdio.h>
#include <stdlib.h>

#define NUM 5
#define MAX 100

void disp_filename(char *x[]);
void No1(char x[][MAX]);
void No2(char x[][MAX]);
void No3(char x[][MAX]);
void No4(char x[][MAX]);

int main(void)
{
	char filename[][MAX] = {"travel.jpeg",
				"kyouto_temple.jpg",
				"flower_fes.jpeg",
				"R0005237.jpg",
				"SOb80617.jpeg"};

	No1(filename);

	No2(filename);

	No3(filename);

	No4(filename);
  
	return 0;
}

void disp_filename(char *x[]){
	int i;

	for(i= 0; i< MAX; i++){
		printf("%s", x[i]);
	}
}

void No1(char x[][MAX]){
  
	printf("\n(1)\n%s\n", x[2]);

}

void No2(char x[][MAX]){
	int i, j;

	printf("\n(2)\n");

	for(i= 0; x[2][i]!= '\0'; i++){
	}

	for(j= 0; j< i- 4; j++){
		printf("%c", x[2][j]);
	}

	printf("jpg\n");
}

void No3(char x[][MAX]){
	int i, j;

	printf("\n(3)\n");

	for(i= 0; x[0][i]!= '\0'; i++){
	}

	for(j= 0; j< i- 4; j++){
		printf("%c", x[0][j]);
	}
	printf("jpg\n");

	printf("%s\n", x[1]);

	for(i= 0; x[2][i]!= '\0'; i++){
	}

	for(j= 0; j< i- 4; j++){
		printf("%c", x[2][j]);
	}
	printf("jpg\n");

	printf("%s\n", x[3]);

	for(i= 0; x[4][i]!= '\0'; i++){
	}

	for(j= 0; j< i- 4; j++){
		printf("%c", x[4][j]);
	}
	printf("jpg\n");
}

void No4(char x[][MAX]){
	int i, j;
	int k, l;
	char **filename;

	filename= (char **)malloc(sizeof (char *)* 5);

	for(i= 0; i< MAX; i++){
		for(j= 0; x[i][j]!= '\0'; j++){
		}

		filename[i]= (char *)malloc(sizeof (char)* j);
	}

	
	for(k= 0; k< i; k++){
		for(l= 0;l< j; l++){
			filename[k][l]= x[k][l];
		}
	}

	disp_filename(filename);
}
