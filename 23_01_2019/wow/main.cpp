#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

map<ll,ll>ans;

ll fun(ll n)
{
    if(n==0)
        return 0;
    if(ans.find(n)!=ans.end())
        return ans[n];

    return ans[n]=max(n,fun(n/2)+fun(n/3)+fun(n/4));
}
int main()
{
    ll t;
    while(cin>>t)
    {
        cout<<fun(t)<<'\n';
    }
    return 0;
}
