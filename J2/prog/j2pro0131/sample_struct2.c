#include <stdio.h>

struct point {
  int x;
  int y;
};

void disp_point(struct point data);
void disp_point_array(struct point *data);
void point_set1(struct point *data);
void point_set2(struct point *data);

int main(void)
{
  struct point player;
  struct point enemy[3];
  struct point *pt;

  int i;

  printf("(1)\n");
  player.x = 2;
  player.y = 3;
  printf("player=(%d,%d)\n", player.x, player.y);
  disp_point(player);

  printf("(2)\n");
  enemy[0].x = 1;
  enemy[0].y = 1;
  enemy[1].x = 2;
  enemy[1].y = 2;
  enemy[2].x = 3;
  enemy[2].y = 3;
  printf("enemy[2]=(%d,%d)\n", enemy[2].x, enemy[2].y);
  disp_point(enemy[2]);

  printf("(3)\n");
  for (i=0; i<3; i++) {
    printf("enemy[%d]=(%d, %d)\n", i, enemy[i].x, enemy[i].y);
  }
  printf("\n");

  printf("(4)\n");
  disp_point_array(enemy);

  printf("(5)\n");
  point_set1(&enemy[2]);
  disp_point_array(enemy);

  printf("(6)\n");
  point_set2(&enemy[2]);
  disp_point_array(enemy);

  printf("(7)\n");
  player = enemy[2];
  disp_point(player);
  enemy[2].x = 9;
  enemy[2].y = 9;
  disp_point(player);
  disp_point_array(enemy);

  printf("(8)\n");
  pt = &enemy[2];
  disp_point(*pt);
  enemy[2].x = 10;
  enemy[2].y = 10;
  disp_point(*pt);
  disp_point_array(enemy);

  return 0;
}

void disp_point(struct point data)
{
  printf("-- disp_point --\n");
  printf("%d, %d\n", data.x, data.y);
  printf("\n");
}

void disp_point_array(struct point data[])
{
  int i;

  printf("-- disp_point_array --\n");
  for (i=0; i<3; i++) {
    printf("%d, %d\n", data[i].x, data[i].y);
  }
  printf("\n");
      
}

void point_set1(struct point *data)
{
  (*data).x = 7;
  (*data).y = 7;
}

void point_set2(struct point *data)
{
  data->x = 8;
  data->y = 8;
}
