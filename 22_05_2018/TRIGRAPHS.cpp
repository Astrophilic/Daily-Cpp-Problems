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



int main()
{   
	fastIO
	ll ctr=1;

	while(1)
    {

    	ll n;
    	cin>>n;
    	if(n==0)
    		break;

    	ll a[n][3];

    	for(ll i=0;i<n;i++)
    		for(ll j=0;j<3;j++)
    			cin>>a[i][j];

    	ll d[n][3];

    	ll s=a[0][1];

    	d[0][2]=s+a[0][2];
    	d[1][0]=s+a[1][0];
    	d[1][1]=a[1][1]+min(d[1][0],min(s,d[0][2]));
    	d[1][2]=a[1][2]+ min(s,min(d[1][1],d[0][2]));
    

    for(ll i=2;i<n;i++)
    {
    	d[i][0]=a[i][0]+min(d[i-1][0],d[i-1][1]);
    	d[i][1]=a[i][1]+min(d[i][0],min(d[i-1][0],min(d[i-1][1],d[i-1][2])));
    	d[i][2]=a[i][2]+min(d[i][1],min(d[i-1][1],d[i-1][2]));
    }

    cout<<ctr++<<". "<<d[n-1][1]<<endl;
}

    return 0;
}