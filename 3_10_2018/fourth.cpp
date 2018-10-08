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


 ll d[N][105];

ll funcr(ll n,ll r,ll M)
{	
	if(r>n)
		return 0;

	if(r==0 || r==n)
		return 1;

	if(d[n][r]!=-1)
		return d[n][r];

	
	return d[n][r]=( funcr(n-1,r-1,M)%M+funcr(n-1,r,M)%M )%M;

}



void solve()
{
	memset(d,-1,sizeof d);

	ll tc,M;

	cin>>tc>>M;
	while(tc--)
	{

		ll n
		cin>>n;


	}

	

	ans-=subtract;
	if(ans>=M)
		ans-=M;

	cout<<ans<<"\n";
}
int main()
{   
	solve();
    return 0;
}