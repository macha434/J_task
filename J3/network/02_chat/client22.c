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

#define PORT     (in_port_t)50000 /* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾ポ¥申鐃緒申鐃瞬刻申 */
#define BUF_LEN  512              /* 鐃緒申鐃緒申鐃緒申鐃塾バッフワ申鐃緒申鐃順き鐃緒申 */

int main()
{
	/* 鐃術随申鐃緒申鐃緒申 */
	struct hostent  *server_ent; /* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾常申鐃緒申 */
	struct sockaddr_in  server;  /* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾ワ申鐃宿レス */
	int soc;                     /* 鐃緒申鐃緒申鐃獣トのデワ申鐃緒申鐃緒申鐃緒申鐃竣ワ申 */
	char hostname[]="localhost"; /* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾ホワ申鐃緒申名 */
	char buf[BUF_LEN];           /* 鐃緒申鐃緒申鐃緒申鐃塾バッフワ申  */
	char P_input[]="Please Input message = ";
	char P_Wait[]="Wait...\n";
	char P_output[]="Message is ";
	/* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾ホワ申鐃緒申名鐃緒申鐃初ア鐃宿レス鐃緒申鐃緒申鐃緒申鐃緒申鐃緒申  */
	if((server_ent = gethostbyname(hostname)) == NULL){
		perror("gethostbyname");
		exit(1);
	}

	/* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃塾ワ申鐃宿レス鐃緒申 sockaddr_in 鐃緒申造鐃塾に鰹申納  */
	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	memcpy((char *)&server.sin_addr, server_ent->h_addr,
	       server_ent->h_length);

	/* IPv4鐃叔ワ申鐃夙リー鐃準型鐃塾ワ申鐃緒申鐃獣トわ申鐃緒申鐃緒申  */
	if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(1);
	}

	/* 鐃緒申鐃緒申鐃緒申(鐃緒申鐃緒申)鐃緒申鐃緒申続  */
	if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
		perror("connect");
		exit(1);
	}

	/* 鐃緒申鐃所が鐃緒申 */

	/* 鐃縮随申鐃塾ルー鐃緒申 */
	do{		int n;                       /* 鐃宿み刻申鐃殉れた鐃出ワ申鐃夙随申  */
		write(1,P_Wait,strlen(P_Wait));
	  n = read(soc, buf, BUF_LEN); /* 鐃緒申鐃緒申鐃獣ワ申soc鐃緒申鐃緒申鐃宿わ申   */
	  write(1,P_output,strlen(P_output));
	  write(1, buf, n);            /* 標鐃緒申鐃緒申鐃緒申1鐃祝書き出わ申   */
	  write(1,P_input,strlen(P_input));
	  n = read(0, buf, BUF_LEN);   /* 標鐃緒申鐃緒申鐃緒申0鐃緒申鐃緒申鐃宿わ申     */
	  write(soc, buf, n);          /* 鐃緒申鐃緒申鐃獣ワ申soc鐃祝書き出わ申 */
	}
	while( strncmp(buf, "quit" ,4) != 0 );        /* 鐃緒申了判鐃緒申 */

	/* 鐃緒申鐃緒申鐃獣トわ申鐃縦わ申鐃緒申 */
	close(soc);
}
