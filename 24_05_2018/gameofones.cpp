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


ll d[2][55];

ll f(ll start,ll len)
{

//	cout<<"f with start "<<start<<" len :"<<len<<endl;
	if(len==1)
		return d[start][len]=start;

	if(d[start][len]!=-1)
		return d[start][len];

	ll ans1=f(0,len-1);
	//cout<<"ones for s: 0 len:"<<len-1<<" :"<<ans1<<endl;
	ll ans2=f(1,len-1);
	//cout<<"ones for s: 1 len:"<<len-1<<" :"<<ans2<<endl;
	return d[start][len]=start*(1LL<<(len-1))+ans1+ans2;

	
}

int main()
{   
	//fastIO

	for(ll i=0;i<2;i++)
		for(ll j=0;j<55;j++)
			d[i][j]=-1;
	t
    {
    	ll n;
    	cin>>n;
    	ll ans=1LL<<(n-1);

    	cout<<ans<<" "<<f(1,n)<<endl;
    }

    return 0;
}