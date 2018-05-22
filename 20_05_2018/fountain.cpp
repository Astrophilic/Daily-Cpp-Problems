#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
//#define ll long long
#define ll unsigned long long
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


const ll MD=1e9+7;

const ll M=1e5+10;

ll fac[M];

ll power(ll x,ll n)
{	
	x%=MD;
	if(n==0)
		return 1;
	else
		if(n%2)
			return (x*power(x*x,n/2))%MD;
		else
			return power(x*x,n/2)%MD;
}

ll modinv(ll x)
{
	return power(x,MD-2)%MD;
}
int main()
{   
	
	fac[0]=fac[1]=1;

	for(ll i=2;i<M;i++)
	{
		fac[i]=i*fac[i-1];

		if(fac[i]>=MD)
			fac[i]%=MD;
	}

	ll n,k;
	cin>>n>>k;

	
	ll nck=(fac[n]*modinv(fac[n-k]))%MD;
	nck*=modinv(fac[k]);

	nck%=MD;

	ll npk=nck*fac[k];

	
	npk%=MD;

	ll ans=npk*nck;

	if(ans>=MD)
		ans%=MD;
	cout<<ans<<"\n";

    return 0;
}