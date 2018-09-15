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

ll d[1000000];

int main()
{   
	//fastIO
	t
    {

    ll e,f;
    cin>>e>>f;

    ll weigh=f-e;

    ll n;
    cin>>n;

    ll p[n],w[n];


    

    const ll inf=1e18;

    for(ll i=0;i<1000000;i++)
    	d[i]=inf;

    for(ll i=0;i<n;i++)
    	cin>>p[i]>>w[i];

    d[0]=0;

    for(ll i=1;i<=weigh;i++)
    {

    	for(ll j=0;j<n;j++)
    	{
    		if(w[j]<=i)
    		{
    			d[i]=min(d[i],p[j]+d[i-w[j]]);

    		}
    	}
    }
    if(d[weigh]==inf)
    	cout<<"This is impossible.\n";
    else cout<<"The minimum amount of money in the piggy-bank is "<<d[weigh]<<"."<<endl;
    }

    return 0;
}