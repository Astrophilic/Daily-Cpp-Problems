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

const ll N=2010;

int d[N][N];

ll n;

ll v[N];


ll f( ll L, ll R)
{

    ll Y=fabs(fabs(R-L)-n);
    if(L==R)
        return v[L]*Y;

    if(d[L][R]!=-1)
        return d[L][R];

    return d[L][R]=max(Y*v[L]+f(L+1,R), Y*v[R] +f(L,R-1));
}

int main()
{   
	fastIO
	
    {


    cin>>n;

    
        
            for(ll k=0;k<N;k++)
                for(ll l=0;l<N;l++)
                    d[k][l]=-1;


    for(ll i=0;i<n;i++)
        cin>>v[i];


    cout<<f(0,n-1)<<"\n";
    
    }

    return 0;
}