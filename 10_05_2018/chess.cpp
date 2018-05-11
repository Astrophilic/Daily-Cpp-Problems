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

ll n;
ll gr[50][50];
ll vis[50][50];

void dfs(ll x, ll y)
{

	vis[x][y]=1;

	for(ll i=-1;i<=1;i++)
	{
		for(ll j=-1;j<=1;j++)
		{
			ll nx,ny;
			nx=x+i;
			ny=y+j;

			if(nx>=0&&ny>=0&&nx<n&ny<n&&gr[nx][ny]&&!vis[nx][ny])
				dfs(nx,ny);
		}
	}
}

int main()
{   
	ll tc=1;

	while(cin>>n){
	    
	   

	    for (int i = 0; i < n; ++i)
	    {
	    	
	    	for (int j = 0; j < n; ++j)
	    	{	
	    		char ch;
	    		cin>>ch;
	    		gr[i][j]=ch-'0';
	    		vis[i][j]=0;
	    	}
	    }
	    ll ans=0;

	    for (int i = 0; i < n; ++i)
	    {
	    	
	    	for (int j= 0; j < n; ++j)
	    	{
	    		if(gr[i][j]&&!vis[i][j])
	    		{
	    			dfs(i,j);
	    			ans++;
	    		}
	    	}
	    }
	    printf("Image number %lld contains %lld war eagles.\n",tc++,ans);

	}		

    return 0;
}