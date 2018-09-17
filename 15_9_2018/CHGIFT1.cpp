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



int main()
{   
    //fastIO
    t
    {
        ll n;
        cin>>n;

        ll a[n];

        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }

        ll d[n][2];
        
        memset(d,0,sizeof(d));

        
        d[0][0]=d[0][1]=a[0];


        for (int i = 1; i < n; ++i)
        {
            d[i][0]=min(a[i]+d[i-1][0],min(d[i-1][0]-a[i],d[i-1][0]*a[i]));

            d[i][0]=min(d[i][0],d[i-1][1]*a[i]);

            d[i][1]=max(d[i-1][1]+a[i],max(d[i-1][1]-a[i],max(d[i-1][1]*a[i],d[i-1][0]*a[i])));

           


        }

        ll ans=d[n-1][0];

        cout<<ans<<"\n";
    }

    return 0;
}