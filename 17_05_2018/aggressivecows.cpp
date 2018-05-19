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
#define ld double
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	t
    {

    ull n,c;
    cin>>n>>c;

    set<ull>xoc;

    for (int i = 0; i < n; ++i)
    {
    	ull x;
    	cin>>x;
    	xoc.insert(x);
    }

    


    ull lo=0,hi=1e9+500;

    while(lo<hi)
    {
    	ull mid=lo+(hi-lo+1)/2;


    	//cout<<"lo:"<<lo<<" hi:"<<hi<<endl;
    	//cout<<"mid is "<<mid<<endl;
    	set<ull>tmp=xoc;
    	ull strt=*xoc.begin();

    	ull ctr=1;
    	ull k=1;


    	while(1)
    	{	

    		auto it=lower_bound(all(tmp),(strt+mid));
    		
    		if(it==tmp.end())
    			break;
    		
    		strt=*it;
    		ctr++;
    		tmp.erase(it);


    	}
    	//cout<<"cows for block size mid"<<ctr<<endl;

    	if(ctr<c)
    		hi=mid-1;
    	else
    		lo=mid;

    }
    cout<<lo<<"\n";
    }

    return 0;
}