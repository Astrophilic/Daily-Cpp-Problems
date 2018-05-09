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
 int a[n];
 ll left=0,right=n-1;
 ll ser=0,dim=0;

 for (int i = 0; i < n; ++i)
 {
   cin>>a[i];
 }
 ll k=0;

 while(left<=right)
 {
  
  ll ans=0;
  cout<<"pointer status left"<<left<<" right:"<<right<<endl;
  if(a[left]>=a[right])
    ans=a[left++];
  else 
    ans=a[right--];

  if(k%2)
    dim+=ans;
  else
    ser+=ans;

  k++;

 }
 cout<<ser<<" "<<dim;

return 0;
  
}
  
