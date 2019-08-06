/*********************************************/
/*       File name:  setup_mserver6.c        */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define HOSTNAME_LENGTH 64

int mserver_socket(in_port_t port, int backlog)
	/* 戻り値   待ち受けソケットのディスクリプタ */
	/* port     接続先のポート番号               */
	/* backlog  待ち受けの数                     */
{
	/* 変数の宣言 */
	struct addrinfo  hints; /* 自分について知っている部分的な情報    */
	struct addrinfo *res;   /* hintsに基づく検索結果の格納場所を指す */
	int soc_waiting;        /* 接続待ちのソケット                    */
	char portstring[8];     /* ポート番号の10進文字列                */
	char hostname[HOSTNAME_LENGTH];               /* 自分のホスト名  */

	/* 検索のヒントの設定 */
	gethostname(hostname, HOSTNAME_LENGTH);
	sprintf(portstring, "%d", port);
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* 自分に関する情報を検索 */
	if(getaddrinfo(hostname, portstring, &hints, &res) != 0){
		perror("getaddrinfo");
		return -1;
	}

	/* IPv4 または IPv6 でソケットの作成 */
	if((soc_waiting = socket(res->ai_family,
	   res->ai_socktype, res->ai_protocol)) < 0){
		perror("socket");
		return -1;
	}

	/* ソケットに自分のアドレスを設定 */
	if(bind(soc_waiting, res->ai_addr, res->ai_addrlen)!=0){
		perror("bind");
		return -1;
	}

	/* ソケットで接続待ちの設定 */
	if (listen(soc_waiting, backlog) == -1){
		perror("listen");
		return -1;
	}
	fprintf(stderr,"successfully setup, now waiting.\n");

	/* 検索で使った動的メモリを解放 */
	freeaddrinfo(res);

	/* 待ち受け用のディスクリプタを返す */
	return soc_waiting;
}

/*  マルチアクセプト  */

int mserver_maccept(int soc_waiting, int limit, void (*func)() )
	/* 戻り値   最大のソケットのディスクリプタ      */
	/* soc_waiting   待ち受けに使うソケット         */
	/* limit    accept の上限                       */
	/* func     accept 毎に実行する関数へのポインタ */
{
	int i;   /* ループカウンタ */
	int fd;  /* ディスクリプタを入れる作業用変数 */

	/* accept を limit 回数実行 */
	for(i=0; i<limit; i++){
		if((fd = accept(soc_waiting, NULL, NULL))==-1){
			fprintf(stderr, "accept error\n");
			return -1;
		}
		(*func)(i, fd);
	}

	/* 待ち受けのソケットを閉じる */
	close(soc_waiting);

	/* 最後の fd つまり最大値を返す */
	return fd;
}
