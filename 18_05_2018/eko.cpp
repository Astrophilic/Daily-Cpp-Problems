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
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   
	
	fastIO
    {

    ll n,m;
    cin>>n>>m;

    ll h[n];

    for(ll i=0;i<n;i++)
    	cin>>h[i];

    ll lo=0;
    ll hi=2e6;
    sort(h,h+n);

    while(lo<hi)
    {
    	
    	//cout<<"lo "<<lo<<" hi:"<<hi<<endl;
    	ll mid=lo+(hi-lo+1)/2;
    	
    	ll ctr=0;

    	for (int i = 0; i < n; ++i)
    	{
    		if(h[i]>=mid)
    			{
    				ctr+=h[i]-mid;
    				

    			}

    	}
    	if(ctr>=m)
    		lo=mid;
    	else 
    		hi=mid-1;


    }
    cout<<lo<<"\n";
    }

    return 0;
}