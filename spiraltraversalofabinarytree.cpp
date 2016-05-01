/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int MAXN = 100005;
//comparator
bool cmp(pii a,pii b){
  if(a.F==b.F) return a.S<b.S;
  else return a.F<b.F;
}
ll exp(ll a, ll b){ll ans=1;while(b!=0){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
/********************************************************************************************************/
struct tree
{
  int val;
  tree* left;
  tree* right;
};
tree* head;
tree* newnode(int value)
{
  tree* temp=new tree;
  temp->val=value;
  temp->right=temp->left=NULL;
  return temp;
}
bool fg=0;
stack<pair<tree*,int> >s,s1,s3;
void spiral()
{
  if(s.size()==0)
    return ;
  if(!fg)//left to right
  {
    while(!s.empty()){
      pair<tree*,int>p=s.top();
      s.pop();
      cout<<p.S<<" ";
      if(p.F->left!=NULL)
      s1.push({p.F->left,p.F->left->val});
      if(p.F->right!=NULL)
      s1.push({p.F->right,p.F->right->val});
    }
  }
  else{
    while(!s.empty()){
      pair<tree*,int>p=s.top();
      s.pop();
      cout<<p.S<<" ";
      if(p.F->right!=NULL)
      s1.push({p.F->right,p.F->right->val});
      if(p.F->left!=NULL)
      s1.push({p.F->left,p.F->left->val});
    }
  }
  fg=!fg;
  cout<<endl;
  while(!s1.empty()){
    s3.push(s1.top());
    s1.pop();
  }
  while(!s3.empty()){
    s.push(s3.top());
    s3.pop();
  }
  spiral();
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  head=new tree;
  head->val=1;
  head->left=newnode(2);
  head->right=newnode(3);
  head->left->left=newnode(4);
  head->left->right=newnode(5);
  head->right->left=newnode(6);
  head->right->right=newnode(7);
  s.push({head,head->val});
  spiral();
  return 0;
}
