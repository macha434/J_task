#include <stdio.h>
#include <stdlib.h>

int main(){
	char **name;
	char str[255];
	int count;
	int nop= 0;
	int i, j;

	printf("人数を入力してください:");
	scanf("%d", &nop);

	name= (char **)malloc(sizeof(int *)* nop);

	for(i= 0; i< nop; i++){

		printf("%d人目の名前を入力してください:", i+ 1);
		scanf("%s", str);

		for(j= 0; str[j]!= '\0'; j++){
		}

		name[i]= (char *)malloc(sizeof(int)* j);

		for(j= 0; str[j]!= '\0'; j++){
			name[i][j]= str[j];
		}
	}

	for(i= 0; i< nop; i++){
		for(j= 0; name[i][j]!= '\0'; j++){

			printf("%c", name[i][j]);
		}
		
		printf("\n");
	}

	for(i= 0; i< nop; i++){
		free(name[i]);
	}

	free(name);

	return 0;
}
