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

ll L[1010],B[1010],d[1010][2];


ll f(ll i,ll oreo)
{

	if(i==0)
	{
		if(oreo==0)
			return d[0][0]=B[0];
		else
			return d[0][1]=L[1];

	}

	if(d[i][oreo]!=-1)
		return d[i][oreo];


	if(oreo==0)
	{
		return d[i][0]=B[i]+max( fabs(L[i]-L[i-1])+f(i-1,0), fabs(L[i]-B[i-1])+ f(i-1,1));
	}

	return d[i][1]=L[i]+ max( fabs(B[i]-L[i-1])+f(i-1,0), fabs(B[i]-B[i-1]) +f(i-1,1));
}


int main()
{   
	fastIO
	
    {
    ll n;
    cin>>n;
    
    memset(d,-1,sizeof(d));
    

    for(ll i=0;i<n;i++)
    	cin>>L[i]>>B[i];

    
    cout<<max(f(n-1,0),f(n-1,1))<<endl;

    }

    return 0;
}