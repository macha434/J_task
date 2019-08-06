/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/3moku            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* 3���¤٤θ��(������)�ץ���� */

#include "goban.h"
extern bool game_judge();
int main(void)
{
	int soc;              /* �����åȤΥǥ�������ץ� */
	char my_stone='o';    /* ��ʬ����                 */
	char peer_stone='x';  /* ������                 */

	/* ��³���մ�λ�ޤ� */
	if( (soc=setup_server(PORT))==-1){
		exit(1);
	}

	/* ���פν���� */
	goban_init(soc, my_stone, peer_stone);

	/* �롼�� */
	while(1){
		/* ������ */
		goban_show();
		if(game_judge()) break;
		printf("Wait.\n");
		if( goban_peer_turn() == -1 ) break;

		/* ��ʬ���� */
		goban_show();
		if(game_judge()) break;
		printf("Go ahead.\n");
		if( goban_my_turn() == -1 ) break;
	}

	/* ��λ���� */
	goban_destroy();
}

