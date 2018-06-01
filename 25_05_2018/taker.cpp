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

ll k1,k2;
const ll M=1e8;

ll d[110][110][15][15];
ll f(ll n1,ll n2,ll onec,ll twoc)
{	

	//printf("f called with n1=%lld  n2=%lld onec=%lld twoc=%lld \n",n1,n2,onec,twoc );
	if(n1==0&&n2==0)
		{	
			//cout<<"correct arrangement \n";
			return 1;
		}

	if(d[n1][n2][onec][twoc]!=-1)
	return d[n1][n2][onec][twoc];

	ll val1=0;

	if(onec<k1&&n1>0)
		val1=f(n1-1,n2,onec+1,0);

	
	ll val2=0;

	if(twoc<k2&&n2>0)
		val2=f(n1,n2-1,0,twoc+1);

	//printf("f with n1=%lld  n2=%lld onec=%lld twoc=%lld  returning values\n",n1,n2,onec,twoc );
	//cout<<"val 1"<<val1<<endl;
	//cout<<"val2 "<<val2<<endl;

	ll ans=val1+val2;
	if(ans>=M)
		ans%=M;

	return d[n1][n2][onec][twoc]=ans;
}


int main()
{   
	fastIO
	t
    {

    	for(ll i=0;i<110;i++)
    		for(ll j=0;j<110;j++)
    			for(ll k=0;k<15;k++)
    				for(ll l=0;l<15;l++)
    					d[i][j][k][l]=-1;

    	ll n1,n2;
    	cin>>n1>>n2>>k1>>k2;

    	cout<<f(n1,n2,0,0)<<endl;
    }

    return 0;
}