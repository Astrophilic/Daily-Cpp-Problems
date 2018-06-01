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

ll a[1010];
ll d[1010][1010];


ll f(ll s, ll e)
{	

	if(s>e)
		return 0;

	
	
	if(d[s][e]!=-1)
		return d[s][e];

	ll v1=a[s]+ ( (a[s+1]>=a[e])? f(s+2,e) : f(s+1,e-1) );

	ll v2=a[e]+ ( (a[s]>=a[e-1])? f(s+1,e-1): f(s,e-2) );

	return d[s][e]=max(v1,v2);
}
int main()
{   
	ll k=1;
	
	while(1)
	{
		ll n;
		cin>>n;
		if(n==0)
			break;

		for(ll i=0;i<1010;i++)
			for(ll j=0;j<1010;j++)
				d[i][j]=-1;

		ll s=0;
		for(ll i=0;i<n;i++)
			cin>>a[i],s+=a[i];

		ll ans=2*f(0,n-1)-s;
		
		printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",k++,ans);




	}

    return 0;
}