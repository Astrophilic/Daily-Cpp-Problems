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


struct node
{
	int left;
	int right;
	node():left(0),right(0)
	{}

	node(int x,int y):left(x),right(y)
	{}
};

node tree[2010];
ll ar[2010];
ll sz[2010];
std::vector<ll>pre,post;


void init(ll x)
{	
	for(ll i=1;i<=x;i++)
		ar[i]=i,sz[i]=1;
}

ll root(ll x)
{
	while(x!=ar[x])
	{
		ar[x]=ar[ar[x]];
		x=ar[x];

	}
	return x;

}

void unio(ll x,ll y)
{
	ll rx=root(x);
	ll ry=root(y);

	if(rx==ry)
		return;

	if(sz[rx]>=sz[ry])
	{
		ar[ry]=rx;
		sz[rx]+=sz[ry];
		return;
	}
	else
	{
		ar[rx]=ry;
		sz[ry]+=sz[rx];
	}
}



void preorder(ll x)
{
	pre.push_back(x);
	
	

	if(tree[x].left)
		preorder(tree[x].left);

	if(tree[x].right)
		preorder(tree[x].right);
}

void postorder(ll x)
{
	if(tree[x].left)
		postorder(tree[x].left);

	if(tree[x].right)
		postorder(tree[x].right);

	post.push_back(x);

}




int main()
{   
	

	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
	ll T;
	cin>>T;


	for(ll tc=1;tc<=T;tc++)
    {
    	pre.clear();
    	post.clear();

    int n,k;
    cin>>n>>k;

    init(n);

    for(ll i=0;i<2010;i++)
    	tree[i].left=tree[i].right=0;

    

    for(int i=1;i<=n;i++)
    {
    	ll x,y;
    	cin>>x>>y;
    	tree[i].left=x;
    	tree[i].right=y;
    }
    preorder(1);
    

    postorder(1);
    

    for(ll i=0;i<pre.size();i++)
    {
    	
    	unio(pre[i],post[i]);
   	}

   	ll cnc=0;
   	
   	map<ll,ll>mymap;

   	for(ll i=1;i<=n;i++)
   	{
   		if(ar[i]==i)
   			{
   				cnc++;
   				mymap[i]=0;
   			}

   	}

   	
   	if(cnc<k)
   	{	

   		cout<<"Case #"<<tc<<": Impossible\n";
   		continue;
   	}

   	ll ctr=1;

   	for(auto x:mymap)
   	{
   		mymap[x.first]=ctr;

   		if(ctr!=k)
   		ctr++;

   	}

   	ll ans[n+1]={0};

  	cout<<"Case #"<<tc<<": ";
   	for(ll i=1;i<=n;i++)
   	{
   		ans[i]=mymap[root(i)];
   		cout<<ans[i]<<" ";
   	}



   	cout<<"\n";

    }

    return 0;
}