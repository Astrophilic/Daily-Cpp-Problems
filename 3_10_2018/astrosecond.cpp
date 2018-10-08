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








void solve()
{
	
	ll n,q;
	cin>>n>>q;

	while(n--)
	{
		ll x,y,r;
		cin>>x>>y>>r;


		ll cnt=0;

		for(ll i=-r;i<=r;i++)
		{
			ld j=sqrt(r*r-i*i);
			if(floor(j)==j)
			{
				cout<<i<<" "<<j<<" is integral point on circle\n";
				cnt++;
			}
			
		}
		cout<<"count of such "<<cnt<<endl;
	}
	
}
int main()
{   
	solve();
    return 0;
}