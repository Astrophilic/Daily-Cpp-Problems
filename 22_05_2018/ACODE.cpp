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
	//fastIO
	while(1)
    {
    	string s;
    	cin>>s;
    	if(s[0]=='0')
    		break;

    	ll d[s.size()+10]={0};

    	ll n=s.size();

    	

    	
    	d[0]=1;

    	if(n>1)
    	{
    		ll q=(s[0]-'0')*10+s[1]-'0';

    		if(q>10&&q<27&&s[1]!='0')
    			d[1]=2;
    		else
    			d[1]=1;

    	}
    	for(ll i=2;i<n;i++)
    	{
    		

    			ll q=(s[i-1]-'0')*10+ s[i]-'0';
    				
    			if(s[i]!='0')
    			{
    				if(q>10&&q<27)
    					d[i]=d[i-1]+d[i-2];
    				else
    					d[i]=d[i-1];
    			}
    			else
    				d[i]=d[i-2];


    	}
    	cout<<d[n-1]<<"\n";
    }

    return 0;
}