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
  ll a,b;
  cin>>a>>b;
  ll ctr=0;

  while(a<=b)
  {
  a*=3;
  b*=2;
  ctr++;
  }
  cout<<ctr<<"\n";

    return 0;
  
}