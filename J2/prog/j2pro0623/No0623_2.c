#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char ch, num;

  srand((unsigned)time(NULL));

  num= rand()% 26+ 'a';

  ch= num;

  printf("ランダムな文字は%cです。\n", ch);
}
