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
// Macro to find number of elements in array
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
 
// A linked list nd has val, nxt pointer and child pointer
struct nd
{
    int val;
    struct nd *nxt;
    struct nd *child;
};
 
// A utility function to create a linked list with n nds. The val
// of nds is taken from arr[].  All child pointers are set as NULL
struct nd *createList(int *arr, int n)
{
    struct nd *head = NULL;
    struct nd *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct nd *)malloc(sizeof(*p));
        else {
            p->nxt = (struct nd *)malloc(sizeof(*p));
            p = p->nxt;
        }
        p->val = arr[i];
        p->nxt = p->child = NULL;
    }
    return head;
}
 
 
// This function creates the input list. Taken from GeeksForGeeks.
struct nd *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
 
    /* create 8 linked lists */
    struct nd *head1 = createList(arr1, SIZE(arr1));
    struct nd *head2 = createList(arr2, SIZE(arr2));
    struct nd *head3 = createList(arr3, SIZE(arr3));
    struct nd *head4 = createList(arr4, SIZE(arr4));
    struct nd *head5 = createList(arr5, SIZE(arr5));
    struct nd *head6 = createList(arr6, SIZE(arr6));
    struct nd *head7 = createList(arr7, SIZE(arr7));
    struct nd *head8 = createList(arr8, SIZE(arr8));
 
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->nxt->nxt->nxt->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->nxt->child = head6;
    head2->nxt->nxt->child = head7;
    head7->child = head8;
 
 
    /* Return head pointer of first linked list.  Note that all nds are
       reachable from head1 */
    return head1;
}
void print(nd* head)
{
  while(head->nxt!=NULL){
    head=head->nxt;
    cout<<head->val<<" ";
  }
  cout<<endl;
}
void flatten(nd** tmp2,nd** en)
{
  while((*tmp2)->nxt){
    if((*tmp2)->child){
      (*en)->nxt=(*tmp2)->child;
      (*tmp2)->child=NULL;
      while((*en)->nxt)
        (*en)=(*en)->nxt;
    }
    (*tmp2)=(*tmp2)->nxt;
  }
}
int main() 
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  nd* tmp= new nd;
  tmp=createList();
  nd* head=new nd;
  head->nxt=tmp;
  
  nd* tmp2=head->nxt;
  nd* en=tmp2;
  
  while(en->nxt){
    en=en->nxt;
  }
  flatten(&tmp2,&en);
  print(head);
  return 0;
}

