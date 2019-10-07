#include <bits/stdc++.h>
#define ff first
#define D double
#define sz size()
#define pb push_back
#define mp make_pair
#define nl printf("\n")
#define ll long long
#define ull unsigned long LL
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define f(i,a,b) for(int i=a;i<b;i++)
#define r(i,a,b) for(int i=a;i>b;i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pul pair<ULL,ULL>
#define pll pair<LL,LL>
#define pii pair<int,int>
#define MX  500007
#define MOD 1000000007
#define INF 2000000000000000LL
#define EPS 1e-9
#define v vector
#define t int t; cin>>t; while(t--)
using namespace std;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }

const ll M=1e6+4;
map<ll,ll>ans[M];
ll fun(ll n,ll r)
{
    if(r==0||r==n)
        return ans[n][r]=1;

    if(ans[n].find(r)!=ans[n].end())
        return ans[n][r];

    return ans[n][r]=fun(n-1,r)+fun(n-1,r-1);
}
int main()
{   t
    {
    ll n,k;
    cin>>n>>k;

    cout<<fun(n-1,min(n-k+1,k-1))<<'\n';
    }

    return 0;
}
