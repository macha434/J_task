#include <stdio.h>

int main(void)
{
	char barcode[100];
	int i;
	int total= 0;

	printf("バーコードを読み込ませてください:");
	scanf("%s", barcode);

	for(i=0; barcode[i]!= '\0'; i++){
		total+= barcode[i]- '0';
	}

	printf("合計は%dです。\n", total);

	return 0;
}
