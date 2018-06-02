#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
//#define mp make_pair
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


map<ll,ll>mp;

ll f(ll coins)
{
	if(coins<12)
		return mp[coins]=coins;


	if(mp.find(coins)!=mp.end())
		return mp[coins];

	return mp[coins]=max(coins,f(coins/2)+f(coins/3)+f(coins/4));
}

int main()
{   
	//fastIO
	
    
    ll n;
    while(cin>>n)
    {

    cout<<f(n)<<endl;	
    }

    return 0;
    
}