#include	<stdio.h>
#include	<stdlib.h>
#include	<termio.h>

/* �ޥåפ�ե����뤫���ɤ߹���褦�ˤʤä� */

char getChar(void);

main(void)
{
	/*  1: ��						*/
	/*  2: ����ʪ					*/
	/*  3: ���						*/
	/*  4: ��󥹥���				*/
	/*  5: ��̩����					*/
	/*  6: ��̩�θ�					*/

	static int map[20][80];
	static int view[20][80];

	int x, y;
	int px,py;
	int dx,dy;
	int direction;
	int player_x = 1,player_y = 1;
	int	hp = 10,gold = 0, key = 0;
	int	h,g,d;

	/* �ޥåפ��ɤ߹��� */
	load_map("map.dat",map);

	/* �ǽ�ϥޥåפ������ʤ����֤ˤ��� */
	y = 0;
	while (y < 20){
		x = 0;
		while (x < 80){
			view[y][x] = 0;
			x = x + 1;
		}
		y = y + 1;
	}

	printf("�����������\n");
	printf(" @  ���ʤ�     2,4,6,8 �ǰ�ư���ޤ�\n");
	printf(" f  ����ʪ     ���Ϥ��������ޤ�\n");
	printf(" g  ���       ���⤬�����ޤ�\n");
	printf(" M  ��󥹥��� �襤�������ꡤ���Ϥ�����ޤ�\n");
	printf(" %%  ��̩����   �����ˤ��ɤ��夤���������Ͻ����ޤ�\n");
	printf(" $  ��̩�θ�   ��̩����򳫤��븰�Ǥ�\n");
	printf("\n");
	sleep(3);

	printf("���ޤ������顤���ʤ����������Ϥޤä��������򵧤�...\n");
	printf("*** ����:%d  ����:%d ***\n\n",hp,gold);

	srandom(time(NULL));
	while (1){
		/* map ɽ�� */
		printf("\n");
		y = 0;
		while (y < 20){
			x = 0;
			while (x < 80){
				/* �ץ쥤��ζ᤯�ϸ�����褦�ˤ��� */
				dx = (player_x - x);
				if (dx < 0){
					dx = -dx;
				}
				dy = (player_y - y);
				if (dy < 0){
					dy = -dy;
				}
				if (dx + dy <= 2){
					view[y][x] = 1;
				}
				/* �ޥåפ�ɽ������ */
				if (x == player_x && y == player_y){
					printf("@");
				}else{
					/* �Ȥ��ɤ�����������󥹥�����ȯ������ */
					if (map[y][x] == 0){
						if (random() % 10000 == 0){
							map[y][x] = 4;
						}
					}
					if (view[y][x] == 1){
						if (map[y][x] == 0){
							printf(" ");
						}else if (map[y][x] == 1){
							printf("#");
						}else if (map[y][x] == 2){
							printf("f");
						}else if (map[y][x] == 3){
							printf("g");
						}else if (map[y][x] == 4){
							printf("M");
						}else if (map[y][x] == 5){
							if (key == 1){
								printf("%%");
							}else{
								printf(" ");
							}
						}else if (map[y][x] == 6){
							printf("$");
						}
					}else{
						printf(".");
					}
				}
				x = x + 1;
			}
			printf("\n");
			y = y + 1;
		}
		printf("*** ����:%d  ����:%d ***\n\n",hp,gold);

		/* �ץ쥤��ΰ�ư */
		printf("> ");
		direction = getChar() - '0';
		if (direction == 2){
			px = player_x;
			py = player_y + 1;
		}else if (direction == 4){
			px = player_x - 1;
			py = player_y;
		}else if (direction == 6){
			px = player_x + 1;
			py = player_y;
		}else if (direction == 8){
			px = player_x;
			py = player_y - 1;
		}
		/* �������ɤ��ʤ����ϰ�ư�Ǥ��� */
		if (map[py][px] != 1){
			player_x = px;
			player_y = py;
		}

		if (map[player_y][player_x] == 2){
			/* ���ϲ��� */
			h = random() % 10;
			printf("���Ϥ� %d ��������\n",h);
			hp = hp + h;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 3){
			/* ��������� */
			g = random() % 10;
			printf("���⤬ %d ������\n",g);
			gold = gold + g;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 4){
			/* ��Ʈ */
			d = random() % 10;
			printf("��󥹥�������ä�\n");
			printf("���Ϥ� %d ���ä�\n",d);
			hp = hp - d;
			map[player_y][player_x] = 0;
			if (hp <= 0){
				printf("\n���ʤ����ϿԤ���...\n");
				exit(0);
			}
		}else if (map[player_y][player_x] == 5 && key == 1){
			printf("���ʤ���̵����������ι���鵢�Ԥ���������ǤȤ�\n");
			printf("*** ����:%d  ����:%d ***\n\n",hp,gold);
			exit(0);
		}else if (map[player_y][player_x] == 6){
			key = 1;
			printf("��̩�θ��������줿!\n");
			map[player_y][player_x] = 0;
		}
	}
}

char
getChar(void)
{
	struct termio old_term, new_term;

	char	c;

	/* ���ߤ���������� */
	ioctl(0, TCGETA, &old_term);

	/* ����Υ��ԡ���Ĥ��� */
	new_term = old_term;

	/* ����ʸ���Υ��������޻ߤ����� */
	new_term.c_lflag &= ~(ICANON | ECHO);

	/* �������ϻߤ�ʤ���� */
	//new_term.c_lflag &= ~(ICANON);

	/* �����������ȿ�Ǥ��� */
	ioctl(0, TCSETAW, &new_term);

	/* 1 ʸ������ */
	c = getchar();

	/* �Ť�������᤹ */
	ioctl(0, TCSETAW, &old_term);

	return (c);
}	

int
load_map(cahr *map_file,int map[20][80])
{
	FILE *fp;
	int x,y;
	char buf[82];
	
	if ((fp = fopen(map_file,"r")) == NULL){
		printf("%s ���ɤ߹���ޤ���\n",map_file);
		exit(1);
	}
	y = 0;
	while (y < 20){
		fgets(buf,82,fp);
		x = 0;
		while (x < 80){
			switch (buf[x]){
			case ' ':
				map[y][x] = 0;
				break;
			case '#':
				map[y][x] = 1;
				break;
			case 'f':
				map[y][x] = 2;
				break;
			case 'g':
				map[y][x] = 3;
				break;
			case 'M':
				map[y][x] = 4;
				break;
			case '%':
				map[y][x] = 5;
				break;
			case '$':
				map[y][x] = 6;
				break;
			default:
				/* �Ѥ�ʸ���϶���Ȥ��ư��� */
				map[y][x] = 0;
			}
			x = x + 1;
		}
		y = y + 1;
	}
	fclose(fp);
	return (1);
}

