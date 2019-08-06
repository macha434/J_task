/*********************************************/
/*       File name:  setup_mserver,c         */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int mserver_socket(in_port_t port, int backlog)
	/* �����   �Ԥ����������åȤΥǥ�������ץ� */
	/* port     ��³��Υݡ����ֹ�               */
	/* backlog  �Ԥ������ο�                     */
{
	/* �ѿ������ */
	struct sockaddr_in me; /* ��ʬ�Υ����åȤΥ��ɥ쥹         */
	int soc_waiting;       /* �Ԥ����������åȤΥǥ�������ץ� */

	/* ��ʬ�Υ��ɥ쥹�� sockaddr_in ��¤�Τ����� */
	memset((char *)&me, 0, sizeof(me));
	me.sin_family = AF_INET;
	me.sin_addr.s_addr = htonl(INADDR_ANY);
	me.sin_port = htons(port);

	/* IPv4 �ǥ��ȥ꡼�෿�Υ����åȤκ��� */
	if ((soc_waiting = socket(AF_INET,SOCK_STREAM,0)) < 0 ){
		perror("socket");
		return -1;
	}

	/* �����åȤ˼�ʬ�Υ��ɥ쥹������ */
	if (bind(soc_waiting,(struct sockaddr *)&me,sizeof(me)) == -1){
		perror("bind");
		return -1;
	}

	/* �����åȤ���³�Ԥ������� */
	if (listen(soc_waiting, backlog) == -1){
		perror("listen");
		return -1;
	}
	fprintf(stderr,"successfully setup, now waiting.\n");

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
