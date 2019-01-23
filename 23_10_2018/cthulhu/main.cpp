
/*code by hazra*/

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define pul pair<ull,ull>
#define pl pair<ll,ll>

#define present(c,x) ((c).find(x) != (c).end())

using namespace std;



#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }




vector<ll>v[110];
ll vis[110];


void dfs(ll s)
{
    vis[s]=1;
    for(auto child:v[s])
        if(!vis[child])dfs(child);
}
void solve()
{



    ll n,m;
    cin>>n>>m;


    for(ll i=0;i<m;i++)
    {

        ll x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    if(n<3||n!=m)
    {
        cout<<"NO\n";
        return;
    }

    dfs(1);

    for(ll i=1;i<=n;i++)
        if(!vis[i])
    {

        cout<<"NO\n";
        return;
    }

    cout<<"FHTAGN!\n";



}
int main()
{
	solve();
    return 0;
}
