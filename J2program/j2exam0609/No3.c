#include <stdio.h>

int side(void)
{
  int side1, side2, side3, side4;

  printf("辺を入力してください。\n");
  
  printf("第1辺 :");
  scanf("%d", &side1);

  printf("第2辺 :");
  scanf("%d", &side2);

  printf("第3辺 :");
  scanf("%d", &side3);

  if (side1 == side2){
    
    side4= side3;
    return side4;
    
  }else if (side1 == side3){

    side4= side2;
    return side4;

  }else if (side2 == side3){

    side4= side1;
    return side4;
  }else{

    return -1;
  }
}

int main(void)
{
  int side4;

  side4= side();

  if (side4 == -1){
    
    printf("エラー");

  }else{
    
    printf("第4辺は%dです。\n", side4);

  }

  return 0;
}
