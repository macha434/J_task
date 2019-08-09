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
int main(int argc,char *hostname[])
{
  int   soc;                       /* ソケット */
  // char  hostname[HOSTNAME_LENGTH]; /* サーバのホスト名 */

  /* サーバのホスト名の入力 */
  //printf("input server's hostname = ");
  //fgets(hostname, HOSTNAME_LENGTH, stdin);
  chop_newline(hostname[1], HOSTNAME_LENGTH);

  /* クライアントとしてのセットアップ */
  if ((soc = setup_client(hostname[1], PORT)) == -1) {
    exit(1);
  }

  /* セッションモジュールの初期化 */
  session_init(soc);

  /* セッションのメインループ */
  session_loop();
  return 0;
}
