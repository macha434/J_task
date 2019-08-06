/*********************************************/
/*       File name:  setup_server6.c         */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"
#define HOSTNAME_LENGTH 64

int setup_server(in_port_t port)
	/* �����   �����åȤΥǥ�������ץ� */
	/* port     ��³��Υݡ����ֹ�       */
{
	struct addrinfo  hints; /* ��ʬ�ˤĤ����ΤäƤ�����ʬŪ�ʾ���    */
	struct addrinfo *res;   /* hints�˴�Ť�������̤γ�Ǽ����ؤ� */
	int soc_waiting;        /* ��³�Ԥ��Υ����å�                    */
	int soc;                /* �̿��˻Ȥ������å�                    */
	char portstring[8];     /* �ݡ����ֹ�ν���ʸ����                */
	char hostname[HOSTNAME_LENGTH];               /* ��ʬ�Υۥ���̾  */

	/* �����Υҥ�Ȥ����� */
	gethostname(hostname, HOSTNAME_LENGTH);
	sprintf(portstring, "%d", port);
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* ��ʬ�˴ؤ������򸡺� */
	if(getaddrinfo(hostname, portstring, &hints, &res) != 0){
		perror("getaddrinfo");
		return -1;
	}

	/* IPv4 �ޤ��� IPv6�ǥ����åȤκ��� */
	if((soc_waiting = socket(res->ai_family,
	   res->ai_socktype, res->ai_protocol)) < 0){
		perror("socket");
		return -1;
	}

	/* �����åȤ˼�ʬ�Υ��ɥ쥹������ */
	if(bind(soc_waiting, res->ai_addr, res->ai_addrlen)!=0){
		perror("bind");
		return -1;
	}

	/* �����åȤ���³�Ԥ������� */
	listen(soc_waiting, 1);
	fprintf(stderr, "successfully bound, now waiting.\n");

	/* ��³�׵᤬����ޤǥ֥�å� */
	soc = accept(soc_waiting, NULL, NULL);

	/* ��³�Ԥ��˻Ȥä������åȤ��Ĥ��� */
	close(soc_waiting);

	/* �����˻Ȥä�ưŪ����β��� */
	freeaddrinfo(res);

	/* �̿��˻Ȥ������åȤΥǥ�������ץ����֤� */
	return soc;
}
