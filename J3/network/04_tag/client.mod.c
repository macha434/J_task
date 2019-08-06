/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 鬼ごっこゲームのクライアントプログラム */

#include "session.h"
#include "tag.h"
/*追加ヘッダ*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
void set(clock_t TIMER,int);
void setter(void);
int main(void)
{
  int soc;    /* ソケットのディスクリプタ */
  char hostname[HOSTNAME_LENGTH]; /* サーバ(相手)のホスト名 */

  /* サーバのホスト名の入力 */
  printf("input  server's  hostname: ");
  fgets(hostname, HOSTNAME_LENGTH, stdin);
  chop_newline(hostname, HOSTNAME_LENGTH);

  /* 接続まで */
  if ((soc = setup_client(hostname,PORT) ) == -1) {
    exit(1);
  }
  
  /* セッションモジュールの初期化 */
  session_init(soc, 'x', 10,10, 'o',1, 1);
  set((unsigned)time(NULL),1);
  setter();
  /* セッションのループ */
  session_loop();
  return 0;
}
