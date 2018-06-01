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
	string a;
	while(cin>>a)
    {
    	

    	ll evup=0,odup=0,evlow=0,odlow=0;
    	for(ll i=0;i<a.size();i++)
    	{
    		if(i%2==0)
    		{
    			if(islower(a[i]))
    				evup++;
    		}
    		else
    		{
    			if(isupper(a[i]))
    				evup++;
    		}
    	}
    	for(ll i=0;i<a.size();i++)
    	{
    		if(i%2)
    		{
    			if(islower(a[i]))
    				odup++;
    		}
    		else
    		{
    			if(isupper(a[i]))
    				odup++;
    		}
    	}

    	for(ll i=0;i<a.size();i++)
    	{
    		if(i%2==0)
    		{
    			if(isupper(a[i]))
    				evlow++;
    		}
    		else
    		{
    			if(islower(a[i]))
    				evlow++;
    		}
    	}


    	for(ll i=0;i<a.size();i++)
    	{
    		if(i%2)
    		{
    			if(isupper(a[i]))
    				odlow++;
    		}
    		else
    		{
    			if(islower(a[i]))
    				odlow++;
    		}
    	}
    	
    	cout<<min(evup,min(odup,min(odlow,evlow)))<<endl;
    }

    return 0;
}