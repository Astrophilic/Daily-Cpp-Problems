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
#define t int t; cin>>t; while(t--)
using namespace std;
#define ld double
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   t
    {

    	ll n,k;
    	cin>>n>>k;

    	ll c[n];

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>c[i];
    	}

    	sort(c,c+n);

    	ll lo=0;
    	ll hi=1e10+100;

    	while(fabs(hi-lo)>10) {
    	    
    	    cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
    	    ll mid=lo+(hi-lo+1)/2;

    	    

    	    ll counthere=0;

    	    for (int i = 0; i < n; ++i)
    	    {
    	    	if(c[i]>=mid)
    	    		counthere+=c[i]/mid;
    	    	if(counthere>=k)
    	    		break;
    	    }

    	    if(counthere>=k)
    	    	lo=mid;
    	    else
    	    	hi=mid-1;

    	}

    	ll ans=lo;
    	for (ll i = lo; i <=hi; ++i)
    	{
    		ll counthere=0;

    	    for (ll j = 0; j < n; ++j)
    	    {
    	    	if(c[j]>=i)
    	    		counthere+=c[j]/i;
    	    	if(counthere>=k)
    	    		break;
    	    }
    	    if(counthere>=k)
    	    	ans=i;

    	}
    	cout<<ans<<"\n";

    }

    return 0;
}