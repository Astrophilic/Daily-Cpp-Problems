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

  
  int n;
  cin>>n;
  int a,b,c,e;
  cin>>a>>b>>c>>e;
  int ans=0;


  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      for (int k = 0; k < 2; ++k)
      {
        
        for (int l = 0; l < 2; ++l)
        {
          
            int sign;
            int d=1;
            int ele=0;
            std::vector<int> v;

            if(i)
            {
              ele++;
              v.push_back(a);
            }

            if(j)
            {
              ele++;
              v.push_back(b);
            }
            if(k)
            {
              ele++;
              v.push_back(c);
            }
            if(l)
            {
              ele++;
              v.push_back(e);
            }

            if(v.empty())
              continue;
            if(v.size()==1)
              d=v[0];
            else
            {
              d=v[0];

              for(int i=1;i<v.size();i++)
              {
                d=(d*v[i])/__gcd(d,v[i]);
              }
            }



            if(ele%2)
              sign=1;
            else
              sign=-1;

            ans+=sign*n/d;



        }
      }
    }
  }
  cout<<ans<<"\n";

    return 0;
}