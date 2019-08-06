/*********************************************/
/*       File name:  goban.c                 */
/*    Project name:  socket/3moku            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* ���ץ⥸�塼�� */

#include "goban.h"

/******************/
/* ��������ѿ��� */
/******************/

static char goban_my_stone;   /* ��ʬ���� */
static char goban_peer_stone; /* ������ */

/* ���פ�����Ƚ���� */
static char goban_plane[6][7] = { "  123",
                                  " +---+",
                                  "a|...|",
                                  "b|...|",
                                  "c|...|",
                                  " +---+"};

static int goban_soc;         /* �����åȤΥǥ�������ץ� */

/********************/
/* ���������ؿ��� */
/********************/

/* ���׽���� */
void goban_init(int soc, char my_stone, char peer_stone)
	/* soc        �̿��ѥ����å� */
	/* my_stone   ��ʬ����       */
	/* peer_stone ������       */
{
	/* �����Υǡ����ϺǸ�ޤ��ݻ������ */
	goban_soc=soc;
	goban_my_stone=my_stone;
	goban_peer_stone=peer_stone;
}

/* ���פ�ɽ�� */
void goban_show()
{
	int i;
	for(i=0;i<6;i++) {
		printf("%s\n",goban_plane[i]);
	}
}

/* �����֤ν��� */
int goban_peer_turn()
{
	char data[10]; /* �����Хåե� */
	int x,y;       /* ��ɸ */

	/* �����åȤ����ɤ� */
	read(goban_soc,data,10);

	/* ��Ƭ�Х��Ȥ򸫤ƽ�λ��Ƚ�� */
	if ( data[0] == 'q' ) return -1;

	/* ��ɸ�ǡ����μ��Ф� */
	y = (int)data[0] - (int)'a' + 1;
	x = (int)data[1] - (int)'0';

	/* �ǡ����ι��� */
	goban_plane[y][x] = goban_peer_stone;

	return 1;
}

/* ��ʬ���֤ν��� */
int goban_my_turn()
{
	char data[10]; /* �����Хåե� */
	int x,y;       /* ��ɸ */

	/* �����ܡ������� */
	while(1){
		fgets(data, 10, stdin);
		if( data[0] == 'q' )
			{ write(goban_soc,data,1); return -1; }
		if( data[0] < 'a' || data[0] > 'c' ||
		    data[1] < '1' || data[1] > '3' ) continue;
		break;
	}

	/* �ǡ����ι��� */
	y = (int)data[0] - (int)'a' + 1;
	x = (int)data[1] - (int)'0';
	goban_plane[y][x] = goban_my_stone;

	/* ���� */
	write(goban_soc,data,10);

	return 1;
}

/* ��λ���� */
void goban_destroy(){
	close(goban_soc);
}
