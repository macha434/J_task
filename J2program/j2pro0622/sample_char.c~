#include <stdio.h>

int main(void)
{
  int i;
  int i_num;
  char ch_num;
  unsigned char uch_num;

  ch_num = 0;
  uch_num = 0;
  for (i=0; i<260; i++) {
    printf("ch_num=%4d, uch_num=%4d\n", ch_num, uch_num);
    ch_num++;
    uch_num++;
  }
  
  printf("-1---------------------------------------\n");
  ch_num = 97;
  printf("ch_num=%d\n", ch_num);
  printf("ch_num=%c\n", ch_num);
  printf("ch_num=%X\n", ch_num);

  printf("-2---------------------------------------\n");
  ch_num = 'b';
  printf("ch_num=%d\n", ch_num);
  printf("ch_num=%c\n", ch_num);
  printf("ch_num=%X\n", ch_num);

  printf("-3---------------------------------------\n");
  i_num = 99;
  printf("i_num=%d\n", i_num);
  printf("i_num=%c\n", i_num);
  printf("i_num=%X\n", i_num);

  printf("-4---------------------------------------\n");
  ch_num = 97;
  for (i=0; i<10; i++) {
    printf("%d, %c\n", ch_num+i, ch_num+i);
  }

  printf("-5---------------------------------------\n");
  ch_num = '0';
  printf("ch_num=%d\n", ch_num);
  printf("ch_num=%c\n", ch_num);
  printf("ch_num=%X\n", ch_num);

  printf("-6---------------------------------------\n");
  ch_num = '0';
  ch_num = ch_num + 1;
  printf("ch_num=%d, %c\n", ch_num, ch_num);

  ch_num = '0' + 7;
  printf("ch_num=%d, %c\n", ch_num, ch_num);

  return 0;
}
