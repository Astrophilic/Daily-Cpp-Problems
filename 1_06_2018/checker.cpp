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


std::vector<ll> v;

ll dp[100][100];
const ll inf=1e17;

ll f(ll ind,ll k)
{
	
    if(k!=0&&ind>=v.size())
        return -inf;
    
    if(k==0||ind>=v.size())
		return 0;




	if(dp[ind][k]!=-1)
		return dp[ind][k];


	return dp[ind][k]=max(v[ind]+f(ind+1,k-1),f(ind+1,k));


}

int main()
{   
	fastIO
	t
    {
    	memset(dp,-1,sizeof(dp));
    	v.clear();

    	ll n;
    	cin>>n;
    	ll k;
    	while(n--)
    	{
    		ll x;
    		cin>>x;
    		v.push_back(x);
    	}
    	cout<<"k"<<endl;
    	cin>>k;

    	cout<<f(0,k)<<endl;
    }

    return 0;
}