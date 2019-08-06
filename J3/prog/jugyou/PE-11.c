#include <stdio.h>
#include <stdlib.h>
double me_sqrt(double x)
{
  double y,z,ans,w;
  if(x==0)
    return 0;
  else{
    y=1;
    for(int i=0;i<=100;i++)
      z=x/y;
      ans=(y+z)/2.0;
      y=ans;
      
    }
    
    return ans;
  }
  
}
int main(void)
{
  int x;
  scanf("%d",&x);
  printf("%.3lf\n",me_sqrt(x*1.0));
  return 0;
}
