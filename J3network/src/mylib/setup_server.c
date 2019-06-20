/*********************************************/
/*       File name:  setup_server.c          */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"

int setup_server(in_port_t port)
	/* 戻り値   ソケットのディスクリプタ */
	/* port     接続先のポート番号       */
{
	struct sockaddr_in me; /* 自分のソケットのアドレス */
	int soc_waiting;       /* 接続待ちのソケット       */
	int soc;               /* 通信に使うソケット       */

	/* 自分のアドレスを sockaddr_in 構造体に設定 */
	memset((char *)&me, 0, sizeof(me));
	me.sin_family = AF_INET;
	me.sin_addr.s_addr = htonl(INADDR_ANY);
	me.sin_port = htons(port);

	/* IPv4 でストリーム型のソケットの作成 */
	if ((soc_waiting = socket(AF_INET,SOCK_STREAM,0)) < 0 ){
		perror("socket");
		return -1;
	}

	/* ソケットに自分のアドレスを設定 */
	if (bind(soc_waiting,(struct sockaddr *)&me,sizeof(me)) == -1){
		perror("bind");
		return -1;
	}

	/* ソケットで接続待ちの設定 */
	listen(soc_waiting,1);
	fprintf(stderr,"successfully bound, now waiting.\n");

	/* 接続要求があるまでブロック */
	soc = accept(soc_waiting, NULL, NULL);

	/* 接続待ちに使ったソケットを閉じる */
	close(soc_waiting);

	/* 通信に使うソケットのディスクリプタを返す */
	return soc;
}
