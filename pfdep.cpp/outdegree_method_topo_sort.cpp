/*input
9 5 
1 4 5 4 3 2 
4 1 6 
5 1 9 
3 1 7 
2 1 8 
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
ll outdeg[105];
vll v[105];
queue<ll>s;
ll has[105];
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n,m;
  cin>>n>>m;
  f(i,0,m){
    ll a;
    cin>>a;
    ll k;
    cin>>k;
    f(j,0,k){
      ll b;
      cin>>b;
      v[b].pb(a);
      outdeg[a]++;
    }
  }
  f(i,1,n+1){
    ll id;
    f(j,1,n+1){
      if(outdeg[j]==0&&!has[j])
      {
        id=j;
        has[j]=1;
        break;
      }
    }
    s.push(id);
    f(j,0,v[id].size())
    {
      outdeg[v[id][j]]--;
    }
  }
  while(!s.empty()){
    cout<<s.front()<<" ";
    s.pop();
  }
  cout<<endl;
  return 0;
}

