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

string a;
string b;

ll d[2010][2010];

ll f(ll length_a, ll length_b)
{
	if(length_a==0)
		return length_b;

	if(length_b==0)
		return length_a;

	if(d[length_a][length_b]!=-1)
		return d[length_a][length_b];

	if(a[length_a-1]==b[length_b-1])
		return d[length_a][length_b]=f(length_a-1,length_b-1);

	return d[length_a][length_b]=1+min(f(length_a,length_b-1),min( f(length_a-1,length_b),f(length_a-1,length_b-1)) );


}
int main()
{   
	//fastIO
	t
    {

    	for(ll i=0;i<2010;i++)
    		for(ll j=0;j<2010;j++)
    			d[i][j]=-1;

    	cin>>a>>b;

    	cout<<f(a.size(),b.size())<<endl;
    }

    return 0;
}