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


const ll M=2e6+10;

ll ar[M];

void init(ll x)
{
    for(ll i=0;i<=x;i++)
        ar[i]=i;

}
ll root(ll x)
{
    while(x!=ar[x])
    {
        ar[x]=ar[ar[x]];
        x=ar[x];

    }
    return x;
}
ll unio(ll x,ll y)
{
    ll rx=root(x);
    ll ry=root(y);

    if(rx==ry)
        return 0;
    ar[rx]=ry;

    return 1;

}
int main()
{   
    
    ll m,n;
    while(1)
    {
        cin>>m>>n;
        if(m==n && n==0)
            return 0;
        init(m);

        std::vector< pair<ll, pair<ll,ll> >  > v;
        ll total=0;

        for(ll i=0;i<n;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            v.push_back({z,{x,y}});
            total+=z;

        }

        sort(all(v));
        ll ans=0;

        for(ll i=0;i<n;i++)
        {
            auto u=v[i];
            ll w=u.ff;
            ll x=u.ss.ff;
            ll y=u.ss.ss;
            if(unio(x,y))
                {
                    cout<<"selecting "<<x<<" and "<<y<<"amd wt "<<w<<endl;
                    ans+=w;
                }


        }
        cout<<total-ans<<"\n";

    }

    return 0;
}