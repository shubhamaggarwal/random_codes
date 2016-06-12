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
struct nd{
  ll val;
  nd* nxt;
};
nd* newnd(ll num)
{
  nd* tmp=new nd;
  tmp->val=num;
  tmp->nxt=NULL;
  return tmp;
}
void print(nd* head)
{
  head=head->nxt;
  while(head){
    cout<<head->val<<" ";
    head=head->nxt;
  }
  cout<<endl;
}
void quick(nd** head)
{
  if((*head)->nxt==NULL||(*head)->nxt->nxt==NULL)
    return ;
  nd* tmp=*head;
  while(tmp->nxt!=NULL)
    tmp=tmp->nxt;
  nd* piv=tmp;
  ll val=tmp->val;
  tmp=(*head)->nxt;
  nd* en=*head;
  while(tmp!=piv){
    ll k=tmp->val;
    if(k<=val){
      swap(en->nxt->val,tmp->val);
      en=en->nxt;
    }
    tmp=tmp->nxt;
  }
  swap(en->nxt->val,piv->val);
  nd* bef=new nd;
  tmp=bef;
  
  nd* tmp2=(*head)->nxt;

  nd* aft=new nd;

  while(tmp2!=en->nxt){
    while(tmp->nxt)
      tmp=tmp->nxt;
    tmp->nxt=newnd(tmp2->val);
    tmp2=tmp2->nxt;
  }
  
  nd* tmp3=new nd;
  tmp3->val=tmp2->val;
  tmp3->nxt=NULL;
  
  tmp2=tmp2->nxt;
  
  tmp=aft;
  
  while(tmp2){
   while(tmp->nxt)
      tmp=tmp->nxt;
    tmp->nxt=newnd(tmp2->val);
    tmp2=tmp2->nxt; 
  }
  quick(&bef);
  quick(&aft);
  
  (*head)->nxt=bef->nxt;
  
  nd* ans=*head;
  while(ans->nxt){
    ans=ans->nxt;
  }
  ans->nxt=tmp3;
  ans=ans->nxt;
  ans->nxt=aft->nxt;
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* head=new nd;
  head->nxt=NULL;

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
  }
  print(head);
  quick(&head);
  print(head);
  return 0;
}
