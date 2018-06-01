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

    std::vector<ll> agn;

    ll x;
    cin>>x;
    if(x==0)
    	continue;
    else
    {
    	agn.push_back(x);
    	while(1)
    	{
    		cin>>x;
    		if(x==0)
    			break;
    		agn.push_back(x);
    	}
    }
    ll ans=0;

  	while(1)
  	{
  		cin>>x;
  		if(x==0)
  			break;
  		std::vector<ll> tm;
  		tm.push_back(x);

  		while(1)
  		{
  			cin>>x;
  			if(x==0)
  				break;
  			tm.push_back(x);
  		}

  		
  		ll d[agn.size()+5][tm.size()+1];

  		memset(d,0,sizeof(d));

  		ll m=agn.size();
  		ll n=tm.size();

  		for(ll i=1;i<=m;i++)
  		{

  			for(ll j=1;j<=n;j++)
  			{

  				if(agn[i-1]==tm[j-1])
  					d[i][j]=1+d[i-1][j-1];
  				else
  					d[i][j]=max(d[i-1][j],d[i][j-1]);
  			}
  		}
  	//	cout<<"lcs "<<d[m][n]<<endl;
  		ans=max(ans,d[m][n]);


  	}
  	cout<<ans<<"\n";
    }

    return 0;
}