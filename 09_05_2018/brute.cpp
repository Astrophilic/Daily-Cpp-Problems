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
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }


int main()
{ 

	int n;
	cin>>n;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ans=0;

	for (int i = 1; i <=n; ++i)
	{
		if(i%a==0||i%b==0||i%c==0||i%d==0)
			ans++;
	}
	cout<<ans<<'\n';
    return 0;
}