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

int m,n;

char gr[100][100],vis[100][100];

std::vector<string> v;

int isvalid(int x,int y)
{
	if(x>=0&&x<m&&y>=0&&y<n)
		return 1;
	return 0;
}

char path[]="IEHOVA#";

char dfs(int x,int y,int p)
{
	vis[x][y]=1;


	//cout<<"dfs with (x,y)"<<x<<":"<<y<<endl;

	if(gr[x][y]=='#')
		return gr[x][y];

	if(p>6)
		return '1';


	
	if(isvalid(x,y-1)&&gr[x][y-1]==path[p]&&!vis[x][y-1])
	{	

		//cout<<gr[x][y-1]<<" "<<path[p]<<endl;
		if(dfs(x,y-1,p+1)=='#')
		{

		v.push_back("left");
		return '#';
		}
	}
	if(isvalid(x,y+1)&&gr[x][y+1]==path[p]&&!vis[x][y+1])
	{

		//cout<<gr[x][y+1]<<" "<<path[p]<<endl;
		if(dfs(x,y+1,p+1)=='#')
		{

		v.push_back("right");
		return '#';
		}
	}
	if(isvalid(x+1,y)&&gr[x+1][y]==path[p]&&!vis[x+1][y])
	{

		//cout<<gr[x+1][y]<<" "<<path[p]<<endl;
		if(dfs(x+1,y,p+1)=='#')
		{

		v.push_back("forth");
		return '#';
		}
	}	

	return '1';

}

int main()
{   t
    {

    	v.clear();
    	cin>>m>>n;
    	int x,y;

    	for (int i = m-1; i >=0; --i)
    	{
    		for (int j = 0; j<n; ++j)
    		{
    			cin>>gr[i][j];
    			vis[i][j]=0;
    			if(gr[i][j]=='@')
    			{
    				x=i;
    				y=j;

    			}
    		}
    	}
    	if(dfs(x,y,0)=='#')
    	{
    		for (int i = v.size()-1; i >0; --i)
    		{
    			cout<<v[i]<<" ";
    		}
    		cout<<v[0];
    	}
    	cout<<"\n";
    	
    }

    return 0;
}