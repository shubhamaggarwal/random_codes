// Spoj problem GSS3
#include <bits/stdc++.h>
#define ll int
//loops
#define f(i,s,n) for(ll i=s;i<n;i++)
#define rf(i,n,s) for(ll i=n-1;i>=s;i--)
#define pb push_back
//reset
#define ms0(X) memset((X), 0, sizeof((X)))
#define ms1(X) memset((X), -1, sizeof((X)))
//STL
#define len(X) X.length()
#define pii pair<ll,ll>
#define vll vector<ll>
#define sll set<ll> 
#define msll map<string, ll> 
#define mll map<ll, ll>
#define LS1(i) (i&(-i))
#define sortv(v) sort(v.begin(),v.end())
#define F first
#define S second
//standard values
#define mod 1000000007LL
#define MAXN 100005
#define LLMAX	9223372036854775807LL
#define PI   3.14159265358979323846264338327950288
#define EPS 1e-6
using namespace std;
//comparator
struct sort_pred{bool operator()(const ll &left, const ll &right) {
        return left > right;
}};
ll exp(ll a, ll b){ll ans=1;while(b!=0){if(b%2)ans=ans*a;a=a*a;b/=2;}return ans;}
/********************************************************************************************************/
struct node{
	ll maxsum;ll presum;ll sufsum;ll sum;
	node fnc(node a, node b)
	{
		sum=a.sum+b.sum;
		
		presum=max(a.presum,a.sum+b.presum);
		
		sufsum=max(b.sufsum,a.sufsum+b.sum);
		
		maxsum=max(sum,max(presum,sufsum));
		
		maxsum=max(maxsum,max(a.maxsum,b.maxsum));
		
		maxsum=max(maxsum,a.sufsum+b.presum);
	}
	node assign(ll val)
	{
		sum=presum=sufsum=maxsum=val;
	}

};
node seg[3*MAXN];
ll arr[MAXN];
void build(ll nd,ll st,ll en)
{
	if(st==en){
		seg[nd].maxsum=seg[nd].presum=seg[nd].sufsum=seg[nd].sum=arr[st];
	}
	else{
		ll mid=(st+en)/2;
		build(2*nd,st,mid);
		build(2*nd+1,mid+1,en);
		seg[nd].fnc(seg[2*nd],seg[2*nd+1]);
	}
}
node que(ll nd,ll st,ll en,ll l,ll r)
{
	if(l<=st&&en<=r)
		return seg[nd];
	ll mid=(st+en)/2;
	if(mid<l)
		return que(2*nd+1,mid+1,en,l,r);
	else if(r<=mid)
		return que(2*nd,st,mid,l,r);
	else{
		node x=que(2*nd,st,mid,l,r);
		node y=que(2*nd+1,mid+1,en,l,r);
		node k;
		k.fnc(x,y);
		return k;	
	}
}
void upd(ll nd,ll st,ll en,ll id,ll val)
{
	if(st==en){
		arr[id]=val;
		seg[nd].assign(val);
	}
	else{
		ll mid=(st+en)/2;
		if(id<=mid)
			upd(2*nd,st,mid,id,val);
		else
			upd(2*nd+1,mid+1,en,id,val);
		seg[nd].fnc(seg[2*nd],seg[2*nd+1]);
	}
}
int main() 
{
	ll n;
	scanf("%d",&n);
	f(i,1,n+1)
	scanf("%d",&arr[i]);
	build(1,1,n);
	ll q;
	scanf("%d",&q);
	f(i,0,q){
		ll a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(!a){
			upd(1,1,n,b,c);
		}
		else{
			ll k=que(1,1,n,b,c).maxsum;
			printf("%d\n",k);
		}
	}
	return 0;
}

