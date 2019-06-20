/*********************************************/
/*       File name:  setup_server.c          */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"

int setup_server(in_port_t port)
	/* �����   �����åȤΥǥ�������ץ� */
	/* port     ��³��Υݡ����ֹ�       */
{
	struct sockaddr_in me; /* ��ʬ�Υ����åȤΥ��ɥ쥹 */
	int soc_waiting;       /* ��³�Ԥ��Υ����å�       */
	int soc;               /* �̿��˻Ȥ������å�       */

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
	listen(soc_waiting,1);
	fprintf(stderr,"successfully bound, now waiting.\n");

	/* ��³�׵᤬����ޤǥ֥�å� */
	soc = accept(soc_waiting, NULL, NULL);

	/* ��³�Ԥ��˻Ȥä������åȤ��Ĥ��� */
	close(soc_waiting);

	/* �̿��˻Ȥ������åȤΥǥ�������ץ����֤� */
	return soc;
}
