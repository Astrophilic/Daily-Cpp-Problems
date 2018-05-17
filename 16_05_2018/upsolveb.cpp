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

	int n,k,remaining=0,flag=0;

	std::cin>>n>>k;

	char grid[5][n+1];


	 for (int i = 0; i <=4; ++i)
	 {
	 	for (int j = 0; j < n+1; ++j)
	 	{
	 		grid[i][j]='.';
	 	}
	 }

	if(k%2)
		remaining=1,k--;


	if(k%2==0)
	{
		for (int i = 2; i <=n/2 ; ++i)
		{
			if(k==0)
				break;

			grid[2][i]=grid[2][n-i+1]='#';
			k-=2;
		}
	}

	if(k%2==0)
	{
		for (int i = 2; i <=n/2 ; ++i)
		{
			if(k==0)
				break;

			grid[3][i]=grid[3][n-i+1]='#';
			k-=2;
		}
	}


	if(k%2==0&&k>0)
	{
		grid[2][n/2+1]=grid[3][n/2+1]='#';
		k-=2;

	}

	if(remaining)
		grid[2][n/2+1]='#';


	cout<<"YES\n";
	
	for (int i = 1; i <=4; ++i)
	{
		for (int j = 1; j < n+1; ++j)
		{
			cout<<grid[i][j];
		}
		cout<<"\n";
	}





    return 0;
}