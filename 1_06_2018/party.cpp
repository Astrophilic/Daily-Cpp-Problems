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

ll fee[150];
ll fun[150];

ll f(ll i,ll sum)
{
	if(i>=n)
		return 0;

	ll v1=0;
	ll v2=0;

	if(fee[i]<=sum)
		v1=fun[i]+f(i+1,sum-fee[i]);
	v2=f(i+1,sum);

	return max(v1,v2);
}

int main()
{   
	
	ll sum=0;
	while(1)
    {
    	cin>>sum>>n;
    	if(sum==n&&n==0)
    		break;
    	for(ll i=0;i<n;i++)
    	{
    		cin>>fee[i]>>fun[i];
    	}
    	cout<<f(0,sum)<<endl;
    }

    return 0;
}