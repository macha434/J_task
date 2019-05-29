#include <stdio.h>

int calc_accelerator(int kmh);

int main(void)
{
  int kmh;
  int accel;

  printf("speed=");
  scanf("%d", &kmh);
  
  accel = calc_accelerator(kmh);
  printf("accel=%d\n", accel);

  return 0;
}

int calc_accelerator(int kmh)
{
  int accel;

  if (kmh< 30){

    accel= 100;
    
  }else if (kmh< 50){

    accel= 50;

  }else{

    accel= 0;

  }

  return accel;
}
