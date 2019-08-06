/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* ミニ電子会議サーバプログラム */

#include <stdio.h>
#include "sessionman.h"
#include "mylib.h"


int main(int  argc,  char  *argv[])
	/* argc     2であって欲しい */
	/* argv[1]  参加者人数      */
{
  int  num;   /* 参加者人数           */
  int  soc;   /* 待ち受けソケット     */
  int  maxfd; /* 最大のディスクリプタ */

  /* 引数で参加者人数を知る。 */
  if (argc != 2) {
    fprintf(stderr,"Usage: s  attendants\n");
    exit(1);
  }

  /* 引数の変換  文字列 --> int  */
  if ((num = atoi(argv[1])) <= 0  ||  num > MAX_ATTENDANTS) {
    fprintf(stderr, "attendants limit= %d\n", MAX_ATTENDANTS);
    exit(1);
  }

  /* ソケットのディスクリプタを soc に受け取る */
  if ( (soc = mserver_socket(PORT, num)) == -1) {
    fprintf(stderr, "cannot setup server\n");
    exit(1);
  }

  /* m_accept にコールバック関数の enter を渡す。
     返って来るのは最大のディスクリプタ */
  maxfd = mserver_maccept(soc, num, enter);

  /* セッションモジュールの初期化 */
  sessionman_init(num, maxfd);

  /* セッション管理のメインループ */
  sessionman_loop();
  return 0;
}
