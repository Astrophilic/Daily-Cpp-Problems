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
  ll a[n];

  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }

  for (int i = n-1; i>=1 ; --i)
  {
    ll start=a[i];


    for(ll j=i-1;j>=0;j--)
    {


    ll diff=a[j]-a[i];

    if(diff>0)
    {
      a[j]-=diff;
      a[i]+=diff;
    }
    }


  }
  for(ll i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<'\n';


return 0;
  
}
  
