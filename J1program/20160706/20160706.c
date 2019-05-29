#include <stdio.h>

main(void)
{
  int a,p,t;
 t=2;
 p=0;
 a=0;

   if(t>=12){
     p=t-12;
   }

   else if(t<12){
     a=t;
   }

   printf("午前%d,午後%d\n",a,p);
}
     
