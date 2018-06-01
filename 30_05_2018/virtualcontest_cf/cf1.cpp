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
#define ld long double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


const ll M=1e5+10;

ll a[M];
ll d[M][110];
const ll INF=1e18;
std::vector<ll> v[M];
ll n,m,k,s;
std::vector<ll> level[110];
ll vis[M];

ll mxlevel=0;
void bfs()
{



	for(ll i=1;i<=k;i++)
	{
		queue<ll>cq;

	for(auto x:level[i])
		cq.push(x);

	memset(vis,0,sizeof(vis));
	
	while(!cq.empty())
	{

		ll par=cq.front();
		cq.pop();

		vis[par]=1;

		for(auto child:v[par])
		{	
			
			if(!vis[child])
			{

				
				{	
					if(d[child][i]>(1+d[par][i]))
					{
					//	cout<<"child "<<child<<" and dis of "<<i<<" updated to ";
						d[child][i]=1+d[par][i];
					//	cout<<d[child][i]<<endl;
					}
				}
				

				cq.push(child);
			}
		}
	}
    }

}
int main()
{   
	fastIO

	for(ll i=0;i<M;i++)
		for(ll j=1;j<=100;j++)
			d[i][j]=INF;
	
    
    
    cin>>n>>m>>k>>s;

    for(ll i=1;i<=n;i++)
    	{
    		cin>>a[i];
    		d[i][a[i]]=0;
    		level[a[i]].push_back(i);
    	}

    for(ll i=0;i<m;i++)
    {
    	ll x,y;
    	cin>>x>>y;

    	v[x].pb(y);
    	v[y].pb(x);
    }

    bfs();

    ll ans=0;

    for(ll i=1;i<=n;i++)
    {
    	std::vector<ll> tm;

    	for(ll j=1;j<=k;j++)
    	{	
    		if(d[i][j]!=INF)
    		tm.push_back(d[i][j]);
    	}
    	sort(tm.begin(), tm.end());

    	ll sum=0;
    	for(ll a=0;a<s;a++)
    		{
    			//cout<<tm[k]<<" ";
    			sum+=tm[a];
    		}
    	//cout<<endl;
    	cout<<sum<<" ";//<<endl;
    	

    }
    



    return 0;
}