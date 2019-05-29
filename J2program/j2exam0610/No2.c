#include <stdio.h>

double calc_BMI(double weight, double hight)
{
  double BMI, h;

  h= hight* hight;
  
  BMI= weight/ h;
  return BMI;
}

int main(void)
{
  double weight, hight, BMI;

  printf("体重を入力してください。 :");
  scanf("%lf", &weight);

  printf("身長を入力してください。 :");
  scanf("%lf", &hight);

  BMI= calc_BMI(weight, hight);

  printf("BMIは%fです。\n", BMI);

  return 0;
}
