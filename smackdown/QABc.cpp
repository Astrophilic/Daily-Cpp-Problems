
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








void solve()
{
	ll t;
	cin>>t;
	while(t--) 
	{
	    

	    ll n;
	    cin>>n;

	    ll a[n],b[n];

	    for(ll i=0;i<n;i++)
	    	cin>>a[i];

	    for(ll i=0;i<n;i++)
	    	cin>>b[i];


	    

	    for(ll i=0;i<n-2;i++)
	    {
	    	ll d1=b[i]-a[i];
	    	ll d2=b[i+1]-a[i+1];
	    	ll d3=b[i+2]-a[i+2];

	    	d1/=1;
	    	d2/=2;
	    	d3/=3;

	    	ll f=min(d1,min(d2,d3));
	    	b[i]-=f*1;
	    	b[i+1]-=f*2;
	    	b[i+2]-=f*3;
	    }

	  
	    ll f=1;
	    for(ll i=0;i<n;i++)
	    {
	    	if(b[i]==a[i])
	    		continue;
	    	else
	    	{
	    		f=0;
	    		break;
	    	}
	    }
	    if(f)
	    	cout<<"TAK\n";
	    else
	    	cout<<"NIE\n";



	    }
	}
		

int main()
{   
	solve();
    return 0;
}