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








void solve()
{
	
	string s;
	cin>>s;
	ll d[s.size()+1]={0};

	for(ll i=s.size()-1;i>=0;i--)
	{
		if((s[i]-'0')&1)
			d[i]=d[i+1];
		else
			d[i]=1+d[i+1];

		
	}
	for(ll i=0;i<s.size();i++)
		cout<<d[i]<<" ";
	
	
}
int main()
{   
	solve();
    return 0;
}