/*input
5
30  3  4  20  5
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
struct nd{
  ll val;
  nd* nxt;
  nd* pre;
};
nd* newnd(ll num)
{
  nd* tmp=new nd;
  tmp->val=num;
  tmp->nxt=tmp->pre=NULL;
  return tmp;
}
void print(nd* head,nd* tail)
{
  head=head->nxt;
  while(head!=tail){
    cout<<head->val<<" ";
    head=head->nxt;
  }
  cout<<endl;
}

void quick(nd** head, nd** tail)
{
  if((*head)->nxt==(*tail)->pre||(*head)->nxt==(*tail)||(*tail)->pre==(*head))
    return;
  nd* piv=(*tail)->pre;
  nd* tmp=(*head)->nxt;
  nd* en=(*head);
  ll val=piv->val;
  while(tmp!=piv){
    ll k=tmp->val;
    if(k<=val){
      swap(en->nxt->val,tmp->val);
      en=en->nxt;
    }
    tmp=tmp->nxt;
  }
  swap(en->nxt->val,piv->val);
  quick(head,&(en->nxt));
  if(en->nxt){
    quick((&en->nxt),tail);
  }
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* head=new nd;
  head->nxt=head->pre=NULL;
  nd* tail=new nd;
  tail->val=-1;
  tail->nxt=tail->pre=NULL;
  ll n;
  cin>>n;
  nd* tmp=head;
  f(i,0,n){
    ll a;
    cin>>a;
    while(tmp->nxt!=NULL){
      tmp=tmp->nxt;
    }
    tmp->nxt=newnd(a);
    tmp->nxt->pre=tmp;
  }
  tmp->nxt->nxt=tail;
  tail->pre=tmp->nxt;
  quick(&head,&tail);
  print(head,tail);
  return 0;
}

