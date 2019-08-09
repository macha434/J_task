#include <stdio.h>

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
    for(j=0;j<=99-i;j++) printf("   ");     //空白調整用
    for (j=0; j<=i; j++) {
      printf("%6d", dfs(i, j));
    }
    putchar('\n');
  }
}

int main(void)
{
  print_pascal(10);
  return 0;
}
