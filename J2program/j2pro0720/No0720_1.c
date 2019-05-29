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

	for(; n>= 0; n--){
		printf("%c", barcode[n]);
	}
	printf("\n");

	return 0;
}
