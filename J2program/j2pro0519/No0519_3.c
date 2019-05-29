#include <stdio.h>
#include <math.h>

double radian(double angle)
{
  double rad;
  
  rad = ((angle* M_PI)* 2)/ 360.0;
  
  return rad;
}


double times(double rad)
{
  double time, s;

  s = sin(rad);
  time = ((30* s)* 2)/ 9.80665;

  return time;
}


double meter(double rad, double time)
{
  double m, c;

  c = cos(rad);
  m = c* time* 30;

  return m;
}

int main(void)
{
  double rad, time, m, angle;
  
  printf("角度を入力してください。:");
  scanf("%lf", &angle);
  
  rad = radian(angle);
  time = times(rad);
  m = meter(rad, time);
 
  printf("%fメートルです。\nMaxは45度です。\n", m);

  return 0;
}
