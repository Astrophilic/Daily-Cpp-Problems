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

//#define t int t; cin>>t; while(t--)
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



const ll M=1e9+7;



ll modexe(ll x,ll n)
{	
	x%=M;

	if(n==0)
		return 1;

	if(n%2)
		return (x*modexe( x*x,n/2))%M;

	return modexe(x*x,n/2)%M;
}

void solve()
{
	
	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll x =modexe(2,n);
		ll y=n-3+1;

		y=y*(y+1)/2;
		y%=M;
		cout<<x<<" "<<y<<endl;
		ll ans=x-y;
		cout<<ans<<"\n";
	}
}
int main()
{   
	solve();
    return 0;
}
