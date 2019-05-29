#include <stdio.h>

char calcBattlePoint(char str[]);

int main(){
	char barcode[256];
	char str[256];

	printf("バーコードを読み取ってください");
	scanf("%s", barcode);

	str[256]= calcBattlePoint(barcode);
	
	printf("%s", str);
	return 0;
}
