#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **numberBox;
  int i, ct;

  // 行数を決める
  numberBox = (int **)malloc(sizeof(int *) * 3);
  // 1行目の列数
  numberBox[0] = (int *)malloc(sizeof(int) * 3);
  // 2行目の列数
  numberBox[1] = (int *)malloc(sizeof(int) * 2);
  // 3行目の列数
  numberBox[2] = (int *)malloc(sizeof(int) * 4);
  
  ct = 1;
  // 1行目
  for (i=0; i<3; i++) {
    numberBox[0][i] = ct++;
  }
  // 2行目
  for (i=0; i<2; i++) {
    numberBox[1][i] = ct++;
  }
  // 3行目
  for (i=0; i<4; i++) {
    numberBox[2][i] = ct++;
  }

  // 出力
  for (i=0; i<3; i++) {
    printf("numberBox[%d][%d]=%d\n", 0, i, numberBox[0][i]);
  }
  for (i=0; i<2; i++) {
    printf("numberBox[%d][%d]=%d\n", 1, i, numberBox[1][i]);
  }
  for (i=0; i<4; i++) {
    printf("numberBox[%d][%d]=%d\n", 2, i, numberBox[2][i]);
  }

  free(numberBox[0]);
  free(numberBox[1]);
  free(numberBox[2]);
  free(numberBox);

  return 0;
}
