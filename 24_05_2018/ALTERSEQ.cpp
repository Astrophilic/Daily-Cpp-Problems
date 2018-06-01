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



int main()
{   
	fastIO
	
    {
    	ll n;
    	cin>>n;

    	ll a[n];

    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	
    	ll d[n]={0};

    	d[0]=1;
    	ll ans=1;

    	for(ll i=1;i<n;i++)
    	{	
    		d[i]=1;

    		for(ll j=i-1;j>=0;j--)
    		{
    			if( (fabs(a[j])<fabs(a[i]))&&(a[j]*a[i]<0) )
    				d[i]=max(d[i],1+d[j]);

    			if(d[i]>ans)
    				ans=d[i];

    		}
    	}
    	cout<<ans<<endl;
    }

    return 0;
}