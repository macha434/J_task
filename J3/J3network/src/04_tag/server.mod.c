/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 鬼ごっこゲームのサーバプログラム */

#include "session.h"
#include "tag.h"

/*追加ヘッダ*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
void set(clock_t TIMER,int);
void setter(void);
int main(void)
{
  int soc;   /* ソケットのディスクリプタ */

  /* 接続受付まで */
  if ((soc = setup_server(PORT) ) == -1) {
    exit(1);
  }

  /* セッションモジュールの初期化 */
  session_init(soc, 'o', 1, 1, 'x', 10, 10);
  set((unsigned)time(NULL),0);
  setter();
  /* セッションのループ */
  session_loop();
  return 0;
}
