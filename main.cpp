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
string getStr(ll val)
{
    string res="";
    while(val)
    {
        ll rem=val%10+1;
        char c='a'+rem-1;
        res+=c;
        val/=10;
    }
    return res;
}
map<string,ll>string_to_hash;
map<ll,string>hash_to_string;

int main()
{


    auto start = high_resolution_clock::now();
     t
    {
        //srand(time(0));

        ll rvalue=1000000000+rand()%100000000;
       // ll rvalue=1+rand();

        //cout<<rvalue<<'\n';
       string random_String=getStr(rvalue);
     //  cout<<random_String<<"\n";
        if(string_to_hash.find(random_String)!=string_to_hash.end())
            continue;

        ll hash_value=compute_hash(random_String);

        //cout<<"randstr"<<randstr<<" hash->"<<hasv<<'\n';
        if(hash_to_string.find(hash_value)!=hash_to_string.end())
        {
            cout<<"collision found\n";

            cout<<"collided string "<<random_String<<" with "<<hash_to_string[hash_value]<<"\n";
        }
        else
        {   string_to_hash[random_String]=hash_value;
            hash_to_string[hash_value]=random_String;

        }

    }
    auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
