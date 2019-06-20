/*********************************************/
/*       File name:  setup_client6.c         */
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
	struct addrinfo  hints; /* ��³�����ʬŪ�ʾ���       */
	struct addrinfo *res;   /* hints�˴�Ť�������̤γ�Ǽ���   */
	int soc;                /* �̿��˻Ȥ������å�                 */
	char portstring[8];     /* ����ϥ����ӥ�̾�����ݡ����ֹ��10��ʸ���� */

	/* �����Υҥ�Ȥ����� */
	sprintf(portstring, "%d", port);
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* ��³��ξ���򸡺� */
	if(getaddrinfo(hostname, portstring, &hints, &res) != 0){
		perror("getaddrinfo");
		return -1;
	}

	/* IPv4 �ޤ��� IPv6 �ǥ����åȤκ��� */
	if((soc = socket(res->ai_family,
	   res->ai_socktype, res->ai_protocol)) < 0){
		perror("socket");
		return -1;
	}

	/* ��³ */
	if(connect(soc,(struct sockaddr *)res->ai_addr,
	   res->ai_addrlen) == -1){
		perror("connect");
		return -1;
	}
	fprintf(stderr, "connected.\n");

	/* �����ǻȤä�ưŪ����β��� */
	freeaddrinfo(res);

	/* �����åȤΥǥ�������ץ����֤� */
	return soc;
}
