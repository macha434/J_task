#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 10
#define NAME 8+1

void initialize(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);
void disp_array(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[], int ATT_MAX_PLA);
int comparison(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);

int main(void)
{
  int no[PLAYER];
  char name[PLAYER][NAME];
  int hp[PLAYER];
  int mp[PLAYER];
  double attack[PLAYER];
  double defence[PLAYER];
  double speed[PLAYER];
  double intelligence[PLAYER];
  int player_no;
  int ATT_MAX_PLA;

  srand((unsigned)time(NULL));

  initialize(no, name, hp, mp, attack, defence);

  ATT_MAX_PLA= comparison(no, name, hp, mp, attack, defence);

  disp_array(no, name, hp, mp, attack, defence, ATT_MAX_PLA);

  return 0;
}

void initialize(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[])
{
  int i, j;

  for (i=0; i<PLAYER; i++) {
    no[i] = i+1;
    for (j=0; j<NAME-1; j++) { 
      name[i][j] = 'a'+rand()%26;
    }
    name[i][j] = '\0';
    hp[i] = rand()%100+1;
    mp[i] = rand()%101;
    attack[i] = (double)rand()/RAND_MAX;
    defence[i] = (double)rand()/RAND_MAX;
  }

}

void disp_array(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[], int ATT_MAX_PLA)
{
  int i;

  printf(" No  Name     HP MP AT   DE \n");
  for (i=0; i<PLAYER; i++) {
    printf("[%2d] ", no[i]);
    printf("%s", name[i]);
    printf(" ");
    printf("%2d %2d %.2f %.2f\n", hp[i], mp[i], attack[i], defence[i]);
  }

  printf("\n");
  printf("MAX ATTACK PLAYER: [%2d] %s %2d %2d %.2f %.2f\n", no[ATT_MAX_PLA], name[ATT_MAX_PLA], hp[ATT_MAX_PLA], mp[ATT_MAX_PLA], attack[ATT_MAX_PLA], defence[ATT_MAX_PLA]);

}

int comparison(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]){
	int i;
	int ATT_MAX_PLA= 0;

	for(i= 0; i< PLAYER; i++){
		if(attack[ATT_MAX_PLA]< attack[i]){
			ATT_MAX_PLA= i;
		}
	}

	return ATT_MAX_PLA;
}
