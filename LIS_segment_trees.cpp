/*input
10
9 8 1 5 4 8 0 1 3 3
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
//loops
#define f(i,s,n) for(ll i=(ll)s;i<(ll)n;i++)
#define rf(i,n,s) for(ll i=(ll)(n-1);i>=(ll)s;i--)
#define raf(i,v) for(__typeof(v.begin())i=v.begin(); i!=v.end(); i++)
#define pb push_back
//reset
#define ms0(X) memset((X), 0, sizeof((X)))
#define ms1(X) memset((X), -1, sizeof((X)))
//STL
#define pii pair<ll,ll>
#define vll vector<ll>
#define vpii vector<pii >
#define mpii map<pii,ll> 
#define msll map<string, ll> 
#define mll map<ll, ll>
#define sortv(v) sort(v.begin(),v.end())
#define F first
#define S second
//standard values
#define EPS 1e-6
#define mod 1000000007LL
#define INF 100000000000LL
#define MAXN 100005LL
//comparator
bool cmp(pii a,pii b){
  if(a.F==b.F) return a.S<b.S;
  else return a.F<b.F;
}
ll exp(ll a, ll b){ll ans=1;while(b!=0){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
/********************************************************************************************************/
pii arr[MAXN];
ll tmp[MAXN];
struct nd{
  ll val;
  nd fnc(nd a, nd b)
  {
    if(a.val>b.val)
      val=a.val;
    else
      val=b.val;
  }
  nd assign(ll x){
    val=x;
  }
};
nd seg[4*MAXN];
void upd(ll nd,ll st,ll en,ll id,ll val)
{
  if(st==en){
    seg[nd].assign(val);
    return ;
  }
  ll mid=st+en>>1;
  if(id<=mid)
    upd(2*nd,st,mid,id,val);
  else
    upd(2*nd+1,mid+1,en,id,val);
  seg[nd].fnc(seg[2*nd],seg[2*nd+1]);
}
nd que(ll nd,ll st,ll en,ll l,ll r)
{
  if(l<=st&&en<=r){
    return seg[nd];
  }
  if(l>en||st>r){
    nd x;
    x.assign(0);
    return x;
  }
  ll mid=st+en>>1;
  nd x;
  x.fnc(que(2*nd,st,mid,l,r),que(2*nd+1,mid+1,en,l,r));
  return x;
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  f(i,1,n+1){
    cin>>tmp[i];
  }
  f(i,1,n+1){
    arr[i].F=tmp[i];
    arr[i].S=i;
  }
  return 0;
}

