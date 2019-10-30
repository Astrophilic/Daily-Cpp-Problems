#include <bits/stdc++.h>
#define ff first
#define ss second
#define D double
#define sz size()
#define pb push_back
#define mp make_pair
#define nl printf("\n")
#define ll long long
#define ull unsigned long LL
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define f(i,a,b) for(int i=a;i<b;i++)
#define r(i,a,b) for(int i=a;i>b;i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pul pair<ULL,ULL>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define MX  500007
#define MOD 1000000007
#define INF 2000000000000000LL
#define EPS 1e-9
#define v vector
//#define t int t; cin>>t; while(t--)


using namespace std;

int main()
{
    string s;
    string p;
    cin>>s>>p;

    string n="";
    n+=s;
    n+='*';
    n+=p;

    ll pi[n.size()]={0};

    for(ll i=1;i<n.size();i++)
    {
        ll j=pi[i-1];
        while(j>0&&n[i]!=n[j])
            j=pi[j-1];

        if(n[i]==n[j])
            pi[i]=j+1;
        cout<<pi[i]<<" ";
        if(pi[i]==s.size())
        {
            cout<<"starting at index "<<" "<<i-2*s.size()<<" "<<p[i-2*s.size()]<<'\n';
        }
    }
    return 0;
}
