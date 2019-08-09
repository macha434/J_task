#include <stdio.h>

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
