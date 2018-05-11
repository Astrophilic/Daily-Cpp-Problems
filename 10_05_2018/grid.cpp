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

char gr[110][110];

int vis[110][110];

ll n;


void dfs(ll x,ll y)
{

	vis[x][y]=1;

	//cout<<"dfs with x,y"<<x<<" "<<y<<endl;
	for (int i = -1; i <=1; ++i)
	{
		
		for (int j = -1; j <=1; ++j)
		{
			if(fabs(i+j)==2)
				continue;

			ll nx=x+i;
			ll ny=y+j;

			if( nx>=0 && nx<n && ny>=0 && ny<n &&!vis[nx][ny] &&( gr[nx][ny]=='@'||gr[nx][ny]=='x'))
				dfs(nx,ny);

		}
	}
}
int main()
{   
	ll tc=1;


	t
	{
		cin>>n;
		ll ans=0;


		for (int i = 0; i < n; ++i)
		{
			
			for (int j = 0; j < n; ++j)
			{
				cin>>gr[i][j];
				vis[i][j]=0;

			}
		}

		for (int i = 0; i < n; ++i)
		{
			
			for (int j = 0; j < n; ++j)
			{
				
				if(gr[i][j]=='x'&&!vis[i][j])
					{
						dfs(i,j);
						ans+=1;
					}
			}
		}
		cout<<"Case"<<" "<<tc++<<": "<<ans<<"\n";
	}

    return 0;
}