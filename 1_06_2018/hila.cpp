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


string s;

ll d[6500][6500];

ll f(ll start,ll end)
{

	//cout<<"f with start:"<<start<<" end"<<end<<endl;

	if(start>end)
		return 0;


	if(d[start][end]!=-1)
		return d[start][end];

	if(s[start]==s[end])
		return d[start][end]=f(start+1,end-1);


	

	return d[start][end]=1+min(f(start,end-1),f(start+1,end));
}
int main()
{   
	//fastIO
	t
    {

    	for (int i = 0; i <6500; ++i)
    	{
    		
    		for (int j = 0; j <6500; ++j)
    		{
    			d[i][j]=-1;
    		}
    	}
    	cin>>s;

    	cout<<f(0,s.size()-1)<<endl;
    	

    }

    return 0;
}
