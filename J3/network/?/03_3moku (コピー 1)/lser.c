#include <stdio.h>
void add(){
  static int a=5;
  a++;
  printf("%d ",a);
}
void prin()
{
  printf("%d",a);
}
int main()
{
  add();
  add();
  return 0;
}
