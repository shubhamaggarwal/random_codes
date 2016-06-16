/*input

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
  nd* lf;
  nd* rt;
};
nd* newnd(ll num)
{
  nd* tmp=new nd;
  tmp->val=num;
  tmp->rt=tmp->lf=NULL;
  return tmp;
}
void inorder(nd* root)
{
  if(!root)
    return ;
  inorder(root->lf);
  cout<<root->val<<" ";
  inorder(root->rt);
}
void preorder(nd* root)
{
  if(!root)
    return ;
  cout<<root->val<<" ";
  preorder(root->lf);
  preorder(root->rt);
}
void postorder(nd* root)
{
  if(!root)
    return ;
  postorder(root->lf);
  postorder(root->rt);
  cout<<root->val<<" ";
}
ll diam(nd* root, ll* h)
{
  if(root==NULL){
    *h=0;
    return 0;
  }
  ll lh=0,rh=0;
  ll a=diam(root->lf,&lh);
  ll b=diam(root->rt,&rh);
  *h=max(lh,rh)+1;
  return max(a,max(b,lh+rh+1)); 
}
ll dia(nd* root)
{
  if(root==NULL)
    return 0LL;
  ll lh=0,rh=0;
  ll a=diam(root->lf,&lh);
  ll b=diam(root->rt,&rh);
  return max(a,max(b,lh+rh+1));
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* root=new nd;
  root->val=1;
  root->lf=newnd(2);
  root->rt=newnd(3);
  root->lf->lf=newnd(4);
  root->lf->rt=newnd(5);
  root->rt->lf=newnd(6);
  root->rt->rt=newnd(7);
  inorder(root);cout<<endl;
  preorder(root);cout<<endl;
  postorder(root);cout<<endl;
  trace1(dia(root));
  return 0;
}

