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

string a,b;
ll k;

const ll inf=1e18;

ll d[110][110][110];

ll fun(ll i,ll j,ll len)
{
	if(len==0)
		return 0;
	if(i>=a.size()||j>=b.size())
		return -inf;

	if(d[i][j][len]!=-1)
		return d[i][j][len];

	if(a[i]==b[j])
		return d[i][j][len]=max(int(a[i])+fun(i+1,j+1,len-1),fun(i+1,j+1,len));

	return d[i][j][len]=max(fun(i+1,j,len),fun(i,j+1,len));

}

int main()
{   
	


	t
	{
		memset(d,-1,sizeof(d));

		cin>>a>>b;
		cin>>k;

		ll ans=fun(0,0,k);

		if(ans<0)
			cout<<0<<"\n";
		else
			cout<<ans<<"\n";


	}
    return 0;
}