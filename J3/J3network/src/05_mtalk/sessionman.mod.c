/*********************************************/
/*       File name:  sessionman.c            */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* ミニ電子会議のセッション管理プログラム */

#include <stdio.h>
#include "stdc.h"
#include <sys/types.h>

#define	MAX_ATTENDANTS 5
#define BUF_LEN	     80


static char    buf[BUF_LEN];  /* 送受信バッファ           */
static fd_set  mask;	     /* select用初期化マスク     */
static int     width;         /* 監視ディスクリプタの範囲 */
static int     attendants;    /* 参加者人数               */

/* 参加者管理のためのデータ構造 */
typedef	struct {
  int   fd;
  char  name[16];
} ATTENDANT;

static ATTENDANT  p[MAX_ATTENDANTS]; /* 参加者情報の配列 */

/*  session のメインループの下請けルーチン */
static void  send_all(int i, int n);
static void  ending(void);


/*  enter は mserver_maccept() に渡されるコールバック関数 */
void enter(int  i, int  fd)
	/* i   受付番号                 */
	/* fd  送受信に使用するソケット */
{
  int  j,cnt=0;
  int  len;   /* 受信バイト数 */
  static char  *mesg1 = "Type your name within 15characters\n";
  static char  *mesg2 = "wait.\n";
  p[i].fd = fd;
  memset(p[i].name, 0, 16);
  write(fd, mesg1, strlen(mesg1));
  len = read(fd, p[i].name, 16);
  for(j=0;j<len;j++){
    if(p[i].name[j]=='\n') cnt++;
  }
  if(cnt>1) len=read(fd,p[i].name,16);
  
  sprintf(p[i].name + len - 1, "  -->  ");
  write(fd, mesg2, strlen(mesg2));
}


/*  セッションの初期化 */
void sessionman_init(int  num, int  maxfd)
	/* num    attendants の人数    */
	/* maxfd  最大のディスクリプタ */
{
  int  i;                /* ループカウンタ */
  static char  *mesg = "Communication Ready.\n";

  attendants = num;     /* 参加者人数の設定 */

  /* select のためのマスクを準備  */
  width = maxfd + 1;
  FD_ZERO(&mask);
  FD_SET(0, &mask);
  for (i = 0;  i < num;  i++) {
    FD_SET(p[i].fd , &mask);
  }

  /* セッション開始のメッセージを全員に送る */
  for (i = 0;  i < num;  i++) {
    write(p[i].fd, mesg, strlen(mesg));
  }
}

/*  セッションのメインループ  */
void  sessionman_loop(void)
{
  fd_set  readOk;     /* selectのためのマスク */
  int  i;             /* ループカウンタ       */

  while(1) {
    /*  select の前に毎回 readOk を初期化する */
    readOk = mask;
    select(width, (fd_set *)&readOk, NULL, NULL, NULL);

    /*  キーボードからの入力ありか？ */
    if ( FD_ISSET(0, &readOk ) ) {
      ending();
    }

    /* ソケットを順に調べる */
    for (i = 0;  i < attendants;  i++) {
      if (FD_ISSET(p[i].fd, &readOk)) {
	int  n;
	
	n = read(p[i].fd, buf, BUF_LEN);
	send_all(i, n);
      }
    }
  }
}


/************************************/
/*  メインループの下請けルーチン達  */
/************************************/

/* 終了処理 */
static void  ending(void)
{
  int  i;

  for (i = 0;  i < attendants;  i++) {
    write(p[i].fd, "quit", 4);
  }

  for (i = 0;  i < attendants;  i++) {
    close(p[i].fd);
  }

  exit(0);
}

static void  send_all(int  i, int  n)
     /* i  p[i] の名前を付けて */
     /* n  送信バイト数        */
{
  int  j;

  for (j = 0;  j < attendants;  j++) {
    write(p[j].fd, p[i].name, strlen(p[i].name));
    write(p[j].fd, buf, n);
  }
}
