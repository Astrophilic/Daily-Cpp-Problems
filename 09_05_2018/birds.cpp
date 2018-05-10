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
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }


int main()
{   

  
  ll n;
  cin>>n;

  ll a[n+2];
  a[0]=0;
  a[n+1]=0;

  for(ll i=1;i<=n;i++)
  {
    cin>>a[i];
  }

  ll m;
  cin>>m;
  while(m--)
  {
    ll x,y;
    cin>>x>>y;
    
    a[x-1]+=y-1;
    a[x+1]+=a[x]-y;
    a[x]=0;

  }
  for(ll i=1;i<=n;i++)
    cout<<a[i]<<'\n';

    return 0;
}