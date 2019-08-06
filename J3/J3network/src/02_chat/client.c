/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/1-1              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT     (in_port_t)50000 /* ������(���)�Υݡ����ֹ� */
#define BUF_LEN  512              /* �������ΥХåե����礭�� */

main()
{
	/* �ѿ���� */
	struct hostent  *server_ent; /* ������(���)�ξ��� */
	struct sockaddr_in  server;  /* ������(���)�Υ��ɥ쥹 */
	int soc;                     /* �����åȤΥǥ�������ץ� */
	char hostname[]="cisprof08"; /* ������(���)�Υۥ���̾ */
	char buf[BUF_LEN];           /* �������ΥХåե�  */

	/* ������(���)�Υۥ���̾���饢�ɥ쥹���������  */
	if((server_ent = gethostbyname(hostname)) == NULL){
		perror("gethostbyname");
		exit(1);
	}

	/* ������(���)�Υ��ɥ쥹�� sockaddr_in ��¤�Τ˳�Ǽ  */
	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	memcpy((char *)&server.sin_addr, server_ent->h_addr,
	       server_ent->h_length);

	/* IPv4�ǥ��ȥ꡼�෿�Υ����åȤ����  */
	if((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		exit(1);
	}

	/* ������(���)����³  */
	if(connect(soc, (struct sockaddr *)&server, sizeof(server)) == -1){
		perror("connect");
		exit(1);
	}

	/* ��꤬�� */
	write(1, "Wait\n", 5);

	/* �̿��Υ롼�� */
	do{
		int n;                       /* �ɤ߹��ޤ줿�Х��ȿ�  */

		n = read(soc, buf, BUF_LEN); /* �����å�soc�����ɤ�   */
		write(1, buf, n);            /* ɸ�����1�˽񤭽Ф�   */
		n = read(0, buf, BUF_LEN);   /* ɸ������0�����ɤ�     */
		write(soc, buf, n);          /* �����å�soc�˽񤭽Ф� */
	}
	while( strncmp(buf, "quit" ,4) != 0 );        /* ��λȽ�� */

	/* �����åȤ��Ĥ��� */
	close(soc);
}
