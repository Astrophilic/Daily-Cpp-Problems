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


const ll M=1e7+7;

int main()
{   
	//fastIO
	
    {

    	ll f[110][110];

    	memset(f,0,sizeof(f));

    	f[1][0]=1;
    	f[1][1]=1;

    	for(ll n=2;n<110;n++)
    	{
    		f[n][0]=1;

    		for(ll r=1;r<=n;r++)
    		{
    			f[n][r]=f[n-1][r]+f[n-1][r-1];

    			if(f[n][r]>=M)
    				f[n][r]%=M;
    		}
    	}


    	ll n1,r1;
    	cin>>n1>>r1;

    	if(r1>n1)
    		cout<<-1<<endl;
    	else
    		cout<<f[n1-1][r1-1]<<"\n";



    }

    return 0;
}