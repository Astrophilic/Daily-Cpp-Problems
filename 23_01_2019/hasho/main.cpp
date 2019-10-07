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
#define pll pair<LL,LL>
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

const ll m=1e9+7;

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
           // cout<<"in value "<<(c - 'a' + 1)<<'\n';
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}



int main()
{



    {
        string s;
        cin>>s;
        ll n=s.size();

       // cout<<"computed hash "<<compute_hash(s)<<'\n';
        ll pre_hash[n],suf_hash[n],powmod[n];

        ll p=31;
        ll m=1e9+7;
        ll ppow=1;
        ll hash_value=0;

        for(ll i=0;i<n;i++)
        {
            powmod[i]=ppow;
            ppow=(ppow*p)%m;
        }

        for(int i=0;i<n;i++)
        {
            hash_value=(hash_value+(s[i]-'a'+1)*powmod[i])%m;

            pre_hash[i]=hash_value;
        }

        hash_value=0;


        for(int i=n-1;i>=0;i--)
        {
              hash_value=(hash_value+(s[i]-'a'+1)*powmod[n-i-1])%m;

            suf_hash[i]=hash_value;
        }

        ll q;
        cin>>q;
        while(q--)
        {

            ll i,j;
            cin>>i>>j;

            string sub=s.substr(i,j-i+1);
            cout<<"sub "<<sub<<"\n";

            ll fhash=pre_hash[j]-(i>0?pre_hash[i-1]:0);
            ll bhash=suf_hash[i]-(j<n-1?suf_hash[j+1]:0);

            cout<<bhash<<'\n';
            ll pf=i;
            ll bf=n-j-1;
            ll df=0;
            if(pf>bf)
                df=pf-bf;
            else
                df=bf-pf;


            if(pf<bf)
                fhash=(fhash*powmod[df])%m;
            else
                bhash=(bhash*powmod[df])%m;

            cout<<"forward hash "<<fhash<<" backward hash"<<bhash<<"\n";
            if(fhash==bhash)
            cout<<"palindrome\n";
            else
                cout<<"not a palin\n";
        }

    }
    auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
