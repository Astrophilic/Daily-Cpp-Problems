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


const ll N=1e5+10;
const ll M=1e9+7;

 ll d[N][105];




std::vector<ll> v[N];
const ll inf=1e18;

ll k,n;

ll fun(ll s,ll x)
{
		if(x==k)
			return 1;

	if(d[s][x]!=-1)
		return d[s][x];
		
		d[s][x]=0;
		
		for(auto child:v[s])
		{   
		    
		    d[s][x]+=fun(child,x+1)+fun(child,x);
		}
    
    return d[s][x];


}


void solve()
{
	memset(d,-1,sizeof d);
	
	
	cin>>n>>k;

	for(ll i=2;i<=n;i++)
	{
		ll x;
		cin>>x;
		v[x].push_back(i);


	}
	
	ll ans=fun(1,0)+fun(1,1);

	cout<<ans<<"\n";
}
int main()
{   
	solve();
    return 0;
}