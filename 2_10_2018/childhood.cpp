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


const ll M=1e5+10;

ll f[M],d[M];

int main()
{   
	//fastIO
	t
    {

    	memset(f,0,sizeof f);
    	memset(d,0,sizeof d);

    	ll n,l,r;
    	cin>>n>>l>>r;



    	for(ll i=1;i<=n;i++)
    	{
    	ll x;
    	cin>>x;
    	f[x]+=1;
    	}

    	for(ll i=1;i<M;i++)
    	{
    		if(i-l-1>=1)
    		{
    			d[i]=max(d[i-l-1]+f[i]*i,d[i-1]);
    		}
    		else
    			d[i]=max(d[i-1],f[i]*i);

    	}
    	cout<<d[M-1]<<"\n";

    	}
    

    return 0;
}
