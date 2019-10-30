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

#define t int t; cin>>t; while(t--)

using namespace std;

const ll N=1e5+10;

ll BIT[N];
ll n;
ll getSum(ll index)
{
    ll sum=0;
    index+=1;
    while(index>0)
    {
        sum+=BIT[index];
        index=index-(index&(-index));
    }
    return sum;
}
void update(ll index)
{
    index+=1;
    while(index<=n)
    {
        BIT[index]+=1;
        index+=(index&(-index));
    }

}

int main()
{


    cin>>n;

    map<ll,ll>mymap;
    ll k=0;

    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        mymap[x]=k++;
    }
    ll ans=0;

    ll ar[n];
    for(ll i=0;i<n;i++)
        cin>>ar[i];

    for(ll i=n-1;i>=0;i--)
    {

        ll an=getSum(mymap[ar[i]]-1);

        if(an)
            ans++;
        update(mymap[ar[i]]);

    }
    cout<<ans<<"\n";



    return 0;
}
