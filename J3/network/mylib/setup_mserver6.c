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
	/* �����   �Ԥ����������åȤΥǥ�������ץ� */
	/* port     ��³��Υݡ����ֹ�               */
	/* backlog  �Ԥ������ο�                     */
{
	/* �ѿ������ */
	struct addrinfo  hints; /* ��ʬ�ˤĤ����ΤäƤ�����ʬŪ�ʾ���    */
	struct addrinfo *res;   /* hints�˴�Ť�������̤γ�Ǽ����ؤ� */
	int soc_waiting;        /* ��³�Ԥ��Υ����å�                    */
	char portstring[8];     /* �ݡ����ֹ��10��ʸ����                */
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

	/* IPv4 �ޤ��� IPv6 �ǥ����åȤκ��� */
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
	if (listen(soc_waiting, backlog) == -1){
		perror("listen");
		return -1;
	}
	fprintf(stderr,"successfully setup, now waiting.\n");

	/* �����ǻȤä�ưŪ�������� */
	freeaddrinfo(res);

	/* �Ԥ������ѤΥǥ�������ץ����֤� */
	return soc_waiting;
}

/*  �ޥ���������ץ�  */

int mserver_maccept(int soc_waiting, int limit, void (*func)() )
	/* �����   ����Υ����åȤΥǥ�������ץ�      */
	/* soc_waiting   �Ԥ������˻Ȥ������å�         */
	/* limit    accept �ξ��                       */
	/* func     accept ��˼¹Ԥ���ؿ��ؤΥݥ��� */
{
	int i;   /* �롼�ץ����� */
	int fd;  /* �ǥ�������ץ�������������ѿ� */

	/* accept �� limit ����¹� */
	for(i=0; i<limit; i++){
		if((fd = accept(soc_waiting, NULL, NULL))==-1){
			fprintf(stderr, "accept error\n");
			return -1;
		}
		(*func)(i, fd);
	}

	/* �Ԥ������Υ����åȤ��Ĥ��� */
	close(soc_waiting);

	/* �Ǹ�� fd �Ĥޤ�����ͤ��֤� */
	return fd;
}
