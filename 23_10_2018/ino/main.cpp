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

    ll n,k;
    cin>>n>>k;
    ll a[n+1],d[n+1]={0},db[n+1]={0};



    for(ll i=1;i<=n;i++)
        cin>>a[i];

    d[k]=0;

    for(ll i=k+1;i<=n;i++)
        {
            d[i]=a[i]+max(d[i-1],d[i-2]);
        }

    db[1]=a[1];db[2]=a[1]+a[2];

    for(ll i=3;i<=n;i++)
        {
            db[i]=a[i]+max(db[i-1],db[i-2]);
        }

    ll ans=-1e18;

    for(ll i=k;i<=n;i++)
        ans=max(ans,d[i]+db[i]-a[i]);

    cout<<ans<<"\n";

    return 0;
}
