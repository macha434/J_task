#include <stdio.h>

/*long long をllと略す*/
typedef long long ll;

/*C++のpairを再現*/
typedef struct
{
  ll first;   //X
  ll second;  //Y
}pair;

/*最大値を返す*/
ll max(ll a,ll b){
  return (a>b)?a:b;
}

/*C++のmake_pairを一部再現*/
void make_pair(pair *s,ll a,ll b)
{
  s->first=a;
  s->second=b;
}

/*X軸の重なりを判定*/
ll overX(pair square[],ll a,ll b,ll c)
{
  for(ll i=square[a].first;i<=square[b].first;i++){
     if(i==square[c].first){return i;}
  }
  return 0;
}

/*Y軸の重なりを判定*/
ll overY(pair square[],ll a,ll b,ll c)
{
  for(ll i=square[a].second;i<=square[b].second;i++){
     if(i==square[c].second){return i;}
  }
  return 0;
}


int main(void)
{
  pair square[4];
  /*
          first second
       0   AX1   AY1
       1   AX2   AY2
       2   BX1   BY1
       3   BY2   BY2
   */
  ll X,Y,S;
  static ll CX1,CX2,CY1,CY2;

  for(ll i=0;i<4;i++){
    printf("X%c%d Y%c%d>",'A'+(i/2),(i%2)+1,'A'+(i/2),(i%2)+1);
    scanf("%d %d",&X,&Y);
    make_pair(&square[i],X,Y);
  }
   CX1=max(overX(square,0,1,2),overX(square,2,3,0));
   CX2=max(overX(square,0,1,3),overX(square,2,3,1));
   CY1=max(overY(square,0,1,2),overY(square,2,3,0));
   CY2=max(overY(square,0,1,3),overY(square,2,3,1));
   S=(CX2-CX1)*(CY2-CY1);
   printf("X1=%d X2=%d Y1=%d Y2=%d\n",CX1,CX2,CY1,CY2);
   if(S!=0)
     printf("%d\n",S);
   else
     printf("重なってません\n");
   return 0;
}
