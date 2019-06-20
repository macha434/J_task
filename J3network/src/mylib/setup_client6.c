/*********************************************/
/*       File name:  setup_client6.c         */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"

int setup_client(char *hostname, in_port_t port)
	/* 戻り値   ソケットのディスクリプタ */
	/* hostname 接続先のホスト名         */
	/* port     接続先のポート番号       */
{
	struct addrinfo  hints; /* 接続先の部分的な情報       */
	struct addrinfo *res;   /* hintsに基づく検索結果の格納場所   */
	int soc;                /* 通信に使うソケット                 */
	char portstring[8];     /* 本来はサービス名だがポート番号の10進文字列 */

	/* 検索のヒントの設定 */
	sprintf(portstring, "%d", port);
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* 接続先の情報を検索 */
	if(getaddrinfo(hostname, portstring, &hints, &res) != 0){
		perror("getaddrinfo");
		return -1;
	}

	/* IPv4 または IPv6 でソケットの作成 */
	if((soc = socket(res->ai_family,
	   res->ai_socktype, res->ai_protocol)) < 0){
		perror("socket");
		return -1;
	}

	/* 接続 */
	if(connect(soc,(struct sockaddr *)res->ai_addr,
	   res->ai_addrlen) == -1){
		perror("connect");
		return -1;
	}
	fprintf(stderr, "connected.\n");

	/* 検索で使った動的メモリの解放 */
	freeaddrinfo(res);

	/* ソケットのディスクリプタを返す */
	return soc;
}
