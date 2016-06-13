/*input
10
9 8 1 5 4 8 0 1 3 3
*/
/****************************
* Used head and tail as     *
*   data nodes of DLL.      *
*****************************/
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
  tmp->pre=tmp->nxt=NULL;
  return tmp;
}
void print(struct nd *head)
{

    nd* tmp=head;
    nd* tmp2;
    while(tmp){
      cout<<tmp->val;
      cout<<" ";
      tmp2=tmp;
      tmp=tmp->nxt;
    }
    cout<<endl;
    while(tmp2)
    {
      cout<<tmp2->val<<" ";
      tmp2=tmp2->pre;
    }
    cout<<endl;
}
void split(nd** head, nd** back)
{

  nd* sl=*head;
  nd* fs=(*head)->nxt;
  if(*head==NULL||(*head)->nxt==NULL)
    return ;
  while(fs&&fs->nxt){
    fs=fs->nxt->nxt;
    sl=sl->nxt;
  }
  (*back)=sl->nxt;
  sl->nxt=NULL;
}
nd* merge(nd** head,nd** back)
{
  nd* a=(*head);
  nd* b=(*back);
  nd* tmp=new nd;
  nd* res=tmp;
  while(a&&b){
    if(a->val==b->val){
      while(res->nxt)
        res=res->nxt;
      res->nxt=newnd(a->val);
      res->nxt->pre=res;
      res=res->nxt;
      res->nxt=newnd(a->val);
      res->nxt->pre=res;
      a=a->nxt;
      b=b->nxt;
    }
    else if(a->val<b->val){
      while(res->nxt)
        res=res->nxt;
      res->nxt=newnd(a->val);
      res->nxt->pre=res;
      a=a->nxt;
    }
    else{
      while(res->nxt)
        res=res->nxt;
      res->nxt=newnd(b->val);
      res->nxt->pre=res;
      b=b->nxt;
    }
  }
  while(a){
    while(res->nxt)
        res=res->nxt;
    res->nxt=newnd(a->val);
    res->nxt->pre=res;
    a=a->nxt;
  }
  while(b){
    while(res->nxt)
        res=res->nxt;
    res->nxt=newnd(b->val);
    res->nxt->pre=res;
    b=b->nxt;
  }
  tmp=tmp->nxt;
  (*head)=tmp;
  (*head)->pre=NULL;
  return *head;
}
void mergesort(nd** head)
{
  if((*head)==NULL||(*head)->nxt==NULL)
    return ;
  nd* back=new nd;
  split(head,&back);
  mergesort(head);
  mergesort(&back);
  *head=merge(head,&back);
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* head=new nd;
  head->nxt=head->pre=NULL;
  nd* tail=new nd;
  tail->nxt=tail->pre=NULL;
  nd* tmp=head;
  ll n;
  cin>>n;
  f(i,0,n){
    ll a;
    cin>>a;
    while(tmp->nxt)
      tmp=tmp->nxt;
    tmp->nxt=newnd(a);
    tmp->nxt->pre=tmp;
  }
  head=head->nxt;
  head->pre=NULL;
  tmp=tmp->nxt;
  tail=tmp;
  print(head);
  mergesort(&head);
  print(head);
  return 0;
}

