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



struct node
{
	ll value;
	ll cur;
	ll ex;
	ll ans;

};

const ll M=2e5+100;

node d[M];

std::vector<ll> v[M];


void dfs(ll s,ll parent)
{

	for(auto child:v[s])
	{
		if(child!=parent)
		{
			d[child].cur=__gcd(d[child].value,d[s].cur);

			d[child].ex=d[s].cur;

			d[child].ans=max(d[child].cur,max( d[child].ex ,__gcd(d[child].value,d[s].ex)));

			//cout<<"values for child:"<<child<<endl;
			//cout<<"cur :"<<d[child].cur<<" ex:"<<d[child].ex<<" ans:"<<d[child].ans<<endl;
			dfs(child,s);
		}
	}
}
int main()
{   
	fastIO
	
    {
    	ll n;
    	cin>>n;
    	for(ll i=1;i<=n;i++)
    	{
    		cin>>d[i].value;
    	}
    	for(ll i=1;i<n;i++)
    	{
    		ll x,y;
    		cin>>x>>y;

    		v[x].pb(y);
    		v[y].pb(x);

    	}
    	d[0].ex=1;
    	d[0].cur=d[1].value;
    	d[0].ans=1;

    	d[1].ans=d[1].value;
    	d[1].ex=1;
    	d[1].cur=d[1].value;


    	dfs(1,0);

    	for (int i = 1; i <=n; ++i)
    	{
    		cout<<d[i].ans<<"\n";
    	}


    }

    return 0;
}