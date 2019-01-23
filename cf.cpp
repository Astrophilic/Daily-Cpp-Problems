
/*code by hazra*/

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define pul pair<ull,ull>
#define pl pair<ll,ll>

#define present(c,x) ((c).find(x) != (c).end())

using namespace std;



#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }








void solve()
{
	ll n;
	cin>>n;

	map<ll,ll>mymp;

	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;

		mymp[x-y]+=1;
		mymp[x+y]+=1;
	}

	ll ans=0;

	for(auto x:mymp)
	{	
		ll val=x.ss;
		if(val>=2)
		{
			ans+=(ll)(val*(ll)(val-1)/2);
		}

	}
	cout<<ans<<"\n";
}
int main()
{   
	solve();
    return 0;
}