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

ll n;
ll a[100010];
ll d[100010];

ll f(ll i)
{
	if(i>n-1)
		return 0;
	if(d[i]!=-1)
		return d[i];

	return d[i]=max(a[i]+f(i+2),max(a[i]+a[i+1]+f(i+4),a[i]+a[i+1]+a[i+2]+f(i+6)));
}

int main()
{   
	fastIO
	t
    {
    	memset(a,0,sizeof(a));
    	
    	for(ll i=0;i<100010;i++)
    		d[i]=-1;

    	cin>>n;

    	for(ll i=0;i<n;i++)
    		cin>>a[i];

    	cout<<f(0)<<endl;
    }

    return 0;
}