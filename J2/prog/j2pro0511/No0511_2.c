#include <stdio.h>

int main(void)
{
  int a=0, b=0, c=0, d=0;
  printf("時間を入力してください！\n時間:");
  scanf("%d",&a);
  if(a>23){
    printf("エラー\n");
    return 0;
  }
  printf("分  :");
  scanf("%d",&b);
  if(b>59){
     printf("エラー\n");
    return 0;
   }
   printf("秒  :");
  scanf("%d",&c);
  if(c>59){
     printf("エラー\n");
    return 0;
   }
   
   a = a*3600;
    b = b*60;
    d = a+b+c;
  
  printf("現在の時間の経過した秒は%dです！\n",d);

  return 0;
}
