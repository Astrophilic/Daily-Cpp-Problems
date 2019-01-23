
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


const ll M=1e5+10;
ll a[M];
struct node
{
ll n0=0;
ll n1=0;
ll n2=0;
ll lazy=0;

};

node tree[4*M];


node merge(node a,node b)
{
        node res;
        res.n0=a.n0+b.n0;

        res.n1=a.n1+b.n1;

        res.n2=a.n2+b.n2;

        return res;

}

void build(ll id, ll s, ll e)
{
    if(s==e)
    {
        if(a[s]==0)
            tree[id].n0=1;
        else if(a[s]==1)
                tree[id].n1=1;
        else if(a[s]==2)
                tree[id].n2=1;

    return;
    }

    ll m=s+(e-s)/2;
    build(2*id,s,m);
    build(2*id+1,m+1,e);

    tree[id]=merge(tree[2*id],tree[2*id+1]);

}

void update(ll id,ll s,ll e,ll ql,ll qr)
{

    if(tree[id].lazy!=0)
    {
        tree[id].lazy%=3;

        if(tree[id].lazy%3!=0)
        {

            ll val=tree[id].lazy;

            if(val==1)
            {

                ll t0=tree[id].n0;
                ll t1=tree[id].n1;
                ll t2=tree[id].n2;

                tree[id].n0=t2;

                tree[id].n1=t0;

                tree[id].n2=t1;

            }
            else if(val==2)
            {




                ll t0=tree[id].n0;
                ll t1=tree[id].n1;
                ll t2=tree[id].n2;

                tree[id].n0=t1;

                tree[id].n1=t2;

                tree[id].n2=t0;


            }
        }
        if(s!=e)
        {
            tree[2*id].lazy+=tree[id].lazy;
            tree[2*id+1].lazy+=tree[id].lazy;
        }
        tree[id].lazy=0;

    }

    if(s>e||s>qr||e<ql)
        return;


    if(s>=ql&&e<=qr)
    {
                ll t0=tree[id].n0;
                ll t1=tree[id].n1;
                ll t2=tree[id].n2;

                tree[id].n0=t2;

                tree[id].n1=t0;

                tree[id].n2=t1;

                if(s!=e)
                {

                    tree[2*id].lazy+=1;
                    tree[2*id+1].lazy+=1;
                }
                return;

    }

    ll m=s+(e-s)/2;
    //cout<<"m is "<<m<<endl;
    update(2*id,s,m,ql,qr);
    update(2*id+1,m+1,e,ql,qr);

    tree[id]=merge(tree[2*id],tree[2*id+1]);

    //cout<<"range is "<<s<<" "<<e<<endl;
    //cout<<"tree after update "<<tree[id].n0<<" "<<tree[id].n1<<" "<<tree[id].n2<<" "<<endl;
}
node query(ll id,ll s, ll e, ll l , ll r)
{
    if(s>e||r<s||e<l)
    {
        node x;
        return x;
    }

     if(tree[id].lazy!=0)
    {
        tree[id].lazy%=3;

        if(tree[id].lazy%3!=0)
        {

            ll val=tree[id].lazy;

            if(val==1)
            {

                ll t0=tree[id].n0;
                ll t1=tree[id].n1;
                ll t2=tree[id].n2;

                tree[id].n0=t2;

                tree[id].n1=t0;

                tree[id].n2=t1;

            }
            else if(val==2)
            {




                ll t0=tree[id].n0;
                ll t1=tree[id].n1;
                ll t2=tree[id].n2;

                tree[id].n0=t1;

                tree[id].n1=t2;

                tree[id].n2=t0;


            }
        }
        if(s!=e)
        {
            tree[2*id].lazy+=tree[id].lazy;
            tree[2*id+1].lazy+=tree[id].lazy;
        }
        tree[id].lazy=0;

    }

    if(l<=s&&e<=r)
        return tree[id];

    ll m=s+(e-s)/2;

    node p1=query(2*id,s,m,l,r);
    node p2=query(2*id+1,m+1,e,l,r);

    node res=merge(p1,p2);
    return res;
}

int main()
{
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
    ll q;
    cin>>q;

    while(q--)
    {

        ll x;
        cin>>x;
        if(x==0)
        {

            ll l,r,c;
            cin>>l>>r>>c;

            node rs=query(1,0,n-1,l-1,r-1);

            ll an=0;

            if(c==0)
                an=rs.n0;
            else if(c==1)
                an=rs.n1;
            else
                an=rs.n2;
            cout<<an<<"\n";

        }
        else
        {
            ll l,r;
            cin>>l>>r;

            update(1,0,n-1,l-1,r-1);

        }
    }
}
