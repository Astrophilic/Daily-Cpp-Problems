
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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;

		ll h[n+1];

		h[0]=0;

		for(ll i=1;i<=n;i++)
			cin>>h[i];


		ll extra=0;

		for(ll i=0;i<n;i++)
		{
			if(h[i+1]>h[i]+k)
			{
				ll df=h[i+1]-h[i];

				if(df%k)
				{
					extra+=df/k;
				}
				else
				{
					extra+=(df/k)-1;
				}
			}
		}
		cout<<extra<<"\n";

	}
}
int main()
{   
	solve();
    return 0;
}