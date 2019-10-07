
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




const ll N=2010;




void solve()
{
	
	

	ll n,t;
	ld p;
	cin>>n>>p>>t;
	ld expp=0;

	ld dp[N][N];

	for(ll i=0;i<N;i++)
		for(ll j=0;j<N;j++)
			dp[i][j]=0.0;


	dp[0][1]=1;
	d[0][0]=1;
	ld an=0;

	for(ll i=0;i<=t;i++)
	{

		for(ll j=0;j<=i;j++)
		{
			if(j>=n)
			dp[i+1][j]+=dp[i][j];
		else
		{
			dp[i+1][j+1]+=dp[i][j]*p;
			dp[i+1][j]+=dp[i][j]*(1-p);
		}
		}
	}

	for(ll j=0;j<=n;j++)
		an+=j*dp[t][j];

	cout<<fixed<<setprecan<<"\n";



}
int main()
{   
	solve();
    return 0;
}