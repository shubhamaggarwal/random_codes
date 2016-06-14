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
ll in[]={4, 2, 5, 1, 6, 3, 7};
ll po[]={4, 5, 2, 6, 7, 3, 1};
ll id=6;
nd* maketree(ll st,ll en)
{
  if(en<0||id<0||st>en)
    return NULL;
  nd* root=newnd(po[id]);
  ll val=po[id];
  ll id2=0;
  f(i,st,en+1){
    if(in[i]==val){
      id2=i;
      break;
    }
  }
  id--;
  root->rt=maketree(id2+1,en);
  root->lf=maketree(st,id2-1);
  return root;
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* root=maketree(0,6);
  preorder(root);cout<<endl;
  cout<<"   "<<root->val<<endl;
  cout<<"  "<<root->lf->val<<" "<<root->rt->val<<endl;
  cout<<root->lf->lf->val<<" "<<root->lf->rt->val<<" "<<root->rt->lf->val<<" "<<root->rt->rt->val<<endl; 
  return 0;
}

