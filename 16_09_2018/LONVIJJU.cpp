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

const ll M=150;

std::vector<ll> v[M];
ll w[M];
const ll INF=1e15;

ll d[M][M];


ll fun(ll src,ll k)
{

    if(k==0)
        return 0;

    if(d[src][k]!=-INF)
        return d[src][k];


    if(v[src].size()==0)
    {
        if(k==1)
            return d[src][k]=w[src];

        return d[src][k]=-INF+1;
    }
    
    

    if(v[src].size()==1)
    {
        return d[src][k]=w[src]+fun(v[src][0],k-1);
    }

    ll mx=-INF;
    if(v[src].size()==2)
    {
        for (int i = 0; i < k; ++i)
        {   
            ll val1=fun(v[src][0],i);
            if(val1<0)
                continue;
            ll val2=fun(v[src][1],k-i-1);

            mx=max(mx,val1+val2);
        }

        return d[src][k]=w[src]+mx;
    }

    if(v[src].size()==3)
    {
        ll mx=-INF;
        for (int i = 0; i < k; ++i)
        {
            ll val=fun(v[src][0],i);

            ll in=k-i-1;

            if(val<0)
                continue;

            for (int j = 0; j <=in; ++j)
            {

                ll val1=fun(v[src][1],j);
                if(val1<0)
                    continue;
                ll val2=fun(v[src][2],in-j);
            mx=max(mx,val+val1+val2);    
            }
        }
        return d[src][k]=w[src]+mx;
    }


}
int main()
{   
    fastIO
    t
    {   
        
        for(ll i=0;i<M;i++)
        v[i].clear();

        for(ll i=0;i<M;i++)
            for(ll j=0;j<M;j++)
                d[i][j]=-INF;

        for(ll i=0;i<M;i++)
            d[i][0]=0;
        ll n;
        cin>>n;
      
        for (int i = 1; i <=n; ++i)
        {
            cin>>w[i];

        }

        for (int i = 2; i <=n; ++i)
        {
            ll x;
            cin>>x;
            v[x].push_back(i);

        }       


        for (int i = 1; i <=n; ++i)
        {
            cout<<fun(1,i)<<" ";
        }
        cout<<"\n";

     }

    return 0;
}