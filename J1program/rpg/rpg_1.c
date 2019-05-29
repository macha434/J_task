#include	<stdio.h>
#include	<stdlib.h>
#include	<termio.h>


char getChar(void);

main(void)
{
	static int	map[10][21] = {
	  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1,1,1,1,1,1,1,1,1},
	  { 1, 0, 4, 0, 2, 0, 0, 0, 0, 1, 0, 1,0,4,0,0,0,0,0,0,1},
	  { 1, 1, 3, 1, 1, 1, 1, 0, 0, 1, 0, 1,4,1,1,1,1,1,1,0,1},
	  { 1, 0, 0, 1, 3, 4, 0, 1, 0, 1, 0, 1,0,1,2,0,0,0,0,0,1},
	  { 1, 0, 0, 0, 1, 4, 1, 0, 0, 1, 0, 1,0,1,3,1,1,1,4,1,1},
	  { 1, 0, 1, 0, 0, 4, 1, 0, 1, 1, 0, 1,2,1,0,0,4,0,0,0,1},
	  { 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1,0,1,0,0,2,0,0,0,1},
	  { 1, 0, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1,7,1,0,2,1,0,0,0,1},
	  { 1, 0, 0, 0, 0, 4, 0, 0, 3, 1, 0, 0,0,1,0,1,0,0,0,0,1},
	  { 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 0, 1,1,1,1,1,1,1,1,1,1}
				};
	int x, y;
	int px,py;
	int direction;
	int player_x = 1,player_y = 1;
	int hp = 20,gold = 0;
	int h,g,d,ex=0,lv=1,a,b = 0;
	char tmp;

	printf("げーむ説明\n");
	printf(" @ ぷれいやー    2,4,6,8 で移動\n");
	printf(" f 回復         hpが回復\n");
	printf(" g お金         gが増える\n");
	printf(" M もんすたー    戦い hpが減るよ\n");
	printf(" W わーぷ       わーぷするお\n");
	printf(" K 鍵           _が出現\n");
	printf(" _ ごーる       げーむくりあ\n");
	printf("\n");
	sleep(1);

	printf("いまここから，あなたの冒険が始まった．幸運を祈る...\n");
	printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);

	srandom(time(NULL));
	while (1){

		printf("\n");
		for (y = 0 ; y < 10 ; y++){
		    
		  for (x = 0 ; x < 21 ; x++){
			 
				if (x == player_x && y == player_y){
				  printf("@");
				}else{
				  switch(map[y][x]){
				  case 0:
				    printf(" ");
				    break;
				  
				  case 1:
				    printf("#");
				    break;
				  
				  case 2:
				    printf("f");
				    break;
				  
				  case 3:
				    printf("g");
				    break;
				  
				  case 4:
				    printf("M");
				    break;
				
				  case 5:
				    printf("W");
				    break;
				  
				  case 6:
				    printf("_");
				    break;
				  
				  case 7:
				    printf("K");
				    break;
				  }
				}
		  }
		  printf("\n");
		}
		printf("\n");
		
	

		printf("*** 体力:%d  お金:%d ***\n\n",hp,gold);

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
		if (map[py][px] != 1){
			player_x = px;
			player_y = py;
		}
		if(map[player_y][player_x] == 2){
			h = random() % 10;
			printf("体力が %d 回復した\n",h);
			hp = hp + h;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 3){
			g = random() % 10;
			printf("お金が %d 増えた\n",g);
			gold = gold + g;
			map[player_y][player_x] = 0;
		}else if (map[player_y][player_x] == 4){
			d = random() % 10;
			a = random() % 15;
			printf("モンスターと戦った\n");
			printf("体力が %d 減った\n",d);
			printf("経験値 %d 得た\n",a);
			hp = hp - d;
			map[player_y][player_x] = 0;
			ex = ex + a;
			if (ex >=10 + b){
			  lv = lv + 1;
			  ex = 0;
			  printf("Lvが上った\nhpが5回復\n");
			  hp = hp + 5;
			  b = b + 10;
			}
			if (hp <= 0){
				printf("\nあなたは力尽きた...\n");
				
				if(g<20){
				  exit(0);
				}else{
				  printf("復活した。");
				  g = 0;
				  hp = random() % 30;
				  ex = 0;
				}
			}else if(map[player_y][player_x] == 5){
			  printf("あなたはわーぷした。");
			  player_y = 1;
			  player_x = 12;
			  map[player_y][player_x] == 0;
		  
			}else if(map[py][px] == 6){
			  printf("げーむくりあ！！\n");
			  exit(0);
			}else if(map[py][px] == 7){
			  map[player_y][player_x] = 0;
			  map[9][19] = 6;
			}        
		}
	}
}

char
getChar(void)
{
	struct termio old_term, new_term;

	char	c;

	ioctl(0, TCGETA, &old_term);

	new_term = old_term;

	new_term.c_lflag &= ~(ICANON | ECHO);

	ioctl(0, TCSETAW, &new_term);

	c = getchar();

	ioctl(0, TCSETAW, &old_term);

	return (c);
}	
