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
#define t int t; cin>>t; while(t--)
using namespace std;

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
using namespace std;

const ll M=5005;

int isPalin[M][M];
int countPalinSubstrings[M][M];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);cin.tie(nullptr);
    string s;
    cin>>s;

    ll n=s.size();

    for(ll len=1;len<=n;len++)
    {
        for(ll j=0;j<=n-len;j++)
        {
            if(len==1)
                {
                    isPalin[j][j]=1;
                    countPalinSubstrings[j][j]=1;
                }
            else if(len==2)
            {
                //cout<<s[j]<<" "<<s[j+1]<<'\n';
                isPalin[j][j+1]=(s[j]==s[j+1]?1:0);
               // cout<<isPalin[j][j+1]<<'\n';

                if(isPalin[j][j+1])
                    countPalinSubstrings[j][j+1]=3;
                    else
                        countPalinSubstrings[j][j+1]=2;
            }
            else
            {
                isPalin[j][j+len-1]=( s[j]==s[j+len-1]?1:0)&isPalin[j+1][j+len-2];

                countPalinSubstrings[j][j+len-1]=countPalinSubstrings[j][j+len-2]+countPalinSubstrings[j+1][j+len-1]-countPalinSubstrings[j+1][j+len-2] + isPalin[j][j+len-1];
            }
        }
    }
//        for(ll i=0;i<n;i++)
//            {for(ll j=0;j<n;j++)
//            cout<<isPalin[i][j]<<" ";
//        cout<<'\n';}
        ll q;
        cin>>q;
        while(q--)
        {
            ll x,y;
            cin>>x>>y;
            x--;y--;
            cout<<countPalinSubstrings[x][y]<<'\n';
        }

    return 0;
}
