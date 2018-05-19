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
{   
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	t
    {

    	ll n,c;
    	cin>>n>>c;

    	ll p[n];

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>p[i];
    	}

    	sort(p,p+n);

    	ll lo=0,hi=1e10+100;

    	while(lo<hi)
    	{
    		ll mid=lo+(hi-lo+1)/2;

    		ll start=p[0];

    		ll cows=1;

    		for (int i = 0; i < n; ++i)
    		{
    			if(p[i]-start>=mid)
    			{
    				start=p[i];
    				cows++;
    			}
    		}

    		if(cows<c)
    			hi=mid-1;
    		else
    			lo=mid;

    	}
    	cout<<lo<<"\n";

    }

    return 0;
}