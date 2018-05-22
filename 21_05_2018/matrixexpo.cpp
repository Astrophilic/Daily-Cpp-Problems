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

ll M;

ll A[2][2]={{1,1},{1,0}};


void multiply(ll a[2][2],ll b[2][2])
{

	ll mul[2][2];

	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<2;j++)
		{
			mul[i][j]=0;

			for(ll k=0;k<2;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];

				if(mul[i][j]>=M)
					mul[i][j]%=M;
			}
		}
	}

	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
			a[i][j]=mul[i][j];

}

ll power(ll F[2][2],ll n)
{	
	if(n==0||n==1)
		return F[0][0]%M;

	power(F,n/2);
	multiply(F,F);

	if(n%2)
		multiply(F,A);
	return F[0][0]%M;
}

ll fib(ll n)
{
	ll F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;

	return power(F,n-1);
}


int main()
{   
	
	ll n,m;

	while(scanf("%ld %ld",&n,&m) == 2)
	{
	
	
	M=1LL<<m;

	
	cout<<fib(n)<<endl;
	}

    return 0;
}