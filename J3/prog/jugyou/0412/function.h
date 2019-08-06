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

/*C++のpairを再現*/
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

