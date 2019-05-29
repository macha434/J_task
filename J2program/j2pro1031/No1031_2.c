#include <stdio.h>
#include <stdlib.h>

int average(char *point);

int main(){
	int i;
	int nop, ave;
	char *point;

	printf("何人ですか?\n");
	scanf("%d", &nop);

	point= (char *)malloc(sizeof(char)* (nop+1));

	for(i= 0; i< nop; i++){

		printf("%d人目の点数は:", i+ 1);
		scanf("%d", &point[i]);

		if(point[i]> 5){
			printf("error\n");
			return 0;
		}
	}

	ave= average(point);

	printf("%d人の平均は%dです\n", nop, ave);

	free(point);

	return 0;
}

int average(char *point){
	int i;
	int ave= 0, total= 0;

	for(i= 0; *point; i++){
		total+= *point;
		point++;
	}

	ave= total/ i;

	return ave;
}
