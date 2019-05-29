#include <stdio.h>

int main(void)
{
	char barcode[100];
	int i;
	int n= 0;

	printf("バーコードを読み込ませてください:");
	scanf("%s", barcode);

	for(i=0; barcode[i]!= '\0'; i++){
		n++;
	}

	n-= 4;

	for(i=0; i<4; i++){
		printf("%c", barcode[n]);
		n++;
	}
	printf("\n");

	return 0;
}
