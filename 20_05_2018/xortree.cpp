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


const ll M=1e5+100;

ll G[M];
ll IN[M];
ll cnt=0;
std::vector<ll>ans;
std::vector<ll>gr[M];

void dfs(ll s,ll p, ll ev, ll od, ll lvl)
{

	//cout<<"dfs with s="<<s<<endl;
	//cout<<"ev:"<<ev<<" od:"<<od<<" lvl"<<lvl<<endl;
	for(auto child:gr[s])
	{
		if(child!=p)
		{	

			//cout<<"status of child:"<<child<<" bef"<<IN[child]<<endl;

			if(lvl%2==0)
			{		
					ll f=0;
					IN[child]^=(ev%2);

				//	cout<<"status of child:"<<child<<" af"<<IN[child]<<endl;
					
					if(IN[child]!=G[child])
						{
							ans.push_back(child);
					//		cout<<"inserting child:"<<child<<endl;
					//		cout<<"increamenting ev"<<endl;
							f=1;

						}

					dfs(child,s,ev+f,od,lvl^1);
			

			}
			else
			{
				
				ll f=0;

				IN[child]^=(od%2);
				//cout<<"status of child:"<<child<<" af"<<IN[child]<<endl;

						if(IN[child]!=G[child])
						{
							f=1;

							ans.push_back(child);
					//		cout<<"inserting child:"<<child<<endl;
					//		cout<<"increamenting ev"<<endl;
						}

					dfs(child,s,ev,od+f,lvl^1);
			

			}
		}
	}
}


int main()
{   
	
	
    {
    	
    	ll n;
    	cin>>n;

    	for (int i = 0; i <n-1; ++i)
    	{
    		
    		ll u,v;
    		cin>>u>>v;
    		gr[u].pb(v);
    		gr[v].pb(u);


    	}
    	for (int i = 1; i <=n; ++i)
    	{
    		cin>>IN[i];

    	}

    	for (int i = 1; i <=n; ++i)
    	{
    		cin>>G[i];

    	}
    	
    	ll f=0;

    	if(G[1]!=IN[1])
    		{
    			ans.push_back(1);
    			f=1;
    		}

    	dfs(1,0,f,0,1);

    	cout<<ans.size()<<endl;

    	for(auto x:ans)
    		cout<<x<<"\n";

    }

    return 0;
}