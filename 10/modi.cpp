
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



ll n,k;

const ll M=1010;
const ll MD=1e9+7;
ll d[M][M];

ll fun(ll in,ll cnt)
{
	if(in>n)
	{
		if(cnt==0)
			return 1;
		return 0;
	}

	if(d[in][cnt]!=-1)
		return d[in][cnt];

	
	return d[in][cnt]=(2*fun(in+2,cnt-2)%MD+4*fun(in+2,cnt-1)%MD+fun(in+1,cnt)%MD)%MD;

}

void solve()
{
	
	ll t;
	cin>>t;

	while(t--)
	{	

		memset(d, -1, sizeof d);

		cin>>n>>k;

		cout<<fun(1,k)<<"\n";

	}
}
int main()
{   
	solve();
    return 0;
}