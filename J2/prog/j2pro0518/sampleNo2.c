#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * オープニング
 */
void opening(void)
{
  /* ここにプログラムを書く */
}

/*
 * キーボードから数値入力
 */
int getInputNumber(void)
{
  /* ここにプログラムを書く */
  return 0;
}

/*
 * サイコロ本体
 */
int dice(int num)
{
  /* ここにプログラムを書く */
  return 0;
}

/*
 * 仮想通貨に変換して結果出力
 */
void calcMoney(int num)
{
  /* ここにプログラムを書く */
}

int main(void)
{
  int num;
  int face;

  // 乱数を初期化
  srand((unsigned)time(NULL));

  // ゲームオープニングメッセージ
  opening();

  // サイコロが何回転がるか，キーボードから入力
  num = getInputNumber();
  
  // サイコロをふる
  face = dice(num);

  // サイコロの目に応じて金額が計算されて，出力される．
  calcMoney(face);

  return 0;
}
