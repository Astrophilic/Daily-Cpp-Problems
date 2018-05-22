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


ll k,n,m;
ll c=0;
ll ck1;
ll x[20];

void multiply(ll a[2][2],ll b[2][2])
{

	ll mul[2][2];

	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<2;j++)
		{
			mul[i][j]=0;

			for(ll k=0;k<2;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];

				if(mul[i][j]>=m)
					mul[i][j]%=m;

			}
		}
	}

	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
			a[i][j]=mul[i][j];


}




void power(ll F[2][2],ll n)
{

	ll A[2][2]={ {c,1},{0,1} };

	if(n==1)
		return;

	cout<<"F here raised to "<<n<<endl;
	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<2;j++)
			cout<<F[i][j];
		cout<<endl;
	}
	cout<<"F raised \n";
	power(F,n/2);

	multiply(F,F);

	if(n%2)
		multiply(F,A);

	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<2;j++)
			cout<<F[i][j];
		cout<<endl;
	}
	return;


}

ll fun(ll n)
{	
	ll F[2][2]={ {c,1},{0,1} };

	for(ll i=0;i<2;i++)
	{
		for(ll j=0;j<2;j++)
			cout<<F[i][j];
		cout<<endl;
	}
	power(F,n-k+1);


	ll ans=0;

	ans+=x[k-1]*F[0][0];

	if(ans>=m)
		ans%=m;

	ans+=ck1;

	if(ans>=m)
		ans%=m;

	return ans;

}
int main()
{   
	fastIO
	t
    {
    	cin>>k>>m>>n;

    	for(ll i=0;i<k;i++)
    	{
    		ll x;
    		cin>>x;
    		c+=x;

    	}
    	cout<<"sum c "<<c<<endl;
    	cin>>ck1;

    	for(ll i=0;i<k;i++)
    		cin>>x[i];

    	if(n<k)
    		cout<<x[n]%m<<endl;
    	else
    		cout<<fun(n)<<endl;



    }

    return 0;
}