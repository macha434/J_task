#include <stdio.h>
/*
                                   -memo-
  n=階段数で考える
  n<=0の時は 0回で登れることは自明。
  n=1の時は 1回でのぼれる
  n=2の時は 1段*2 または 2段*1で登れることが分かる(2回)
  n=3の時は 1*3 2*1+1 1+2*2 3 で登れる(4回)
  n=4の時は 7回 これは(n=3)+(n=2)+(n=1)の和である
  n=5の時は...?
*/
unsigned long long dfs(int n)
{
  if(n<=0) return 0;
  if(n==1) return 1;
  if(n==2) return 2;
  if(n==3) return 4;
  return dfs(n-3)+dfs(n-2)+dfs(n-1);
}
int main(void)
{
  unsigned long long  stairs;
  printf("Stairs>");
  scanf("%d",&stairs);
  printf("permutation=%u\n",dfs(stairs));
  return 0;
}
