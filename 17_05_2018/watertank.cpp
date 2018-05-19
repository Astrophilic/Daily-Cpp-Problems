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
#define t int t; cin>>t; while(t--)
using namespace std;
#define ld  double
const ld EPS=1e-7;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



struct node
{
	ld b,h,w,d;

};
int main()
{   
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	t
    {
    	ll n;
    	cin>>n;

    	node here[n];
    	ld hv=0.0;

    	for (int i = 0; i < n; ++i)
    	{	
    		ld x,y,z,u;
    		cin>>x>>y>>z>>u;

    	
    		
    		here[i].b=x;
    		here[i].h=y;
    		here[i].w=z;
    		here[i].d=u;

    		hv+=y*z*u;
    	}

    	ld V;
    	cin>>V;

    	//cout<<fixed<<setprecision(10)<<"here volume and given vol"<<hv<<" "<<V<<endl;
    	if(hv<V)
    	{
    		cout<<"OVERFLOW\n";
    		continue;
    	}

    	ld lo=0;
    	ld hi=1e7;
    	ld fans=0;

    	while(1)
    	{


    		if(dcmp(lo,hi)==0)
    			break;
    		ld mid=(lo+hi)/2.0;


    		
    		ld fvalue=0;

    		ll flag=0;
    		//cout<<"lo :"<<lo<<" hi:"<<hi<<"\n";
    		//cout<<"set mid="<<mid<<endl;

    		for (int i = 0; i < n; ++i)
    		{	
    			if(here[i].b<mid)
    			{
    				ld hereh=min(here[i].h,fabs(here[i].b-mid));

    				if(hereh!=here[i].h)
    					flag=1;

    				//cout<<"here h ="<<hereh<<endl;
    				fvalue+=hereh*here[i].w*here[i].d;

    			}
    		}
    		//cout<<"fvalue here "<<fvalue<<endl;

    		


    		
    		 if(fvalue>=V)
    			hi=mid;
    		else
    			lo=mid;




    	}

    	cout<<fixed<<setprecision(2)<<lo<<"\n";



    }

    return 0;
}