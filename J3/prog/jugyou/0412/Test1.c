#include <stdio.h>
#include "function.h"
int main(void)
{
  pair square[4];
  ll X,Y,S;
  static ll CX1,CX2,CY1,CY2;

  for(ll i=0;i<4;i++){
    printf("X%c%d Y%c%d>",'A'+(i/2),(i%2)+1,'A'+(i/2),(i%2)+1);
    scanf("%d %d",&X,&Y);
    make_pair(&square[i],X,Y);
  }
  S=(max(overX(square,0,1,3),overX(square,2,3,1))-max(overX(square,0,1,2),overX(square,2,3,0)))*(max(overY(square,0,1,3),overY(square,2,3,1))-max(overY(square,0,1,2),overY(square,2,3,0)));;
  printf("X1=%d X2=%d Y1=%d Y2=%d\n",CX1,CX2,CY1,CY2);
  if(S!=0)
    printf("%d\n",S);
  else
    printf("重なってません\n");
  return 0;
}
