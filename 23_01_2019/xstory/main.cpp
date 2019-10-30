#include <bits/stdc++.h>
#define ff first
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
#define ss second
#define t int t; cin>>t; while(t--)
using namespace std;
string as,bs;
const ll M=1e6;
ll a[M],b[M];

ll p[3]={0,31,37};
ll m[3]={0,(ll)1e9+7,(ll)1e9+9};
ll ind;
struct HASH{
  size_t operator()(const pair<long long,long long>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
bool check(ll len)
{
    pll hashval;
    pll powp;
    powp={1,1};
    hashval={0,0};

    unordered_set< pll,HASH>parentset;

    for(ll i=len-1;i>=0;i--)
    {
        hashval.ff=(hashval.ff+a[i]*powp.ff)%m[1];
        hashval.ss=(hashval.ss+a[i]*powp.ss)%m[2];

        if(i>0)
        {
            powp.ff=(powp.ff*p[1])%m[1];
            powp.ss=(powp.ss*p[2])%m[2];
        }
    }
    parentset.insert(hashval);

    pll hashval1={0,0};
    pll powp1={1,1};

    for(ll i=len-1;i>=0;i--)
    {
        hashval1.ff=(hashval1.ff+b[i]*powp1.ff)%m[1];
        hashval1.ss=(hashval1.ss+b[i]*powp1.ss)%m[2];

        if(i>0)
        {
            powp1.ff=(powp1.ff*p[1])%m[1];
            powp1.ss=(powp1.ss*p[2])%m[2];
        }
    }
    if(parentset.find(hashval1)!=parentset.end())
    {
        ind=0;
        return true;
    }

    for(ll i=len;i<as.size();i++)
    {
        ll last=(a[i-len]*powp.ff)%m[1];

        hashval.ff=(((hashval.ff-last+m[1])%m[1])*p[1])%m[1];
        hashval.ff=(hashval.ff+a[i])%m[1];

        last=(a[i-len]*powp.ss)%m[2];

        hashval.ss=(((hashval.ss-last+m[2])%m[2])*p[2])%m[2];
        hashval.ss=(hashval.ss+a[i])%m[2];

        parentset.insert(hashval);
    }


    if(parentset.find(hashval1)!=parentset.end())
    {
        ind=0;
        return true;
    }

    for(ll i=len;i<bs.size();i++)
    {
        ll last=(b[i-len]*powp1.ff)%m[1];

        hashval1.ff=(((hashval1.ff-last+m[1])%m[1])*p[1])%m[1];
        hashval1.ff=(hashval1.ff+b[i])%m[1];

        last=(b[i-len]*powp1.ss)%m[2];

        hashval1.ss=(((hashval1.ss-last+m[2])%m[2])*p[2])%m[2];
        hashval1.ss=(hashval1.ss+b[i])%m[2];

        if(parentset.find(hashval1)!=parentset.end())
        {
            ind=i-len+1;
            return true;
        }
    }
    return false;

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    {
        cin>>as>>bs;

        for(ll i=0;i<as.size();i++)
            a[i]=as[i]-'a'+1;

        for(ll i=0;i<bs.size();i++)
            b[i]=bs[i]-'a'+1;

        ll lo=0,hi=bs.size();
        ll lode;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo+1)/2;

            if(check(mid))
                {
                    lode=mid;
                    lo=mid+1;
                }
            else
                hi=mid-1;
        }

        if(lode==0)
            cout<<lode<<'\n';
        else
            cout<<bs.substr(ind,lode)<<'\n'<<lode<<'\n';

    }
    return 0;
}
