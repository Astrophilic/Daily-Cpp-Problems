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
const ll m=1e9+7;

ll modexe(ll x,ll n)
{
    x=(x%m);

    if(n==0)
        return 1;
    ll p=modexe(x*x,n/2);

    if(n%2)
        p=(p*x);

    return p%m;

}

ll modinv(ll x)
{
    return modexe(x,m-2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin>>s;

    ll n=s.length();

    ll lo=0,hi=n-2;

    ll preHash[n];
    ll powp[n];
    ll invp[n];

    ll ppow=1;
    ll p=31;

    powp[0]=1;
    for(ll i=1;i<n;i++)
    {
        powp[i]=(p*powp[i-1])%m;
    }

    for(ll i=0;i<n;i++)
    {
        invp[i]=modinv(powp[i]);
    }

    ll hashVal=0;
    for(ll i=0;i<n;i++)
    {
        hashVal=(hashVal+ppow*(s[i]-'a'+1))%m;
        ppow=(ppow*p)%m;
        preHash[i]=hashVal;
    }


    vector<ll>lengths;

    for(ll len=n-2;len>=1;len--)
     {
    ll leftend=len-1;
     ll rightstart=n-len;

     ll prefixhash=preHash[leftend];
     ll suffixhash=(((preHash[n-1]-preHash[n-len-1]+m)%m) * invp[n-len]  )%m;

    if(prefixhash==suffixhash)
        lengths.push_back(len);
    }


    if(lengths.empty())
    {
        cout<<"Just a legend\n";
    }
    else
    {




        sort(lengths.begin(),lengths.end());

        if(lengths.size()==1)
        {
            ll window=lengths[0];
            ll curhash=preHash[window-1];
            ll flag=0;
            for(ll i=window;i<n-1;i++)
            {
                ll winhash=(((preHash[i]-preHash[i-window]+m)%m)*invp[i-window+1])%m;
                if(curhash==winhash)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                 cout<<"Just a legend\n";
            }
            else
                cout<<s.substr(0,window);
            return 0;

        }

        ll lodu=0;
        ll hidu=lengths.size()-1;

        while(lodu<hidu)
        {


            ll index=lodu+(hidu-lodu+1)/2;

            ll window=lengths[index];


            ll curhash=preHash[window-1];
            ll flag=0;
            for(ll i=window;i<n-1;i++)
            {
                ll winhash=(((preHash[i]-preHash[i-window]+m)%m)*invp[i-window+1])%m;
                if(curhash==winhash)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                lodu=index;
            else
                hidu=index-1;
        }
        if(lodu==0)
        {
            ll window=lengths[0];

            ll curhash=preHash[window-1];
            ll flag=0;
            for(ll i=window;i<n-1;i++)
            {
                ll winhash=(((preHash[i]-preHash[i-window]+m)%m)*invp[i-window+1])%m;
                if(curhash==winhash)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout<<s.substr(0,lengths[0])<<'\n';
            else
                cout<<"Just a legend\n";
        }
        else
            cout<<s.substr(0,lengths[lodu])<<'\n';
    }

    return 0;
}
