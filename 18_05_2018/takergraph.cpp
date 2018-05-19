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
	int value;
	int depth=0;
	int x,y;

};
const ll M=1010;
ll n,m;
node graph[M][M];

ll vis[M][M];


void bfs(ll sx,ll sy)
{
	memset(vis,0,sizeof(vis));

	vis[sx][sy]=1;

	
	cout<<"bfs with x:"<<sx<<" y:"<<sy<<"\n";

	queue<node>pq;

	pq.push(graph[sx][sy]);

	if(pq.empty())
		cout<<"fuck";
	while(!pq.empty())
	{

		node u=pq.front();
		pq.pop();

		int level=u.depth;

		if(level==0)
			{
				cout<<"return hoche\n";
				return;
			}

		vis[u.x][u.y]=1;

		for (int i = -1; i <=1; ++i)
		{
			for (int j = -1; j <=-1; ++j)
			{
				if(fabs(i)+fabs(j)==2)
					continue;

				ll nx=u.x+i;
				ll ny=u.y+j;

				cout<<"testing nx:"<<nx<<" ny:"<<ny<<endl;
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&graph[nx][ny].value!=-1&&!vis[nx][ny])
				{
					if(graph[nx][ny].depth<=level-1)
					{

						cout<<"updating depth of grid["<<nx<<"]["<<ny<<"]="<<level-1<<endl;
						graph[nx][ny].depth=level-1;

						node nw;
						nw.x=nx;
						nw.y=ny;
						nw.depth=level-1;
						nw.value=level-1;
						pq.push(nw);
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

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			cin>>graph[i][j].value;
    			if(graph[i][j].value>0)
    				graph[i][j].depth=graph[i][j].value;
    			graph[i][j].x=i;
    			graph[i][j].y=j;


    		}
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		
    		for (int j = 0; j < m; ++j)
    		{
    			if(graph[i][j].value>=graph[i][j].depth&&graph[i][j].value)
    			{
    				bfs(i,j);
    			}
    		}
    	}
    	string s[n];

    	for (int i = 0; i < n; ++i)
    	{
    		
    		for (int j = 0; j < m; ++j)
    		{
    			
    			if(graph[i][j].value==-1)
    				s[i]+='B';
    			else if(graph[i][j].depth==0)
    				s[i]+='N';
    			else if(graph[i][j].depth>0)
    				s[i]+='Y';


    		}
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		
    		cout<<s[i]<<"\n";
    	}

    }

    return 0;
}