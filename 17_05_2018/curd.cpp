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
const ll EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


int main()
{   

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	t
    {
    
    ull n,T;
    cin>>n>>T;

    ull q[n];

    for (int i = 0; i < n; ++i)
    	{
    		cin>>q[i];
    	}

    ull lo=0,hi=1e19+10;

    while(lo<hi)
    {
    	ull mid=lo+(hi-lo)/2;


    	ull prod=0;

    	for (int i = 0; i < n; ++i)
    	{
    		prod+=mid/q[i];
    	}

    	if(prod>=T)
    		hi=mid;
    	else
    		lo=mid+1;

    }
    cout<<lo<<"\n";

   	}


    return 0;
}