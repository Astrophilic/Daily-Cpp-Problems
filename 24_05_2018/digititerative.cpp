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



ll d[10][70];


int main()
{   
	//fastIO
	



	for(ll i=0;i<=9;i++)
		d[i][1]=1;


	for(ll len=2;len<70;len++)
	{

		for(ll start=0;start<=9;start++)
		{

			for(ll subs=start;subs<=9;subs++)
			{
				d[start][len]+=d[subs][len-1];
			}
		}
	}

	t
    {
    	ll x;
    	cin>>x;
    	ll n;
    	cin>>n;
    	ll ans=0;
    	for(ll i=0;i<10;i++)
    		ans+=d[i][n];
    	cout<<x<<" "<<ans<<"\n";

    }

    return 0;
}