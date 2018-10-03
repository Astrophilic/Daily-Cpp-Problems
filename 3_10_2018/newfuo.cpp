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

	ll a[n+1],b[n+1],d[n+2][2];


	for (int i =1; i <=n; ++i)
	{
		cin>>a[i];
	}

	for (int i =1; i <=n; ++i)
	{
		cin>>b[i];
	}

	memset(d,0,sizeof(d));

	d[n][0]=a[n];
	d[n][1]=b[n];


	for (int i = n-1; i>=1; --i)
	{
		d[i][0]=a[i]+d[i+1][1];
		d[i][1]=b[i]+d[i+1][0];

		cout<<d[i][0]<<" "<<d[i][1]<<endl;
	}

	while(q--) {
	    ll i,l,r;
	    cin>>i>>l>>r;
	    i--;
	    ll del=i;

	    if((r-l)%2==0)
	    {
	    	if(i==1)
	    		del=0;
	    	else
	    		del=1;
	    }

	    cout<<d[l][i]<<" "<<d[r+1][del]<<endl;
	    cout<<d[l][i]-d[r+1][del]<<"\n";
	    
	}
	
}
int main()
{   
	solve();
    return 0;
}