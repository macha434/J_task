/*********************************************/
/*       File name:  setup_client.c          */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"

int setup_client(char *hostname, in_port_t port)
	/* �����   �����åȤΥǥ�������ץ� */
	/* hostname ��³��Υۥ���̾         */
	/* port     ��³��Υݡ����ֹ�       */
{
	/* �ѿ������ */
	struct hostent *server_ent; /* ��³��Υۥ��Ȥξ���       */
	struct sockaddr_in server;  /* ��³��Υ����åȤΥ��ɥ쥹 */
	int soc;                    /* �̿��˻Ȥ������å�         */

	/* ��³��Υۥ���̾����ۥ��Ȥξ�������� */
	if((server_ent = gethostbyname(hostname)) == NULL){
		perror("gethostbyname");
		return -1;
	}

	/* ��³��Υ��ɥ쥹�� sockaddr_in ��¤�Τ����� */
	memset((char *)&server,0,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	memcpy((char *)&server.sin_addr, server_ent->h_addr,
	       server_ent->h_length);

	/* IPv4 �ǥ��ȥ꡼�෿�Υ����åȤ���� */
	if ((soc = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket");
		return -1;
	}

	/* ��³ */
	if (connect(soc,(struct sockaddr *)&server,sizeof(server)) == -1){
		perror("connect");
		return -1;
	}
	fprintf(stderr, "connected.\n");

	/* �����åȤ��֤� */
	return soc;
}
