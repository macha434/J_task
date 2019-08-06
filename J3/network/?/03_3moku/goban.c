/*********************************************/
/*       File name:  goban.c                 */
/*    Project name:  socket/3moku            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 碁盤モジュール */

#include "goban.h"

/******************/
/* 非公開の変数群 */
/******************/

static char goban_my_stone;   /* 自分の石 */
static char goban_peer_stone; /* 相手の石 */

/* 碁盤の定義と初期化 */
static char goban_plane[7][7] = { "  123 ",
                                  " +---+",
                                  "a|...|", /*[2][2]~[4][4]*/
                                  "b|...|",
                                  "c|...|",
                                  " +---+"};

static int goban_soc;         /* ソケットのディスクリプタ */

/********************/
/* 公開される関数群 */
/********************/

/* 碁盤初期化 */
void goban_init(int soc, char my_stone, char peer_stone)
	/* soc        通信用ソケット */
	/* my_stone   自分の石       */
	/* peer_stone 相手の石       */
{
	/* これらのデータは最後まで保持される */
	goban_soc=soc;
	goban_my_stone=my_stone;
	goban_peer_stone=peer_stone;
}

/* 碁盤の表示 */
void goban_show()
{
	int i;
	for(i=0;i<6;i++) {
		printf("%s\n",goban_plane[i]);
	}
}

/* 相手の番の処理 */
int goban_peer_turn()
{
	char data[10]; /* 受信バッファ */
	int x,y;       /* 座標 */

	/* ソケットから読む */
	read(goban_soc,data,10);

	/* 先頭バイトを見て終了か判定 */
	if ( data[0] == 'q' ) return -1;

	/* 座標データの取り出し */
	y = (int)data[0] - (int)'a' + 1;
	x = (int)data[1] - (int)'0';

	/* データの更新 */
	goban_plane[y+1][x+1] = goban_peer_stone;

	return 1;
}

/* 自分の番の処理 */
int goban_my_turn()
{
	char data[10]; /* 送信バッファ */
	int x,y;       /* 座標 */

	/* キーボード入力 */
	while(1){
		fgets(data, 10, stdin);
		y = (int)data[0] - (int)'a' + 1;
		x = (int)data[1] - (int)'0';

		if( data[0] == 'q' )
			{ write(goban_soc,data,1); return -1; }
		/* 石があった場合 もう一度入力 */
		if(goban_plane[y+1][x+1]!='.') continue;

		/*データの入力に誤りがないか検出*/
		if( data[0] < 'a' || data[0] > 'c' ||
		    data[1] < '1' || data[1] > '3' ) continue;

		break;
	}

	/* データの更新 */
	y = (int)data[0] - (int)'a' + 1;
	x = (int)data[1] - (int)'0';
	goban_plane[y+1][x+1] = goban_my_stone;

	/* 送信 */
	write(goban_soc,data,10);

	return 1;
}
bool game_judge(void)
{
  char p1='x';
  char p2='o';
  int cnt1=0;
  int cnt2=0;
  
  /*横判定*/
  for(int i=2;i<5;i++){
    for(int j=2;j<5;j++){
      if(goban_plane[i][j]==p1) cnt1++;
      else if(goban_plane[i][j]==p2) cnt2++;
    }
    if(cnt1==3){
      printf("Client Win\n");
      return true;
    }
    if(cnt2==3){
      printf("Server Win\n");
    }
    cnt1=0;
    cnt2=0;
  }
  
  /*縦判定*/
  for(int i=2;i<5;i++){
    for(int j=2;j<5;j++){
      if(goban_plane[j][i]==p1) cnt1++;
      else if(goban_plane[j][i]==p2) cnt2++;
    }
    if(cnt1==3){
      printf("Client Win\n");
      return true;
    }
    if(cnt2==3){
      printf("Server Win\n");
    }
    cnt1=0;
    cnt2=0;
  }
  
  /*斜め判定*/
  for(int i=2;i<5;i++){
    if(goban_plane[i][i]==p1) cnt1++;
    else if(goban_plane[i][i]==p2) cnt2++;
  }
  if(cnt1==3){
    printf("Client Win\n");
    return true;
  }
  if(cnt2==3){
    printf("Server Win\n");
  }
  cnt1=0;
  cnt2=0;
  
  for(int i=4;i>=2;i--){
    if(goban_plane[6-i][i]==p1) cnt1++;
    else if(goban_plane[6-i][i]==p2) cnt2++;
  }
  if(cnt1==3){
    printf("Client Win\n");
    return true;
  }
  if(cnt2==3){
    printf("Server Win\n");
  }
  cnt1=0;
  cnt2=0;

  /*引き分け*/
  for(int i=2;i<5;i++){
    for(int j=2;j<5;j++){
      if(goban_plane[i][j]!='.') cnt1++;
    }
  }
  if(cnt1==9){
    printf("Draw\n");
    return true;
  }
  
  return false;
}
/* 終了処理 */
void goban_destroy(){
	close(goban_soc);
}


