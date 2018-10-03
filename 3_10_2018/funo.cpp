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


const ll M=1e5+10;

ll a[M],b[M];

map< pair< pair<ll,ll>, ll >,ll  >d;



ll fun(ll L,ll R,ll i)
{
	if(L==R)
	{
		if(i==1)
			return d[ { {L,R},1} ]=a[L];

		return d[ { {L,R}, 2} ]=b[L];
	}

	

	if(d.find({ {L,R}, i})!=d.end())
		return d[{ {L,R}, i}];


	if(i==1)
	{
		return d[{ {L,R}, i}]=a[L]+fun(L+1,R,2);
	}
	else
	{
		return d[{ {L,R}, i}]=b[L]+fun(L+1,R,1);
	}
}


void solve()
{
	
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	

	ll n,q;
	cin>>n>>q;

	for(ll i=1;i<=n;i++)
		cin>>a[i];

	for(ll i=1;i<=n;i++)
		cin>>b[i];

	while(q--)
	{
		ll i,x,y;
		cin>>i>>x>>y;

		cout<<fun(x,y,i)<<"\n";
	}
	

	
}
int main()
{   
	solve();
    return 0;
}