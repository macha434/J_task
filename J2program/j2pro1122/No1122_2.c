#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shufful_card(char *trunp);

int main(void){
	char trunp[255];
	int i;
	int j= 100;
	int k= 1;

	srand((unsigned)time(NULL));

	for(i= 0; i< 52; i++){
		trunp[i]= j+ k;

		k++;

		if(k== 13){
			j+= 100;
			k= 1;
		}
	}

	trunp[i]= 0;
	
	shufful_card(trunp);

	return 0;
}

void shufful_card(char *trunp){
	char shufful[53];
	int sto[53];
	int i, j;
	int num;

	for(i= 0; i< 53; i++){
	
		num= rand()% 53;
		
		for(j= 0; j< i; j++){
			if(sto[j]== num){
				num= rand()% 53;
				j--;
			}
		}

		printf("%d= %d\n", i, num);

		sto[i]= num;

		shufful[i]= trunp[num];
	}

	for(i= 0; i< 53; i++){
		switch(shufful[i]/ 100){
			case 1:
				printf("S %d", shufful[i]% 100);
				break;

			case 2:
				printf("H %d", shufful[i]% 100);
				break;

			case 3:
				printf("C %d", shufful[i]% 100);
				break;

			case 4:
				printf("D %d", shufful[i]% 100);
				break;

			case 0:
				printf("Joker");
				break;
		}

		printf("\n");
	}
}
