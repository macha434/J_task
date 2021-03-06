/*********************************************/
/*       File name:  session.c               */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <sys/types.h>
#include <curses.h>
#include <signal.h>
/*追加ヘッダ*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*追加関数*/
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define NUMBER 10

#define BUF_LEN 20
#define MIN_X	1
#define MIN_Y	1
#define MAX_X	60
#define MAX_Y	20

static int map_flag[MAX_Y][MAX_X];

/* 移動キーの割り当て */
#define NORTH 'k'
#define SOUTH 'j'
#define EAST  'l'
#define WEST  'h'
#define QUIT  'q'

/* プライベート変数 */
static  int    session_soc;     /* socket  */
static  fd_set mask;            /* fd mask */
static  int    width;           /* width of the mask */
static  char   my_char, peer_char; /* character */

typedef	struct{
  int x,y;
  char	look;  /* character */
} PLAYER;

static PLAYER  me, peer;    /* 自分と相手の状態を保持する変数  */

static char  buf[BUF_LEN];  /* 送受信兼用バッファ */

static WINDOW  *win;	   /* 表示用ウィンドウ */

/*  session モジュールにプライベートな関数  */
static void  hide(PLAYER *who);
static void  show(PLAYER *who);
static int   update(PLAYER *who, int c);
static int   interpret(PLAYER *who);
static void  die();

/*  session モジュールの初期化  */
void  session_init(int soc,
                   char mc, int mx, int my,
                   char pc, int px, int py)
	   /* soc  ソケットのディスクリプタ */
	   /* mc   自分の表示用の文字       */
	   /* mx   自分の初期x座標          */
	   /* my   自分の初期y座標          */
	   /* pc   相手の表示用の文字       */
	   /* px   相手の初期x座標          */
	   /* py   相手の初期y座標          */
{
  /* 初期データの設定 */
  session_soc = soc;
  width = soc + 1;
  FD_ZERO(&mask);
  FD_SET(0, &mask);
  FD_SET(session_soc, &mask);
  me.look = mc;
  peer.look = pc;

  me.x = mx;  me.y = my;
  peer.x = px;  peer.y = py;

  /* curses の初期化 */
  initscr();
  signal(SIGINT, die);

  /* ウィンドウ枠 */
  win = newwin(MAX_Y + 2, MAX_X + 2, 0, 0);
  box(win, '|', '-');

  /* 端末設定 */
  cbreak();
  noecho();
}

/*  初期位置の設定  */
void set(clock_t TIMES,int flag)
{
  /* ランダムに生成 */
  srand(TIMES);

  if(flag==0){                        /* サーバー側 */
    me.x=rand_range(MIN_X,MAX_X);
    me.y=rand_range(MIN_Y,MAX_Y);
    peer.x=rand_range(MIN_X,MAX_X);
    peer.y=rand_range(MIN_Y,MAX_Y);
  }else{                              /*クライアント側*/
    peer.x=rand_range(MIN_X,MAX_X);
    peer.y=rand_range(MIN_Y,MAX_Y);
    me.x=rand_range(MIN_X,MAX_X);
    me.y=rand_range(MIN_Y,MAX_Y);
  }
}

/*  障害物の設置   */
void setter(void)
{
  int x,y;
  for(int i=0;i<NUMBER;i++){
    x=rand_range(MIN_X,MAX_X);
    y=rand_range(MIN_Y,MAX_Y);
    map_flag[y][x]=1;
    wmove(win,y,x);
    waddch(win,'.');
  }
}
/*  session メインループ  */
void  session_loop()
{
  int c;         /* キーボードからの入力文字 */
  int flag;      /* ループ継続フラッグ       */
  fd_set readOk; /* 多重入力のマスク         */

  /* 自分の姿の表示 */
  show(&me);
  /*相手の姿の表示*/
  show(&peer);
  /* ループ継続フラッグの初期化 */
  flag = 1;

  /* ループ */
  while(1) {
    /*  select の前に毎回 readOk を初期化する。 */
    readOk = mask;
    select(width,(fd_set *)&readOk,NULL,NULL,NULL);

    /*  キーボードからの入力ありか？ */
    if (FD_ISSET(0, &readOk) ) {
      c = getchar();            /* キーボードから入力     */
      hide(&me);                /* 自分の姿を隠す         */
      flag = update(&me, c);    /* 状態を更新             */
      show(&me);                /* 自分の姿を現す         */
      write(session_soc, buf, BUF_LEN);  /* 更新データを送る */
      if (flag == 0) {  /* ループ抜け出し判定  */
	break;
      }
    }
    /*  ソケットにデータありか？ */
    if (FD_ISSET(session_soc, &readOk) ) {
      read(session_soc,buf,BUF_LEN); /* ソケットから入力  */
      hide(&peer);              /* 相手の姿を隠す         */
      flag = interpret(&peer);  /* 相手の状態の更新       */
      show(&peer);              /* 相手の姿を現す         */
      if (flag == 0) {  /* ループ抜け出し判定  */
	break;
      }
    }
    
    /*もし移動先が自分だった場合*/
    if(me.x==peer.x&&me.y==peer.y) break;
  }

  /* 端末属性を復旧して終わる */
  die();
}


static void  show(PLAYER *who)
	/* who  誰を表示するか  */
{
  wmove(win, who->y, who->x); /* whoの場所に動く           */
  waddch(win, who->look);     /* その場所にwhoのlookを置く */
  wmove(win, who->y, who->x); /* カーソルを戻す            */
  wrefresh(win);              /* ウィンドウの更新          */
}


static void  hide(PLAYER *who)
	/* who  誰の姿を消すか  */
{
  wmove(win, who->y, who->x); /* whoの場所に動く           */
  waddch(win, ' ');           /* その場所にスペースを書く  */
}


static int  update(PLAYER *who, int c)
	/* who  誰を             */
	/* c    どちらへ動かすか */
{
  switch (c) {
  case WEST:
    if ( who->x > MIN_X && map_flag[who->y][(who->x)-1]==0) {
      who->x --;
    }
    break;
  case SOUTH:
    if ( who->y < MAX_Y && map_flag[(who->y)+1][who->x]==0) {
      who->y ++;
    }
    break;
  case NORTH:
    if ( who->y > MIN_Y && map_flag[(who->y)-1][who->x]==0) {
      who->y --;
    }
    break;
  case EAST:
    if ( who->x < MAX_X && map_flag[who->y][(who->x)+1]==0) {
      who->x ++;
    }
    break;
  case QUIT:
    buf[0] = QUIT;
    return 0;
  default:
    break;
  }

  /* 更新された位置データを送信用文字列に変換する */
  sprintf(buf, "%d %d\n", who->x, who->y);

  return 1;
}

static int  interpret(PLAYER *who)
	/* who 解釈後のデータの格納先を指す */
{
  /* もし相手が終了を希望したら */
  if (buf[0] == 'q') {
    return 0;
  }
  
  /* 受信文字列から位置データに変換する。 */
  sscanf(buf, "%d %d", &who->x, &who->y);

  return 1;
}

static void  die()
{
  endwin();  /* 端末属性の復旧 */

  exit(0);
}
