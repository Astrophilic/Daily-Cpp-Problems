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

const ll M=1e5;
std::vector<ll> v[M];
ll cost[M];
ll d[M];
ll vis[M];

ll dfs(ll src,ll par)
{

    cout<<"dfs with src "<<src<<" par "<<par<<endl;
	if(d[src]!=-1)
		{
		    cout<<"returning dire"<<d[src]<<endl;
		    return d[src];
		}


	ll ans=0;
	ll an=0;
	ll an2=0;
	for(auto child:v[src])
	{

		if(child!=par)
			{
				an2+=dfs(child,src);


		for(auto grandchild:v[child])
		{
		    cout<<"f with src "<<src<<" par "<<par<<"child "<<child<<" "<<grandchild<<endl;
			if(child!=grandchild&&grandchild!=src)
			an+=dfs(grandchild,child);

		}
			}
	}

	return d[src]=max(cost[src]+an,an2);


}




int main()
{
	//fastIO

    {
    	memset(d,-1,sizeof d);
    	ll n;
    	cin>>n;

    	for (int i = 0; i < n-1; ++i)
    	{

    		ll x,y;
    		cin>>x>>y;
    		v[x].pb(y);
    		v[y].pb(x);

    	}

    	for (int i = 1; i <= n; ++i)
    	{

    		cin>>cost[i];
    	}

    	cout<<dfs(1,0)<<endl;

    	for (int i = 1; i <=n; ++i)
    	{
    		cout<<d[i]<<" ";
    		cout<<"\n"	;/* code */
    	}
    }

    return 0;
}
