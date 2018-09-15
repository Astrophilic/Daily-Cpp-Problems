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


ll f(int A,int B,int C)
{	
	if(A<0||B<0||C<0)
		return 0;

	if(A==0 && B==0)
		return 1;

	if(B==0 && C==0)
		return 1;

	if(C==0 && A==0)
		return 1;


	return (A>0 ?f(A-1,B,C):0)+(B>0 ?f(A,B-1,C):0) +(C>0 ?f(A,B,C-1):0);
}

int main()
{   
	//fastIO
	t
    {
    	ll a,b,c;
    	cin>>a>>b>>c;

    	cout<<f(a,b,c)<<endl;
    }

    return 0;
}