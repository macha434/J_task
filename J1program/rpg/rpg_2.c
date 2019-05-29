#include	<stdio.h>
#include	<stdlib.h>

/* 迷路から脱出できたら終了 */

main(void)
{
	/*  1: 壁						*/
	/*  2: 食べ物					*/
	/*  3: 金貨						*/
	/*  4: モンスター				*/
	/*  5: 秘密の扉					*/
	/*  6: 秘密の鍵					*/
	/*  7: 壁						*/
					

	static int	map[10][10] = {
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{ 1, 0, 4, 0, 2, 0, 0, 0, 0, 1},
					{ 1, 1, 3, 1, 1, 1, 1, 0, 0, 1},
					{ 1, 0, 0, 1, 3, 4, 0, 1, 0, 1},
					{ 1, 0, 0, 6, 1, 4, 1, 0, 0, 1},
					{ 1, 0, 1, 0, 0, 4, 1, 0, 1, 1},
					{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
					{ 1, 0, 1, 2, 0, 0, 1, 1, 5, 1},
					{ 1, 0, 0, 0, 0, 4, 0, 0, 3, 1},
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
				};
	int x, y;
	int px,py;
	int direction;
	int player_x = 1,player_y = 1;
	int	hp = 10,gold = 0, key = 0;
	int	h,g,d;

	printf("ゲームの説明\n");
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
		while (y < 10){
			x = 0;
			while (x < 10){
				if (x == player_x && y == player_y){
					printf("@");
				}else{
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
				}
				x = x + 1;
			}
			printf("\n");
			y = y + 1;
		}
		printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);

		/* プレイヤの移動 */
		printf("> ");
		scanf("%d",&direction);
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
			}else if (map[player_y][player_x] == 5 && key == 1){
			printf("あなたは無事に冒険の旅から帰ってきた．おめでとう\n");
			printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);
			exit(0);
		}else if (map[player_y][player_x] == 6){
			key = 1;
			printf("秘密の鍵を手に入れた!\n");
			map[player_y][player_x] = 0;
		}
	}
}
