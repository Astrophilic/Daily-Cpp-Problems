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
using namespace std::chrono;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }

const ll m1=1e9+7;
const ll m2=1e9+9;
ll p1=31;
ll p2=101;
const ll M=1e6;

ll ind;
string a,b;

pair<ll,ll>hash_a[M],hash_b[M];

ll powp1[M],powp2[M];

ll powinvp1[M],powinvp2[M];

ll modexe(ll x,ll n,ll m)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(res*x)%m;
        x=(x*x)%m;
        n>>=1;
    }
    return res;
}


ll modinv(ll x,ll m)
{
    return modexe(x,m-2,m);
}

void init(ll len)
{
    powp1[0]=1;
    powp2[0]=1;
    for(ll i=1;i<len;i++)
    {
        powp1[i]=(p1*powp1[i-1])%m1;
        powp2[i]=(p2*powp2[i-1])%m2;
    }

    for(ll i=0;i<len;i++)
    {
        powinvp1[i]=modinv(powp1[i],m1);
        powinvp2[i]=modinv(powp2[i],m2);
    }
}


bool valid(ll len)
{
    if(len==0)
        return 0;

    set<pll>parset;
    pll prevhash=hash_a[len-1];
    parset.insert(prevhash);
    for(ll i=len;i<a.size();i++)
    {
       // ll curhash1=(((hash_a[i].ff-hash_a[i-len].ff+m1)%m1)*modinv(modexe(p1,i-len+1,m1),m1))%m1;
       // ll curhash2=(((hash_a[i].ss-hash_a[i-len].ss+m2)%m2)*modinv(modexe(p2,i-len+1,m2),m2))%m2;


        ll curhash1=(((hash_a[i].ff-hash_a[i-len].ff+m1)%m1)*powinvp1[i-len+1])%m1;//modinv(modexe(p1,i-len+1,m1),m1))%m1;
        ll curhash2=(((hash_a[i].ss-hash_a[i-len].ss+m2)%m2)*powinvp2[i-len+1])%m2;//modinv(modexe(p2,i-len+1,m2),m2))%m2;


        parset.insert({curhash1,curhash2});
    }

    prevhash=hash_b[len-1];

    if(parset.find(prevhash)!=parset.end())
    {
        ind=0;
        return 1;
    }
    for(ll i=len;i<b.size();i++)
    {


     //   ll curhash1=(((hash_b[i].ff-hash_b[i-len].ff+m1)%m1)*modinv(modexe(p1,i-len+1,m1),m1))%m1;
     //   ll curhash2=(((hash_b[i].ss-hash_b[i-len].ss+m2)%m2)*modinv(modexe(p2,i-len+1,m2),m2))%m2;

          ll curhash1=(((hash_b[i].ff-hash_b[i-len].ff+m1)%m1)*powinvp1[i-len+1])%m1;//modinv(modexe(p1,i-len+1,m1),m1))%m1;
        ll curhash2=(((hash_b[i].ss-hash_b[i-len].ss+m2)%m2)*powinvp2[i-len+1])%m2;//modinv(modexe(p2,i-len+1,m2),m2))%m2;
        if(parset.find({curhash1,curhash2})!=parset.end())
        {
           //cout<<"for length "<<len<<" string "<<b.substr(i-len+1,len)<<'\n';
            ind=i-len+1;
            return 1;
        }
    }
    return 0;
}
int main()
{



    {

    cin>>a>>b;

    init(max(a.size(),b.size()));
    ll hash_value1=0;
    ll hash_value2=0;


    for(ll i=0;i<a.size();i++)
    {
        hash_value1=(hash_value1+(a[i]-'a'+1)*powp1[i])%m1;
        hash_value2=(hash_value2+(a[i]-'a'+1)*powp2[i])%m2;

        hash_a[i]={hash_value1,hash_value2};
    }



    hash_value1=0;
    hash_value2=0;

    for(ll i=0;i<b.size();i++)
    {
        hash_value1=(hash_value1+(b[i]-'a'+1)*powp1[i])%m1;
        hash_value2=(hash_value2+(b[i]-'a'+1)*powp2[i])%m2;

        hash_b[i]={hash_value1,hash_value2};
    }


    ll lo=0,hi=b.size();

    while(lo<hi)
    {
        ll mi=lo+(hi-lo+1)/2;

        if(valid(mi))
            lo=mi;
        else
            hi=mi-1;

    }
    if(lo==0)
        cout<<lo<<"\n";
    else
        cout<<b.substr(ind,lo)<<"\n"<<lo<<'\n';

    }

    return 0;
}
