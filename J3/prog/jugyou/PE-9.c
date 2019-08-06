#include <stdio.h>
/*
                                     -memo-
n=段数 r=右から数えて何番目か
n段目の右から数えてr番目は n-1段目の右から数えてr-1番目とn-1段目の右から数えてr番目の和
多分 return dfs(n-1,r-1)+dfs(n-1,r);で実装可能?

最終リターン条件はrが0未満になったらおかしい。
  発生元は dfs(n-1,r-1)
rが0のときは1をreturnすれば何とかなる...？
rが0未満の時は0をreturnすれば 0 + 1 で 1 になるはず...

もしくはn段目にr行しか存在しないにも関わらず、rがnより大きくなった場合?
こちらも0をreturnすれば 0 + 1 で 1 になるはず

*/
int dfs(int n, int r)
{
  if(r<0||r>n)
    return 0;
  else if(r==0)
    return 1;
  else
    return dfs(n-1,r-1) + dfs(n-1,r);
}
void print_pascal(int n)
{
  int i, j;
  
  for (i=0; i<n; i++){
    for(j=0;j<=10-i;j++) printf("   ");     //空白調整用
    for (j=0; j<=i; j++) {                 
      printf("%6d", dfs(i, j));
    }
    putchar('\n');
  }
}

int main(void)
{
  print_pascal(11);
  return 0;
}
