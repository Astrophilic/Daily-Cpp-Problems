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
  string s;
  cin>>s;
  int ant=0,dani=0;
  for(int i=0;i<s.size();i++)
    if(s[i]=='A')
      ant++;
    else
      dani++;

    if(ant==dani)
      cout<<"Friendship\n";
    else if(ant>dani)
      cout<<"Anton\n";
    else
      cout<<"Danik\n";
    return 0;
}