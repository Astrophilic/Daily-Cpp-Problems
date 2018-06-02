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


ll dp[110][110];
vector<char>v;
ll f(ll ind,ll k)
{
	
    if(k!=0&&ind>=v.size())
        return -1;

    if(k==0||ind>=v.size())
		return 0;




	if(dp[ind][k]!=-1)
		return dp[ind][k];


    ll v1=f(ind+1,k-1);

    if(v1!=-1)
        v1+=v[ind];
    else
        v1=0;

    ll v2=f(ind+1,k);

    if(v2==-1)
        v2=0;

	return dp[ind][k]=max(v1,v2);


}


int main()
{   
	
	t
    {
    	v.clear();
    	string a,b;
    	cin>>a>>b;
    	ll k;
    	cin>>k;

    	ll d[a.size()+10][b.size()+10];
    	memset(d,0,sizeof(d));
    	
        set< pair<char , pair<ll,ll> > >ans;

    	for(ll i=0;i<110;i++)
    		for(ll j=0;j<110;j++)
    			dp[i][j]=-1;


    	for(ll i=1;i<=a.size();i++)
    	{
    		for(ll j=1;j<=b.size();j++)
    		{
    			if(a[i-1]==b[j-1])
    				d[i][j]=1+d[i-1][j-1],ans.insert({a[i-1],{i-1,j-1}});
    			else
    				d[i][j]=max(d[i-1][j],d[i][j-1]);
    		}
    	}
    	

        for(auto x:ans)
            v.push_back(x.ff);


    	if(v.size()<k)
    		cout<<0<<endl;
    	else
    	{

            if(k>v.size())
                k=v.size();


    		cout<<f(0,k)<<endl;
    	}
    	
    	
    }

    return 0;
}