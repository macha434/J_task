/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/1-1              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT     (in_port_t)50000 /* サーバ(相手)のポート番号 */
#define BUF_LEN  512              /* 送受信のバッファの大きさ */

int main()
{
	/* 変数宣言 */
	struct hostent  *server_ent; /* サーバ(相手)の情報 */
	struct sockaddr_in  server;  /* サーバ(相手)のアドレス */
	int soc;                     /* ソケットのディスクリプタ */
	char hostname[]="J3F175.local.j.kisarazu.ac.jp"; /* サーバ(相手)のホスト名 */
	char Prompt_In
	char buf[BUF_LEN];           /* 送受信のバッファ  */

	/* サーバ(相手)のホスト名からアドレス情報を得る  */
	if((server_ent = gethostbyname(hostname)) == NULL){
		perror("gethostbyname");
		exit(1);
	}

	/* サーバ(相手)のアドレスを sockaddr_in 構造体に格納  */
	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	memcpy((char *)&server.sin_addr, server_ent->h_addr,
	       server_ent->h_length);

	/* IPv4でストリーム型のソケットを作成  */
	if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(1);
	}

	/* サーバ(相手)に接続  */
	if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
		perror("connect");
		exit(1);
	}

	/* 相手が先 */
	write(1, "Wait\n", 5);

	/* 通信のループ */
	do{		int n;                       /* 読み込まれたバイト数  */
	  printf("wait.\n");
	  n = read(soc, buf, BUF_LEN); /* ソケットsocから読む   */
	  printf("Received message is \n");
	  write(1, buf, n);            /* 標準出力1に書き出す   */
	  printf("Please input =\n");
	  n = read(0, buf, BUF_LEN);   /* 標準入力0から読む     */
	  write(soc, buf, n);          /* ソケットsocに書き出す */
	}
	while( strncmp(buf, "quit" ,4) != 0 );        /* 終了判定 */

	/* ソケットを閉じる */
	close(soc);
}
