#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
//#define ll long long
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


#define ll long

const ll M=5e6+5;
ll mod;
ll fac[M];

void facx()
{	
	
	fac[0]=1;
	fac[1]=1;
	fac[2]=1;

	for(ll i=3;i<M-4;i++)
	{
		fac[i]=i*fac[i-1];

		if(fac[i]>=mod)
			fac[i]%=mod;
	}

}





void solve()
{
	
	ll tc;
	cin>>tc>>mod;
	facx();
	while(tc--)
	{
		ll n;
		cin>>n;	

		if(n<=2)
		{
			cout<<0<<" ";
			continue;
		}
		if(n==3)
		{
			ll ans=9%mod;
			cout<<ans<<" ";
			continue;

		}
		
		ll v1=((n*n)%mod *( fac[n-1]))%mod;

		ll v2=(2*(fac[n-1])-1+mod)%mod;

		ll ans=(v1*v2)%mod;

		cout<<ans<<" ";
	}
	
}
int main()
{   
	solve();
    return 0;
}