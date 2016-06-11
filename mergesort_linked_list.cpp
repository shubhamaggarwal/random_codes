/*input
10
9 8 1 5 4 7 0 1 3 3
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
  while(head->nxt!=NULL){
    head=head->nxt;
    cout<<head->val<<" ";
  }
  cout<<endl;
}
void split(nd * head, nd** front, nd** back)
{
  if(head->nxt==NULL){
      *front=NULL;
      *back=NULL;
  }
  else if(head->nxt->nxt==NULL){
    *front=head->nxt;
    *back=NULL;
  }
  else{
    nd* slow=head;
    nd* fast=head->nxt;
    while(fast!=NULL){
      slow=slow->nxt;
      fast=fast->nxt;
      if(fast!=NULL)
        fast=fast->nxt;
    }
    *front=head->nxt;
    *back=slow->nxt;
  }
}
nd* merge(nd** head1, nd** head2)
{
  if((*head1)->nxt==NULL)
    return *head2;
  if((*head2)->nxt==NULL)
    return *head1;
  nd* result=new nd;
  result->nxt=NULL;
  nd* temp=result;
  nd* t1=(*head1)->nxt;
  nd* t2=(*head2)->nxt;
  while(t1&&t2)
  {
    if(t1->val==t2->val){
      temp->nxt=newnd(t1->val);
      temp=temp->nxt;
      temp->nxt=newnd(t2->val);
      temp=temp->nxt;
      t1=t1->nxt;
      t2=t2->nxt;
    }
    else if(t1->val<t2->val){
      temp->nxt=newnd(t1->val);
      temp=temp->nxt;
      t1=t1->nxt;
    }
    else{
      temp->nxt=newnd(t2->val);
      temp=temp->nxt;
      t2=t2->nxt;
    }
  }
  while(t1){
      temp->nxt=newnd(t1->val);
      temp=temp->nxt;
      t1=t1->nxt;
  }
  while(t2){
      temp->nxt=newnd(t2->val);
      temp=temp->nxt;
      t2=t2->nxt;
  }
  return result;
}
void mergesort(nd** head)
{
  if((*head)->nxt==NULL||(*head)->nxt->nxt==NULL)
    return;
  nd* front,*back;
  split(*head,&front,&back);
  nd* f1=new nd;
  nd* tmp=f1;
  nd* tm=*head;
  tmp->nxt=newnd(front->val);
  tm=tm->nxt->nxt;
  while(tm!=NULL&&tm!=back){
    while(tmp->nxt!=NULL)
      tmp=tmp->nxt;
    tmp->nxt=newnd(tm->val);
    tm=tm->nxt;
  }
  nd* b1=new nd;
  nd* tmp2=b1;
  while(tm!=NULL){
    while(tmp2->nxt!=NULL)
      tmp2=tmp2->nxt;
    tmp2->nxt=newnd(tm->val);
    tm=tm->nxt;
  }
 
   mergesort(&f1);
   mergesort(&b1);
   *head=merge(&f1,&b1);
}

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* head;
  head=new nd;
  head->nxt=NULL;
  ll n;
  cin>>n;
  nd* tmp=head;
  f(i,0,n){
    ll a;
    cin>>a;
    tmp->nxt=newnd(a);
    tmp=tmp->nxt;
  }
  mergesort(&head);
  print(head);
  return 0;
}

