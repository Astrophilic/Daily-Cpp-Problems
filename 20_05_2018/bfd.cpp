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

const ll M=1010;

struct node
{
	ll x;
	ll y;
	ll value;
	ll depth=0;
	ll valid=0;
	ll vis=0;




};
node grid[M][M];

ll n,m;

priority_queue< pair< ll, pair<ll,ll> > >cq;


void bfs()
{
	

	if(!cq.empty())
	{

	

	
	
	//cout<<"bfs with x:"<<x<<" y:"<<y<<endl;

	
	


	while(!cq.empty())
	{

		auto  var=cq.top();
		node u;
		u.depth=var.ff;
		u.x=var.ss.ff;
		u.y=var.ss.ss;

		cq.pop();

		if(grid[u.x][u.y].vis)
			continue;


		grid[u.x][u.y].vis=1;
		grid[u.x][u.y].valid=1;

		
	

		

	//	cout<<"node u x:"<<u.x<<" y:"<<u.y<<" and depth:"<<u.depth<<endl;

	
		for (int i = -1; i <=1; ++i)
		{
			
			for (int j = -1; j <=1; ++j)
			{
				if(fabs(i)+fabs(j)==2)
					continue;

				ll nx=u.x+i;
				ll ny=u.y+j;
				

				
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny].value!=-1&&grid[nx][ny].vis==0)
				{

					

					if(grid[nx][ny].depth<u.depth-1)
					{	
						//cout<<" into que grid["<<nx<<"]["<<ny<<"]="<<u.depth-1<<"\n";

						grid[nx][ny].depth=u.depth-1;
						grid[nx][ny].valid=1;
						cq.push({u.depth-1,{nx,ny}});
						
						


					}
					else 
					if(grid[nx][ny].depth==0&&u.depth-1==0)
					{
						
						//cout<<" into grid["<<nx<<"]["<<ny<<"]="<<grid[nx][ny].value<<"\n";
						grid[nx][ny].valid=1;
						
						

						//cq.push(grid[nx][ny]);

					}
					
				}
					

				}
			}
		
	}

	}
}

int main()
{   
	fastIO
	t
    {
    	cin>>n>>m;

    	for(ll i=0;i<n;i++)
    		for(ll j=0;j<m;j++)
    		{
    			grid[i][j].valid=0;
    			grid[i][j].depth=0;
    			grid[i][j].vis=0;
    		}

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			
    		
    		ll x;
    		cin>>x;
    		grid[i][j].value=x;
    		grid[i][j].x=i;
    		grid[i][j].y=j;

    		if(x>0)
    		{
    			grid[i][j].depth=x;
    			cq.push({x,{i,j}});
    		}
    		}
    	}
    	


    	
    	bfs();

    	char ans[M][M];

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<m;j++)
    		{
    			if(grid[i][j].valid)
    				ans[i][j]='Y';
    			else if(grid[i][j].value==-1)
    				ans[i][j]='B';
    			else
    				ans[i][j]='N';

    			cout<<ans[i][j];



    		}
    		cout<<"\n";
    	}




     }

    return 0;
}