
/*code by hazra*/

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define pul pair<ull,ull>
#define pl pair<ll,ll>

#define present(c,x) ((c).find(x) != (c).end())

using namespace std;



#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }






std::vector<ll>p;
bool pms[150];
ll spm[210];

void fun()
{
	
	for(ll i=2;i<150;i++)
	{
		if(pms[i]==false)
		{
			p.push_back(i);
			for(ll j=2*i;j<150;j+=i)
				pms[j]=true;
		}
	}

	for(ll i=0;i<p.size();i++)
	{
		for(ll j=0;j<p.size();j++)
		{	
			if(i==j)
				continue;
			ll prod=p[i]*p[j];

			if(prod<=200)
				spm[prod]=1;
		}
	}

}
void solve()
{	

	fun();





	ll t;
	cin>>t;
	while(t--) 
	{
	    
	    ll n;
	    cin>>n;

	    ll a[n+1];
	    ll cum[n+1];

	    for(ll i=1;i<=n;i++)
	    	cin>>a[i];
	    
	    cum[1]=a[1];

	    for(ll i=2;i<=n;i++)
	    	cum[i]=a[i]+cum[i-1];

	    ll reach=a[1];
	    ll pepe=1;

	    ll in=1;

	    ll day=1;

	    for(;;day++)
	    {
	    	pepe+=reach;

	    	//cout<<"day "<<day<<" and peps "<<pepe<<"\n";
	    	if(pepe>=n)
	    		break;
	    	in+=reach;
	    	reach=cum[in];
	    }
	    cout<<day<<"\n";
	}
}
int main()
{   
	solve();
    return 0;
}