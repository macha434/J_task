/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/3moku            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 3目並べの先手(クライアント)プログラム */

#include "goban.h"
extern bool game_judge();
int main(void)
{
	int soc;              /* ソケットのディスクリプタ */
	char my_stone='x';    /* 自分の石                 */
	char peer_stone='o';  /* 相手の石                 */
	char hostname[64];    /* 後手(サーバ)のホスト名   */

	/* サーバのホスト名の入力 */
	printf("Input  server's  hostname: ");
	fgets(hostname, HOSTNAME_LENGTH, stdin);
	chop_newline(hostname, HOSTNAME_LENGTH);

	/* 接続完了まで */
	if( (soc=setup_client(hostname, PORT))==-1){
		exit(1);
	}

	/* 碁盤の初期化 */
	goban_init(soc,my_stone,peer_stone);

	/* ループ */
	while(1){
		/* 自分の番 */
		goban_show();
		if(game_judge())break;
		printf("Go ahead.\n");
		if( goban_my_turn() == -1 ) break;
		/* 相手の番 */
		goban_show();
		if(game_judge())break;
		printf("Wait.\n");
		if( goban_peer_turn() == -1 ) break;
	}
	/* 終了処理 */
	goban_destroy();
}
