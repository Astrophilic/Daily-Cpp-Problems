#include <bits/stdc++.h>
#define ff first
#define ss second
#define D double
#define sz size()
#define pb push_back
#define mp make_pair
#define nl printf("\n")
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define f(i,a,b) for(int i=a;i<b;i++)
#define r(i,a,b) for(int i=a;i>b;i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pull pair<ull,ull>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define MX  500007
#define MOD 1000000007
#define INF 2000000000000000LL
#define EPS 1e-9
const ll N=1e6+10;
#define t int t; cin>>t; while(t--)
using namespace std;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }

struct node
{
    int self;
    int strength=0;
    int vis=0;
    vector<int>neighbours;
};
node *gr;
int bfs(ll src, ll str)
{
    if(gr[src].vis!=0)
        {//cout<<"src start "<<src<<endl;
        return -1;}
    gr[src].vis=src;
    gr[src].strength=str;
    gr[src].self=src;


    queue<node>q;
    q.push(gr[src]);

    while(!q.empty())
    {
        node tp=q.front();
        int u=tp.self;
        q.pop();
        if(tp.strength==0)
            break;

        for(ll i=0;i<gr[u].neighbours.size();i++)
        {   ll c=gr[u].neighbours[i];
            if(!gr[c].vis)
            {
                gr[c].vis=src;
                gr[c].self=c;
                gr[c].strength=gr[u].strength-1;
                q.push(gr[c]);
            }
            else if(gr[c].vis!=src)
                {
                   // cout<<"vis neig "<<c<<endl;
                    return -1;
                }
        }

    }
    return 0;
}

int main()
{      ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
       t{

        ll n,r,m;
        cin>>n>>r>>m;
        gr=new node[n+15];

        while(r--)
        {
            ll a,b;
            cin>>a>>b;
            gr[a].neighbours.pb(b);
            gr[b].neighbours.pb(a);
        }
        vector< pll >plc;
        while(m--)
        {
            ll k,s;
            cin>>k>>s;
            plc.pb({k,s});
        }
        ll f=0;
        for(ll i=0;i<plc.size();i++)
        {
            ll fv=plc[i].ff;
            ll st=plc[i].ss;
            if(bfs(fv,st)==-1)
            {
                f=1;
                break;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            if(gr[i].vis==0)
        {
            f=1;
            break;
        }
        }
        if(f)
            cout<<"No\n";
        else
            cout<<"Yes\n";
       }
    return 0;
}
