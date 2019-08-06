#include <stdio.h>
#include <math.h>

int main(void)
{
  int Num(1), Num(2), Num(3), Num(4), Num(5), t= 1, a, b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, c, d;

  printf("4桁の整数を入力して下さい。");

  printf("Num(1)= :");
  scanf("%d", &Num(1));

  printf("Num(2)= :");
  scanf("%d", &Num(2));

  printf("Num(3)= :");
  scanf("%d", &Num(3));

  printf("Num(4)= :");
  scanf("%d", &Num(4));

  printf("Num(5)= :");
  scanf("%d", &Num(5));

  while(t<=5){
    a= 0;
    while(a<4){
      d= pow(10, a);
      c= Num(t)/ d;

      if (c==1){
	b1++;
      }else if(c==2){
	b2++;
      }else if(c==3){
	b3++;
      }else if(c==4){
	b4++;
      }else if(c==5){
	b5++;
      }else if(c==6){
	b6++;
      }else if(c==7){
	b7++;
      }else if(c==8){
	b8++;
      }else if(c==9){
	b9++;
      }else if(c==0){
	b0++;
      }

      a++;
    }
    t++;
  }

  printf("0 -> %d", b1);
  printf("1 -> %d", b2);
  printf("2 -> %d", b3);
  printf("3 -> %d", b4);
  printf("4 -> %d", b5);
  printf("5 -> %d", b6);
  printf("6 -> %d", b7);
  printf("7 -> %d", b8);
  printf("8 -> %d", b9);
  printf("9 -> %d", b0);

  return 0;
}
