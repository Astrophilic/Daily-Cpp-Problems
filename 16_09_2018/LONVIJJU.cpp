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


    if(d[src][k]>0)
        return d[src][k];

    if(k==1)
        return d[src][1]=w[src];


    ll c1,c2,c3;
    c1=c2=c3=110;

    ll leaf=1;

    for(auto child:v[src])
    {   
        if(c1==110)
            c1=child;
        else if(c2==110)
            c2=child;
        else if(c3==110)
                c3=child;

        leaf=0;

        for(ll i=1;i<=k-1;i++){
            d[child][i]=fun(child,i);
           // cout<<"fun with src "<<src<<" and k "<<k<<endl;
           // cout<<"d["<<child<<"]["<<i<<"]="<<d[child][i]<<endl;
        }
    }


    if(leaf)
        return d[src][k]=-INF;

    ll mx=-INF;


    for(ll i=0;i<k;i++)
        for(ll j=0;j<k;j++)
        {
            
            {   
                if(i==j&&i==0)
                    continue;
                if(i+j==k-1)
                {   
                  //  cout<<"d["<<c1<<"]["<<i<<"]="<<d[c1][i]<<endl;
                  //  cout<<"d["<<c2<<"]["<<j<<"]="<<d[c2][j]<<endl;
                  //  cout<<"d["<<c3<<"]["<<l<<"]="<<d[c3][l]<<endl;
                    
                    mx=max(mx,d[c1][i]+d[c2][j]);
                 //   cout<<"mx "<<mx<<endl;
                }
            }
        }


     d[src][k]=w[src]+mx;

   //  cout<<"d["<<src<<"]["<<k<<"]="<<d[src][k]<<endl;

     return d[src][k];


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


        for(ll i=1;i<=n;i++)
            cout<<fun(1,i)<<" ";
        
        cout<<"\n";

     }

    return 0;
}