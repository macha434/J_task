#include <stdio.h>

int main(void)
{
  char barcode[100];

  printf("バーコードを読み込ませてください:");
  scanf("%s", barcode);

  printf("Barcode : %s\n", barcode);
  printf("Barcode[5] : %c\n", barcode[5]);

  return 0;
}
