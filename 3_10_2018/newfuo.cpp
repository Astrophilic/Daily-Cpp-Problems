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







int get(char c)
{
	return int(c-'0');
}

int isnov(char c)
{
	if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		return 0;
	return 1;
}
void solve()
{
	
	string s;
	cin>>s;

	ll s1=get(s[0])+get(s[1]);

	ll s2=get(s[3])+get(s[4]);
	
	ll s3=get(s[4])+get(s[5]);

	ll s4=get(s[7])+get(s[8]);

	if(s1%2==0 && s2%2==0 && s3%2==0 && s4%2==0 && isnovow(s[2]))
	{
		cout<<"valid";
	}
	else
		cout<<"invalid";


	
}
int main()
{   
	solve();
    return 0;
}