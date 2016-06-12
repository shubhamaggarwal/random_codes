/*input
5
1 2 3 4 5
5
2 4 5 8 9
3
2 3 3
0
1 
16
2
10 23
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
  nd* li;
};
nd* newnd(ll a)
{
  nd* tmp=new nd;
  tmp->nxt=NULL;
  tmp->li=NULL;
  tmp->val=a;
  return tmp;
}
void print(nd* head)
{
  while(head->nxt!=NULL){
    head=head->nxt;
    cout<<head->val<<" ";
  }
  cout<<endl;
}
void print2(nd* head)
{
  cout<<head->val<<" ";
  while(head->li){
    head=head->li;
    cout<<head->val<<" ";
  }
  cout<<endl;
}
void merge(nd** h1, nd** h2)
{
  nd* tmp=(*h1);
  nd* tmp2=(*h2);
  nd* result=new nd;
  result->li=NULL;
  nd* tmp3=result;
  while(tmp&&tmp2){
    ll a=tmp->val;
    ll b=tmp2->val;
    if(a==b){
      while(tmp3->li){
        tmp3=tmp3->li;
      }
      tmp3->li=newnd(a);
      tmp3=tmp3->li;
      tmp3->li=newnd(a);
      tmp=tmp->li;
      tmp2=tmp2->li;
    }
    else if(a<b){
      while(tmp3->li){
        tmp3=tmp3->li;
      }
      tmp3->li=newnd(a);
      tmp=tmp->li;
    }
    else{
      while(tmp3->li){
        tmp3=tmp3->li;
      }
      tmp3->li=newnd(b);
      tmp2=tmp2->li;
    }
  }
  while(tmp){
    while(tmp3->li){
      tmp3=tmp3->li;
    }
    tmp3->li=newnd(tmp->val);
    tmp=tmp->li;
  }
  while(tmp2){
    while(tmp3->li){
      tmp3=tmp3->li;
    }
    tmp3->li=newnd(tmp2->val);
    tmp2=tmp2->li;
  }
  (*h1)=result->li;
  (*h1)->nxt=(*h2);
}
void flaten(nd** head)
{
  nd* tmp=(*head)->nxt;
  nd* tmp2;
  while(tmp->nxt){
    tmp2=tmp->nxt;
    merge(&tmp,&tmp2);
    tmp->nxt=tmp->nxt->nxt;
  }
  nd* ans=*head;
  while(tmp){
    ans->nxt=newnd(tmp->val);
    ans=ans->nxt;
    tmp=tmp->li;
  }
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  ll n;
  cin>>n;
  nd* head=new nd;
  head->nxt=NULL;
  head->li=NULL;
  nd* tmp=head;
  f(i,0,n){
    ll a;
    cin>>a;
    while(tmp->nxt){
      tmp=tmp->nxt;
    }
    tmp->nxt=newnd(a);
  }
  tmp=head;
  f(i,0,n){
    tmp=tmp->nxt;
    ll k;
    cin>>k;
    nd* tmp2=tmp;
    f(i,0,k){
      ll a;
      cin>>a;
      while(tmp2->li)
        tmp2=tmp2->li;
      tmp2->li=newnd(a);
    }
  }
  flaten(&head);
  print(head);
  return 0;
}
