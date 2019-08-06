#include <stdio.h>

int main(void)
{
  int a,b;

  printf("金額を入力してください");
  scanf("%d",&a);

  while(a>1){
    while(a>5){
      while(a>10){
	while(a>50){
	  while(a>100){
	    while(a>500){
	      while(a>1000){
		while(a>5000){
		  b = a / 5000;
		  printf("5000円 %d枚\n",b);
		  a = a - 5000 * b;
		}
		b = a / 1000;
		printf("1000円 %d枚\n",b);
		a = a - 1000 * b;
	      }
	      b = a / 500;
	      printf("500円 %d枚\n",b);
	      a = a - 500 * b;
	    }
	    b = a / 100;
	    printf("100円 %d枚\n",b);
	    a = a - 100 * b;
	  }
	  b = a / 50;
	  printf("50円  %d枚\n",b);
	  a = a - 50 * b;
	}
	
