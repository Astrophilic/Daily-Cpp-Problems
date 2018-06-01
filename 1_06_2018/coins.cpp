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

const ll M=1000010;
ll d[M];
ll L,K;

int main()
{   
	//fastIO
	
    
    	
    	cin>>K>>L;
    	ll n;
    	cin>>n;


    	for(ll i=1;i<M;i++)
    	{
    		if(i==K||i==L||i==1)
    		{
    			d[i]=1;
    		}
    		else
    		{

    			ll pv1=i-1;
    			ll pvl=i-L;
    			ll pvk=i-K;

    			ll v1,v2,v3;
    			v1=v2=v3=1;

    			if(pv1>0)
    				v1=d[pv1];
    			if(pvl>0)
    				v2=d[pvl];
    			if(pvk>0)
    				v3=d[pvk];

    			if(v1==0||v2==0||v3==0)
    				d[i]=1;

    		}
    	}
    	while(n--)
    	{
    		ll x;
    		cin>>x;
    		if(d[x])
    		    cout<<'A';
    		else
    			cout<<'B';
    	
    	}
    

    return 0;
}