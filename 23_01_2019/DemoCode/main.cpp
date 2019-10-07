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

using namespace std;

#define t int t; cin>>t; while(t--)
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

const ll M=1e7+10;

class bit
{
public:
    ll *BIT;
    int len;

    bit(int len)
    {
        BIT=new ll[len+1];

        for(ll i=0;i<len+1;i++)
            BIT[i]=0;

        this->len=len;
    }
    void build(int idx,int value)
    {

        ll next=idx+1;

        while(next<=len)
        {
            BIT[next]+=value;
            next=next+(next & (-next));
        }
    }
    ll query(ll idx)
    {

        ll next=idx+1;
        ll value=0;

       // cout<<"query idx "<<idx<<endl;
        while(next>0)
        {
            value+=BIT[next];
          //  cout<<"Bit vaue "<<BIT[next]<<endl;

            next=next-(next & (-next));
           // cout<<"value"<<value<<endl;
        }
        return value;

    }
};




int main()
{

    ll tc;
    cin>>tc;
    while(tc--)
    {


    ll n;
    cin>>n;
    ll ans=0;
    ll a[n];
    ll mx=0;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);

    }

    bit B(mx+1);

    for(ll i=0;i<n;i++)
    {

        ans+=B.query(mx)-B.query(a[i]);
        B.build(a[i],1);
    }

    cout<<ans<<"\n";


    }




    return 0;
}
