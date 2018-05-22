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

const ll M=500010;



int main()
{   
	
    ll p[M];
    for(int i=1;i<M;i++)
    	p[i]=1;



    for (int i = 2; i*i <= M; ++i)
    {
    	
    	for (int j = i+1; i*j <=M; ++j)
    	{
    			

    		if(__gcd(i,j)==1)
    		{	
    			//cout<<" co prime "<<i<<" "<<j<<endl;
    			for (int k = i*j; k < M; k+=(i*j))
    			{
    				p[k]++;
    			}
    		}
    	}
    }
    ll q;
    cin>>q;
    while(q--)
    {
    	ll n;
    	cin>>n;
    	if(n==1)
    		cout<<n<<endl;
    	else
    	cout<<2*p[n]<<endl;
    }

    return 0;
}