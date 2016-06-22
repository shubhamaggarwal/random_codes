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
ll arr[MAXN];
ll LIS[MAXN];
vll v;
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  f(i,0,n){
    cin>>arr[i];
  }
  ll ans=1;
  LIS[0]=1;
  v.pb(arr[0]);
  __typeof(v.begin()) up;
  f(i,1,n){
    ll x=arr[i];
    up=upper_bound(v.begin(),v.end(),x);
    if(up==v.end()){
      v.pb(x);
      LIS[i]=v.size();
    }
    else{
      ll val=up-v.begin()+1;
      LIS[i]=val;
      *up=x;
    }
  }
  f(i,0,n){
    cout<<LIS[i]<<" ";
  }
  cout<<endl;
  return 0;
}

