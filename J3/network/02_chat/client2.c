/*********************************************/
/*       File name:  client2.c               */
/*    Project name:  socket/1-1              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT     (in_port_t)50000 /* サーバ(相手)のポート番号 */
#define BUF_LEN  512              /* 送受信のバッファの大きさ */


int main(void)
{
	struct hostent  *server_ent;
	struct sockaddr_in  server;
	int    soc;  /* descriptor for socket */
	char   ip_str[]="192.168.123.140";
	struct in_addr  ip;
	char   buf[BUF_LEN];

	inet_aton(ip_str, &ip);

	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	memcpy((char *)&server.sin_addr, &ip, sizeof(ip));

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
	do{
		int n;                       /* 読み込まれたバイト数  */

		n = read(soc, buf, BUF_LEN); /* ソケットsocから読む   */
		write(1, buf, n);            /* 標準出力1に書き出す   */
		n = read(0, buf, BUF_LEN);   /* 標準入力0から読む     */
		write(soc, buf, n);          /* ソケットsocに書き出す */
	}
	while( strncmp(buf, "quit", 4) != 0 );        /* 終了判定 */

	/* ソケットを閉じる */
	close(soc);
}
