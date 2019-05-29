#include <stdio.h>
#include <math.h>

int main(void)
{
  int Num1, Num2, Num3, Num4, Num5, a, b[10], c, d, e;

  for(a=0; a<10; a++){
    b[a]= 0;
  }
  
  printf("4桁の整数を入力して下さい。\n");
  
  printf("Num1= :");
  scanf("%d", &Num1);
  
  for(; Num1 <1000 || Num1 >=10000;){
    printf("error\n");
    printf("Num1= :");
    scanf("%d", &Num1);
  }
  
  printf("Num2= :");
  scanf("%d", &Num2);
  
  for(; Num2 <1000 || Num2 >=10000;){
    printf("error\n");
    printf("Num2= :");
    scanf("%d", &Num2);
  }
  
  printf("Num3= :");
  scanf("%d", &Num3);
  
  for(; Num3 <1000 || Num3 >=10000;){
    printf("error\n");
    printf("Num3= :");
    scanf("%d", &Num3);
  }
  
  printf("Num4= :");
  scanf("%d", &Num4);
  
  for(; Num4 <1000 || Num4 >=10000;){
    printf("error\n");
    printf("Num4= :");
    scanf("%d", &Num4);
  }
  
  printf("Num5= :");
  scanf("%d", &Num5);
  
  for(; Num5 <1000 || Num5 >=10000;){
    printf("error\n");
    printf("Num5= :");
    scanf("%d", &Num5);
  }

  for(a=0; a<4; a++){

    e= 3-a;
    c= pow(10,e);
    
    d= Num1/ c;
    Num1= Num1- (d* c);
    b[d]++;

    
    d= Num2/ c;
    Num2= Num2- (d* c); 
    b[d]++;
        
    d= Num3/ c;
    Num3= Num3- (d* c);
    b[d]++;
        
    d= Num4/ c;
    Num4= Num4- (d* c);
    b[d]++;
        
    d= Num5/ c;
    Num5= Num5- (d* c);
    b[d]++;
        
  }
  
  for(a=0; a<10; a++){
    
    printf("%d -> %d\n", a, b[a]);
    
  }
  return 0;
}
