#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
#define N 10
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
typedef long long ll;
ll max(ll a,ll b)
{
  if(a>b) return a;
  else return b;
}
void init(ll n[])
{
  for(ll i=0;i<N;i++){n[i]=rand_range(-RAND_MAX,RAND_MAX);printf("n[%d]=%d\n",i,n[i]);}
}
int main()
{
  ll n[N];
  ll max1,max2,max3,min1,min2;
  init(n);
  max1=max2=max3=-LLONG_MAX;
  min1=min2=LLONG_MAX;
  for(ll i=0;i<N;i++){
    if(max1<n[i]) max1=n[i];
    if(max2<n[i]&&max1>n[i]) max2=n[i];
    if(max3<n[i]&&max2>n[i]) max3=n[i];
    if(min1>n[i]) min1=n[i];
    if(min2>n[i]&&min1<n[i]) min2=n[i];
  }
  printf("%lld\n",max(max1*max2*max3,min1*min2*max1));
  return 0;
}
