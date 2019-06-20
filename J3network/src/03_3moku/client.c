/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/3moku            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 3���¤٤����(���饤�����)�ץ���� */

#include "goban.h"

main()
{
	int soc;              /* �����åȤΥǥ�������ץ� */
	char my_stone='x';    /* ��ʬ����                 */
	char peer_stone='o';  /* ������                 */
	char hostname[64];    /* ���(������)�Υۥ���̾   */

	/* �����ФΥۥ���̾������ */
	printf("Input  server's  hostname: ");
	fgets(hostname, HOSTNAME_LENGTH, stdin);
	chop_newline(hostname, HOSTNAME_LENGTH);

	/* ��³��λ�ޤ� */
	if( (soc=setup_client(hostname, PORT))==-1){
		exit(1);
	}

	/* ���פν���� */
	goban_init(soc,my_stone,peer_stone);

	/* �롼�� */
	while(1){
		/* ��ʬ���� */
		goban_show();
		printf("Go ahead.\n");
		if( goban_my_turn() == -1 ) break;

		/* ������ */
		goban_show();
		printf("Wait.\n");
		if( goban_peer_turn() == -1 ) break;
	}

	/* ��λ���� */
	goban_destroy();
}
