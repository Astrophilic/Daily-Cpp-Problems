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
    fastIO
    
    while(1)
    {

        ll w,n;
        cin>>w>>n;
        if(w==n&&n==0)
            break;
        ll fee[n+1]={0};
        ll fun[n+1]={0};

        std::vector< pair<ll,ll> > v;

        for(ll i=0;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        sort(all(v));

        for(ll i=1;i<=n;i++)
            {
                fee[i]=v[i-1].ff;
                fun[i]=v[i-1].ss;
            }

        ll d[n+10][w+10];

        for(ll i=0;i<n+10;i++)
            for(ll j=0;j<w+10;j++)
                d[i][j]=0;

        
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=w;j++)
            {
                if(fee[i]<=j)
                    d[i][j]=max(fun[i]+d[i-1][j-fee[i]],d[i-1][j]);
                else
                    d[i][j]=d[i-1][j];

               // cout<<d[i][j]<<" ";

            }
          //  cout<<"\n";

        }

        ll i=n,j=w;
        std::vector<ll>ans;
        /*while(i>0&&j>0)
        {   
            //cout<<"i "<<i<<" j"<<j<<endl;
            if(d[i][j]==d[i-1][j])
                i--;
           else if(d[i][j]==fun[i]+d[i-1][j-fee[i]])
            {   
              //  cout<<"into ans index "<<i<<" fee"<<fee[i]<<endl;
                ans.push_back(fee[i]);
                
                j-=fee[i];
                i--;
            }
            
        }
        */
        ll minmoney=0;
        for(ll i=0;i<=w;i++)
        {
            if(d[n][i]==d[n][w])
            {
                minmoney=i;
                break;
            }
        }

        

        cout<<minmoney<<" "<<d[n][w]<<endl;
    }

    return 0;
}
/*
5
3
1 2
2 3
5 5
*/