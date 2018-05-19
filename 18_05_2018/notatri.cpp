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
#define ld double
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   
	ios::sync_with_stdio(0);
	//cin.tie(NULL);
	//cout.tie(NULL);
	while(1)
    {

    int n;
    cin>>n;
    if(!n)
    	break;

    vector <ll> L(n,0);


    for (int i = 0; i < n; ++i)
    {
    	cin>>L[i];
    }
    sort(all(L));
    int ans=0;

    for (int i = 0; i < n; ++i)
    {
    	
    	for (int j = i+1; j < n; ++j)
    	{
    		int sum=L[i]+L[j];

    		auto dis=upper_bound(all(L),sum)-L.begin();

    		dis=n-dis;

    		ans+=dis;
    		if(dis==0)
    			break;
    		
    	}
    }
    cout<<ans<<"\n";




    }
    return 0;
}