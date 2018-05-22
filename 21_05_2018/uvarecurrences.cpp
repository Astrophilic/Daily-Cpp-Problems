#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
//#define ll long long
#define ll unsigned long long
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


ll X[20];
ll G[20][20];
ll F[20][20];

ll d,n,m;

void multiply2()
{

	ll b[20][20];
	ll mul[20][20];


	for(ll i=0;i<d;i++)
		for(ll j=0;j<d;j++)
			b[i][j]=G[i][j];


	for(ll i=0;i<d;i++)
	{
		for(ll j=0;j<d;j++)
		{	mul[i][j]=0;

			for(ll k=0;k<d;k++)
			{
				mul[i][j]+=F[i][k]*b[k][j];

				if(mul[i][j]>=m)
					mul[i][j]%=m;

			}
		}
	}

	for(ll i=0;i<d;i++)
		for(ll j=0;j<d;j++)
			F[i][j]=mul[i][j];
}

void multiply()
{

	ll b[20][20];
	ll mul[20][20];


	for(ll i=0;i<d;i++)
		for(ll j=0;j<d;j++)
			b[i][j]=F[i][j];


	for(ll i=0;i<d;i++)
	{
		for(ll j=0;j<d;j++)
		{	mul[i][j]=0;

			for(ll k=0;k<d;k++)
			{
				mul[i][j]+=F[i][k]*b[k][j];

				if(mul[i][j]>=m)
					mul[i][j]%=m;

			}
		}
	}

	for(ll i=0;i<d;i++)
		for(ll j=0;j<d;j++)
			F[i][j]=mul[i][j];


}
void power(ll n)
{

	if(n==1)
		return;

	power(n/2);
	multiply();

	if(n%2)
		multiply2();

	return;


	
}
ll fun(ll n)
{
	if(n<=d)
		return X[n-1]%m;

	
	power(n-d);


	ll ans=0;

	for(ll i=0;i<d;i++)
	{
		ans+=X[d-i-1]*F[0][i];
		
		if(ans>=m)
			ans%=m;

	}
	return ans;
}
int main()
{   
	fastIO
	while(1)
    {
    	cin>>d>>n>>m;

    	if(d==n&&n==m&&d==0)
    		return 0;

    	memset(F,0,sizeof(F));
    	memset(G,0,sizeof(G));


    	for(ll i=0;i<d;i++)
    		cin>>F[0][i];

    	for(ll i=1;i<d;i++)
    		F[i][i-1]=1;

    	for(ll  i=0;i<d;i++)
    		for(ll j=0;j<d;j++)
    			G[i][j]=F[i][j];


    	for(ll i=0;i<d;i++)
    		cin>>X[i];

    	cout<<fun(n)<<"\n";



    }

    return 0;
}