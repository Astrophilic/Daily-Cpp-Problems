#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pul pair<ull,ull>
#define pl pair<ll,ll>
#define pi pair<int,int>

using namespace std;

#define t int t; cin>>t; while(t--)
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

const ll M=1LL<<17+10;
ll a[M];

struct node
{
	int x=0;

	
};
node merge(node a ,node b,ll flag)
	{	
		node res;

		if(flag==1)
		{
			res.x=a.x|b.x;
		}
		else
			res.x=a.x^b.x;

		return res;
	}

node tree[3*M];

void build(ll nod,ll start,ll end,ll flag)
{
	if(start==end)
	{
		tree[nod].x=a[start];
		return;
	}
	ll mid=start+(end-start)/2;

	build(2*nod,start,mid,flag^1);
	build(2*nod+1,mid+1,end,flag^1);

	tree[nod]=merge(tree[2*nod],tree[2*nod+1],flag);



}
node query(ll nod,ll start,ll end,ll ql,ll qr,ll flag)
{
	if(qr<start||end<ql||start>end)
	{
		node a;
		a.x=0;
		return a;
	}

	if(ql<=start&&qr<=end)
		return tree[nod];

	ll mid=start+(end-start)/2;

	node left=query(2*nod,start,mid,ql,qr,flag^1);
	node right=query(2*nod+1,mid+1,end,ql,qr,flag^1);

	node res=merge(left,right,flag);

	return res;

}

void update(ll nod,ll start,ll end,ll in,ll val,ll flag)
{
	if(start==end)
	{
		if(start==in){
			a[in]=val;
			tree[nod].x=a[start];
		}
		return;
	}
		ll mid=start+(end-start)/2;

		if(in<=mid)
			update(2*nod,start,mid,in,val,flag^1);
		else 
			update(2*nod+1,mid+1,end,in,val,flag^1);

		tree[nod]=merge(tree[2*nod],tree[2*nod+1],flag);
}


int main()
{   
	//fastIO
	

	ll n,m;
	cin>>n>>m;

	for(ll i=0;i<n;i++)
		cin>>a[i];

	build(1,0,n-1,n%2);

	while(m--)
	{
		ll p,b;
		cin>>p>>b;
		update(1,0,n-1,p-1,b,n%2);

		node res=query(1,0,n-1,0,n-1,n%2);

		cout<<res.x<<"\n";

	}
    return 0;
}