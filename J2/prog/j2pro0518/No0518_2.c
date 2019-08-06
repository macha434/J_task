#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_start(void)
{
  
  printf("\n\nゲームスタート!!\n\n\n");

}

int dice_value(void)
{
  int times;
  
  printf("1~100の数字を入力してね。 : ");
  scanf("%d", &times);
  
  while (times< 1 || times> 100){ 
    printf("1~100の数字を入力してね。 : ");
    scanf("%d", &times);
  }
  
  return times;
}

int dice(int times)
{
  int total, a, RN;

  for (a= 0; a< times; a++){
    RN = rand()% 6+ 1;
    printf("%d\n",RN);
    sleep(1);
    total = total+ RN;
  }

  return total;
}

int get_money(int total)
{
  int TM= 0;

  TM = total* 100;

  return TM;
}

int main(void)
{
  int  times, total, TM;

  srand((unsigned)time(NULL));

  game_start();

  times = dice_value();

  total = dice(times);

  TM = get_money(total);

  printf("あなたは%dJ手に入れた。\n", TM- times* 100);

  return 0;

}
