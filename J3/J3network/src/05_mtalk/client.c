/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* ミニ電子会議クライアントプログラム */

#include "session.h"
#include "mylib.h"
#include <stdlib.h>
int main(void)
{
  int   soc;                       /* ソケット */
  char  hostname[HOSTNAME_LENGTH]; /* サーバのホスト名 */

  /* サーバのホスト名の入力 */
  printf("input server's hostname = ");
  fgets(hostname, HOSTNAME_LENGTH, stdin);
  chop_newline(hostname, HOSTNAME_LENGTH);

  /* クライアントとしてのセットアップ */
  if ((soc = setup_client(hostname, PORT)) == -1) {
    exit(0);
  }

  /* セッションモジュールの初期化 */
  session_init(soc);

  /* セッションのメインループ */
  session_loop();
  return 0;
}
