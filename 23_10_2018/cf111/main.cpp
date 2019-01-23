#include <bits/stdc++.h>
using namespace std;
#define ll long long



const ll M=1e6;
vector<ll>v;

void seive()
{

    bool primes[M];
    memset(primes,true,M);

    for(ll i=4;i<M;i+=2)
        primes[i]=false;

    for(ll i=3;i*i<=M;i++)
    {
        if(primes[i]==true)
        {

            for(ll j=i*i;j<M;j+=i)
                primes[j]=false;
        }
    }
    for(ll i=2;i<M;i++)
    {
        if(primes[i]==true)
            v.push_back(i);
    }
}

ll totient(ll x)
{

    ll prod=x;
    ll num,deno;
    num=deno=1;

    for(ll i=0;i<v.size();i++)
    {

        if(v[i]*v[i]>x)
            break;

        if(x%v[i]==0)
        {

        num*=(v[i]-1);
        deno*=v[i];

        while(x%v[i]==0)
        {
            x/=v[i];
        }
        }

    }
    if(x!=1)
    {
        num*=(x-1);
        deno*=x;
    }
    return (prod*num)/deno;
}
const ll N=1e5;

vector<ll>look(3*N,0);

ll ntot(ll n,ll x)
{

    ll cnt=1;

    if(x==1)
        return 1;

    for(ll i=2;i<=n;i++)
    {

        if(__gcd(n,i)==1)
        {


            cnt++;
            if(cnt==x)
            {
                return i;
            }



        }
    }

    return -1;


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive();

        look[0]=1;

        for(ll n=1;n<300000;n++)
            look[n]=look[n-1]+totient(n);

        while(1)
        {

        ll k;
        cin>>k;
        if(k==0)
            break;

        if(k==1)
        {
            cout<<"0/1\n";
            continue;
        }
        ll in=lower_bound(look.begin(),look.end(),k)-look.begin();

       // cout<<"in is"<<in<<" "<<look[in]<<"\n";

        ll to=k-look[in-1];

       // cout<<"to is"<<to<<endl;
        cout<<ntot(in,to)<<"/"<<in<<endl;
        }

    return 0;
}
