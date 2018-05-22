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

    	ll p[a];

    	for (int i = 0; i < a; ++i)
    	{
    		cin>>p[i];
    	}

    	ll mind=1e15;
    	ll maxp=0;

    	ll start=0;
    	ll end=0;


    	ll sum=0;

    	for(end=0;end<a;end++)
    	{
    		
    		
    		
    			sum+=p[end];
    		
    		

    		while(sum>b)
    			sum-=p[start++];


    		cout<<"st:"<<start<<" en"<<end<<" sum"<<sum<<endl;


    		if(sum<=b)
    		{
    			ll dif=end-start+1;

    			if(dif>maxp)
    			{
    				maxp=dif;
    				mind=sum;
    			}
    			else if(dif==maxp&&sum<mind)
    			{
    				mind=sum;
    				maxp=dif;

    			}
    		}
    		//cout<<"max plat "<<maxp<<" "<<" minsum"<<mind<<endl;

    		

    	}

    	if(mind==1e15)
    		mind=0;
    	cout<<mind<<" "<<maxp<<"\n";
    }

    return 0;
}