/*********************************************/
/*       File name:  setup_server6.c         */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"
#define HOSTNAME_LENGTH 64

int setup_server(in_port_t port)
	/* 戻り値   ソケットのディスクリプタ */
	/* port     接続先のポート番号       */
{
	struct addrinfo  hints; /* 自分について知っている部分的な情報    */
	struct addrinfo *res;   /* hintsに基づく検索結果の格納場所を指す */
	int soc_waiting;        /* 接続待ちのソケット                    */
	int soc;                /* 通信に使うソケット                    */
	char portstring[8];     /* ポート番号の十進文字列                */
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

	/* IPv4 または IPv6でソケットの作成 */
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
	listen(soc_waiting, 1);
	fprintf(stderr, "successfully bound, now waiting.\n");

	/* 接続要求があるまでブロック */
	soc = accept(soc_waiting, NULL, NULL);

	/* 接続待ちに使ったソケットを閉じる */
	close(soc_waiting);

	/* 検索に使った動的メモリの解放 */
	freeaddrinfo(res);

	/* 通信に使うソケットのディスクリプタを返す */
	return soc;
}
