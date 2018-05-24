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
	t
    {

    	ll d[55][1010];
		ll k,m;
		ll p[55];
		ll wt[55];

    for(ll i=0;i<55;i++)
    	for(ll j=0;j<1010;j++)
    		d[i][j]=0;



    cin>>k>>m;

    for(ll i=1;i<=m;i++)
    {
    	cin>>wt[i]>>p[i];
    }

    
    for(ll i=1;i<=m;i++)
    {
    	for(ll j=1;j<=k;j++)
    	{
    		if(wt[i]<=j)
    			d[i][j]=max(d[i-1][j],p[i]+d[i-1][j-wt[i]]);
    		else
    			d[i][j]=d[i-1][j];
    	}
    }



    cout<<"Hey stupid robber, you can get "<<d[m][k]<<".\n";
    }

    return 0;
}