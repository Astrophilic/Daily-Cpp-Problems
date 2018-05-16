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







int main()
{  

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    t
    {
    	

    	ll N;
    	cin>>N;
    

    	set< pair<ll,ll> >mset[N];


    	ll a[N+10];

    	const ll INF=1e15;

    	for(ll i=0;i<N+10;i++)
    			a[i]=INF;



    	for (int i = 1; i < N+1; ++i)
    	{
    		cin>>a[i];

    	}


    	
    	ll groups=-1;


    	set< pair<ll,ll> >used;



    	for (int i = 1; i < N+1; ++i)
    	{	

    		ll indflag=-1;

    		if( (a[i-1]-a[i])>0 && (a[i+1]-a[i])>0 )
    		{
                 indflag=1;

    			if( (a[i+1]-a[i+2])>0 && ( a[i+3]-a[i+2] )>0 )
    			{

    				
    				if((a[i+1]-a[i]-a[i+2])<=0)
    				{

    					indflag=0;

    					if(groups!=-1)
    					{
    						if( (mset[groups].find({a[i],i})!=mset[groups].end())||(mset[groups].find({a[i+2],i+2})!=mset[groups].end()))
    						{
    							mset[groups].insert({a[i],i});
    							mset[groups].insert({a[i+2],i+2});
    							
    						}
    						else
    						{
    							groups++;
    							mset[groups].insert({a[i],i});
    							mset[groups].insert({a[i+2],i+2});

    						}
    					}
    					else
    					{
    						groups=0;
    						mset[groups].insert({a[i],i});
    						mset[groups].insert({a[i+2],i+2});

    					}
    					
    					//cout<<"values insertted "<<a[i]<<"  "<<a[i+2]<<endl;
    						used.insert({a[i],i});
    						used.insert({a[i+2],i+2});

    				}

    			}
    			
    			if(indflag==1&&used.find({a[i],i})==used.end())
    				{
    					mset[++groups].insert({a[i],i});
    					//cout<<"values insertted "<<a[i]<<" in group "<<groups<<endl;
    					used.insert({a[i],i});
    				}
    			
    		}
    	}

    	set<ll>indices;
    	ll k=groups;

    	for(ll i=0;i<=k;i++)
    			{
    				
    				//cout<<"group no "<<i<<endl;
    				if(!mset[i].empty())
    				{	

    					std::vector< pair<ll,ll> > tmp;

    					int itr=0;
    					for(auto x:mset[i])
    						{
    							//cout<<x.ff<<" and ind "<<x.ss<<endl;
    							tmp.push_back({x.ss,x.ff});
    						}
    					sort(tmp.begin(),tmp.end());

    					ll d[mset[i].size()+20][2];
    					


    					memset(d,0,sizeof(d));

    					for (int j = tmp.size()-1; j>=0; --j)
    					{
    						d[j][0]=max(d[j+1][0],d[j+1][1]);

    						d[j][1]=tmp[j].ss +d[j+1][0];


    				//	cout<<d[j][0]<<" "<<d[j][1]<<endl;
    					}


    					ll here=max(d[0][0],d[0][1]);

    					for(int y=0;y<mset[i].size();y++)
    					{
    						if(d[y][1]==here)
    						{
    							here-=tmp[y].ss;
    						//	cout<<"use ho raha "<<tmp[y].ss<<endl;
    						//	cout<<"inser ho rha index"<<tmp[y].ff<<endl;
    							indices.insert(tmp[y].ff);
    						}
    					}

    					//cout<<'\n';	
    				}
    				
    			}
    		/*cout<<"indices to be negative\n";
    			for(auto it:indices)
    				cout<<it<<" ";
    			cout<<"\n";
                */
    			
    			for(int u=1;u<=N;u++)
    			{
    				if(indices.find(u)!=indices.end())
    					cout<<-a[u]<<" ";
    				else
    					cout<<a[u]<<" ";
    			}
    			cout<<"\n";


    }

    return 0;
}