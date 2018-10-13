
/*code by hazra*/

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define pul pair<ull,ull>
#define pl pair<ll,ll>
#define all(c) c.begin(), c.end()
#define present(c,x) ((c).find(x) != (c).end())

using namespace std;



#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


ll w,h;



void bfs()
{
	char  grid[w][h],d[w][h];
	
	ll vis[w][h][2];


	ll sx,sy,dx,dy;

	sx=sy=dx=dy=-1;

	for(ll i=0;i<h;i++)
		for(ll j=0;j<w;j++)
			cin>>grid[i][j],d[i][j]='#';


	for(ll i=0;i<h;i++)
		for(ll j=0;j<w;j++)
		{
			if(grid[i][j]=='C')
			{
				if(sx==sy && sx==-1)
				{
					sx=i;
					sy=j;
				}
				else
				{
					dx=i;
					dy=j;
				}
			}
		}



	queue< pl >cq;

	cq.push({sx,sy});
	d[sx][sx]='@';
	d[dx][dy]='@';

	vis[sx][sy][1]=0;
	while(!cq.empty())
	{

		auto x=cq.front();
		cq.pop();

		char dire=d[x.ff][x.ss];

		vis[x.ff][x.ss][0]=1;


		for(ll i=-1;i<=1;i++)
		{
			for(ll j=-1;j<=1;j++)
			{
				if(fabs(i)+fabs(j)==2)
					continue;

				if(i==0 && j==0)
					continue;

				ll nx=x.ff+i;
				ll ny=x.ss+j;

				if(nx>=0 && nx<h && ny>=0 && ny<w && !vis[nx][ny])
				{
						if(nx-x.ff==0)
						{
							if(d[x.ff][x.ss]=='h')
							{
								d[nx][ny]='h';
								vis[nx][ny][1]=vis[x.ff][x.ss][1];

							}
							else if(d[x.ff][x.ss]=='nh')
							{
								
							}
						}
				}
			}
		}
	}

}



void solve()
{
	cin>>w>>h;
	bfs();

}
int main()
{   
	solve();
    return 0;
}