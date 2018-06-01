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
	t
    {


    	ll a,b;
    	cin>>a>>b;

    	if(a==0)
    		{
    			cout<<b<<endl;
    			continue;
    		}
    	if(b==0)
    	{
    		cout<<a<<endl;
    		continue;
    	}

    	ll hi=1e10+10;
    	ll lo=0;

    	while(lo<hi)
    	{

    		ll mid=lo+(hi-lo+1)/2;

    		//cout<<"mid:"<<mid<<endl;
    		ll numa=a/mid;

    		ll numb=b/mid;


    		if(numa*mid==a&&numb*mid==b)
    		{
    			lo=mid;

    		}
    		if(numa*mid!=0&&numb*mid!=0&&numa*mid<=a&&numb*mid<=b)
    			lo=mid;
    		else
    			hi=mid-1;

    	}
    	cout<<lo<<endl;
    }

    return 0;
}