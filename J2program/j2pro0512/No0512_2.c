#include <stdio.h>

int calc_sum(int a, int b, int c)
{
  int ans1, ans2, ans;

  if (a< b){
    ans1 = a;
  }else {
    ans1 = b;
    
  }if (b< c){
    ans2 = b;
  }else{
    ans2 = c;
  }

  if (ans1< ans2){
    ans = ans1;
  }else {
    ans = ans2;
  }
  
  return ans;
}

int main(void)
{
  int a;
  int b;
  int c;
  int min;

  printf("a = :");
  scanf("%d",&a);
  printf("b = :");
  scanf("%d",&b);
  printf("c = :");
  scanf("%d",&c);
  
  min = calc_sum(a, b, c);

  printf("Min = %dです。\n",min);

  return 0;
}
