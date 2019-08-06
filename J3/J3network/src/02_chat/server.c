/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/1-1              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT     (in_port_t)50000 /* ������(��ʬ)�Υݡ����ֹ� */
#define BUF_LEN  512              /* �������ΥХåե����礭�� */

main()
{
	/* �ѿ���� */
	struct sockaddr_in me; /* ������(��ʬ)�ξ���   */
	int soc_waiting;       /* listen���륽���å�   */
	int soc;               /* �������˻Ȥ������å� */
	char buf[BUF_LEN];     /* �������ΥХåե�     */

	/* ������(��ʬ)�Υ��ɥ쥹�� sockaddr_in ��¤�Τ˳�Ǽ  */
	memset((char *)&me, 0, sizeof(me));
	me.sin_family = AF_INET;
	me.sin_addr.s_addr = htonl(INADDR_ANY);
	me.sin_port = htons(PORT);

	/* IPv4�ǥ��ȥ꡼�෿�Υ����åȤ����  */
	if((soc_waiting = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
		perror("socket");
		exit(1);
	}

	/* ������(��ʬ)�Υ��ɥ쥹�򥽥��åȤ����� */
	if(bind(soc_waiting, (struct sockaddr *)&me, sizeof(me)) == -1){
	  perror("bind");
	  exit(1);
	}

	/* �����åȤ��Ԥ������뤳�Ȥ����� */
	listen(soc_waiting, 1);

	/* ��³�׵᤬���ޤǥ֥�å����� */
	soc = accept(soc_waiting, NULL, NULL);

	/* ��³�Ԥ��Τ���Υ����åȤ��Ĥ��� */
	close(soc_waiting);

	/* �����餫���� */
	write(1, "Go ahead!\n", 10);

	/* �̿��Υ롼�� */
	do{
	  int n;                       /* �ɤ߹��ޤ줿�Х��ȿ�  */

	  n = read(0, buf, BUF_LEN);   /* ɸ������0�����ɤ�     */
	  write(soc, buf, n);          /* �����å�soc�˽񤭽Ф� */
	  n = read(soc, buf, BUF_LEN); /* �����å�soc�����ɤ�   */
	  write(1, buf, n);            /* ɸ�����1�˽񤭽Ф�   */
	}
	while (strncmp(buf,"quit",4) != 0);         /* ��λȽ�� */

	/* �����åȤ��Ĥ��� */
	close(soc);
}
