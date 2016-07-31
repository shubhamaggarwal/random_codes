/*input
geeksforgeeks
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//loops
#define f(i,s,n) for(ll i=(ll)s;i<(ll)n;i++)
#define rf(i,n,s) for(ll i=(ll)(n-1);i>=(ll)s;i--)
//reset
#define ms0(X) memset((X), 0, sizeof((X)))
#define ms1(X) memset((X), -1, sizeof((X)))
//IO
#define bio ios_base::sync_with_stdio;cin.tie(NULL)
//STL
#define pb push_back
#define pii pair<ll,ll>
#define vll vector<ll>
#define vpii vector<pii >
#define mll map<ll, ll>
#define mpii map<pii,ll> 
#define msll map<string, ll> 
#define sortv(v) sort(v.begin(),v.end())
#define F first
#define S second
//standard values
#define mod (ll)(1e9+7)
#define INF (ll)1e16
#define MAXN (ll)(1e5+5)
//comparator
bool cmp(pii a,pii b){
  if(a.F==b.F) return a.S<b.S;
  else return a.F<b.F;
}
ll exp(ll a, ll b){ll ans=1;while(b!=0){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
/********************************************************************************************************/
struct nd{
  char val;
  nd* nxt,* pre;
};
pair<bool,nd*> has[30];
nd* newnd(char c)
{
  nd* tmp=new nd;
  tmp->val=c;
  tmp->pre=NULL;
  tmp->nxt=tmp->pre;
  return tmp;
}
int main() 
{
  bio;
  string s;
  cin>>s;
  nd* head=new nd;
  nd* tail=new nd;
  head->nxt=tail;
  tail->pre=head;
  f(i,0,s.size()){
    cout<<s[i]<<" ";
    if(has[s[i]-'a'].S==NULL){
      nd* tmp=newnd(s[i]);
      nd* hold=tail->pre;
      tail->pre=tmp;
      hold->nxt=tmp;
      tmp->pre=hold;
      tmp->nxt=tail;
      has[s[i]-'a'].S=tmp;
    }
    else{
      if(has[s[i]-'a'].F){
        cout<<head->nxt->val<<endl;
        continue;
      }
      else{
        nd* x=has[s[i]-'a'].S;
        nd* prev=x->pre;
        nd* next=x->nxt;
        prev->nxt=next;
        next->pre=prev;
        free(x);
        has[s[i]-'a'].F=true;
      }
    }
    cout<<head->nxt->val<<endl;
  }
  return 0;
}
