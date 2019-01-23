#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pul pair<ull,ull>
#define pl pair<ll,ll>
#define pi pair<int,int>

using namespace std;

//#define t int t; cin>>t; while(t--)
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }

map<string,ll> mp;
string a[100005];

ll bin(string s, string r)
{
    ll l=0,h=min(r.size(),s.size())-1;
    ll mid;
    while(h-l>5)
    {
        mid=(l+h)/2LL;
        if(s[mid]==r[mid])
            l=mid;
        else
            h=mid-1LL;
    }
    for(ll i=h;i>=l;i--)
    {
        if(s[i]==r[i])
            return i;
    }
}

int main()
{
	fastIO
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        string r="";
        for(ll j=0;j<a[i].size();j++)
        {
            r+=a[i][j];
            if(mp.find(r)==mp.end())
                mp[r]=i;
        }
    }
    while(m--)
    {
        string s,r="";
        cin>>s;
        ll ans=s.size();
        for(ll i=0;i<s.size();i++)
        {
            r+=s[i];
            if(mp.find(r)==mp.end())
                continue;
            ll ind=mp[r];
            ll mat=bin(a[ind],s)+1LL;
            ll tot=i+2LL+((ll)a[ind].size()-mat)+((ll)s.size()-mat);
            ans=min(ans,tot);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
