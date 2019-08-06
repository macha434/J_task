#include	<stdio.h>
#include	<stdlib.h>
#include	<termio.h>

/* マップをファイルから読み込むようになった */

char getChar(void);

main(void)
{
	/*  1: 壁						*/
	/*  2: 食べ物					*/
	/*  3: 金貨						*/
	/*  4: モンスター				*/
	/*  5: 秘密の扉					*/
	/*  6: 秘密の鍵					*/

	static int map[20][80];
	static int view[20][80];

	int x, y;
	int px,py;
	int dx,dy;
	int direction;
	int player_x = 1,player_y = 1;
	int	hp = 10,gold = 0, key = 0;
	int	h,g,d;

	/* マップを読み込む */
	load_map("map.dat",map);

	/* 最初はマップが見えない状態にする */
	y = 0;
	while (y < 20){
		x = 0;
		while (x < 80){
			view[y][x] = 0;
			x = x + 1;
		}
		y = y + 1;
	}

	printf("ゲームの説明\n");
	printf(" @  あなた     2,4,6,8 で移動します\n");
	printf(" f  食べ物     体力が回復します\n");
	printf(" g  金貨       お金が増えます\n");
	printf(" M  モンスター 戦いが起こり，体力が減ります\n");
	printf(" %%  秘密の扉   ここにたどり着いたら冒険は終わります\n");
	printf(" $  秘密の鍵   秘密の扉を開ける鍵です\n");
	printf("\n");
	sleep(3);

	printf("いまここから，あなたの冒険が始まった．幸運を祈る...\n");
	printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);

	srandom(time(NULL));
	while (1){
		/* map 表示 */
		printf("\n");
		y = 0;
		while (y < 20){
			x = 0;
			while (x < 80){
				/* プレイヤの近くは見えるようにする */
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
				/* マップを表示する */
				if (x == player_x && y == player_y){
					printf("@");
				}else{
					/* ときどき，新しいモンスターが発生する */
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
		printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);

		/* プレイヤの移動 */
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
		/* そこに壁がない場合は移動できる */
		if (map[py][px] != 1){
			player_x = px;
			player_y = py;
		}

		if (map[player_y][player_x] == 2){
			/* 体力回復 */
			h = random() % 10;
			printf("体力が %d 回復した\n",h);
			hp = hp + h;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 3){
			/* 所持金増加 */
			g = random() % 10;
			printf("お金が %d 増えた\n",g);
			gold = gold + g;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 4){
			/* 戦闘 */
			d = random() % 10;
			printf("モンスターと戦った\n");
			printf("体力が %d 減った\n",d);
			hp = hp - d;
			map[player_y][player_x] = 0;
			if (hp <= 0){
				printf("\nあなたは力尽きた...\n");
				exit(0);
			}
		}else if (map[player_y][player_x] == 5 && key == 1){
			printf("あなたは無事に冒険の旅から帰還した．おめでとう\n");
			printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);
			exit(0);
		}else if (map[player_y][player_x] == 6){
			key = 1;
			printf("秘密の鍵を手に入れた!\n");
			map[player_y][player_x] = 0;
		}
	}
}

char
getChar(void)
{
	struct termio old_term, new_term;

	char	c;

	/* 現在の設定を得る */
	ioctl(0, TCGETA, &old_term);

	/* 設定のコピーをつくる */
	new_term = old_term;

	/* 入力文字のエコーを抑止する場合 */
	new_term.c_lflag &= ~(ICANON | ECHO);

	/* エコーは止めない場合 */
	//new_term.c_lflag &= ~(ICANON);

	/* 新しい設定を反映する */
	ioctl(0, TCSETAW, &new_term);

	/* 1 文字入力 */
	c = getchar();

	/* 古い設定に戻す */
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
		printf("%s を読み込めません\n",map_file);
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
				/* 変な文字は空白として扱う */
				map[y][x] = 0;
			}
			x = x + 1;
		}
		y = y + 1;
	}
	fclose(fp);
	return (1);
}

