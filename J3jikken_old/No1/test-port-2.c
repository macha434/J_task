#include "h8-3052-iodef.h"


int main(void)
{
  P9DDR = 0x30;  /* ポート9の初期化(P94--P95を出力に設定) */

  P9DR = 0x10;  /* 出力データをセット */

  while(1)
  {
    /* 得に何もせず無限ループ */
  }
}
