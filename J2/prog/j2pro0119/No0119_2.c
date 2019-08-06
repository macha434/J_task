#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 10
#define NAME 8+1

struct parameter {
  int no;
  char name[NAME];
  int hp;
  int mp;
  double attack;
  double defence;
};

void initialize(struct parameter player[]);
void disp_array(struct parameter player[], int ATT_MAX_PLA);
int comparison(struct parameter player[]);

int main(void)
{
  struct parameter player[PLAYER];
  int ATT_MAX_PLA;

  srand(1);

  initialize(player);

  ATT_MAX_PLA= comparison(player);

  disp_array(player, ATT_MAX_PLA);

  return 0;
}

void initialize(struct parameter player[])
{
  int i, j;

  for (i=0; i<PLAYER; i++) {
    player[i].no = i+ 1;
    for (j=0; j<NAME-1; j++) { 
      player[i].name[j] = 'a'+rand()%26;
    }
    player[i].name[j] = '\0';
    player[i].hp = rand()%100;
    player[i].mp = rand()%100;
    player[i].attack = (double)rand()/RAND_MAX;
    player[i].defence = (double)rand()/RAND_MAX;
  }

}

void disp_array(struct parameter player[], int ATT_MAX_PLA)
{
  int i;

  printf(" No  Name     HP MP AT   DE \n");
  for (i=0; i<PLAYER; i++) {
    printf("[%2d] ", player[i].no);
    printf("%s", player[i].name);
    printf(" ");
    printf("%2d %2d %.2f %.2f\n", 
	   player[i].hp, player[i].mp, player[i].attack, player[i].defence);
  }

  printf("\n");
  printf("ATTACK MAX PLAYER: [%2d] %s %2d %2d %.2f %.2f\n", 
		  player[ATT_MAX_PLA].no, player[ATT_MAX_PLA].name, player[ATT_MAX_PLA].hp, player[ATT_MAX_PLA].mp, player[ATT_MAX_PLA].attack, player[ATT_MAX_PLA].defence);

}

int comparison(struct parameter player[]){
	int i;
	int ATT_MAX_PLA= 0;

	for(i= 0; i< PLAYER; i++){
		if(player[ATT_MAX_PLA].attack< player[i].attack){
			ATT_MAX_PLA= i;
		}
	}

	return ATT_MAX_PLA;
}
