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
    	ll n,k;
    	cin>>n>>k;
    	std::vector<ll> v(n);

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>v[i];
    	}
    	sort(all(v));


    	ll ans=0;

    	for (int i = 0; i < n; ++i)
    	{
    		ll x=v[i];
    		x+=k;

    		auto it=lower_bound(all(v),x)-v.begin();

    		
    		if(it!=n&&v[it]==x)
    		{
    			auto dis=upper_bound(all(v),x)-v.begin();
    			
    	
    			dis=dis-it;

    			
    			ans+=dis;

    		}
    	}
    	cout<<ans<<endl;
    }

    return 0;
}