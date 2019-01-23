
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




void solve()
{

    ll n;
    cin>>n;

    stack<ll>stk;

    ll a[n+2],ans[n+1],L[n+1],R[n+1];

    for(ll i=1;i<=n;i++)
        ans[i]=0,R[i]=n+1,L[i]=0;

    ans[n+1]=0;

    for(ll i=1;i<=n;i++)
        cin>>a[i];

    for(ll i=1;i<=n;i++)
    {

        while(!stk.empty()&&a[stk.top()]>=a[i])
            stk.pop();

        if(!stk.empty())
            L[i]=stk.top();

        stk.push(i);
    }
    while(!stk.empty())
        stk.pop();

    for(ll i=n;i>=1;i--)
    {

     while(!stk.empty()&&a[stk.top()]>=a[i])
            stk.pop();

        if(!stk.empty())
            R[i]=stk.top();

        stk.push(i);
    }


//    for(ll i=1;i<=n;i++)
//        cout<<L[i]<<" "<<R[i]<<endl;

    for(ll i=1;i<=n;i++)
    {
        ll length=R[i]-L[i]-1;

       // cout<<"length "<<length<<" "<<ans[length]<<"\n";
        ans[length]=max(ans[length],a[i]);
      //  cout<<"after update "<<ans[length]<<"\n";
    }


//    for(ll i=1;i<=n;i++)
//        cout<<ans[i]<<" ";
//    cout<<"\n";
    for(ll i=n;i>0;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }


    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";





}
int main()
{
	solve();
    return 0;
}
